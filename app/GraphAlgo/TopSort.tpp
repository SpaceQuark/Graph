#ifndef TOPSORT_TPP
#define TOPSORT_TPP

/*
Topological sort:

- Find ordering of vertices in a graph (directed) -- a program cannot be built unless its dependencies are first built
- The only type of graph which has a valid topological ordering is a Directed Acyclic Graph (DAG)
- A application of this sort is to find the shortest path between two vertices in a DAG.
- Topological sorts are not UNIQUE

Steps:
1. find unvisited vertex
2. From the selected vertex, do a DFS exploring only the unvisited vertices.
3. On the recursive callback of the DFS, add the current vertex to the topological ordering in reverse order.



Time complexity: O(V+E)
*/
template <typename V, typename W>
auto Graph<V,W>::top_sort() -> vectV
{
    // ---------- Setup ---------- //
    unordered_map<V,bool> visited;
    for (const auto& vidx : vertices)
    {
        visited[vidx.first] = false;
    }
    vectV ordering(numV);

    // index of ordering vector
    int idx = numV-1; 

    auto DFS_ts = [&](V at, auto&& DFS_ts) -> int
    {
        visited[at] = true;
        for (const auto& [to, w] : edges[at])
        {
            if (!visited[to])
            {
                idx = DFS_ts(to, DFS_ts);
            }
        }
        ordering[idx] = at;
        return idx-1;
    };

    // ---------- Setup ---------- //


    for (const auto& vidx: vertices)
    {
        if (!visited[vidx.first])
        {
            idx = DFS_ts(vidx.first, DFS_ts);
        }
    }
    return ordering;
}

#endif