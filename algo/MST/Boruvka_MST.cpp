#include "Graph.hpp"
#include "UnionFind.hpp"

Graph::EdgeList Graph::boruvka_mst(){
	EdgeList mst; 
    UnionFind uf(vertices.size()); // Union-Find to manage components
    uint64_t num_components = vertices.size();

    while (num_components > 1) {
        // Find the cheapest edge for each component
        vector<const Edge*> cheapest(vertices.size(), nullptr);

        for (const auto& edge : edges) {
            uint64_t comp_u = uf.find(edge.x_id);
            uint64_t comp_v = uf.find(edge.y_id);

            // Check if edge is cheapest for either component
            if (comp_u != comp_v) {
                if (cheapest[comp_u] == nullptr || edge.weight < cheapest[comp_u]->weight) {
                    cheapest[comp_u] = &edge;
                }

                if (cheapest[comp_v] == nullptr || edge.weight < cheapest[comp_v]->weight) {
                    cheapest[comp_v] = &edge;
                }
            }
        }

        // Add the cheapest edges to the MST and unify components
        for (const auto& edge : cheapest) {
            if (edge == nullptr) continue;

            uint64_t comp_u = uf.find(edge->x_id);
            uint64_t comp_v = uf.find(edge->y_id);

            if (comp_u != comp_v) {
                mst.push_back(*edge);
                uf.unify(comp_u, comp_v);
                num_components--;
            }
        }
    }

    return mst;
}