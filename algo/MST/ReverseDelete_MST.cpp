#include "Graph.hpp"
#include "UnionFind.hpp"

Graph::EdgeList Graph::reversedelete_mst(){
    EdgeList mst = edges; 

    // Sort edges in decreasing order of weight
    sort(mst.begin(), mst.end(), [](const Edge& a, const Edge& b) {
        return a.weight > b.weight;
    });


    EdgeList final_mst; 

    for (const auto& edge : mst) {
        UnionFind uf(vertices.size()); // Union-Find for connectivity checks
        for (const auto& e : mst) {
            if (e.x_id == edge.x_id && e.y_id == edge.y_id) continue; // Skip this edge
            uf.unify(e.x_id, e.y_id);
        }

        // Check if the graph remains connected without this edge
        bool connected = true;
        for (uint64_t i = 1; i < vertices.size(); ++i) {
            if (!uf.connected(0, i)) {
                connected = false;
                break;
            }
        }

        // If graph remains connected without the edge, remove it
        if (!connected) {
            final_mst.push_back(edge);
        }
    }

    return final_mst;
}