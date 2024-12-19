#include "Graph.hpp"
#include "UnionFind.hpp"

Graph::EdgeList Graph::kruskal_mst(){
	EdgeList mst;
	EdgeList sorted_edges = edges;
	sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
	});

	UnionFind uf(vertices.size());

	// Process edges in sorted order
    for (const auto& edge : sorted_edges) {
        if (!uf.connected(edge.x_id, edge.y_id)) {
            uf.unify(edge.x_id, edge.y_id);
            mst.push_back(edge);

            // Stop early if MST is complete
            if (mst.size() == vertices.size() - 1) {
                break;
            }
        }
    }

	if (mst.size() != vertices.size() - 1) {
        throw std::runtime_error("Graph is not connected, MST cannot be formed");
    }

	return mst;
}