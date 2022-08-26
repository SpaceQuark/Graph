#include <gtest/gtest.h>
#include "../app/Graph.hpp"

TEST(GraphAlgoTests, TopSort) {
    Graph<int,float> g(true);
    g.add_edge(0, 1, 3);
    g.add_edge(0, 2, 2);
    g.add_edge(0, 5, 3);
    g.add_edge(1, 3, 1);
    g.add_edge(1, 2, 6);
    g.add_edge(2, 3, 1);
    g.add_edge(2, 4, 10);
    g.add_edge(3, 4, 5);
    g.add_edge(5, 4, 7);

    
    std::vector<int> ts = g.top_sort();
    std::vector<int> res{0, 1, 2, 5, 3, 4};
    
    // Under Construction -- several topological sorts exists

    EXPECT_EQ(ts, res);
}


TEST(GraphAlgoTests, DAGShortestPath) {
    Graph<int,float> g(true);
    g.add_edge(0, 1, 3);
    g.add_edge(0, 2, 2);
    g.add_edge(0, 5, 3);
    g.add_edge(1, 3, 1);
    g.add_edge(1, 2, 6);
    g.add_edge(2, 3, 1);
    g.add_edge(2, 4, 10);
    g.add_edge(3, 4, 5);
    g.add_edge(5, 4, 7);

    unordered_map<int, float> res( {{0, 0}, 
                                    {5, 3}, 
                                    {1, 3}, 
                                    {2, 2}, 
                                    {3, 3}, 
                                    {4, 8}});
    
    EXPECT_EQ(g.DAG_shortest_path(0), res);
}