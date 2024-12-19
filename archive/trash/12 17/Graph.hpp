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




enum Key{V, E, AL, AM};

// enum VertexKey{V};
// enum EdgeList{E};
// enum AdjListKey {AL};
// enum AdjMatrixKey {AM};

template <typename T = int64_t>
class Graph
{
    // using max = std::max;
    // using min = std::min;

    using VertexList = vector<Vertex>;
    using EdgeSet = unordered_set<Edge>;
    // using EdgeList = vector<Edge<T>>
    using AdjList = vector<vector<const Edge*>>;
    using AdjMatrix = vector<vector<bool>>;

public:

    explicit Graph(uint64_t num_vertices_=0, bool undirected_=true, bool weighted_=false, bool flows_=false)
        : undirected(undirected_), weighted(weighted_), flows(flows_) {
            if (num_vertices_ == 0){ return; }
            vertices.resize(num_vertices_);
            for (uint64_t i = 0; i < num_vertices_; ++i){
                vertices[i].id = i;
            }
    }

    explicit Graph(VertexList vertices_, bool undirected_=true, bool weighted_=false, bool flows_=false)
        : undirected(undirected_), weighted(weighted_), flows(flows_) {
            if (vertices_.empty()){ return; }
            auto max_id = std::max_element(vertices_.begin(), vertices_.end(), [](const Vertex& x, const Vertex& y) {
                return x.id < y.id;
            })->id;
            vertices.resize(max_id+1);

            for (auto& vertex: vertices_) {
                vertices[vertex.id] = std::move(vertex);
            }
            // some vertices would still have -1 as their id

    }

    explicit Graph(EdgeSet edges_, bool undirected_=true, bool weighted_=false, bool flows_=false)
        : edges(std::move(edges_)), undirected(undirected_), weighted(weighted_), flows(flows_) {
            if (edges.empty()){
                return;
            }

            uint64_t max_id = 0;
            for (const auto& edge : edges) {
                max_id = std::max(max_id, std::max(edge.x_id, edge.y_id));
            }
            
            vertices.resize(max_id+1);
            for (uint64_t i = 0; i <= max_id; ++i){
                vertices[i].id = i;
            }
    }

    // destructor
    virtual ~Graph() = default;

    const auto& operator[](Key key) const {
        if (key == V) { return vertices; }
        else if (key == E){ return edges; }
        else if (key == AL){
            if (stale_adj_list) {
                static const AdjList empty_adj_list{};
                return empty_adj_list;
            } else {
                return adj_list;
            }
        } 
        else if (key == AM){
            if (stale_adj_matrix) {
                static const AdjMatrix empty_adj_matrix{};
                return empty_adj_matrix;
            } else {
                return adj_matrix;
            }
        }
        throw invalid_argument("Invalid key for access");
    }

    bool is_undirected() const { return undirected; }
    bool is_weighted() const { return weighted; }
    bool is_flows() const {return flows; }

    // void add_vertex(const uint64_t& v_id, const string& name = "", Color color = Color::Black){
    // }
    void add_edge(uint64_t v_id, uint64_t w_id, int64_t weight=0, uint64_t flow=0, uint64_t& capacity=0, Color color = Color::Black){
        if (!has_edge(v_id, w_id)){
            Edge edge(v_id, w_id, weight, flow, capacity, color);
            edges.insert(edge);
            if (undirected){
                Edge swapped_edge(w_id, v_id, weight, flow, capacity, color);
                edges.insert(swapped_edge);
            }

            this->stale_adj_list = true;
            this->stale_adj_matrix = true;
            
        } else{
            cerr << "Edge " << v_id << " -> " << w_id << " already exists in the graph." << endl;
        }
    }

    // void del_vertex(const uint64_t& v_id);
    void del_edge(uint64_t v_id, uint64_t w_id){
        if (!has_edge(v_id, w_id)){
            cerr << "Edge " << v_id << " -> " << w_id << " does not exists in the graph." << endl;
        } else {
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

    bool has_vertex(const uint64_t& v_id) const{ return v_id < vertices.size(); }
    bool has_edge(const uint64_t& v_id, const uint64_t& w_id) const {
        bool contains_edge = edges.contains({v_id, w_id});
        if (contains_edge){
            assert((v_id < vertices.size() && w_id < vertices.size()) && "edges shouldn't have this element!");
        }
        return contains_edge;
        
    }

    void build_adj_list(){
    //     if (stale_adj_list) {
    //         cerr << "Building adjacency list..." << endl;
    //         for (auto& set : adj_list) {
    //             set.clear();  // Clear each unordered_set<Edge*> in the vector
    //         }
    //         adj_list.clear();  // Clear the vector itself


    //         size_t n = vertices.size();
    //         adj_list.resize(n);
    //         for (const auto& [ids, edge] : edges) {
    //             assert((ids.first == edge.x_id && ids.second == edge.y_id) && "incorrect pairing!");
    //             adj_list[ids.first].insert(ids.second);  // Add the edge to the adjacency list for vertex x
    //         }
    //         stale_adj_list = false;
    // }
    };
    void build_adj_matrix();


    // -------------------------------------------------------------------------------------

    // Traversals

    // VertexIds BFS(const uint64_t& source);
    // VertexIds DFS(const uint64_t& source);
    // VertexIds DFS_cycle();

    // //ShortestPaths
    // VertexIdWeights dijkstras(const uint64_t& source);

// private member variables
private:
    VertexList vertices;
    EdgeSet edges;

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
