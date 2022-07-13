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
#include <unordered_map>
#include <map>

template <typename T, typename W = bool>
class Graph
{

public:
    // 2 different constructors that can be called to initialize a Graph object
    explicit Graph(bool digraph = false, bool weight = false);
    explicit Graph(const std::vector<T>& vs, bool digraph = false, bool weight = false);
    // Graph(const std::vector<T>& vs, const std::vector<std::vector<T>>& es, bool digraph = false, bool weight = false);

    ~Graph() = default;

    void add_vertex(const T& v);
    void delete_vertex(const T& v);

    // // std::optional?
    void add_edge(const T& v1, const T& v2);
    void add_edge(const T& v1, const T& v2, const W& w);

    void delete_edge(const T& v1, const T& v2);


    bool isDirected() const;
    bool isWeighted() const;
    bool has_vertex(const T& v);
    bool has_edge(const T& v1, const T& v2);


    
    // std::vector getVertices() const;
    // std::vector getEdges(const T& vertex) const;
    

    int degree();
    
    // Print vertices
    void pV();
    // Print adjacency list
    void pL();
    // Print adjacency matrix
    void pM();


    // void DFS(const T& source);
    // void BFS(const T& source);


private:
    std::map<T, size_t> vertices;
    std::vector<std::vector<std::pair<T,W>>> edges;

    size_t numV;
    bool directed;
    bool weighted;
};

#include "Graph.tpp"
#endif