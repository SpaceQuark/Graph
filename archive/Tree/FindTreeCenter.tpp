#ifndef FINDTREECENTER_HPP
#define FINDTREECENTER_HPP

template <typename V, typename W>
auto find_tree_center() -> vectV
{
    vectV leaves;

    std::vector<size_t> degree(numV, numE);

    for (const auto& [v, idx] : vertices)
    {
        // we found the leafs
        if (vec.size() <= 1)
        {
            leaves.push_back(v);
            degree[v] = 0; 
        }

        
    }

    int processed = leaves.size();

    while (processed < numV)
    {
        vectV newLeaves;
        for (const auto& [v, vec] : edges)
        {
            for (const auto& [adj, w] : edges[v])
            {
                if (--degree[adj] == 1)
                {
                    newLeaves.push_back(adj);
                }
            }
        }

        processed += newLeaves.size();
        leaves = newLeaves;
    }
    
    return leaves;
}


#endif
