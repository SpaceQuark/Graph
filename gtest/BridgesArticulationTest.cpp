#include <gtest/gtest.h>
#include "../app/Graph.hpp"

TEST(BridgeTest, Bridges) {
    Graph<int> g(false);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 2);
    g.add_edge(2, 3);
    g.add_edge(3, 4);
    g.add_edge(2, 5);
    g.add_edge(5, 6);
    g.add_edge(6, 7);
    g.add_edge(7, 8);
    g.add_edge(8, 5);

    
    vector<pair<int, int>> res = {{3,4}, {2,3}, {5,2}};

    EXPECT_EQ(g.find_bridges(), res);
}


TEST(ArticulationTests, ArticulationPoints) {
    Graph<int> g(false);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 2);
    g.add_edge(2, 3);
    g.add_edge(3, 4);
    g.add_edge(2, 5);
    g.add_edge(5, 6);
    g.add_edge(6, 7);
    g.add_edge(7, 8);
    g.add_edge(8, 5);

    
    unordered_set<int> res = {2,3,5};

    EXPECT_EQ(g.find_articulations(), res);
}