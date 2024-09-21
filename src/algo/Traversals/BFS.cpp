#include "Graph.hpp"

VertexIds Graph::BFS(const uint64_t& source)
{
    assert(!adj_list.empty() && "Adjacency list is empty!");
    
    vector<bool> visited(vertices.size(), false);
    visited[source] = true;
    VertexIds sequence = {vertices[source].id};


    queue<uint64_t> q;
    q.push(source);

    while (!q.empty())
    {
        uint64_t front = q.front();
        q.pop();

        // find all adjacent vertices of the top vertex that have not been visited yet, then push it to queue
        for (const auto& neighbor : adj_list[front])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                sequence.push_back(vertices[neighbor].id);
                q.push(neighbor);
            }
        }
    }

    return sequence;
}