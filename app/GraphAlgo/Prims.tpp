#ifndef PRIMS_TPP
#define PRIMS_TPP

/*
Minimal Spanning Tree (MST): subset of edges in the graph that connects all vertices (creating no cycles) while minimizing total edge cost
Note: All nodes must be connected for there to be a minimal spanning tree

Prim's MST algorithm
- Greedy
- meets or improves time bounds of Boruvka's and Kruskals

Lazy implementation of Prim's Algorithm

Time Complexity: O(E Log E)

*/
template <typename V, typename W>
pair<W, vector<pair<V,V>>> Graph<V,W>::Prims(const V& source)
{
    // ---------- Setup ---------- //
    size_t totEdges = numV - 1; // total edges (For trees, total edges = total vertices - 1)
    size_t edgeCount = 0; // current edge count
    W mstCost = 0; // MST total weight

    vector<pair<V,V>> mstEdges(totEdges);
    unordered_map<V, bool> visited;

    for (const auto& vidx : vertices)
    {
        visited.insert({vidx.first, false});
    }

    auto mint = [](const std::tuple<V, V, W>& lhs, const std::tuple<V, V, W>& rhs)
    { return std::get<2>(lhs) > std::get<2>(rhs); };


    // create a min heap priority queue (consists of a tuple of start vertex, end vertex, and edge weight) 
    // PQ sorts edges based on min edge weight
    std::priority_queue<std::tuple<V,V,W>,std::vector<std::tuple<V, V, W>>, decltype(mint)> pq(mint);

    
    // add edges helper lambda function
    auto addEdges = [&](V from)
    {
        visited[from] = true;

        for (const auto& [to, w] : edges[from])
        {
            if (!visited[to])
            {
                pq.push(std::make_tuple(from, to, w));
            }
        }
    };


    V minVx; // start vertex of edge
    V minVy; // end vertex of edge
    W minVal; // minimum edge


    // ---------- Setup ---------- //

    // mark current node as visited, iterate over all edges going outward from current node
    addEdges(source);



    while (!pq.empty() && edgeCount != totEdges)
    {
        minVx = std::get<0>(pq.top());
        minVy = std::get<1>(pq.top());
        minVal = std::get<2>(pq.top());
        pq.pop();

        // skips an edge that points to a visited vertex (edge can become stale/outdated 
        // in the PQ if the vertex they are pointing at becomes visited by another path)
        if (visited[minVy])
        {
            continue;
        }

        mstEdges[edgeCount++] = std::make_pair(minVx, minVy);
        mstCost += minVal;

        addEdges(minVy);
    }

    // No MST exist! Graph not entirely spanned
    if (edgeCount != totEdges)
    {
        return std::make_pair(0, vector<pair<V,V>>());
    }

    return std::make_pair(mstCost, mstEdges);
}




#endif
