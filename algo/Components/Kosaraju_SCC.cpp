/*

* Status: Tested on Yosupo - Strongly Connected Components
*/

#include "Graph.hpp"

vector<Graph::VertexIds> Graph::kosaraju_scc(){
	vector<VertexIds> sccs; // List of SCCs
	vector<bool> visited(vertices.size(), false);
	stack<uint32_t> finish_order; 

    // Perform DFS on the original graph and record finish times
    auto dfs1 = [&](auto&& self, uint64_t node) -> void {
        visited[node] = true;
        for (const Edge* edge : adj_list[node]) {
            uint64_t neighbor = edge->y_id;
            if (!visited[neighbor]) {
                self(self, neighbor);
            }
        }
        finish_order.push(node); // Push the vertex after exploring all neighbors
    };


    for (uint64_t i = 0; i < vertices.size(); ++i) {
        if (!visited[i]) {
            dfs1(dfs1, i);
        }
    }

	// Reverse the graph
    vector<vector<uint64_t>> reversed_adj_list(vertices.size());
    for (uint64_t u = 0; u < vertices.size(); ++u) {
        for (const Edge* edge : adj_list[u]) {
            reversed_adj_list[edge->y_id].push_back(u); // Reverse the direction of edges
        }
    }

	// Perform DFS on the reversed graph in finish time order
    visited.assign(vertices.size(), false); // Reset visited
	
    auto dfs2 = [&](auto&& self, uint64_t node, VertexIds& scc) -> void {
        visited[node] = true;
        scc.push_back(node); // Add the node to the current SCC
        for (uint64_t neighbor : reversed_adj_list[node]) {
            if (!visited[neighbor]) {
                self(self, neighbor, scc);
            }
        }
    };


    while (!finish_order.empty()) {
        uint64_t v = finish_order.top();
        finish_order.pop();
        if (!visited[v]) {
            VertexIds scc;
            dfs2(dfs2, v, scc); // Find one SCC
            sccs.push_back(scc);   // Add it to the list of SCCs
        }
    }

	return sccs; // SCCs in topological order
}