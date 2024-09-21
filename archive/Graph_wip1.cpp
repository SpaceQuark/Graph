
#include "Graph.hpp"

Graph::Graph(bool undirected, bool weighted, bool flows, const optional<vector<Vertex>>& vertices)
    : vertices{vertices.value_or(vector<Vertex>{})}, edges{unordered_set<Edge>{}}, undirected{undirected}, weighted{weighted}, flows{flows}
{
    if (!this->vertices.empty()){
        for(size_t i = 0; i < this->vertices.size(); ++i){
            this->vertices[i].id = i;
        }
    }
}


size_t Graph::get_numV()
{
    return vertices.size();
}
size_t Graph::get_numE()
{
    return edges.size();
}
bool Graph::is_undirected()
{
    return undirected;
}
bool Graph::is_weighted()
{
    return weighted;
}
bool Graph::is_flows()
{
    return flows;
}


void Graph::add_vertex(const Vertex& v)
{
    vertices.emplace_back(v);
    vertices.back().id = vertices.size() - 1;
}

void Graph::del_vertex(const Vertex& v)
{

    if (has_vertex(v))
    {
        // size_t idx = vertices[v];
        vertices.erase(vertices.begin()+v.id);

        // Remove all edges involving the vertex
        erase_if(edges,
            [&v](const Edge& e) {
                return *(e.x) == v || *(e.y) == v;  // Remove edges involving the vertex
            }), edges.end();
        

        for (auto& vertex : vertices) {
            if (vertex.id > v.id) {
                vertex.id--;  // Decrement ID
            }
        }
    }
    else
    {
        cout << "Vertex " << v.id << " doesn't exist in this graph" << endl;
    }
}

void Graph::add_edge(const Vertex& v, const Vertex& w, const double& weight = 0.0, Color color = Color::Black, const double& flow = 0.0, const double& capacity = 0.0)
{
    uint64_t v_id = v.id, w_id = w.id;
    if (!has_vertex(v))
    {
        add_vertex(v);
        v_id = vertices.size() - 1;
    }

    if (!has_vertex(w))
    {
        add_vertex(v);
        v_id = vertices.size() - 1;
    }

    Edge edge(&vertices[v_id], &vertices[w_id], weight, color, flow, capacity);

    if (!has_edge(edge))
    {
        edges.insert(edge);
        if (undirected){
            Edge swapped_edge(edge.y, edge.x, edge.weight, edge.color, edge.flow, edge.capacity);
            edges.insert(swapped_edge);
        }
    }
    else
    {
        cout << "Edge " << edge.x->id << " -> " << edge.y->id << " already exists in the graph." << endl;
    }
}

void Graph::del_edge(const Vertex& v, const Vertex& w, const double& weight = 0.0, Color color = Color::Black, const double& flow = 0.0, const double& capacity = 0.0)
{

    if (v.id >= vertices.size() || w.id >= vertices.size()){
        cout << "Invalid vertices ids." << endl;
        return;
    }

    Edge edge(&vertices[v.id], &vertices[w.id], weight, color, flow, capacity);

    if (!has_edge(edge))
    {
        edges.erase(edges.find(edge), edges.end());

        if (undirected){
            Edge swapped_edge(edge.y, edge.x, edge.weight, edge.color, edge.flow, edge.capacity);
            edges.erase(edges.find(swapped_edge), edges.end());
        }
    } 
    else
    {
        cout << "Edge " << edge.x->id << " -> " << edge.y->id << " doesn't exists in the graph." << endl;
    }
}


bool Graph::has_vertex(const Vertex& v){
    return v.id < vertices.size();
}
bool Graph::has_edge(const Edge& e){
    return edges.contains(e);
}


// void Graph::adj_list(){

// }

// void Graph::adj_matrix(){

// }
