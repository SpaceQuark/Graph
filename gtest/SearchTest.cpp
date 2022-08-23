#include <gtest/gtest.h>
#include "../app/Graph.hpp"

TEST(GraphAlgoTests, DFS_directed) {
    Graph<int> g(true);
    g.add_edge(1, 0);
    g.add_edge(0, 2);
    g.add_edge(0, 3);
    g.add_edge(2, 1);
    g.add_edge(1, 4);

    
    auto v = g.DFS(0);
    vector<int> res{ 0, 3, 2, 1, 4 };
    
    EXPECT_EQ(v, res);
}

TEST(GraphAlgoTests, DFS_undirected) {
    Graph<int> g;
    g.add_edge(1, 0);
    g.add_edge(0, 2);
    g.add_edge(0, 3);
    g.add_edge(2, 1);
    g.add_edge(3, 4);
    g.add_edge(1, 4);

    
    auto v = g.DFS(0);
    vector<int> res{ 0, 3, 4, 1, 2 };
    
    EXPECT_EQ(v, res);
}

TEST(GraphAlgoTests, BFS_directed) {
    Graph<int> g(true);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 2);
    g.add_edge(2, 0);
    g.add_edge(2, 3);
    g.add_edge(3, 3);
    g.add_edge(3, 4);
    g.add_edge(4, 0);

    
    auto v = g.BFS(2);
    vector<int> res{ 2, 0, 3, 1, 4};
    
    EXPECT_EQ(v, res);
}

TEST(GraphAlgoTests, BFS_undirected) {
    Graph<int> g(true);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 2);
    g.add_edge(2, 0);
    g.add_edge(2, 3);
    g.add_edge(3, 4);
    g.add_edge(4, 0);
    
    auto v = g.BFS(2);
    vector<int> res{ 2, 0, 3, 1, 4};
    
    EXPECT_EQ(v, res);
}