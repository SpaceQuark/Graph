#include "Graph.hpp"

Graph::VertexIds Graph::BFS(const uint64_t& source)
{
    assert(!adj_list.empty() && "Adjacency list is empty!");
    
    vector<bool> visited(vertices.size(), false);
    visited[source] = true;
    VertexIds sequence = {};

    queue<uint64_t> q;
    q.push(source);

    while (!q.empty()) {
        uint64_t front = q.front();
        q.pop();

        sequence.push_back(vertices[front]->id);

        // find all adjacent vertices of the top vertex that have not been visited yet, then push it to queue
        for (const Edge* edge : adj_list[front]) {
            if (edge == nullptr) { continue; }

            uint64_t neighbor = edge->y_id;
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    return sequence;
}