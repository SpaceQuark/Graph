#ifndef COMPONENTS_HPP
#define COMPONENTS_HPP

template <typename V, typename W>
auto Graph<V,W>::findComponents() -> std::vector<vectV>
{
    // total number of components
    int count{};
    std::vector<vectV> components;

    std::unordered_map<V,bool> visited;
    for (const auto& vidx : vertices)
    {
        visited[vidx.first] = false;
    }


    auto DFSUtil = [this, &visited](const V& source)
    {
        vectV seq;

        // DFS stack
        std::stack<V> s;
        s.push(source);

        while (!s.empty())
        {
            V top = s.top();
            s.pop();

            if (!visited[top])
            {
                visited[top] = true;
                seq.push_back(top);

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
    };

    for (const auto& vidx : vertices)
    {
        if (!visited[vidx.first])
        {
            ++count;
            vectV component = DFSUtil(vidx.first);
            components.push_back(component);
        }
    }

    return components;
}


#endif
