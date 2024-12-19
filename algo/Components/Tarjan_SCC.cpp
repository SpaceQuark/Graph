/*

* Status: Tested on Yosupo - Strongly Connected Components
*/

#include "Graph.hpp"

vector<Graph::VertexIds> Graph::tarjan_scc(){
	uint32_t UNVISITED = static_cast<uint32_t>(-1);

	vector<VertexIds> sccs; // List of SCCs
	vector<bool> on_stack(vertices.size(), false);
	vector<uint32_t> low(vertices.size(), 0); // Lowest reachable vertex
	vector<uint32_t> cids(vertices.size(), UNVISITED);

	stack<uint64_t> stk;
	uint32_t time = 0;

	auto dfs = [&](auto&& self, uint64_t source) -> void {
		low[source] = cids[source] = time++;

		stk.push(source);
		on_stack[source] = true;

        for (const Edge* edge : adj_list[source]) {  // Traverse neighbors
            uint64_t neighbor = edge->y_id;

            if (cids[neighbor] == UNVISITED) {       // If the neighbor has not been visited
                self(self, neighbor);               // Recur for the neighbor
            } 
			if (on_stack[neighbor]) {        // If the neighbor is in the current stack
                low[source] = min(low[source], low[neighbor]);
            }
        }


		if (low[source] == cids[source]) {
            VertexIds scc;
            uint64_t v;
            do {
                v = stk.top();
                stk.pop();
                on_stack[v] = false;
                scc.push_back(v);
            } while (v != source);
            sccs.push_back(scc); // Add the SCC to the result
        }
	};


	// Run DFS for every vertex
    for (uint64_t i = 0; i < vertices.size(); ++i) {
        if (cids[i] == UNVISITED) {
            dfs(dfs, i);
        }
    }

	// Optional: reverse SCCs for topological order
	reverse(sccs.begin(), sccs.end());

	return sccs;
}