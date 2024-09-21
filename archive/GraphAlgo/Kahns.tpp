#ifndef KAHNS_TPP
#define KAHNS_TPP

template <typename V, typename W>
auto Graph<V,W>::Kahns() -> vectV
{
    auto inout = in_out_degree();
    unordered_map<V,int> in = inout.first;
    vectV order(numV);

    std::queue<V> q;
    for (const auto& v: in)
    {
        if (in[v] == 0)
        {
            q.push(v);
        }
    }

    int idx = 0;
    while (!q.empty())
    {
        V at = q.front();
        order[idx++] = at;
        for (const auto& adjw: edges[at])
        {
            in[adjw.first]--;
            if (in[adjw.first] == 0)
            {
                q.push(adjw.first);
            } 
        }
    }
    
    return (idx == numV-1 ? vectV() : order); 

}
#endif
