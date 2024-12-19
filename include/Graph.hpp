#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "utils.hpp"
#include "vertex.hpp"
#include "edge.hpp"

/*
This header file contains a Graph class template

This Graph class contains vertices (nodes) that is
represented by a list and edges that is represented by a 2D list.

The Graph class implements various member functions
as well as several algorithm implementations.
*/

namespace std {
    template <>
    struct hash<pair<uint64_t, uint64_t>> {
        size_t operator()(const pair<uint64_t, uint64_t>& p) const {
            size_t seed = hash<uint64_t>{}(p.first);
            seed ^= hash<uint64_t>{}(p.second) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            return seed;
        }
    };
}

enum VKey{V};
enum EKey{E};
enum ALKey{AL};
enum AMKey{AM};

class Graph
{
    using VertexList = vector<optional<Vertex>>;
    // using EdgeSet = unordered_set<Edge>;
    using EdgeList = vector<Edge>;
    using AdjList = vector<vector<const Edge*>>;
    using AdjMatrix = vector<vector<const Edge*>>;

    using VertexIds = vector<uint64_t>;
    using VertexIdWeights = vector<int64_t>;

public:

    explicit Graph(uint64_t num_vertices_=0, bool undirected_=true, bool weighted_=false, bool flows_=false)
        : undirected(undirected_), weighted(weighted_), flows(flows_), stale_adj_list(true), stale_adj_matrix(true) {
            if (num_vertices_ == 0){ return; }
            vertices.resize(num_vertices_);
            for (uint64_t i = 0; i < num_vertices_; ++i){
                vertices[i].emplace(i);
            }
    }

    explicit Graph(VertexList vertices_, bool undirected_=true, bool weighted_=false, bool flows_=false)
        : undirected(undirected_), weighted(weighted_), flows(flows_), stale_adj_list(true), stale_adj_matrix(true)  {
            if (vertices_.empty()){ return; }
            auto max_id = std::max_element(vertices_.begin(), vertices_.end(), [](const optional<Vertex>& x, const optional<Vertex>& y) {
                return x && y ? x->id < y->id : !x;
            })->value().id;
            vertices.resize(max_id+1);

            for (auto& vertex_opt : vertices_) {
                if (vertex_opt) { // Ensure vertex_opt contains a value
                    vertices[vertex_opt->id] = std::move(vertex_opt);
                }
            }
    }

    explicit Graph(EdgeList edges_, bool undirected_=true, bool weighted_=false, bool flows_=false)
        : edges(std::move(edges_)), undirected(undirected_), weighted(weighted_), flows(flows_), stale_adj_list(true), stale_adj_matrix(true)  {
            if (edges.empty()){
                return;
            }

            uint64_t max_id = 0;
            for (const auto& edge : edges) {
                max_id = std::max({max_id, edge.x_id, edge.y_id});
            }
            
            vertices.resize(max_id+1);

            for (const auto& edge : edges) {
                if (!vertices[edge.x_id]) { vertices[edge.x_id].emplace(edge.x_id); }
                if (!vertices[edge.y_id]) { vertices[edge.y_id].emplace(edge.y_id); }
            }
    }

    // destructor
    virtual ~Graph() = default;

    const VertexList& operator[](VKey key) const
    {
        if (key == V) {
            return vertices;
        }
        throw invalid_argument("Invalid key for access");
    }
    const EdgeList& operator[](EKey key) const
    {
        if (key == E) {
            return edges;
        }
        throw invalid_argument("Invalid key for access");
    }
    const AdjList& operator[](ALKey key) const
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
    const AdjMatrix& operator[](AMKey key) const
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

    bool is_undirected() const { return undirected; }
    bool is_weighted() const { return weighted; }
    bool is_flows() const {return flows; }

    void add_vertex(const uint64_t& v_id, const string& name="", Color color=Color::Black){
        if (v_id >= vertices.size()){
            vertices.resize(v_id+1);
        } 
        if (vertices[v_id]){
            std::cerr << "Vertex with ID " << v_id << " already exists!" << std::endl;
            return;
        }
        vertices[v_id].emplace(v_id, name, color);
        this->stale_adj_list = true;
        this->stale_adj_matrix = true;
    }

    void add_edge(uint64_t v_id, uint64_t w_id, int64_t weight=0, uint64_t flow=0, uint64_t capacity=0, Color color = Color::Black){
        if (!has_vertex(v_id) || !has_vertex(w_id)){
            std::cerr << "Cannot add edge: Vertex " << v_id << " or Vertex " << w_id << " does not exist!" << std::endl;
            return;
        }

        edges.emplace_back(v_id, w_id, weight, flow, capacity, color);
        if (undirected){
            edges.emplace_back(w_id, v_id, weight, flow, capacity, color);
        }

        this->stale_adj_list = true;
        this->stale_adj_matrix = true;
    }

    // void del_vertex(const uint64_t& v_id);
    // void del_edge(uint64_t v_id, uint64_t w_id);

    bool has_vertex(const uint64_t& v_id) const{ return v_id < vertices.size() && vertices[v_id]; }
    // bool has_edge(const uint64_t& v_id, const uint64_t& w_id) const;

    void build_adj_list(){
        if (stale_adj_list) {
            cerr << "Building adjacency list..." << endl;
            adj_list.clear();
            adj_list.resize(vertices.size());

            for (const Edge& edge : edges) { // Iterate through each edge in the edge list
                // Add the edge to the adjacency list of edge.x_id
                adj_list[edge.x_id].push_back(&edge);
            }
        stale_adj_list = false;
        }
    };
    void build_adj_matrix() {
        if (stale_adj_matrix) {  
            cerr << "Building adjacency matrix..." << endl;

            adj_matrix.clear();
            adj_matrix.resize(vertices.size(), std::vector<const Edge*>(vertices.size(), nullptr));

            for (const Edge& edge : edges) {
                assert(edge.x_id < vertices.size() && edge.y_id < vertices.size() && "Vertex IDs out of bounds!");

                adj_matrix[edge.x_id][edge.y_id] = &edge;

                if (undirected) {
                    adj_matrix[edge.y_id][edge.x_id] = &edge;
                }
            }
            stale_adj_matrix = false; 
        }
    }

    void print_adj_list(){
        cout << "Adjacency List:" << endl;

        for (size_t v = 0; v < adj_list.size(); ++v) {
            cout << "Vertex " << v << ": ";
            for (const Edge* edge : adj_list[v]) {
                if (edge) {
                    cout << "(" << edge->x_id << " -> " << edge->y_id << ", weight: " << edge->weight << ") ";
                }
            }
            cout << endl;
        }
    }

    void print_adj_matrix(){
        cout << "Adjacency Matrix:" << endl;

        for (size_t i = 0; i < adj_matrix.size(); ++i) {
            for (size_t j = 0; j < adj_matrix[i].size(); ++j) {
                if (adj_matrix[i][j]) {
                    cout << adj_matrix[i][j]->weight << "\t"; // Print edge weight
                } else {
                    cout << "0\t"; // No edge
                }
            }
            cout << endl;
        }
    }


    // -------------------------------------------------------------------------------------

    // Traversals

    VertexIds BFS(const uint64_t& source);
    VertexIds DFS(const uint64_t& source);
    VertexIds DFS_cycle();

    VertexIds TSP_hamiltonian_cycle();
    VertexIds fleury_hamiltonian_cycle();

    // Topological Sorting
    VertexIds DFS_topsort();
    VertexIds Kahn_topsort();

    // Shortest Paths
    
    // SSSP
    VertexIdWeights dijkstra_sssp(const uint64_t& source);
    pair<VertexIds, int64_t> dijkstra_sssp_reconstruct(const uint64_t& source, const uint64_t& destination);

    VertexIdWeights dial_sssp(const uint64_t& source, int64_t max_weight);
    VertexIdWeights bellmanford_sssp(const uint64_t& source);

    // APSP
    vector<VertexIdWeights> floydwarshall_apsp();

    // Components
    vector<VertexIds> tarjan_scc();
    vector<VertexIds> kosaraju_scc();

    EdgeList bridges();
    VertexIds articulation_points();

    // MST
    EdgeList jarnik_mst();
    EdgeList kruskal_mst();
    EdgeList reversedelete_mst();
    EdgeList boruvka_mst();

    // Clique
    vector<VertexIds> enumerate_cliques();

    // Coloring
    uint64_t chromatic_number();
    vector<int64_t> chromatic_polynomial();


    // Matching
    pair<VertexIds, VertexIds> bipartite();


// private member variables
private:
    VertexList vertices;
    EdgeList edges;

    AdjList adj_list;
    AdjMatrix adj_matrix;

    const bool undirected;
    const bool weighted;
    const bool flows;

    bool stale_adj_list;
    bool stale_adj_matrix;
};

// #include "GraphAlgo/DFS.tpp"
// #include "GraphAlgo/BFS.tpp"
// #include "GraphAlgo/TopSort.tpp"
// #include "GraphAlgo/Kahns.tpp"
// #include "GraphAlgo/Dijkstras.tpp"
// #include "GraphAlgo/BellmanFord.tpp"
// #include "GraphAlgo/FloydWarshall.tpp"

// #include "Applications/BridgesAndArticulations.tpp"

// #include "GraphAlgo/Prims.tpp"
// #include "GraphAlgo/Kruskals.tpp"

// #include "GraphAlgo/TarjanSCC.tpp"
// #include "Applications/Components.tpp"
// #include "Applications/SSSPDAG.tpp"

// #include "GraphAlgo/TravellingSalesman.tpp"
// #include "GraphAlgo/Eulerian.tpp"

// #include "NetworkFlow/Bipartite.tpp"


#endif
