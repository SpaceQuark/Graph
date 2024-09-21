#ifndef TARJANSCC_TPP
#define TARJANSCC_TPP

/*
Tarjan's Strongly Connected Components algorithm

low-link value: of a vertex is the smallest vertex id reachable from that node via DFS

Because of the ramdomness nature of DFS, the low-link values could vary drastically.
Tarjan's SCC maintains an invariant that prevent SCC's to interfere with the low link
values of other SCCs

------------------------- Stack Invariant -------------------------
Vertices are added to stack (set) of valid vertices as they are explored fro the first time
Vertices are removed from the stack (set) each time a complete SCC is found

1. Mark the id of each vertex as unvisited
2. Begin DFS. Upon visiting a vertex assign it an id and low-link value
   Mark the current vertices as onStack and add them to a stack
3. On DFS callback, if the previous vertex is on the stack, then the "min"
   the current vertex's low-link value with the last vertex's low link value.
   This alls the low-link values to propagate through the cycles.
4. After visiting all neighbors, if the current vertex started a connected component
   (id = low-link value), then pop vertex off stack until current vertex is reached
   

*/

template <typename V, typename W>
pair<unordered_map<V, int>, int> Graph<V,W>::TarjanSCC()
{
   int UNVISITED = -1;
   int id{};
   int sccCount{};

   unordered_map<V, int> ids;
   unordered_map<V, int> low;
   unordered_map<V, int> sccs;
   unordered_map<V, bool> onStack;
   std::stack<V> stk;

   for (const auto& vidx : vertices)
   {
      ids.insert({vidx.first, UNVISITED});
      low.insert({vidx.first, 0});
      sccs.insert({vidx.first, 0});
      onStack.insert({vidx.first, false});
   }

   
   auto DFSSCC = [&](V at, auto&& DFSSCC) -> void
   {
      ids[at] = low[at] = id++;
      stk.push(at);
      onStack[at] = true;


      // visit all neighbors and min low-link values on the callback
      for (const auto& [to, w] : edges[at])
      {
         if (ids[to] == UNVISITED)
         {
            DFSSCC(to, DFSSCC);
         }
         if (onStack[to])
         {
            low[at] = min(low[at], low[to]);
         }
      }
      
      // During recursive callback, if we return to the root node (start of SCC)
      // we empty the seen stack until we are back to the root.
      if(ids[at] == low[at])
      {
         for (V top = stk.top(); ; top = stk.top())
         {
            stk.pop();
            onStack[top] = false;
            sccs[top] = sccCount;
            if (top == at)
            {
               break;
            }
         }
         ++sccCount;
      }
   }; 


   for (const auto& vidx : vertices)
   {
      if (ids[vidx.first] == UNVISITED)
      {
         DFSSCC(vidx.first, DFSSCC);
      }
   }

   return {sccs, sccCount};
}



#endif
