#include "Graph.hpp"

Graph::VertexIds Graph::DFS_topsort(){
	VertexIds top_ordering(vertices.size());
	vector<bool> visited(vertices.size(), false);

	uint64_t idx = vertices.size()-1; 

	auto dfs = [&](auto&& self, uint64_t node) -> void {
        visited[node] = true;
       	for (const Edge* edge : adj_list[node]) {
            if (edge == nullptr) continue;
            uint64_t neighbor = edge->y_id;

            if (!visited[neighbor]) {
                self(self, neighbor);
            }
        }
		top_ordering[idx--] = node;
	};

	for (uint64_t i = 0; i < vertices.size(); ++i) {
        if (!visited[i]) {
            dfs(dfs, i);
        }
    }

    if (idx != static_cast<uint64_t>(-1)) { 
        throw std::runtime_error("Graph contains a cycle, topological sorting not possible");
    }

	return top_ordering;
}