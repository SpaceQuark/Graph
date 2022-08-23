#ifndef FLOYD_WARSHALL_TPP
#define FLOYD_WARSHALL_TPP

/*
Ideal for
- small graphs
- all pair shortest path (APSP)
- detecting negative cycles

Can be used only for adjacency matrices

FW algorithm
1. Start 


Time Complexity: O(V^3)
*/
template <typename V, typename W>
std::vector<std::vector<W>> Graph<V,W>::FloydWarshall()
{
    std::vector<std::vector<W>> dp = AM();

    // Execute FW APSP algorithm
    for (int k = 0; k < numV; ++k)
    {
        for (int i = 0; i < numV; ++i)
        {
            for (int j = 0; j < numV; ++j)
            {
                if (dp[i][k] + dp[k][j] < dp[i][j])
                {
                    dp[i][j] = dp[i][k] + dp[k][j];
                }
            }
        }
    }

    // execute FW APSP algorithm a second time, but this time
    // if the distance can be improved, we set the optimal distance to -INF
    // All edges (i,j) marked with -INF is either part of a negative cycle
    // or passes through a negative cycle

    for (int k = 0; k < numV; ++k)
    {
        for (int i = 0; i < numV; ++i)
        {
            for (int j = 0; j < numV; ++j)
            {
                // dp[i][k] + dp[k][j] < dp[i][j]
                if (dp[i][k] != PINF<W> && dp[k][j] != PINF<W> && dp[k][k] < 0)
                {
                    dp[i][j] = NINF<W>;
                }
            }
        }
    }

    return dp;
}

// returns the 2D dp vector of shortest paths along with next 2D vector
// (which captures the next vertex visited during the trip from i to j)

template <typename V, typename W>
std::pair<std::vector<std::vector<W>>, std::vector<std::vector<W>>> Graph<V,W>::floyd_warshall_construct()
{
    std::vector<std::vector<W>> dp = AM();
    
    // next matrix used to reconstruct shortest paths
    std::vector<std::vector<W>> next(numV, std::vector<W>(numV, 0));

    // set up next matrix
    for (int i = 0; i < numV; ++i)
    {
        for (int j = 0; j < numV; ++j)
        {
            if (dp[i][j] != PINF<W>)
            {
                next[i][j] = j;
            }
        }
    }

    // Execute FW APSP algorithm
    for (int k = 0; k < numV; ++k)
    {
        for (int i = 0; i < numV; ++i)
        {
            for (int j = 0; j < numV; ++j)
            {
                if (dp[i][k] + dp[k][j] < dp[i][j])
                {
                    dp[i][j] = dp[i][k] + dp[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }

    // execute FW APSP algorithm a second time, but this time
    // if the distance can be improved, we set the optimal distance to -INF
    // All edges (i,j) marked with -INF is either part of a negative cycle
    // or passes through a negative cycle

    for (int k = 0; k < numV; ++k)
    {
        for (int i = 0; i < numV; ++i)
        {
            for (int j = 0; j < numV; ++j)
            {
                // if (dp[i][k] != PINF<W> && dp[k][j] != PINF<W> && dp[k][k] < 0)
            
                if (dp[i][k] + dp[k][j] < dp[i][j])
                {
                    dp[i][j] = NINF<W>;

                    // indicate path affected by negative cycle
                    next[i][j] = -1;
                }
            }
        }
    }

    return make_pair(dp, next);
}



template <typename V, typename W>
std::optional<std::vector<V>> Graph<V,W>::fw_reconstruct_path(const V& source, const V& end)
{
    std::vector<V> path;
    std::pair<std::vector<std::vector<W>>, std::vector<std::vector<W>>> dpnext = floyd_warshall_construct();
    std::vector<std::vector<W>> dp = dpnext.first;
    std::vector<std::vector<W>> next = dpnext.second;

    W NEGATIVE_CYCLE = -1;

    // create a temporary reverse map lookup
    std::unordered_map<size_t, V> reverse;
    for (const auto& [v, idx] : vertices)
    {
        reverse.insert({idx, v});
    }


    size_t s_idx = vertices[source];
    size_t e_idx = vertices[end];

    // Begin algorithm:

    // path does not exist from source to end
    if (dp[s_idx][e_idx] == PINF<W>)
    {
        return path;
    }

    // start from source
    V at = source;
    size_t a_idx{};

    while (at != end)
    {
        // negative cycle exists, infinite solutions
        if (at == NEGATIVE_CYCLE)
        {
            return {};
        }
        path.push_back(at);


        a_idx = vertices[at];
        at = reverse[next[a_idx][e_idx]];
    }


    if (next[vertices[at]][e_idx] == NEGATIVE_CYCLE)
    {
        // negative cycle exists, infinite solutions
        return {};
    }

    path.push_back(end);
    return path;
}



#endif
