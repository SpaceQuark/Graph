#ifndef GRAPH_HPP
#define GRAPH_HPP

/*
This header file contains a Graph class template

This Graph class contains vertices (nodes) that is
represented by a list and edges that is represented by a 2D list.

The Graph class implements various setter and getter and member functions
as well as several algorithm implementations.
*/

#include <iostream>
// #include <algorithm>
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


// #include "../SupportADT/WEdge.hpp"
#include "Support/UnionFind.hpp"

#include "prettyprint.hpp"

using std::vector;
using std::pair;
using std::unordered_map;
using std::unordered_set;

template <typename W>
constexpr W PINF = std::numeric_limits<W>::infinity();

template <typename W>
constexpr W NINF = -1 * std::numeric_limits<W>::infinity();

namespace
{
    template <typename T>
    T min(T val1, T val2) 
    {
        return (val1 < val2) ? val1: val2;
    }

    template <typename T>
    T max(T val1, T val2) 
    {
        return (val1 > val2) ? val1: val2;
    }


    template <typename W>
    constexpr W gmax = std::numeric_limits<W>::max();

    template <typename W>
    constexpr W gmin = std::numeric_limits<W>::min();

    template <typename V, typename W>
    auto minp = [](const pair<V, W>& lhs, const pair<V, W>& rhs)
    { return lhs.second > rhs.second; };

    template <typename V, typename W>
    auto maxp = [](const pair<V, W>& lhs, const pair<V, W>& rhs)
    { return lhs.second < rhs.second; };


}

template <typename V, typename W = bool>
class Graph
{
public:
    using vectV = vector<V>;
    using vectW = vector<W>;
    using matW = vector<vectW>;

    using setV = unordered_set<V>;


public:
    // 2 different constructors that can be called to initialize a Graph object
    explicit Graph(bool digraph = false, bool weight = false);
    explicit Graph(const vectV& vs, bool digraph = false, bool weight = false);

    // destructor
    virtual ~Graph() = default;

    // add vertex and delete vetex
    void add_vertex(const V& v);
    void del_vertex(const V& v);

    // add edge (for unweighted/weighted graphs) and delete edges
    void add_edge(const V& v1, const V& v2);
    void add_edge(const V& v1, const V& v2, const W& w);

    void del_edge(const V& v1, const V& v2);
    

    // total edges of the graph
    int total_edges() const;

    // outdegree of a vertex
    int outdegree(const V& v) const;
    

    inline bool is_directed() const;
    inline bool is_weighted() const;
    bool has_vertex(const V& v) const;
    bool has_edge(const V& v1, const V& v2);


    // Create Adjacency Matrix
    matW AM();

    // Create Edge List
    vector<std::tuple<V,V,W>> EL() const;

    // Print vertices
    void pV() const;
    // Print adjacency list
    void pL() const;
    // Print adjacency matrix
    void pM();
    // Print edge list
    void pEL() const;

    // ------------------------- //
    // |      Graph Algos      | //
    // ------------------------- //

    // iterative DFS and BFS
    vectV DFS(const V& source);
    vectV BFS(const V& source);


    // shortest paths
    unordered_map<V, W> DAG_shortest_path(V start);

    unordered_map<V, W> Dijkstras(const V& source);
    vectV dk_shortest_path(const V& source, const V& end);

    unordered_map<V, W> BellmanFord(const V& source);

    matW FloydWarshall();
    std::optional<vectV> fw_reconstruct_path(const V& source, const V& end);


    // topological sort
    vectV top_sort();

    // components
    vector<vectV> findComponents();
    pair<unordered_map<V, int>, int> TarjanSCC();

    // bridges and articulation points
    vector<pair<V,V>> find_bridges();
    setV find_articulations();


    // MST
    Graph<V,W> Boruvkas();
    pair<W, vector<pair<V,V>>> Prims(const V& source);
    pair<W, vector<pair<V,V>>> Kruskals(const V& source);
    Graph<V,W> ReverseDelete();


    // Eulerian circuit
    vectV Hierholzer();

    // Tree

    
private:
    
    unordered_map<V, pair<W, V>> dijkstras_construct(const V& source);
    pair<matW, matW> floyd_warshall_construct();
    


// private member variables
private:

    unordered_map<V, size_t> vertices;
    unordered_map<V, vector<pair<V,W>>> edges;

    size_t numV;
    size_t numE;
    bool directed;
    bool weighted;
};

#include "Graph.tpp"
#include "GraphAlgo/DFS.tpp"
#include "GraphAlgo/BFS.tpp"
#include "GraphAlgo/TopSort.tpp"
#include "GraphAlgo/Dijkstras.tpp"
#include "GraphAlgo/BellmanFord.tpp"
#include "GraphAlgo/FloydWarshall.tpp"

#include "Applications/BridgesAndArticulations.tpp"

#include "GraphAlgo/Prims.tpp"
#include "GraphAlgo/Kruskals.tpp"

#include "GraphAlgo/TarjanSCC.tpp"
#include "Applications/Components.tpp"
#include "Applications/SSSPDAG.tpp"


#endif
