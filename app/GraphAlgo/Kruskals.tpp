#ifndef KRUSKALS_HPP
#define KRUSKALS_HPP


/*
Kruskal's MST Algorithm

Algorithm steps:
1. Sort edges by ascending edge weight
2. Traverse the sorted edges and look for two nodes the edge belongs to
   (if the nodes are already unified, we don't include this edge, otherwise we include it and unify the nodes)
3. The algorithm terminates when every edge has been processed or all vertices are unified

Time Complexity: O(E Log V)

*/

template <typename V, typename W>
auto Graph<V,W>::Kruskals(const V& source) -> pair<W, vector<wEdge>>
{
    // ---------- Setup ---------- //
    auto edgeList = EL(); // vector of start vertex, end vertex, weight
    vector<wEdge> mstEdges;
    W mstCost = 0; // MST total weight

    // sort by the weight
    std::sort(edgeList.begin(), edgeList.end(), 
        [](wEdge const &t1, wEdge const &t2) 
        {
            return std::get<2>(t1) < std::get<2>(t2);
        }
    );

    UnionFind uf = UnionFind(numV);


    // ---------- Setup ---------- //

    // mark current node as visited, iterate over all edges going outward from current node

    for (const auto& [from, to, w] : edgeList)
    {
        // if connected, skip this edge to avoid creating a cycle
        if (uf.connected(vertices[from], vertices[to]))
        {
            continue;
        }

        mstEdges.push_back({from, to, w});
        uf.unify(vertices[from], vertices[to]);
        mstCost += w;

        if (uf.component_size(0) == numV)
        {
            break;
        }
    }

    // No MST exist! Graph not entirely spanned
    if (uf.component_size(0) != numV)
    {
        return {0, vector<wEdge>()};
    }

    return {mstCost, mstEdges};
}

#endif
