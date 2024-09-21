#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "vertex.hpp"
#include "edge.hpp"

/*
This header file contains a Graph class template

This Graph class contains vertices (nodes) that is
represented by a list and edges that is represented by a 2D list.

The Graph class implements various member functions
as well as several algorithm implementations.
*/

#include <iostream>
#include <algorithm> 
#include <limits>
#include <vector>
#include <utility>
#include <tuple>
#include <iterator>
#include <iomanip>
#include <optional>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <list>

using std::vector;
using std::pair;
using std::unordered_set;
using std::unordered_map;

using std::remove;
using std::remove_if;
using std::erase_if;

// namespace
// {
//     template <typename W>
//     constexpr W gmax = std::numeric_limits<W>::max();

//     template <typename W>
//     constexpr W gmin = std::numeric_limits<W>::min();

//     template <typename W>
//     constexpr W PINF = std::numeric_limits<W>::infinity();

//     template <typename W>
//     constexpr W NINF = -1 * std::numeric_limits<W>::infinity();


//     template <typename V, typename W>
//     auto minp = [](const pair<V, W>& lhs, const pair<V, W>& rhs)
//     { return lhs.second > rhs.second; };

// }


class Graph
{
public:
    vector<Vertex> vertices;
    unordered_set<Edge> edges;

    optional<unordered_map<Vertex, vector<Vertex>>> adj_list;
    optional<vector<vector<Vertex>>> adj_matrix;

public:
    // 2 different constructors that can be called to initialize a Graph object
    explicit Graph(bool undirected = true, bool weighted = false, bool flows = false, const optional<vector<Vertex>>& vertices = nullopt);
    // explicit Graph(const optional<vector<Vertex>>& vertices = nullopt, const optional<vector<Edge>>& edges);

    // destructor
    virtual ~Graph() = default;


    size_t get_numV();
    size_t get_numE();
    bool is_undirected();
    bool is_weighted();
    bool is_flows();


    // add vertex and delete vetex
    void add_vertex(const Vertex& v);
    void del_vertex(const Vertex& v);


    void add_edge(const Vertex& v, const Vertex& w, const double& weight, Color color, const double& flow, const double& capacity);
    void del_edge(const Vertex& v, const Vertex& w, const double& weight, Color color, const double& flow, const double& capacity);


    bool has_vertex(const Vertex& v);
    bool has_edge(const Edge& e);

    // void adj_list();
    // void adj_matrix();


    // total edges of the graph
    size_t num_vertices() const;
    size_t num_edges() const;

    // outdegree of a vertex


 

private:
    



// private member variables
private:
    bool undirected;
    bool weighted;
    bool flows;
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
