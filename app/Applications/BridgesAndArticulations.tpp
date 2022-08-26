#ifndef BRIDGESANDARTICULATIONS_TPP
#define BRIDGESANDARTICULATIONS_TPP

/*
Bridge/cut edge: any edge in a graph whose removal increases the number of connected components
Articulation point/cut vertex: any vertex in a graph whose removal increases number of connected components
Bridges and articulation points: important in graph theory, since they hint at weak points, bottlenecks, or vulnerabilities in a graph
So, it is crucial to be able to quickly detect when/where these occur


Low-link value: of a vertex is the smallest id reachable from that vertex when performing a DFS

Bridge algorithm:
1. start at any node and do a DFS traversal labeling nodes with an increasing id value as you go
2. Keep track of the id  of each node and smallest low-link value
3. During DFS, bridges will be found where the id of the node your edge is coming from is less than the low-link value
   of the vertex your edge is going to.
*/

#endif

template <typename V, typename W>
vector<pair<V,V>> Graph<V,W>::find_bridges()
{
   // ---------- Setup ---------- //
   unordered_map<V, int> ids;
   unordered_map<V, int> low;
   unordered_map<V, bool> visited;
   vector<pair<V,V>> bridges;

   for (const auto& vidx : vertices)
   {
      ids.insert({vidx.first, 0});
      low.insert({vidx.first, 0});
      visited.insert({vidx.first, false});
   }

   int id = 0;

   auto DFS_util = [&](V at, std::optional<V> parent, auto&& DFS_util) -> void
   {
      visited[at] = true;
      low[at] = ids[at] = ++id;

      for (const auto& [to, w] : edges[at])
      {
         if (parent && to == parent.value())
         {
            continue;
         }
         if (!visited[to])
         {
            DFS_util(to, at, DFS_util);
            
            // on the callback, propagates low-link values
            low[at] = std::min(low[at], low[to]);

            if (ids[at] < low[to])
            {
               bridges.push_back({at, to});
            }
         }
         else
         {
            // visit an already visit node, which has a chance to have a lower id than current low-link value
            low[at] = std::min(low[at], ids[to]);
         }
      }
   };

   // ---------- Setup ---------- //

   for (const auto& vidx : vertices)
   {
      if (!visited[vidx.first])
      {
         DFS_util(vidx.first, std::nullopt, DFS_util);
      }
   }
   return bridges;
}

template <typename V, typename W>
auto Graph<V,W>::find_articulations() -> setV
{
   // ---------- Setup ---------- //
   unordered_map<V, int> ids;
   unordered_map<V, int> low;
   unordered_map<V, bool> visited;
   setV arts;

   for (const auto& vidx : vertices)
   {
      ids.insert({vidx.first, 0});
      low.insert({vidx.first, 0});
      visited.insert({vidx.first, false});
   }

   int id = 0;

   auto DFS_util = [&](V at, std::optional<V> parent, auto&& DFS_util) -> void
   {
      visited[at] = true;
      low[at] = ids[at] = ++id;

      for (const auto& [to, w] : edges[at])
      {
         if (parent && to == parent.value())
         {
            continue;
         }
         if (!visited[to])
         {
            DFS_util(to, at, DFS_util);
            
            // on the callback, propagates low-link values
            low[at] = std::min(low[at], low[to]);

            if (ids[at] < low[to])
            {
               arts.insert(at);
            }
         }
         else
         {
            // visit an already visit node, which has a chance to have a lower id than current low-link value
            low[at] = std::min(low[at], ids[to]);
         }
      }
   };


   // ---------- Setup ---------- //


   for (const auto& vidx : vertices)
   {
      if (!visited[vidx.first])
      {
         DFS_util(vidx.first, std::nullopt, DFS_util);
      }
   }
   return arts;
}
