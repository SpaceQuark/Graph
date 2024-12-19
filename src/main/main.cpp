#include <iostream>
#include "Graph.hpp"

#ifndef DEBUG
#include "debug.tpp"
#else
#define dbg(...)
#define dbgArr(...)
#endif

// uint64_t
void print_vertex_ids(const std::vector<size_t>& vertex_ids) {
    cout << "Vertex IDs: ";
    for (auto id : vertex_ids) {
        cout << id << " ";
    }
    cout << endl;
}

void print_vertex_ids_weights(const std::vector<int64_t>& vertex_ids) {
    cout << "Vertex IDs: ";
    for (auto id : vertex_ids) {
        cout << id << " ";
    }
    cout << endl;
}


int main() {
    std::cout << "Hello World!" << std::endl;
    Graph g(5, false);

    // g.add_edge(0, 1, 1);
    // g.add_edge(1, 2, 1);
    // g.add_edge(2, 3, 1);
    // g.add_edge(0, 2, 1);
    // g.add_edge(1, 3, 1);


    // g.add_edge(5,7);
    g.add_edge(0,3,5);
    g.add_edge(0,4,3);
    g.add_edge(2,4,2);
    g.add_edge(4,3,10);
    g.add_edge(4,0,7);
    g.add_edge(2,1,5);
    g.add_edge(1,0,1);

    // g.add_edge(1,0,10);


    g.build_adj_list();
    g.build_adj_matrix();

    g.print_adj_list();
    g.print_adj_matrix();

    auto bfs = g.BFS(0);
    auto dfs = g.DFS(0);
    // print_vertex_ids(bfs);
    // print_vertex_ids(dfs);

    auto dijkstras = g.dijkstra_sssp(2);
    print_vertex_ids_weights(dijkstras);

    auto dijkstras_path = g.dijkstra_sssp_reconstruct(2, 3);
    print_vertex_ids(dijkstras_path.first);
    cout << dijkstras_path.second << endl;



    // auto dfs_cycle = g.DFS_cycle();
    
    // vector<std::size_t> vertex_ids;

    // print_vertex_ids(dfs_cycle);

    





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
