#ifndef GRAPH_ALGO_TPP
#define GRAPH_ALGO_TPP

template <typename T, typename W>
std::vector<T> Graph<T,W>::DFS(const T& source)
{
    // start by marking all vertices as not visited
    std::unordered_map<T,bool> visited;
    for (const auto& vidx : vertices)
    {
        visited[vidx.first] = false;
    }

    //sequence of vertices that are visited
    std::vector<T> seq;

    // create a DFS stack
    std::stack<T> s;

    // push the source node
    s.push(source);

    while (!s.empty())
    {
        // pop of the top vertex from the stack
        T top = s.top();
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

template <typename T, typename W>
std::vector<T> Graph<T,W>::BFS(const T& source)
{
    // start by marking all vertices as not visited
    std::unordered_map<T,bool> visited;
    for (const auto& vidx : vertices)
    {
        visited[vidx.first] = false;
    }

    //sequence of vertices that are visited
    std::vector<T> seq;

    // create a BFS queue
    std::queue<T> q;
    
    // enqueue the source
    q.push(source);
    while (!q.empty())
    {
        T rear = q.front();
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

template <typename T, typename W>
std::unordered_map<T, size_t> Graph<T,W>::Dijkstras(const T& source)
{
    // create in map between adjacent vertex and distance along with vertex and a boolean (visited?) 
    std::unordered_map<T, size_t> dist;
    std::unordered_map<T, bool> SPT;

    // create a min heap priority queue
    auto cmp = [](const std::pair<T, size_t>& lhs, const std::pair<T, size_t>& rhs)
    {
    return lhs.second > rhs.second;
    };

    std::priority_queue<std::pair<T,size_t>,std::vector<std::pair<T, size_t>>, decltype(cmp)> pq(cmp);

    // start with maximum distance between source to all vertices, and label visited vertices as false
    for (const auto& vidx : vertices)
    {
        dist.insert({vidx.first, SIZE_MAX});
        SPT.insert({vidx.first, false});
    }
    
    dist[source] = 0;

    // insert the source node to kickstart the algorithm
    pq.push(std::make_pair(source, 0));

    T index;
    size_t minVal;
    size_t newDist{};

    // while priority queue is not empty, remove the minimum index, minVal pair
    while(!pq.empty())
    {
        index = pq.top().first;
        minVal = pq.top().second;
        pq.pop();
        // mark node as visited
        SPT[index] = true;    

        // Optimization: skip vertex where we already found a better path routing through other vertex
        if (dist[index] < minVal)
        {
            continue;
        }

        for (const auto& [adj, w] : edges[index])
        {
            // skip visited vertex
            if (SPT[adj])
            {
                continue;
            }
            // perform edge relaxation operation
            // start by computing distance to new vertex
            newDist = dist[index] + w;

            // compare the new distance with the next vertex and update value if it is better
            if (newDist < dist[adj])
            {
                dist[adj] = newDist;
                pq.push(std::make_pair(adj, newDist));
            }
        }
    }
    return dist;
}

template <typename T, typename W>
std::unordered_map<T, size_t> Graph<T,W>::DijkstrasConstruct(const T& source)
{
    // create in map between adjacent vertex and distance, vertex and traveled nodes, along with vertex and a boolean (visited?) 
    std::unordered_map<T, size_t> dist;
    std::unordered_map<T, size_t> prev;
    std::unordered_map<T, bool> SPT;

    // create a min heap
    auto cmp = [](const std::pair<T, size_t>& lhs, const std::pair<T, size_t>& rhs)
    {
    return lhs.second > rhs.second;
    };

    std::priority_queue<std::pair<T,size_t>,std::vector<std::pair<T, size_t>>, decltype(cmp)> pq(cmp);

    
    for (const auto& vidx : vertices)
    {
        dist.insert({vidx.first, SIZE_MAX});
        prev.insert({vidx.first, -1});
        SPT.insert({vidx.first, false});
    }
    
    dist[source] = 0;
    prev[source] = 0;

    // insert the source node to kickstart the algorithm
    pq.push(std::make_pair(source, 0));

    T index;
    size_t minVal;
    size_t newDist{};

    // while priority queue is not empty, remove the minimum index, minVal pair
    while(!pq.empty())
    {
        index = pq.top().first;
        minVal = pq.top().second;
        pq.pop();
        // mark node as visited
        SPT[index] = true;    

        // Optimization: skip vertex where we already found a better path routing through other vertex
        if (dist[index] < minVal)
        {
            continue;
        }

        for (const auto& [adj, w] : edges[index])
        {
            // skip visited vertex
            if (SPT[adj])
            {
                continue;
            }
            // perform edge relaxation operation
            // start by computing distance to new vertex
            
            newDist = dist[index] + w;

            // compare the new distance with the next vertex and update value if it is better
            if (newDist < dist[adj])
            {
                prev[adj] = index;
                dist[adj] = newDist;
                pq.push(std::make_pair(adj, newDist));
            }
        }
    }
    return prev;
}


#endif