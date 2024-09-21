#ifndef BFS_TPP
#define BFS_TPP

/*
Ideal for
- large graphs
- best for SP on graph with unweighted edges

Time Complexity: O(V+E)
*/


template <typename V, typename W>
auto Graph<V,W>::BFS(const V& source) -> vectV
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

    // create a BFS queue
    std::queue<V> q;

    // ---------- Setup ---------- //
    
    // algorithm begins: enqueue the source
    q.push(source);
    while (!q.empty())
    {
        V rear = q.front();
        // dequeue the queue
        q.pop();

        if (!visited[rear])
        {
            visited[rear] = true;
            seq.push_back(rear);

            // find all adjacent vertices of the top vertex that have not been visited yet, then push it to queue
            for (const auto& adjw : edges[rear])
            {
                if (!visited[adjw.first])
                {
                    q.push(adjw.first);
                }
            }

        }
    }

    return seq;
}

#endif
