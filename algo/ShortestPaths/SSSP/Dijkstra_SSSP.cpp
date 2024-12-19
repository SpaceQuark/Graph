/*

* Status: Tested on Yosupo - Shortest Path
*/

#include "Graph.hpp"

Graph::VertexIdWeights Graph::dijkstra_sssp(const uint64_t& source)
{
    VertexIdWeights distances(vertices.size(), std::numeric_limits<int64_t>::max());
    distances[source] = 0;

	min_heap<pair<int64_t, uint64_t>> pq;
    pq.emplace(0, source);

    while (!pq.empty()) {
		auto [current_distance, u] = pq.top();
        pq.pop();

        // If the current distance is greater than the recorded distance, skip
        if (current_distance > distances[u]) {
            continue;
        }

        // Iterate through all neighbors of u
        for (const auto& edge : adj_list[u]) {
			uint64_t v = edge->y_id;
            // Calculate the new tentative distance to neighbor v
            int64_t new_distance = distances[u] + edge->weight;

            // If the new distance is shorter, update and push to the queue

            if (new_distance < distances[v]) {
                distances[v] = new_distance;
                pq.emplace(new_distance, v);
            }
        }
    }
    return distances;
}


pair<Graph::VertexIds, int64_t> Graph::dijkstra_sssp_reconstruct(const uint64_t& source, const uint64_t& destination){
	VertexIdWeights distances(vertices.size(), std::numeric_limits<int64_t>::max());
	distances[source] = 0;

	VertexIds parent(vertices.size(), INV); // Track the path
	parent[source] = source; // Source is its own parent

	min_heap<pair<int64_t, uint64_t>> pq;

	pq.emplace(0, source);

	while (!pq.empty()) {
		auto [current_distance, u] = pq.top();
		pq.pop();

		// If the current distance is greater than the recorded distance, skip
		if (current_distance > distances[u]) {
			continue;
		}

		// Iterate through all neighbors of u
		for (const auto& edge : adj_list[u]) {
			uint64_t v = edge->y_id;

			// Calculate the new tentative distance to neighbor v
			int64_t new_distance = distances[u] + edge->weight;

			// If the new distance is shorter, update and push to the queue
			if (new_distance < distances[v]) {
				distances[v] = new_distance;
				parent[v] = u; // Update the parent
				pq.emplace(new_distance, v);
			}
		}
	}

	// Reconstruct the path from source to destination
	VertexIds path;
	if (distances[destination] == std::numeric_limits<int64_t>::max()) {
		// No path found
		return {path, -1};
	}

	for (uint64_t current = destination; current != source; current = parent[current]) {
		if (current == INV) {
			// Break if the path is incomplete (should not happen in valid input)
			return {VertexIds{}, -1};
		}
		path.push_back(current);
	}
	path.push_back(source);
	reverse(path.begin(), path.end()); // Reverse to get the path from source to destination

	return {path, distances[destination]};
}
