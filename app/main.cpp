#include <iostream>
#include "Graph.hpp"
#include "prettyprint.hpp"
// #include "Support/UnionFind.hpp"
using namespace std;

int main()
{
    srand(0);
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

    g.pEL();

    cout << g.find_bridges() << endl;
    cout << g.find_articulations() << endl;

    // cout << g.Kruskals(0) << endl;

    return 0;
}

