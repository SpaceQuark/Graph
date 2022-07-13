#include "Graph.hpp"

int main()
{
    Graph<int> g;
    g.add_vertex(10);
    g.add_vertex(20);
    g.add_vertex(30);
    g.add_vertex(40);
    g.add_vertex(50);
    g.pL();

    g.delete_vertex(30);
    g.pL();

    g.add_edge(10, 20);
    g.add_edge(20, 40);
    g.add_edge(10, 40);
    // g.add_edge(10,100);
    g.pL();
    g.delete_edge(10,40);
    g.delete_edge(10,10);
    g.pL();
    g.pM();



    return 0;
}

