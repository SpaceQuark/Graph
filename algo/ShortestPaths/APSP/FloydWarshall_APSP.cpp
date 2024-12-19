#include "Graph.hpp"

vector<Graph::VertexIdWeights> Graph::floydwarshall_apsp()
{
    // Initialize distance matrix
    vector<VertexIdWeights> dist(vertices.size(), VertexIdWeights(vertices.size(), WINF));

    for (uint64_t u = 0; u < vertices.size(); ++u) {
        dist[u][u] = 0; // Distance to self is 0
        for (const Edge* edge : adj_matrix[u]) {
            if (edge != nullptr) {
                dist[u][edge->y_id] = edge->weight;
            }
        }
    }

    // Perform relaxation
    for (uint64_t k = 0; k < vertices.size(); ++k) {
        for (uint64_t u = 0; u < vertices.size(); ++u) {
            for (uint64_t v = 0; v < vertices.size(); ++v) {
                if (dist[u][k] != WINF && dist[k][v] != WINF) {
                    dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
                }
            }
        }
    }

    // Step 3: Check for negative weight cycles
    for (uint64_t u = 0; u < vertices.size(); ++u) {
        if (dist[u][u] < 0) {
            throw std::runtime_error("Graph contains a negative weight cycle");
        }
    }

    return dist;
}