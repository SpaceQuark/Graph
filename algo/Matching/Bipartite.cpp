#include "Graph.hpp"


pair<Graph::VertexIds, Graph::VertexIds> Graph::bipartite(){
    VertexIds set1, set2;          
    vector<int> color(vertices.size(), -1); // Color array: -1 = unvisited, 0 or 1 for the two sets

    auto is_bipartite = [&](auto&& self, uint64_t u, int current_color) -> bool {
        color[u] = current_color;

        for (const Edge* edge : adj_list[u]) {
            if (!edge) continue;
            uint64_t v = edge->y_id;

            if (color[v] == -1) { // Unvisited
                if (!self(self, v, 1 - current_color)) {
                    return false;
                }
            } else if (color[v] == current_color) { // Same color, not bipartite
                return false;
            }
        }

        return true;
    };

    for (uint64_t i = 0; i < vertices.size(); ++i) {
        if (color[i] == -1) {
            if (!is_bipartite(is_bipartite, i, 0)) {
                return {}; 
            }
        }
    }

    // Divide vertices into two sets
    for (uint64_t i = 0; i < vertices.size(); ++i) {
        if (color[i] == 0) {
            set1.push_back(i);
        } else if (color[i] == 1) {
            set2.push_back(i);
        }
    }

    return {set1, set2}; 
}