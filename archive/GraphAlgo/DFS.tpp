#ifndef DFS_TPP
#define DFS_TPP

/*



Time Oomplexity: O(V+E)

*/

template <typename V, typename W>
auto Graph<V,W>::DFS(const V& source) -> vectV
{
    // ---------- Setup ---------- //

    // start by marking all vertices as not visited
    std::unordered_map<V,bool> visited;
    for (const auto& vidx : vertices)
    {
        visited[vidx.first] = false;
    }

    //sequence of vertices that are visited
    vectV seq;

    // create a DFS stack
    std::stack<V> s;

    // ---------- Setup ---------- //


    // algorithm begins: push the source node
    s.push(source);

    while (!s.empty())
    {
        // pop of the top vertex from the stack
        V top = s.top();
        s.pop();

        if (!visited[top])
        {
            visited[top] = true;
            seq.push_back(top);

            // find all adjacent vertices of the top vertex that have not been visited yet, then push it to stack
            for (const auto& adjw : edges[top])
            {
                if (!visited[adjw.first])
                {
                    s.push(adjw.first);
                }
            }
        }
    }

    return seq;
}

#endif