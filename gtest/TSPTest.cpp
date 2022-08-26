#include <gtest/gtest.h>
#include "../app/Graph.hpp"

TEST(TSPTests, TSPDiGraph)
{
    Graph<int, float> g(true);
    g.add_edge(5, 0, 10);
    g.add_edge(1, 5, 12);
    g.add_edge(4, 1, 2);
    g.add_edge(2, 4, 4);
    g.add_edge(3, 2, 6);
    g.add_edge(0, 3, 8);

    pair<float, vector<int>> ans{42, {0, 3, 2, 4, 1, 5, 0}};

    EXPECT_EQ(g.TSP(0), ans);
}