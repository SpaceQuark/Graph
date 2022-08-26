#include <gtest/gtest.h>
#include "../app/Graph.hpp"

TEST(EulerianTests, EulerianDiGraph)
{
    Graph<int> g(true);
    g.add_edge(0, 1);
    g.add_edge(1, 2);
    g.add_edge(1, 3);
    g.add_edge(1, 4);
    g.add_edge(2, 1);
    g.add_edge(4, 1);


    std::list<int> ans = {0, 1, 4, 1, 2, 1, 3};
    EXPECT_EQ(g.Eulerian(), ans);
}