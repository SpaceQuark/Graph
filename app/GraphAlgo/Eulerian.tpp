#ifndef EULERIAN_TPP
#define EULERIAN_TPP

/*
Eulerian Path: a path of edges that visites all edges in a graph exactly once
Eulerian Circuit: an eulerian path that starts and ends on the same vertex.

Eulerian Path - UG: Either every vertex has even degree or exactly two vertices have an odd degree
Eulerian Circuit - UG: Every vertex has an even degree

Eulerian Path - DG: At most one vertex has (outdegree - indegree) = 1 and at most one vertex has (indegree - outdegree) = 1
                    and all other vertices have equal in and out degrees
Eulerian Circuit - DG: Every vertex has an equal indegree and outdegree

Hierholzer's Algorithm (Directed graph):
1. Choose a unique vertex as the start
2. DFS and find another vertex with ongoing edges.
3. After completing


*/

template <typename V, typename W>
std::list<V> Graph<V,W>::Eulerian()
{
    // ---------- Setup ---------- //
    std::list<V> path;

    auto inout = in_out_degree();
    unordered_map<V, int> in = inout.first, out = inout.second;


    auto has_eulerian_path = [&]()
    {
        int start_v = 0, end_v = 0;
        for (const auto& [v, idx] : vertices)
        {
            if (abs(out[v] - in[v]) > 1)
            {
                return false;
            }
            else if (out[v] - in[v] == 1)
            {
                ++start_v;
            }
            else if (in[v] - out[v] == 1)
            {
                ++end_v;
            }
        }
        return ((end_v == 0 && start_v == 0) || ((end_v == 1 && start_v == 1)));
    };

    auto find_start_vertex = [&]()
    {
        V start = (vertices.begin())->first;
        for (const auto& [v, idx] : vertices)
        {
            // Unique starting vertex
            if (out[v] - in[v] == 1)
            {
                return v;
            }

            // start at any vertex with an outgoing edge
            if (out[v] > 0)
            {
                start = v;
            }
        }
        return start;
    };

    auto DFS_util = [&](V at, auto&& DFS_util) -> void
    {
        // while the current vertex has outgoing edges
        while (out[at] != 0)
        {
            // Select the next unvisited ongoing edge
            // The out map is used to track whether or not there are still outgoing edges,
            // and index into the adjacency list to select the next outgoing edge
            V next =  edges[at][--out[at]].first;
            DFS_util(next, DFS_util);
        }
        path.push_front(at);
    };


    // ---------- Setup ---------- //
    if (!has_eulerian_path())
    {
        return {};
    }
    
    DFS_util(find_start_vertex(), DFS_util);

    // Return eulerian path if we traversed all the edges. If the graph is disconnected
    // then it is impossible to have an eulerian path


    if (path.size() == numE+1)
    {
        return path;
    }
    return {};

}

#endif