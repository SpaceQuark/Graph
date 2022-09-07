#include <gtest/gtest.h>
#include "../app/Graph.hpp"

TEST(MSTalgo, PrimMST)
{
    Graph<int,int> g(false);

    g.add_edge(0, 1, 5);
    g.add_edge(1, 2, 4);
    g.add_edge(2, 9, 2);
    g.add_edge(0, 4, 1);
    g.add_edge(0, 3, 4);
    g.add_edge(1, 3, 2);
    g.add_edge(2, 7, 4);
    g.add_edge(2, 8, 1);
    g.add_edge(9, 8, 0);
    g.add_edge(4, 5, 1);
    g.add_edge(5, 6, 7);
    g.add_edge(6, 8, 2);
    g.add_edge(4, 3, 2);
    g.add_edge(5, 3, 5);
    g.add_edge(3, 6, 11);
    g.add_edge(6, 7, 1);
    g.add_edge(3, 7, 2);
    g.add_edge(7, 8, 6);

    auto MST = g.Prims(0);

    int total_weight = 12;
    vector<tuple<int, int, int>> MST_edges = {{0, 4, 1}, {4, 5, 1}, {4, 3, 2}, {3, 1, 2}, {3, 7, 2}, {7, 6, 1}, {6, 8, 2}, {8, 9, 0}, {8, 2, 1}};

    EXPECT_EQ(MST.first, total_weight);
    EXPECT_EQ(MST.second, MST_edges);
}


TEST(MSTAlgo, KruskalMST)
{
    Graph<int,int> g(false);

    g.add_edge(0, 1, 4);
    g.add_edge(0, 2, 4);
    g.add_edge(1, 2, 2);
    g.add_edge(2, 3, 3);
    g.add_edge(2, 5, 2);
    g.add_edge(2, 4, 4);
    g.add_edge(3, 4, 3);
    g.add_edge(5, 4, 3);
    
    auto MST = g.Kruskals(0);

    int total_weight = 14;
    vector<tuple<int, int, int>> MST_edges = { {5, 2, 2}, {2, 1, 2}, {4, 3, 3}, {4, 5, 3}, {2, 0, 4} };
    EXPECT_EQ(MST.first, total_weight);
    EXPECT_EQ(MST.second, MST_edges);
}