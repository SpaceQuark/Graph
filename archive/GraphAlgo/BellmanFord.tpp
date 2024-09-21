#ifndef BELLMAN_FORD_TPP
#define BELLMAN_FORD_TPP



/*
Bellman Ford Algorithm

Ideal for
- small/medium graphs
- ok for SP on graph with weighted edges
- can detect neative cycles


Algorithm Steps:
1. Set every entry in dist to +inf
2. set dist[source] = 0
3. Relax each edge V-1 times:


Time Complexity: O(EV)
*/
template <typename V, typename W>
std::unordered_map<V, W> Graph<V,W>::BellmanFord(const V& source)
{
    // ---------- Setup ---------- //
    std::unordered_map<V, W> dist;

    for (const auto& vidx : vertices)
    {
        // dist.insert({vidx.first, gmax<W>});
        dist.insert({vidx.first, PINF<W>});
    }

    // In the worst case, it takes V-1 iterations for Bellman-Ford algorithm
    // to complete - the longest path would connect all vertices, and will need
    // us to assess V-1 edges. An optimization is that when we are unable to relax 
    // an edge, this means that we have reached the optimal solution early.

    dist[source] = 0;

    // ---------- Setup ---------- //

    // bool relaxedAnEdge = true;

    for (int i = 0; i < numV-1; ++i)
    {
        // relaxedAnEdge = false;
        for (const auto& [from, vec] : edges)
        {
            for (const auto& [to, w] : vec)
            {
                // dealing with +INF overflow
                // if (dist[from] == gmax<W>)
                // {
                //     continue;
                // }
                // relax edge (update dist with shorter path)
                if (dist[from] + w < dist[to])
                {
                    dist[to] = dist[from] + w;
                    // relaxedAnEdge = true;
                }

            }
        }
    }

    // Repeat to find vertices caught in a negative cycle

    for (int i = 0; i < numV-1; ++i)
    {
        for (const auto& [from, vec] : edges)
        {
            for (const auto& [to, w] : vec)
            {
                // dealing with -INF overflow
                // if (dist[from] == gmin<W> && w < 0)
                // {
                //     dist[to] = gmin<W>;
                // }
                // relax edge (update dist with shorter path)
                if (dist[from] + w < dist[to])
                {
                    dist[to] = NINF<W>;
                }
            }
        }
    }

    return dist;
}


#endif