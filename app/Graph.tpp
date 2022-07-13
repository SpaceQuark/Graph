#ifndef GRAPH_TPP
#define GRAPH_TPP

template <typename T, typename W>
Graph<T,W>::Graph(bool digraph, bool weight)
    : vertices{}, edges{}, numV{}, directed{digraph}, weighted{weight} {}

template <typename T, typename W>
Graph<T,W>::Graph(const std::vector<T>& vs, bool digraph, bool weight)
    : edges{}, numV{}, directed{digraph}, weighted{weight} 
{
    for (const auto& ele : vs)
    {
        vertices.insert(ele, numV);
        ++numV;
    }
}

// template <typename T, typename W>
// Graph<T,W>::Graph(const std::vector<T>& vs, const std::vector<std::vector<T>>& es, bool digraph, bool weight)
//     : vertices{vs}, edges{es}, directed{digraph}, weighted{weight} {}

template <typename T, typename W>
void Graph<T,W>::add_vertex(const T& v)
{
    if (!has_vertex(v))
    {
        vertices[v] = numV;
        edges.push_back(std::vector<std::pair<T, W>>());
        ++numV;
    }
    else
    {
        std::cerr << "Vertex already exist in this graph" << '\n';
    }
}

template <typename T, typename W>
void Graph<T,W>::delete_vertex(const T& v)
{
    if (has_vertex(v))
    {
        size_t index = vertices[v];

        auto it = vertices.begin();
        for (std::advance(it, index); it != vertices.end(); ++it)
        {
            --it->second;
        }
       vertices.erase(v);
       edges.erase(edges.begin() + index);
       --numV;
    }
    else
    {
        std::cerr << "Vertex doesn't exist in this graph" << '\n';
    }
}

template <typename T, typename W>
void Graph<T,W>::add_edge(const T& v1, const T& v2)
{
    if (has_vertex(v1) && has_vertex(v2))
    {
        if (!has_edge(v1,v2))
        {
            size_t idx = vertices[v1];
            edges[idx].push_back(std::make_pair(v2, 1));
            if (directed)
            {
                size_t idy = vertices[v2];
                edges[idy].push_back(std::make_pair(v1, 1));
            }
        }
        else
        {
            std::cerr << "An edge already exists" << '\n';
        }
    }
    else
    {
        std::cerr << "One of the provided vertex doesn't exist in this graph" << '\n';
    }
}

template <typename T, typename W>
void Graph<T,W>::add_edge(const T& v1, const T& v2, const W& w)
{
    if (has_vertex(v1) && has_vertex(v2))
    {
        if (!has_edge(v1,v2))
        {
            size_t idx = vertices[v1];
            edges[idx].push_back(std::make_pair(v2, w));
            if (directed)
            {
                size_t idy = vertices[v2];
                edges[idy].push_back(std::make_pair(v1, w));
            }
        }
        else
        {
            std::cerr << "An edge already exists" << '\n';
        }
    }
    else
    {
        std::cerr << "One of the provided vertex doesn't exist in this graph" << '\n';
    }
}

template <typename T, typename W>
void Graph<T,W>::delete_edge(const T& v1, const T& v2)
{
    size_t idx = vertices[v1];
    size_t idy = vertices[v2];
    
    if (has_vertex(v1) && has_vertex(v2))
    {
        edges[idx].erase(std::remove_if(edges[idx].begin(), edges[idx].end(), [&v2](const std::pair<T,W>& ele){return ele.first == v2;}), edges[idx].end());
        
        if (directed)
        {
            edges[idy].erase(std::remove_if(edges[idy].begin(), edges[idy].end(), [&v1](const std::pair<T,W>& ele){return ele.first == v1;}), edges[idx].end());
        }
    }
    else
    {
        std::cerr << "One of the provided vertex doesn't exist in this graph" << '\n';
    }
}

template <typename T, typename W>
bool Graph<T,W>::isDirected() const
{
    return directed;
}

template <typename T, typename W>
bool Graph<T,W>::isWeighted() const
{
    return weighted;
}


template <typename T, typename W>
bool Graph<T,W>::has_vertex(const T& v)
{
    return (vertices.find(v) != vertices.end());
}


template <typename T, typename W>
bool Graph<T,W>::has_edge(const T& v1, const T& v2)
{
    size_t idx = vertices[v1];
    size_t idy = vertices[v2];
    
    if (!directed)
    {
        return (std::find_if(edges[idx].begin(), edges[idx].end(), [&v2](const std::pair<T,W>& ele){return ele.first == v2;}) != edges[idx].end());
    }
    else
    {
        return (std::find_if(edges[idx].begin(), edges[idx].end(), [&v2](const std::pair<T,W>& ele){return ele.first == v2;}) != edges[idx].end())
        && (std::find_if(edges[idy].begin(), edges[idy].end(), [&v1](const std::pair<T,W>& ele){return ele.first == v1;}) != edges[idy].end());
    }

}

template <typename T, typename W>
int Graph<T,W>::degree()
{
    return vertices.size();
}


template <typename T, typename W>
void Graph<T,W>::pV()
{
    for(const auto& ele : vertices)
    {
        std::cout << "Vertex: " << ele.first << "\n";
    // << ' ' << ele.second
    }
    std:: cout << "\n";
}

template <typename T, typename W>
void Graph<T,W>::pL()
{

    for(const auto& [key, idx] : vertices)
    {
        std::cout << "Vertex: " << key << " ";

        for (const auto& [adj, w] : edges[idx])
        {
            std::cout << " -> " << adj << " (weight = " << w << ')'; 
        }
        std::cout << '\n';
    }
    std::cout << "\n";
}

template <typename T, typename W>
void Graph<T,W>::pM()
{
    std::vector<std::vector<W>> matrix(numV, std::vector<W>(numV, 0));
    for (int i = 0; i < numV; ++i)
    {
        for (const auto& [j, w] : edges[i])
        {
            matrix[i][vertices[j]] = w;
        }
    }



    for (int i = 0; i < numV; ++i)
    {
        for (int j = 0; j < numV; ++j)
        {
            std::cout << matrix[i][j] << "  ";
        }
        std::cout << '\n';
    }
}


#endif