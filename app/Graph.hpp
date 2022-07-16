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
#include <algorithm>
#include <vector>
#include <utility>
#include <iterator>
#include <iomanip>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>

template <typename T, typename W = bool>
class Graph
{

public:
    // 2 different constructors that can be called to initialize a Graph object
    explicit Graph(bool digraph = false, bool weight = false);
    explicit Graph(const std::vector<T>& vs, bool digraph = false, bool weight = false);

    // destructor
    virtual ~Graph() = default;

    // add vertex and delete vetex
    void add_vertex(const T& v);
    void del_vertex(const T& v);

    // add edge (for unweighted/weighted graphs) and delete edges
    void add_edge(const T& v1, const T& v2);
    void add_edge(const T& v1, const T& v2, const W& w);

    void del_edge(const T& v1, const T& v2);
    

    // total edges of the graph
    int total_edges() const;

    // outdegree of a vertex
    int outdegree(const T& v) const;
    

    inline bool isDirected() const;
    inline bool isWeighted() const;
    bool has_vertex(const T& v) const;
    bool has_edge(const T& v1, const T& v2);


    // Print vertices
    void pV() const;
    // Print adjacency list
    void pL() const;
    // Print adjacency matrix
    void pM();

    // ------------------------- //
    // |      Graph Algos      | //
    // ------------------------- //

    // iterative DFS and BFS
    std::vector<T> DFS(const T& source);
    std::vector<T> BFS(const T& source);

    // shortest paths
    std::unordered_map<T, size_t> Dijkstras(const T& source);
    std::unordered_map<T, size_t> DijkstrasConstruct(const T& source);
    std::vector<T> BellmanFord(const T& source, const T& target);
    std::vector<T> FloydWarshall(const T& source, const T& target);

    // MST
    Graph<T,W> Boruvkas();
    Graph<T,W> Prims();
    Graph<T,W> Kruskals();
    Graph<T,W> ReverseDelete();

    // Eulerian circuit
    std::vector<T> Hierholzer();

    



private:
    // std::map<T, size_t> vertices;
    // std::vector<std::vector<std::pair<T,W>>> edges;

    std::unordered_map<T, size_t> vertices;
    std::map<T, std::vector<std::pair<T,W>>> edges;

    size_t numV;
    size_t numE;
    bool directed;
    bool weighted;
};

#include "Graph.tpp"
#include "GraphAlgo.tpp"


#endif