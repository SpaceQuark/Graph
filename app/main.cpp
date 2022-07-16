#include "Graph.hpp"
#include "prettyprint.hpp"

int main()
{
    Graph<int,int> g(true);
    // g.add_vertex(10);
    // g.add_vertex(20);
    // g.add_vertex(30);
    // g.add_vertex(40);
    // g.add_vertex(50);
    // g.pL();

    // g.del_vertex(30);
    // g.pL();

    // g.add_edge(10, 20);
    // g.add_edge(20, 40);
    // g.add_edge(10, 40);
    // g.add_edge(10,100);
    // g.pL();
    // g.del_edge(10,40);
    // g.del_edge(10,10);
    // g.pL();
    // g.pM();

    // g.add_vertex(0);
    // g.add_vertex(1);
    // g.add_vertex(2);
    // g.add_vertex(3);
    // g.add_vertex(4);

    // g.add_edge(0, 1);
    // g.add_edge(0, 2);
    // g.add_edge(1, 2);
    // g.add_edge(2, 0);
    // g.add_edge(2, 3);
    // g.add_edge(3, 3);


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

    std::cout << g.Dijkstras(0) << std::endl;
    std::cout << g.DijkstrasConstruct(0) << std::endl;

    g.pL();
    // g.pM();
    //std::cout << g.BFS(2) << std::endl;



    return 0;
}

