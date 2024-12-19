#include "Graph.hpp"

Graph::VertexIdWeights Graph::dial_sssp(const uint64_t& source, int64_t max_weight){
    VertexIdWeights distances(vertices.size(), std::numeric_limits<int64_t>::max());
    distances[source] = 0;

	int64_t max_distance = vertices.size() * max_weight;
	vector<vector<uint64_t>> buckets(max_distance + 1);

	buckets[0].push_back(source);

	int64_t current_distance = 0;

	while (current_distance <= max_distance) {
        while (current_distance <= max_distance && buckets[current_distance].empty()) {
            ++current_distance;
        }

        if (current_distance > max_distance) break;

        // Process all vertices in the current bucket
        while (!buckets[current_distance].empty()) {
            uint64_t u = buckets[current_distance].back();
            buckets[current_distance].pop_back();

            // Skip if the current distance is greater than the recorded distance
            if (distances[u] < current_distance) continue;

            // Iterate through all neighbors of u
            for (const auto& edge : adj_list[u]) {
                uint64_t v = edge->y_id;
                int64_t new_distance = distances[u] + edge->weight;

                // If the new distance is shorter, update and push to the correct bucket
                if (new_distance < distances[v]) {
                    distances[v] = new_distance;

                    if (new_distance <= max_distance) {
                        buckets[new_distance].push_back(v);
                    }
                }
            }
        }
    }

    return distances;
}