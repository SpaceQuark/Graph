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


using VertexList = vector<Vertex>;
using VertexIds = vector<uint64_t>;
using VertexIdPair = pair<uint64_t, uint64_t>;
using VertexIdWeights = vector<pair<uint64_t, double>>;
using EdgeSet = unordered_set<Edge>;
using EdgeMap = unordered_map<VertexIdPair, Edge>;
using AdjList = vector<unordered_set<uint64_t>>;
using AdjMatrix = vector<vector<bool>>;


enum AdjListKey {AL};
enum AdjMatrixKey {AM};

class Graph
{
public:
    explicit Graph(size_t num_vertices_ = 0, bool undirected_ = true, bool weighted_ = false, bool flows_ = false);

    // destructor
    virtual ~Graph() = default;

    const VertexList& operator[](VertexKey key) const;
    const EdgeMap& operator[](EdgeKey key) const;
    const AdjList& operator[](AdjListKey key) const;
    const AdjMatrix& operator[](AdjMatrixKey key) const;

    bool is_undirected() const;
    bool is_weighted() const;
    bool is_flows() const;

    void add_vertex(const uint64_t& v_id, const char* name = "", Color color = Color::Black);
    void del_vertex(const uint64_t& v_id);

    void add_edge(uint64_t v_id, uint64_t w_id, const double& weight = 0.0, Color color = Color::Black, const double& flow = 0.0, const double& capacity = 0.0);
    void del_edge(uint64_t v_id, uint64_t w_id);

    bool has_vertex(const uint64_t& v_id) const;
    bool has_edge(const uint64_t& v_id, const uint64_t& w_id) const;

    void build_adj_list();
    void build_adj_matrix();


    // -------------------------------------------------------------------------------------

    // Traversals

    VertexIds BFS(const uint64_t& source);
    VertexIds DFS(const uint64_t& source);
    VertexIds DFS_cycle();

    //ShortestPaths
    VertexIdWeights dijkstras(const uint64_t& source);

// private member variables
private:
    VertexList vertices;
    EdgeMap edges;

    AdjList adj_list;
    AdjMatrix adj_matrix;

    const bool undirected;
    bool weighted;
    bool flows;

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
