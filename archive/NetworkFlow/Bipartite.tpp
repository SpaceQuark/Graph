#ifndef BIPARTITE_TPP
#define BIPARTITE_TPP

/*
Checks whether the graph is bipartite or not 
*/

template <typename V, typename W>
bool Graph<V,W>::Bipartite()
{
    static constexpr int RED = 0b1; // BLACK = RED ^ 1
    if (numV <= 1)
    {
        return false;
    }

    unordered_map<V, int> colors; 


    auto color_graph = [&](V i, int color, auto color_graph) -> int
    {
        colors[i] = color;

        // Toggles the color between RED and BLACK by flipping LSD
        int nextColor = (color ^ 1);

        int visitCount = 1;
  

        for (const auto& [to, w] : edges[i]) {
            // Contradiction - In a bipartite graph no two
            // nodes of the same color can be next to each other
            if (colors[to] == color)
            {
                return -1;
            } 
            if (colors[to] == nextColor)
            {
                continue;
            }

            // If there is a contradiction propagate and return -1
            // otherwise keep track of the number of visited nodes.
            int count = colorGraph(to, nextColor, color_graph);
            if (count == -1)
            {
                return -1;
            }
            visitCount += count;
        }

        return visitCount;
    };

    int total_visited = color_graph(0, RED);
    return total_visited = numV;

}

#endif
