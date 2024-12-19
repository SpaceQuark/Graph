#include "Graph.hpp"

Graph::VertexIdWeights Graph::bellmanford_sssp(const uint64_t& source)
{
	VertexIdWeights distances(vertices.size(), WINF);
    distances[source] = 0;

	// Relax all edges (V-1) times (Why V-1 iteration? that is the longest path to connect all vertices!)
    for (size_t i = 0; i < vertices.size() - 1; ++i) {
        for (uint64_t u = 0; u < vertices.size(); ++u) {
            for (const auto& edge : adj_list[u]) {
                uint64_t v = edge->y_id;
                int64_t weight = edge->weight;

                // Relax the edge (u, v)
                if (distances[u] != WINF && distances[u] + weight < distances[v]) {
                    distances[v] = distances[u] + weight;
                }
            }
        }
    }


	// Check for negative weight cycles
    for (uint64_t u = 0; u < vertices.size(); ++u) {
        for (const auto& edge : adj_list[u]) {
            uint64_t v = edge->y_id;
            int64_t weight = edge->weight;

            // If we can still relax an edge, a negative weight cycle exists!
            if (distances[u] != WINF && distances[u] + weight < distances[v]) {
                throw std::runtime_error("Graph contains a negative weight cycle");
            }
        }
    }

    return distances;

}