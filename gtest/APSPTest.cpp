#include <gtest/gtest.h>
#include "../app/Graph.hpp"

TEST(FloydWarshallTests, FloydWarshallAPSPDiGraph)
{
    Graph<int,float> g(true);

    g.add_vertex(0);
    g.add_vertex(1);
    g.add_vertex(2);
    g.add_vertex(3);
    g.add_vertex(4);
    g.add_vertex(5);
    g.add_vertex(6);

    g.add_edge(0, 1, 2);
    g.add_edge(0, 2, 5);
    g.add_edge(0, 6, 10);
    g.add_edge(1, 2, 2);
    g.add_edge(1, 4, 11);
    g.add_edge(2, 6, 2);
    g.add_edge(6, 5, 11);
    g.add_edge(4, 5, 1);
    g.add_edge(5, 4, -2);

    vector<vector<float>> ans{{0, 2, 4, PINF<float>, NINF<float>, NINF<float>, 6 }, 
                                        {PINF<float>, 0, 2, PINF<float>, NINF<float>, NINF<float>, 4},
                                        {PINF<float>, PINF<float>, 0, PINF<float>, NINF<float>, NINF<float>, 2},
                                        {PINF<float>, PINF<float>, PINF<float>, 0, PINF<float>, PINF<float>, PINF<float>},
                                        {PINF<float>, PINF<float>, PINF<float>, PINF<float>, NINF<float>, NINF<float>, PINF<float>},
                                        {PINF<float>, PINF<float>, PINF<float>, PINF<float>, NINF<float>, NINF<float>, PINF<float>},
                                        {PINF<float>, PINF<float>, PINF<float>, PINF<float>, NINF<float>, NINF<float>, 0}
                                        };

    EXPECT_EQ(g.FloydWarshall(), ans);
}