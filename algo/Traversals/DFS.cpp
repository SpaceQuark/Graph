#include "Graph.hpp"

Graph::VertexIds Graph::DFS(const uint64_t& source)
{
    assert(!adj_list.empty() && "Adjacency list is empty!");
    
    vector<bool> visited(vertices.size(), false);
    visited[source] = true;
    VertexIds sequence = {};

    stack<uint64_t> s;
    s.push(source);

    while (!s.empty()) {
        uint64_t top = s.top();
        s.pop();

        sequence.push_back(vertices[top]->id);

        // Push all unvisited neighbors to the stack
        for (const Edge* edge : adj_list[top]) {
            if (edge == nullptr) { continue; }

            uint64_t neighbor = edge->y_id;
            if (!visited[neighbor]) {
                visited[neighbor] = true; // Mark as visited when pushing
                s.push(neighbor);
            }
        }
    }

    return sequence;
}

