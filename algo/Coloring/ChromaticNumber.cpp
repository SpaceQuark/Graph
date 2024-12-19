#include "Graph.hpp"

uint64_t Graph::chromatic_number(){
    uint64_t n = vertices.size();
    if (n == 0) return 0;

    // Convert adjacency list to bitmask representation
    vector<uint64_t> adj(n, 0);
    for (uint64_t u = 0; u < n; ++u) {
        for (const Edge* edge : adj_list[u]) {
            if (edge != nullptr) {
                adj[u] |= 1 << edge->y_id;
            }
        }
    }

	// Compute dp[S] (number of independent sets in subset S)
    vector<uint64_t> dp(1 << n, 0);
    dp[0] = 1; // Empty set is always independent
    for (uint64_t S = 1; S < (uint64_t(1) << n); ++S) {
        uint64_t i = __builtin_ctz(S); // rightmost set bit (first vertex in subset)
        dp[S] = dp[S ^ (1 << i)] + dp[(S ^ (1 << i)) & ~adj[i]];
    }

    // Inclusion-Exclusion
    vector<int64_t> cnt((1 << n) + 1, 0); // cnt[k] = number of subsets with exactly k independent sets
    for (uint64_t S = 0; S < (uint64_t(1) << n); ++S) {
        cnt[dp[S]] += (__builtin_parity(S) ? 1 : -1);
    }

    vector<pair<long long, long long>> f; // Independent sets and coefficients
    for(long long i = 0; i <= (1 << n); i++){
        if(cnt[i] != 0){
            f.emplace_back(i, cnt[i]);
        }
    }

    int chromatic = n;
    constexpr long long MODS[] = {1000000007, 1000000009, 1000000021};
    for(int i = 0; i < 3; i++){
        auto nf = f;
        for(int k = 1; k <= n; k++){
            if(chromatic <= k) break;
            long long sum = 0;
            for(auto &[x, y] : nf){
                sum += (y = y * x % MODS[i]);
                sum %= MODS[i];
            }
            if(sum != 0) chromatic = min(chromatic, k);
        }
    }
    return chromatic;
}