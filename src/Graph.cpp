
#include "Graph.hpp"

Graph::Graph(bool undirected_, bool weighted_, bool flows_, const VertexList& vertices_)
    : vertices{vertices_}, edges{EdgeSet{}}, adj_list{vector<unordered_set<uint64_t>>{}}, adj_matrix{vector<vector<bool>>{}}, undirected{undirected_}, weighted{weighted_}, flows{flows_}
{
    if (!this->vertices.empty()){
        for(size_t i = 0; i < this->vertices.size(); ++i){
            this->vertices[i].id = i;
        }
        this->stale_adj_list = true;
        this->stale_adj_matrix = true;
    } else{
        this->stale_adj_list = false;
        this->stale_adj_matrix = false;
    }
}

// size_t Graph::get_numV() const
// {
//     return vertices.size();
// }
// size_t Graph::get_numE() const
// {
//     return edges.size();
// }
// const VertexList& Graph::get_V() const
// {
//     return vertices;
// }
// const EdgeSet& Graph::get_E() const
// {
//     return edges;
// }
// const vector<unordered_set<uint64_t>>& Graph::get_AL() const{
//     if (stale_adj_list){
//         cerr << "Rebuild the adjacency list!" << endl;
//     } else{
//         return adj_list;
//     }
// }
// const vector<vector<bool>>& Graph::get_AM() const{
//     return adj_matrix;
// }

const VertexList& Graph::operator[](VertexKey key) const
{
    if (key == V) {
        return vertices;
    }
    throw invalid_argument("Invalid key for access");
}
const EdgeSet& Graph::operator[](EdgeKey key) const
{
    if (key == E) {
        return edges;
    }
    throw invalid_argument("Invalid key for access");
}
const AdjList& Graph::operator[](AdjListKey key) const
{
    if (stale_adj_list){
        static const AdjList empty_adj_list{};
        return empty_adj_list;
    }
    if (key == AL) {
        return adj_list;
    }
    throw invalid_argument("Invalid key for access");
}
const AdjMatrix& Graph::operator[](AdjMatrixKey key) const
{
    if (stale_adj_matrix){
        static const AdjMatrix empty_adj_matrix{};
        return empty_adj_matrix;
    }
    if (key == AM) {
        return adj_matrix;
    }
    throw invalid_argument("Invalid key for access");
}

bool Graph::is_undirected() const
{
    return undirected;
}
bool Graph::is_weighted() const
{
    return weighted;
}
bool Graph::is_flows() const
{
    return flows;
}


void Graph::add_vertex(const uint64_t& v_id, const char* name, Color color)
{
    if (!has_vertex(v_id)){

        vertices.emplace_back(name, color);
        vertices.back().id = vertices.size()-1;
        cout << "Added " << vertices.back() << endl;
    } else{
        cerr << "Vertex " << v_id << " already exists!" << endl;
    }

    this->stale_adj_list = true;
    this->stale_adj_matrix = true;
}
void Graph::del_vertex(const uint64_t& v_id)
{

    if (has_vertex(v_id))
    {
        // size_t idx = vertices[v];
        vertices.erase(vertices.begin()+v_id);
        
        erase_if(edges,
            [&v_id](const Edge& e) {
                return e.x_id == v_id || e.y_id == v_id;  // Remove edges involving the vertex
            }), edges.end();
        

        for (auto& vertex : vertices) {
            if (vertex.id > v_id) {
                vertex.id--;  // Decrement ID
            }
        }

        this->stale_adj_list = true;
        this->stale_adj_matrix = true;
    }
    else
    {
        cout << "Vertex " << v_id << " doesn't exist in this graph!" << endl;
    }

}

void Graph::add_edge(uint64_t v_id, uint64_t w_id, const double& weight, Color color, const double& flow, const double& capacity)
{
    if (!has_vertex(v_id))
    {
        add_vertex(v_id);
        v_id = vertices.size() - 1;
    }

    if (!has_vertex(w_id))
    {
        add_vertex(w_id);
        w_id = vertices.size() - 1;
    }

    Edge edge(v_id, w_id, weight, color, flow, capacity);

    if (!has_edge(v_id, w_id))
    {
        edges.insert(edge);
        if (undirected){
            Edge swapped_edge(edge.y_id, edge.x_id, edge.weight, edge.color, edge.flow, edge.capacity);
            edges.insert(swapped_edge);
        }
    }
    else
    {
        cerr << "Edge " << edge.x_id << " -> " << edge.y_id << " already exists in the graph." << endl;
    }

    this->stale_adj_list = true;
    this->stale_adj_matrix = true;

}
void Graph::del_edge(uint64_t v_id, uint64_t w_id)
{

    if (v_id >= vertices.size() || w_id >= vertices.size()){
        cerr << "Invalid vertices ids." << endl;
        return;
    }

    Edge temp_edge{v_id, w_id};
    auto it = edges.find(temp_edge);
    
    if (it != edges.end()) {
        edges.erase(it);
        cout << "Edge " << v_id << " -> " << w_id << " deleted." << endl;

        // adj_list[v_id].erase(w_id);
        // adj_matrix[v_id][w_id] = 0;

        if (undirected){
            Edge swapped_temp_edge{w_id, v_id};
            edges.erase(edges.find(swapped_temp_edge));
            cout << "Edge " << w_id << " -> " << v_id << " deleted." << endl;

            // adj_list[w_id].erase(v_id);
            // adj_matrix[w_id][v_id] = 0;
        }

        this->stale_adj_list = true;
        this->stale_adj_matrix = true;

    } else {
        cerr << "Edge " << v_id << " -> " << w_id << " not found." << endl;
    }

}


bool Graph::has_vertex(const uint64_t& v_id) const{
    return v_id < vertices.size();
}
bool Graph::has_edge(const uint64_t& v_id, const uint64_t& w_id) const{
    if (v_id >= vertices.size() || w_id >= vertices.size()){
        return false;
    }

    Edge temp_edge{v_id, w_id};
    return edges.contains(temp_edge);
}


void Graph::build_adj_list(){
    if (stale_adj_list)
    {
        cout << "Building adjacency list..." << endl;
        for (auto& set : adj_list) {
            set.clear();  // Clear each unordered_set<Edge*> in the vector
        }
        adj_list.clear();  // Clear the vector itself


        size_t n = vertices.size();
        adj_list.resize(n);
        for (const Edge& edge : edges) {
            adj_list[edge.x_id].insert(edge.y_id);  // Add the edge to the adjacency list for vertex x
        }
        stale_adj_list = false;
    }
}
// void Graph::clear_adj_list() {
//     for (auto& set : adj_list) {
//         set.clear();  // Clear each unordered_set<Edge*> in the vector
//     }
//     adj_list.clear();  // Clear the vector itself
// }

void Graph::build_adj_matrix(){
    if (stale_adj_matrix)
    {
        cout << "Building adjacency matrix..." << endl;
        size_t n = vertices.size();
        adj_matrix.resize(n);                // Resize outer vector to hold n rows
        for (size_t i = 0; i < n; ++i) {
            adj_matrix[i].resize(n, 0);      // Resize each row to have n columns, initialize with 0
        }

        for (const Edge& edge : edges) {
            adj_matrix[edge.x_id][edge.y_id] = 1;  // Add the edge to the adjacency list for vertex x
        }
        stale_adj_matrix = false;
    }

}
// void Graph::clear_adj_matrix(){
//     adj_matrix.clear();
//     adj_matrix.shrink_to_fit();
// }

