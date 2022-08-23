#ifndef KRUSKALS_TPP
#define KRUSKALS_TPP


/*
Kruskal's MST Algorithm

Algorithm steps:
1. Sort edges by ascending edge weight
2. Traverse the sorted edges and look for two nodes the edge belongs to
   (if the nodes are already unified, we don't include this edge, otherwise we include it and unify the nodes)
3. The algorithm terminates when every edge has been processed or all vertices are unified


*/

template <typename V, typename W>
pair<W, vector<pair<V,V>>> Graph<V,W>::Kruskals(const V& source)
{
    // ---------- Setup ---------- //
    auto edgeList = EL(); // vector of start vertex, end vertex, weight
    vector<pair<V,V>> mstEdges;
    W mstCost = 0; // MST total weight

    // sort by the weight
    std::sort(edgeList.begin(), edgeList.end(), 
        [](std::tuple<V, V, W> const &t1, std::tuple<V, V, W> const &t2) 
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

        mstEdges.push_back(std::make_pair(from, to));
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
        return std::make_pair(0, vector<pair<V,V>>());
    }

    return std::make_pair(mstCost, mstEdges);
}

#endif
