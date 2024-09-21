#include "Graph.hpp"

VertexIds Graph::DFS(const uint64_t& source)
{
    assert(!adj_list.empty() && "Adjacency list is empty!");
    
    vector<bool> visited(vertices.size(), false);
    visited[source] = true;
    VertexIds sequence = {vertices[source].id};


    stack<uint64_t> s;
    s.push(source);

    while (!s.empty())
    {
        uint64_t top = s.top();
        s.pop();

        // find all adjacent vertices of the top vertex that have not been visited yet, then push it to stack
        for (const auto& neighbor : adj_list[top])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                sequence.push_back(vertices[neighbor].id);
                s.push(neighbor);
            }
        }
    }
    return sequence;
}

/**
 * Verified on Yosupo (https://judge.yosupo.jp/problem/cycle_detection, https://judge.yosupo.jp/problem/cycle_detection_undirected)
 * Finds a cycle in directed and undirected graph
 * Time: O(V+E)
 * Space: O(V)
 */

VertexIds Graph::DFS_cycle()
{
    bool is_cycle = false;
    VertexIds cycle;
    vector<int> state(vertices.size(), 0);
    VertexIds parent(vertices.size(), INV);

    if (undirected)
    {            
        // if graph is undirected and had 1 undirected edge, then it is a cycle
        if (edges.size() == 2){
            cycle = {edges.begin()->first.first, edges.begin()->first.second, edges.begin()->first.first};
                return cycle;
        }

        function<void(uint64_t, uint64_t)> dfs = [&](uint64_t source, uint64_t  par) {
            if (is_cycle) return; // found cycle; early exit

            state[source] = 1;
            parent[source] = par;
            for (auto&& neigh: adj_list[source]){
                if (neigh == par){
                    continue; // skip edge leading back to parent
                }
                if (state[neigh] == 0){
                    dfs(neigh, source);
                    if (is_cycle) return;
                } else if (state[neigh] == 1){
                    is_cycle = true;

                    // reconstruct the cycle
                    uint64_t current = source;
                    cycle.push_back(neigh);
                    while(current != neigh && current != INV){
                        cycle.push_back(current);
                        current = parent[current];
                    }
                    cycle.push_back(neigh);
                    reverse(cycle.begin(), cycle.end());
                    return;
                } 
            }
            state[source] = 2;
        };

        for (uint64_t source = 0; source < vertices.size(); ++source){
            if (state[source] == 0){
                dfs(source, INV);
                if (is_cycle) break;
            }
        }
        return cycle;
    } else
    {
        function<void(uint64_t)> dfs = [&](uint64_t source) {
            if (is_cycle) return; // found cycle; early exit

            state[source] = 1;
            for (auto&& neigh: adj_list[source]){
                if (state[neigh] == 0){
                    parent[neigh] = source;
                    dfs(neigh);
                    if (is_cycle) return;
                } else if (state[neigh] == 1){
                    is_cycle = true;

                    // reconstruct the cycle
                    uint64_t current = source;
                    cycle.push_back(neigh);
                    while(current != neigh && current != INV){
                        cycle.push_back(current);
                        current = parent[current];
                    }
                    cycle.push_back(neigh);
                    reverse(cycle.begin(), cycle.end());
                    return;
                } 
            }
            state[source] = 2;
        };

        for (uint64_t source = 0; source < vertices.size(); ++source){
            if (state[source] == 0){
                dfs(source);
                if (is_cycle) break;
            }
        }
        return cycle;
    }

}