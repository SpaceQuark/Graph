#include <gtest/gtest.h>
#include "../app/Graph.hpp"

TEST(GraphTests, CreateGraph) {
    // Check graph has directed/weighted attributes
    Graph<int,float> g1;

    EXPECT_FALSE(g1.is_directed());
    EXPECT_FALSE(g1.is_weighted());

    Graph<int,float> g2(true, true);

    EXPECT_TRUE(g2.is_directed());
    EXPECT_TRUE(g2.is_weighted());
}

TEST(GraphTests, AddVertex) {
    // Check graph has directed/weighted attributes
    Graph<int,float> g;
    EXPECT_FALSE(g.has_vertex(1));

    g.add_vertex(1);
    EXPECT_TRUE(g.has_vertex(1));

    g.add_vertex(2);
    EXPECT_TRUE(g.has_vertex(2));

    g.add_vertex(3);
    EXPECT_TRUE(g.has_vertex(3));

    g.del_vertex(3);
    EXPECT_FALSE(g.has_vertex(3));
}


TEST(GraphTests, CreateAdjMatrix) {
    // Check graph has directed/weighted attributes
    Graph<int,float> g(true);

    g.add_vertex(0);
    g.add_vertex(1);
    g.add_vertex(2);
    g.add_vertex(3);
    g.add_vertex(4);

    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 2);
    g.add_edge(2, 0);
    g.add_edge(2, 3);
    g.add_edge(3, 3);

    auto am = g.AM();

    vector<vector<float>> ans{{0, 1, 1, PINF<float>, PINF<float>}, 
                                        {PINF<float>, 0, 1, PINF<float>, PINF<float>},
                                        {1, PINF<float>, 0, 1, PINF<float>},
                                        {PINF<float>, PINF<float>, PINF<float>, 0, PINF<float>},
                                        {PINF<float>,PINF<float>, PINF<float>, PINF<float>, 0}
                                        };

    EXPECT_EQ(am, ans);
}