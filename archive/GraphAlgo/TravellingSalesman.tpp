#ifndef TRAVELLINGSALESMAN_TPP
#define TRAVELLINGSALESMAN_TPP

/*
Travelling Salesman Problem (TSP)

Hamiltonian path: path that visits every vertex once
Hamiltonian cycle: Hamiltonian path that starts and ends at the same vertex.

We want to find the hamiltonian cycle of minimum cost.
Note: finding optimal solution is extremely hard (NP complete)

DP improves TSP from O(n!) to O(n^2*2^n)

1. start by choosing a starting node
2. Compute and store the optimal value from S to each node
   This will solve TSp problem for all paths of length n = 2

3. To computer for paths of length 3, we need to store
   set of visited nodes in the subpath, and index of last visited
   node in the path

There are N possible vertices that we could ahve visited last and 2^N
subsets of visited vertices. Therefore, the space necessary to store the answer 
for each subproblem is bounded by O(N*2^N)


*/


template <typename V, typename W>
auto Graph<V,W>::TSP(const V& source) -> pair<W, vectV>
{
// ---------- Setup ---------- //

    // create a temporary reverse map lookup
    std::unordered_map<size_t, V> reverse;
    for (const auto& [v, idx] : vertices)
    {
        reverse.insert({idx, v});
    }

   // matW dp(numV, vectW(1 << numV, gmax<W>));
   matW dp(numV, vectW(1 << numV));

   matW m = AM();
   size_t s = vertices[source];

   for (size_t e = 0; e < numV; ++e)
   {
      if (e == s)
      {
         continue;
      }

      // Store the optimal value from source vertext to each other vertices i
      // (this is given as input in the adj matrix m)

      dp[e][(1 << s) | (1 << e)] = m[s][e];
   }

   auto not_in = [](size_t i, size_t subset) 
   {
      return ((1 << i) & subset) == 0;
   };

   // Recursive method to generate bitsets
   auto _combinations = [&](size_t set, size_t at, size_t r, vector<size_t>& subsets, auto&& _combinations)
   {
      // Return early if there are more elements to select than what is available
      size_t elemsLeft = numV - at;
      if (elemsLeft < r)
      {
         return;
      }
      
      if (r == 0)
      {
         subsets.push_back(set);
      }
      else
      {
         for (size_t i = at; i < numV; ++i)
         {
            // flip ith bit
            set ^= (1 << i);
            _combinations(set, i + 1, r - 1, subsets, _combinations);

            // backtrack and flip off ith bit
            set ^= (1 << i);
         }
      }
   };

   auto combinations = [&](size_t r)
   {
      vector<size_t> subsets;
      _combinations(0, 0, r, subsets, _combinations);
      return subsets;

   };

// ---------- Setup ---------- //

   for (size_t r = 3; r <= numV; ++r)
   {
      // The combination function generates all bit sets of size numV
      // with r bits set to 1. Ex. combinations(2,3) = {011, 101, 110}
      for (auto subset : combinations(r))
      {
         if (not_in(s, subset))
         {
            continue;
         }
         for (size_t next = 0; next < numV; ++next)
         {
            if (next == s || not_in(next, subset))
            {
               continue;
            }
            // The subset state wiwthout the next vertex
            size_t state = subset ^ (1 << next);
            W minDist = PINF<W>;

            // e is end vertex
            for (size_t e = 0; e < numV; ++e)
            {
               if (e == s || e == next || not_in(e, subset))
               {
                  continue;
               }
               W newDist = dp[e][state] + m[e][next];

               if (newDist < minDist)
               {
                  minDist = newDist;
               }
            }
            dp[next][subset] = minDist;
         }
      }
   }

   // Find min cost

   // The end state is bit mask with N bits set to 1 (2^N - 1)
   size_t END_STATE = (1 << numV) - 1;
   W minTourCost = PINF<W>;

   for (size_t e = 0; e < numV; ++e)
   {
      if (e == s)
      {
         continue;
      }
      W tourCost = dp[e][END_STATE] + m[e][s];
      if (tourCost < minTourCost)
      {
         minTourCost = tourCost;
      }
   }
   

   // Find optimal cost

   size_t lastIdx = s;
   size_t state = (1 << numV) - 1; // End state
   vectV tour(numV+1);

   for (size_t i = numV-1; i >= 1; --i)
   {
      size_t idx = -1;
      for (size_t j = 0; j < numV; ++j)
      {
         if (j == s || not_in(j, state))
         {
            continue;
         }
         
         if (idx == -1)
         {
            idx = j;
         }

         W prevDist = dp[idx][state] + m[idx][lastIdx];
         W newDist = dp[j][state] + m[j][lastIdx];

         if (newDist < prevDist)
         {
            idx = j;
         }
      }

      tour[i] = reverse[idx];
      state = state ^ (1 << idx);
      lastIdx = idx;
   }

   tour[0] = tour[numV] = source;
   return {minTourCost, tour};
}



#endif