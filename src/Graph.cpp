
#include "Graph.hpp"

Graph::Graph(size_t num_vertices_, bool undirected_, bool weighted_, bool flows_)
    : vertices{VertexList{}}, edges{EdgeMap{}}, adj_list{vector<unordered_set<uint64_t>>{}}, adj_matrix{vector<vector<bool>>{}}, undirected{undirected_}, weighted{weighted_}, flows{flows_}
{
    while (num_vertices_ > 0)
    {
        vertices.emplace_back();
        vertices.back().id = vertices.size()-1;
        cout << "Added " << vertices.back() << endl;
        --num_vertices_;
    }
}


const VertexList& Graph::operator[](VertexKey key) const
{
    if (key == V) {
        return vertices;
    }
    throw invalid_argument("Invalid key for access");
}
const EdgeMap& Graph::operator[](EdgeKey key) const
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
        cerr << "Added " << vertices.back() << endl;
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
        cerr << "Vertex " << v_id << " doesn't exist in this graph!" << endl;
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
        // edges[{v_id, w_id}] = edge;
        edges.insert({{v_id, w_id}, edge});
        if (undirected){
            Edge swapped_edge(edge.y_id, edge.x_id, edge.weight, edge.color, edge.flow, edge.capacity);
            // edges[{w_id, v_id}] = swapped_edge;
            edges.insert({{w_id, v_id}, swapped_edge});
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
    if (!has_edge(v_id, w_id)){
        cerr << "Edge " << v_id << " -> " << w_id << " does not exists in the graph." << endl;
    }
    else
    {
        edges.erase({v_id, w_id});
        cerr << "Edge " << v_id << " -> " << w_id << " deleted." << endl;

        if (undirected){
            edges.erase({w_id, v_id});
            cerr << "Edge " << w_id << " -> " << v_id << " deleted." << endl;

        }

        this->stale_adj_list = true;
        this->stale_adj_matrix = true;
    }
}


bool Graph::has_vertex(const uint64_t& v_id) const{
    return v_id < vertices.size();
}
bool Graph::has_edge(const uint64_t& v_id, const uint64_t& w_id) const{
    bool contains_edge = edges.contains({v_id, w_id});

    if (contains_edge){
        assert((v_id < vertices.size() && w_id < vertices.size()) && "edges shouldn't have this element!");
    }
    
    return contains_edge;
}


void Graph::build_adj_list(){
    if (stale_adj_list)
    {
        cerr << "Building adjacency list..." << endl;
        for (auto& set : adj_list) {
            set.clear();  // Clear each unordered_set<Edge*> in the vector
        }
        adj_list.clear();  // Clear the vector itself


        size_t n = vertices.size();
        adj_list.resize(n);
        for (const auto& [ids, edge] : edges) {
            assert((ids.first == edge.x_id && ids.second == edge.y_id) && "incorrect pairing!");
            adj_list[ids.first].insert(ids.second);  // Add the edge to the adjacency list for vertex x
        }
        stale_adj_list = false;
    }
}


void Graph::build_adj_matrix(){
    if (stale_adj_matrix)
    {
        cerr << "Building adjacency matrix..." << endl;
        size_t n = vertices.size();
        adj_matrix.resize(n);                // Resize outer vector to hold n rows
        for (size_t i = 0; i < n; ++i) {
            adj_matrix[i].resize(n, 0);      // Resize each row to have n columns, initialize with 0
        }

        for (const auto& [ids, edge] : edges) {
            assert((ids.first == edge.x_id && ids.second == edge.y_id) && "incorrect pairing!");
            adj_matrix[ids.first][ids.second] = 1;  // Add the edge to the adjacency list for vertex x
        }
        stale_adj_matrix = false;
    }

}
