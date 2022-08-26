#ifndef SSSPDAG_TPP
#define SSSPDAG_TPP

/*
The  single source shortest path problem can be solved efficiently on a DAG 
Using topological sorting
*/

template <typename V, typename W>
unordered_map<V, W> Graph<V,W>::DAG_shortest_path(V start)
{
    // ---------- Setup ---------- //
    vectV topsort = top_sort();
    unordered_map<V, W> dist;
    int UNVISITED = -1;

    for (const auto& vidx : vertices)
    {
        dist.insert({vidx.first, UNVISITED});
    }

    dist[start] = 0;
    // ---------- Setup ---------- //

    for (const auto& from: topsort)
    {
        if (dist[from] != UNVISITED)
        {
            for(const auto& [to, w]: edges[from]) 
            {
                W newDist = dist[from] + w;
                if (dist[to] == UNVISITED)
                {
                    dist[to] = newDist;
                }
                else{
                    dist[to] = std::min(dist[to], newDist);
                }
            }
        }
    }

    return dist;
}

#endif
