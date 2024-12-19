#include "Graph.hpp"

vector<Graph::VertexIds> Graph::enumerate_cliques(){
	vector<VertexIds> cliques; // To store all cliques

    auto bron_kerbosch_all = [&](auto&& self, VertexIds R, VertexIds P, VertexIds X) -> void {
        // Record every clique as `R`
        if (!R.empty()) {
            cliques.push_back(R);
        }

        // Iterate over a copy of P
        auto P_copy = P;
        for (uint64_t v : P_copy) {
            R.push_back(v);

            VertexIds neighbors;
            for (const Edge* edge : adj_list[v]) {
                if (edge) {
                    neighbors.push_back(edge->y_id);
                }
            }

            // Intersect P and neighbors, and intersect X and neighbors
            VertexIds P_next, X_next;
            for (uint64_t u : P) {
                if (std::find(neighbors.begin(), neighbors.end(), u) != neighbors.end()) {
                    P_next.push_back(u);
                }
            }
            for (uint64_t u : X) {
                if (std::find(neighbors.begin(), neighbors.end(), u) != neighbors.end()) {
                    X_next.push_back(u);
                }
            }

            self(self, R, P_next, X_next);

            R.pop_back();
            P.erase(remove(P.begin(), P.end(), v), P.end());
            X.push_back(v);
        }
    };

    VertexIds P(vertices.size()), R, X;
    iota(P.begin(), P.end(), 0); 

    bron_kerbosch_all(bron_kerbosch_all, R, P, X);

    return cliques;
}