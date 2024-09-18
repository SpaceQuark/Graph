#include "Graph.hpp"

VertexList Graph::DFS(const uint64_t& source)
{
    assert(!adj_list.empty() && "Adjacency list is empty!");
    
    vector<bool> visited(vertices.size(), false);
    visited[source] = true;
    VertexList sequence = {vertices[source]};


    stack<uint64_t> s;
    s.push(source);

    while (!s.empty())
    {
        uint64_t top = s.top();
        s.pop();

        // find all adjacent vertices of the top vertex that have not been visited yet, then push it to queue
        for (const auto& neighbor : adj_list[top])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                sequence.push_back(vertices[neighbor]);
                s.push(neighbor);
            }
        }
    }

    return sequence;
}