#include "Graph.hpp"

/**
 * Verified on Yosupo (https://judge.yosupo.jp/problem/cycle_detection, https://judge.yosupo.jp/problem/cycle_detection_undirected)
 * Finds a cycle in directed and undirected graph
 * Time: O(V+E)
 * Space: O(V)
 */

Graph::VertexIds Graph::DFS_cycle()
{
    bool is_cycle = false;
    VertexIds cycle;
    vector<int> state(vertices.size(), 0);
    VertexIds parent(vertices.size(), INV);

    if (undirected) {            
        // if graph is undirected and has 1 undirected edge, then it is a cycle
        if (edges.size() == 2) {
            return {edges[0].x_id, edges[0].y_id, edges[0].x_id};
        }

        auto dfs = [&](auto&& self, uint64_t source, uint64_t par) -> void {
            if (is_cycle) return; // found cycle; early exit
            state[source] = 1;
            parent[source] = par;

            for (const Edge* edge : adj_list[source]) {
                uint64_t neighbor = edge->y_id;
                if (neighbor == par){
                    continue; // skip edge leading back to parent
                }

                if (state[neighbor] == 0){
                    self(self, neighbor, source);
                    if (is_cycle) return;
                } else if (state[neighbor] == 1){
                    is_cycle = true;

                    // reconstruct the cycle
                    uint64_t current = source;
                    cycle.push_back(neighbor);
                    while(current != neighbor && current != INV){
                        cycle.push_back(current);
                        current = parent[current];
                    }
                    cycle.push_back(neighbor);
                    reverse(cycle.begin(), cycle.end());
                    return;
                } 
            }
            state[source] = 2;
        };

        for (uint64_t source = 0; source < vertices.size(); ++source){
            if (state[source] == 0){
                dfs(dfs, source, INV);
                if (is_cycle) break;
            }
        }
        return cycle;
    } else{
        auto dfs = [&](auto&& self, uint64_t source, uint64_t par) -> void {
            if (is_cycle) return; // found cycle; early exit
            state[source] = 1;
            parent[source] = par;

            for (const Edge* edge : adj_list[source]) {
                uint64_t neighbor = edge->y_id;

                if (state[neighbor] == 0){
                    parent[neighbor] = source;
                    self(self, neighbor, source);
                    if (is_cycle) return;
                } else if (state[neighbor] == 1){
                    is_cycle = true;

                    // reconstruct the cycle
                    uint64_t current = source;
                    cycle.push_back(neighbor);
                    while(current != neighbor && current != INV){
                        cycle.push_back(current);
                        current = parent[current];
                    }
                    cycle.push_back(neighbor);
                    reverse(cycle.begin(), cycle.end());
                    return;
                } 
            }
            state[source] = 2;
        };

        for (uint64_t source = 0; source < vertices.size(); ++source){
            if (state[source] == 0){
                dfs(dfs, source, INV);
                if (is_cycle) break;
            }
        }
        return cycle;
    }
}