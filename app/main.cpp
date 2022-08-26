#include <iostream>
#include "Graph.hpp"
#include "prettyprint.hpp"
// #include "Support/UnionFind.hpp"
using namespace std;

int main()
{
    srand(0);
    Graph<int> g(true);
    g.add_edge(0, 1);
    g.add_edge(1, 2);
    g.add_edge(1, 3);
    g.add_edge(1, 4);
    g.add_edge(2, 1);
    g.add_edge(4, 1);

    g.pEL();
    cout << g.Eulerian() << endl;

    // cout << g.Kruskals(0) << endl;

    return 0;
}

