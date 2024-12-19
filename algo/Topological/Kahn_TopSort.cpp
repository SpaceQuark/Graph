#include "Graph.hpp"

Graph::VertexIds Graph::Kahn_topsort(){
	VertexIds top_ordering(vertices.size());

	vector<uint64_t> in_degree(vertices.size(), 0);
    for (uint64_t u = 0; u < vertices.size(); ++u) {
        for (const Edge* edge : adj_list[u]) {
            uint64_t v = edge->y_id;
            in_degree[v]++;
        }
    }


	// Initialize the queue with all vertices having in-degree 0
	queue<uint64_t> q;
	for (uint64_t i = 0; i < vertices.size(); ++i) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

	uint64_t idx = 0;
   	while (!q.empty()) {
        uint64_t u = q.front();
        q.pop();
        top_ordering[idx++] = u;

        // Reduce the in-degree of all neighbors
        for (const Edge* edge : adj_list[u]) {
            uint64_t v = edge->y_id;
            in_degree[v]--;
            if (in_degree[v] == 0) {
                q.push(v);
            }
        }
    }

	if (idx != vertices.size()) { 
		throw std::runtime_error("Graph contains a cycle, topological sorting not possible");
	}

    return top_ordering;
}