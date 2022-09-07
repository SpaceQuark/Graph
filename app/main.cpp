#include <iostream>
#include "Graph.hpp"
#include "prettyprint.hpp"
// #include "Support/UnionFind.hpp"
using namespace std;

int main()
{
    srand(0);
    Graph<int, int> g(true);
    g.add_edge(0, 1, 4);
    g.add_edge(0, 2, 4);
    g.add_edge(1, 2, 2);
    g.add_edge(2, 3, 3);
    g.add_edge(2, 5, 2);
    g.add_edge(2, 4, 4);
    g.add_edge(3, 4, 3);
    g.add_edge(5, 4, 3);

    g.pEL();
    // cout << g.Eulerian() << endl;

    cout << g.Kruskals(0) << endl;

    return 0;
}

