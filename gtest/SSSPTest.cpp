#include <gtest/gtest.h>
#include "../app/Graph.hpp"

TEST(DijkstrasTests, DijkstrasSSSP)
{
    Graph<int,int> g(false);
    g.add_edge( 0, 1, 4);
    g.add_edge( 0, 7, 8);
    g.add_edge( 1, 2, 8);
    g.add_edge( 1, 7, 11);
    g.add_edge( 2, 3, 7);
    g.add_edge( 2, 8, 2);
    g.add_edge( 2, 5, 4);
    g.add_edge( 3, 4, 9);
    g.add_edge( 3, 5, 14);
    g.add_edge( 4, 5, 10);
    g.add_edge( 5, 6, 2);
    g.add_edge( 6, 7, 1);
    g.add_edge( 6, 8, 6);
    g.add_edge( 7, 8, 7);

    unordered_map<int, int> ans({ {0, 0},
                                  {1, 4},
                                  {7, 8},
                                  {2, 12},
                                  {3, 19},
                                  {8, 14},
                                  {5, 11},
                                  {4, 21},
                                  {6, 9} });
    
    EXPECT_EQ(g.Dijkstras(0), ans);
}

TEST(DijkstrasTests, DijkstrasShortestPath)
{
    Graph<int,int> g(false);
    g.add_edge( 0, 1, 4);
    g.add_edge( 0, 7, 8);
    g.add_edge( 1, 2, 8);
    g.add_edge( 1, 7, 11);
    g.add_edge( 2, 3, 7);
    g.add_edge( 2, 8, 2);
    g.add_edge( 2, 5, 4);
    g.add_edge( 3, 4, 9);
    g.add_edge( 3, 5, 14);
    g.add_edge( 4, 5, 10);
    g.add_edge( 5, 6, 2);
    g.add_edge( 6, 7, 1);
    g.add_edge( 6, 8, 6);
    g.add_edge( 7, 8, 7);

    vector<int> ans{0, 7, 6, 5};
    
    EXPECT_EQ(g.dk_shortest_path(0, 5), ans);
}


TEST(BellmanFordTests, BellmanFordSSSP)
{
    Graph<int,float> g(true);

    g.add_edge(0, 1, 1);
    g.add_edge(1, 2, 1);
    g.add_edge(2, 4, 1);
    g.add_edge(4, 3, -3);
    g.add_edge(3, 2, 1);
    g.add_edge(1, 5, 4);
    g.add_edge(1, 6, 4);
    g.add_edge(5, 6, 5);
    g.add_edge(6, 7, 4);
    g.add_edge(5, 7, 3);

    unordered_map<int, float> ans({ {0, 0},
                                  {1, 1},
                                  {2, NINF<float>},
                                  {4, NINF<float>},
                                  {3, NINF<float>},
                                  {5, 5},
                                  {6, 5},
                                  {7, 8}
                                  });
    EXPECT_EQ(g.BellmanFord(0), ans);
}
