#include <iostream>
#include "Graph.hpp"

#ifndef DEBUG
#include "debug.tpp"
#else
#define dbg(...)
#define dbgArr(...)
#endif

int main() {
    // Graph g;
    // g.add_vertex(0);
    // g.add_vertex(1); 
    // g.add_vertex(5); // 2

    // dbg(g[V]);

    // g.add_edge(4,5);
    // g.add_edge(0,1);

    // dbg(g[E]);

    // g.build_adj_list();
    // g.build_adj_matrix();

    // dbg(g[AL]);
    // dbg(g[AM]);

    // // g.del_vertex(0);
    // // dbg(g.vertices);

    // g.del_edge(0,1);
    
    // dbg(g[AL]);
    // dbg(g[AM]);

    // g.build_adj_list();
    // g.build_adj_matrix();

    // dbg(g[AL]);
    // dbg(g[AM]);

    // BFS Tests ------------------------------------------------
    // Graph g, h(false);
    // g.add_edge(0,1);
    // g.add_edge(0,2);
    // g.add_edge(0,3);
    // g.add_edge(2,3);

    // g.build_adj_list();
    // g.build_adj_matrix();

    // dbg(g[V]);
    // dbg(g[E]);
    // dbg(g[AM]);

    // auto seq1 = g.BFS(0);
    // dbg(seq1);

    // h.add_edge(0,1);
    // h.add_edge(0,1);
    // h.add_edge(0,2);
    // h.add_edge(0,3);
    // h.add_edge(2,4);

    // h.build_adj_list();
    // h.build_adj_matrix();

    // auto seq2 = h.BFS(0);
    // dbg(seq2);

    
    return 0;
}
