#include "Graph.hpp"

Graph::EdgeList Graph::jarnik_mst(){
    vector<bool> in_mst(vertices.size(), false);  // Tracks vertices in MST
    vector<const Edge*> min_edge(vertices.size(), nullptr); // Stores the minimum edge for each vertex
    
	min_heap<pair<int64_t, uint64_t>> pq;
    uint64_t start = 0; // start with an arbitrary vertex (0)
    pq.emplace(0, start);

	EdgeList mst;

	while (!pq.empty()) {
        auto [current_weight, u] = pq.top();
        pq.pop();

        if (in_mst[u]) continue; // Skip if already in MST

        in_mst[u] = true;

        // If there's a valid edge connecting u to the MST, add it
        if (min_edge[u] != nullptr) {
            mst.push_back(*min_edge[u]);
        }

        for (const Edge* edge : adj_list[u]) {
            uint64_t v = edge->y_id;

            if (!in_mst[v] && (min_edge[v] == nullptr || edge->weight < min_edge[v]->weight)) {
                // Update the minimum edge for vertex v
                min_edge[v] = edge;
                pq.emplace(edge->weight, v);
            }
        }
    }

	// Check if the graph is connected
    if (mst.size() != vertices.size() - 1) {
        throw std::runtime_error("Graph is not connected, MST cannot be formed");
    }

    return mst;
}