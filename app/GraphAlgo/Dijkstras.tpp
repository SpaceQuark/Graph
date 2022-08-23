#ifndef DIJKSTRAS_TPP
#define DIJKSTRAS_TPP


/*
Ideal for
- medium/large graphs
- best for SSSP on graph with weighted edges
- ok for SP on graph with unweighted edges
- ok for APSP

Lazy implementation of Dijkstras algorithm:
1. Start by maintaining a dist hashmap where distance to every vertex is marked as
   positive infinity. Then mark the source node to be 0
2. Maintain a PQ of key-value pairs (vertex, distance) which tells us which vertex to visit
   based on the root (min distance value)
3. Insert (source, 0) into PQ and loop while PQ is not empty - pull out the next most promising
   (vertex distance) pair.
4. Iterate over all edges outwards from current vertex and relax each edge appending a new 
   (vertex, distance) key-value pair to the PQ for every relaxation

Time Complexity: O((E+V)log(V))
*/
template <typename V, typename W>
unordered_map<V, W> Graph<V,W>::Dijkstras(const V& source)
{
    // ---------- Setup ---------- //

    // create map between adjacent vertex and distance 
    unordered_map<V, W> dist; 
    // create a map between adjacent vertex and bool (visited?)
    unordered_map<V, bool> visited;

    // create a min heap priority queue
    std::priority_queue<pair<V,W>,vector<pair<V, W>>, decltype(minp<V,W>)> pq(minp<V,W>);

    // start with maximum distance between source to all vertices, and label visited vertices as false
    for (const auto& vidx : vertices)
    {
        dist.insert({vidx.first, gmax<W>});
        visited.insert({vidx.first, false});
    }
    
    dist[source] = 0;

    V minVx; // adjacent vertex on top of PQ
    W minVal; // adjacent vertex's weight 
    W newDist; // current distance (sum of weights)

    // ---------- Setup ---------- //

    // insert the source node to kickstart the algorithm
    pq.push(std::make_pair(source, 0));

    

    // while priority queue is not empty, remove the minimum vertex, minVal pair
    while(!pq.empty())
    {
        minVx = pq.top().first;
        minVal = pq.top().second;
        pq.pop();
        // mark node as visited
        visited[minVx] = true;    

        // Optimization: skip vertex where we already found a better path routing through other vertex
        if (dist[minVx] < minVal)
        {
            continue;
        }

        for (const auto& [adj, w] : edges[minVx])
        {
            // skip visited vertex
            if (visited[adj])
            {
                continue;
            }
            // perform edge relaxation operation
            // start by computing distance to new vertex
            newDist = dist[minVx] + w;

            // compare the new distance with the next vertex and update value if it is better
            if (newDist < dist[adj])
            {
                dist[adj] = newDist;

                // Note: we insert a key-value pair in the PQ since it takes O(log(n)) time
                // while searching and updating takes O(n) time.
                pq.push(std::make_pair(adj, newDist));
            }
        }
    }
    return dist;
}

template <typename V, typename W>
unordered_map<V, pair<W, V>> Graph<V,W>::dijkstras_construct(const V& source)
{
    // ---------- Setup ---------- //

    // create in map between adjacent vertex and distance and previous vertex, along with vertex and a boolean (visited?) 
    unordered_map<V, bool> visited;
    unordered_map<V, pair<W, V>> dist_prev;

    // create a min heap
    std::priority_queue<pair<V,W>,vector<pair<V, W>>, decltype(minp<V,W>)> pq(minp<V,W>);

    
    for (const auto& vidx : vertices)
    {
        dist_prev.insert({vidx.first, std::make_pair(gmax<W>, V{})});
        visited.insert({vidx.first, false});
    }
    
    dist_prev[source].first = 0;
    dist_prev[source].second = source;

    V minVx; // adjacent vertex on top of PQ
    W minVal; // adjacent vertex's weight 
    W newDist; // current distance (sum of weights)

    // ---------- Setup ---------- //

    // insert the source node to kickstart the algorithm
    pq.push(std::make_pair(source, 0));

    // while priority queue is not empty, remove the minimum minVx, minVal pair
    while(!pq.empty())
    {
        minVx = pq.top().first;
        minVal = pq.top().second;
        pq.pop();
        // mark node as visited
        visited[minVx] = true;    

        // Optimization: skip vertex where we already found a better path routing through other vertex
        if (dist_prev[minVx].first < minVal)
        {
            continue;
        }

        for (const auto& [adj, w] : edges[minVx])
        {
            // skip visited vertex
            if (visited[adj])
            {
                continue;
            }
            // perform edge relaxation operation
            // start by computing distance to new vertex
            newDist = dist_prev[minVx].first + w;

            // compare the new distance with the next vertex and update value if it is better
            if (newDist < dist_prev[adj].first)
            {
                // Vertex I'm going to came from vertex I'm currently at
                dist_prev[adj].first = newDist;
                dist_prev[adj].second = minVx;
                pq.push(std::make_pair(adj, newDist));
            }
        }
    }
    return dist_prev;
}

template <typename V, typename W>
vector<V> Graph<V,W>::dk_shortest_path(const V& source, const V& end)
{
    // get the vertex and the corresponding 
    unordered_map<V, pair<W, V>> dist_prev = dijkstras_construct(source);
    vector<V> path{};
    
    // source does not reach end
    if (dist_prev[end].first == gmax<W>)
    {
        return path;
    }

    // start from end and make back to the source vertex
    for (V at = end; at != source; at = dist_prev[at].second)
    {
        path.push_back(at);
    }
    path.push_back(source);

    // the path should be in reverse order [source .... end]
    std::reverse(path.begin(), path.end());
    return path;
}

#endif