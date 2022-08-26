#include <gtest/gtest.h>
#include "../app/Graph.hpp"

TEST(GraphTests, CreateGraph) 
{
    // *Check graph has directed/weighted attributes
    Graph<int,float> g1;

    EXPECT_FALSE(g1.is_directed());
    EXPECT_FALSE(g1.is_weighted());

    Graph<int,float> g2(true, true);

    EXPECT_TRUE(g2.is_directed());
    EXPECT_TRUE(g2.is_weighted());
}

TEST(GraphTests, AddDelVertex)
{

    Graph<int> g;
    EXPECT_FALSE(g.has_vertex(1));

    g.add_vertex(1);
    EXPECT_TRUE(g.has_vertex(1));

    g.add_vertex(2);
    EXPECT_TRUE(g.has_vertex(2));

    g.add_vertex(3);
    EXPECT_TRUE(g.has_vertex(3));

    g.del_vertex(3);
    EXPECT_FALSE(g.has_vertex(3));

    g.del_vertex(2);
    EXPECT_FALSE(g.has_vertex(2));

    g.del_vertex(1);
    EXPECT_FALSE(g.has_vertex(1));

    g.add_vertex(10);
    EXPECT_TRUE(g.has_vertex(10));

    g.del_vertex(10);
    EXPECT_FALSE(g.has_vertex(10));
}

TEST(GraphTests, AddDelEdgeDirectedGraph) 
{

    Graph<int> g(true);

    g.add_edge(4,5);
    EXPECT_TRUE(g.has_vertex(4));
    EXPECT_TRUE(g.has_vertex(5));
    EXPECT_TRUE(g.has_edge(4,5));
    EXPECT_FALSE(g.has_edge(5,4));

    g.add_edge(10,12);
    EXPECT_TRUE(g.has_vertex(10));
    EXPECT_TRUE(g.has_vertex(12));
    EXPECT_TRUE(g.has_edge(10,12));
    EXPECT_FALSE(g.has_edge(12,10));


    g.del_edge(4,5);
    EXPECT_FALSE(g.has_edge(4,5));
    EXPECT_FALSE(g.has_edge(5,4));

    g.del_edge(10,12);
    EXPECT_FALSE(g.has_edge(10,12));
    EXPECT_FALSE(g.has_edge(12,10));
}

TEST(GraphTests, AddDelEdgeUndirectedGraph) 
{

    Graph<int> g(false);

    g.add_edge(4,5);
    EXPECT_TRUE(g.has_vertex(4));
    EXPECT_TRUE(g.has_vertex(5));
    EXPECT_TRUE(g.has_edge(4,5));
    EXPECT_TRUE(g.has_edge(5,4));

    g.add_edge(10,12);
    EXPECT_TRUE(g.has_vertex(10));
    EXPECT_TRUE(g.has_vertex(12));
    EXPECT_TRUE(g.has_edge(10,12));
    EXPECT_TRUE(g.has_edge(12,10));


    g.del_edge(4,5);
    EXPECT_FALSE(g.has_edge(4,5));
    EXPECT_FALSE(g.has_edge(5,4));

    g.del_edge(10,12);
    EXPECT_FALSE(g.has_edge(10,12));
    EXPECT_FALSE(g.has_edge(12,10));
}

TEST(GraphTests, CreateEdgeListDirectedGraph) 
{
    Graph<int, float> g(true, true);

    g.add_vertex(0);
    g.add_vertex(1);
    g.add_vertex(2);
    g.add_vertex(3);
    g.add_vertex(4);

    g.add_edge(0, 1, 1);
    g.add_edge(0, 2, 2);
    g.add_edge(1, 2, 3);
    g.add_edge(2, 0, 4);
    g.add_edge(2, 3, 5);
    g.add_edge(3, 3, 0);

    vector<tuple<int, int, float>> ans = {{3,3,0}, {2,0,4}, {2,3,5}, {1,2,3}, {0,1,1}, {0,2,2}};

    EXPECT_EQ(g.EL(), ans);
}




TEST(GraphTests, CreateAdjMatrixDirectedGraph) 
{
    Graph<int, float> g(true, true);

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

    vector<vector<float>> ans{{0, 1, 1, PINF<float>, PINF<float>}, 
                                        {PINF<float>, 0, 1, PINF<float>, PINF<float>},
                                        {1, PINF<float>, 0, 1, PINF<float>},
                                        {PINF<float>, PINF<float>, PINF<float>, 0, PINF<float>},
                                        {PINF<float>,PINF<float>, PINF<float>, PINF<float>, 0}
                                        };

    EXPECT_EQ(g.AM(), ans);
}