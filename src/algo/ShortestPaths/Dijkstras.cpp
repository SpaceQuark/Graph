#include "Graph.hpp"

VertexIdWeights Graph::dijkstras(const uint64_t& source)
{
    vector<double> distance(vertices.size(), numeric_limits<double>::infinity());
    distance[source] = 0.0;

    priority_queue<pair<double, uint64_t>, vector<pair<double, uint64_t>>, greater<pair<double, uint64_t>>> pq;

    pq.emplace(0.0, source);

    while (!pq.empty()) {
        double current_distance = pq.top().first;
        uint64_t u = pq.top().second;
        pq.pop();

        // If the current distance is greater than the recorded distance, skip
        if (current_distance > distance[u]) {
            continue;
        }

        // Iterate through all neighbors of u
        for (const auto& v : adj_list[u]) {
            Edge e = edges[{u, v}];

            // Calculate the new tentative distance to neighbor v
            double new_distance = distance[u] + e.weight;

            // If the new distance is shorter, update and push to the queue
            if (new_distance < distance[v]) {
                distance[v] = new_distance;
                pq.emplace(new_distance, v);
            }
        }
    }

    // Prepare the result as VertexIdWeights
    VertexIdWeights result;
    result.reserve(vertices.size()); // Reserve space to avoid reallocations

    for (int64_t i = 0; i < vertices.size(); ++i) {
        result.emplace_back(i, distance[i]);
    }

    return result;
}
