#ifndef GRAPH_TPP
#define GRAPH_TPP


template <typename T, typename W>
Graph<T,W>::Graph(bool digraph, bool weight)
    : vertices{}, edges{}, numV{}, numE{}, directed{digraph}, weighted{weight} {}

template <typename T, typename W>
Graph<T,W>::Graph(const std::vector<T>& vs, bool digraph, bool weight)
    : edges{}, numV{}, numE{}, directed{digraph}, weighted{weight} 
{
    for (const auto& v : vs)
    {
        vertices.insert({v, numV++});
    }
}

template <typename T, typename W>
void Graph<T,W>::add_vertex(const T& v)
{
    if (!has_vertex(v))
    {
        vertices.insert({v, numV++});
        edges[v] = std::vector<std::pair<T, W>>();
    }
    else
    {
        std::cerr << "Vertex already exist in this graph" << '\n';
    }
}

template <typename T, typename W>
void Graph<T,W>::del_vertex(const T& v)
{
    if (has_vertex(v))
    {
       vertices.erase(v);
       edges.erase(v);
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

    if (!has_edge(v1,v2))
    {
        if (!has_vertex(v1))
        {
            vertices.insert({v1, numV++});
            edges[v1] = std::vector<std::pair<T, W>>();
        }

        if (!has_vertex(v2))
        {
            vertices.insert({v2, numV++});
            edges[v2] = std::vector<std::pair<T, W>>();
        }


        edges[v1].push_back(std::make_pair(v2, 1));
        if (!directed)
        {
            edges[v2].push_back(std::make_pair(v1, 1));
        }
    }
    else
    {
        std::cerr << "An edge already exists" << '\n';
    }
}

template <typename T, typename W>
void Graph<T,W>::add_edge(const T& v1, const T& v2, const W& w)
{
    if (!has_edge(v1,v2))
    {
        if (!has_vertex(v1))
        {
            vertices.insert({v1, numV++});
            edges[v1] = std::vector<std::pair<T, W>>();
        }

        if (!has_vertex(v2))
        {
            vertices.insert({v2, numV++});
            edges[v2] = std::vector<std::pair<T, W>>();
        }

        edges[v1].push_back(std::make_pair(v2, w));
        if (!directed)
        {
            edges[v2].push_back(std::make_pair(v1, w));
        }
        
        ++numE;
    }
    else
    {
        std::cerr << "An edge already exists" << '\n';
    }
}

template <typename T, typename W>
void Graph<T,W>::del_edge(const T& v1, const T& v2)
{
    if (has_vertex(v1) && has_vertex(v2))
    {
        edges[v1].erase(std::remove_if(edges[v1].begin(), edges[v1].end(), [&v2](const std::pair<T,W>& ele){return ele.first == v2;}), edges[v1].end());
        
        if (!directed)
        {
            edges[v2].erase(std::remove_if(edges[v2].begin(), edges[v2].end(), [&v1](const std::pair<T,W>& ele){return ele.first == v1;}), edges[v2].end());
        }
        --numE;
    }
    else
    {
        std::cerr << "One of the provided vertex doesn't exist in this graph" << '\n';
    }
}

template <typename T, typename W>
int Graph<T,W>::total_edges() const
{
    return numE;
}

template <typename T, typename W>
int Graph<T,W>::outdegree(const T& v) const
{
    return edges[v].size();
}

template <typename T, typename W>
inline bool Graph<T,W>::isDirected() const
{
    return directed;
}

template <typename T, typename W>
inline bool Graph<T,W>::isWeighted() const
{
    return weighted;
}

template <typename T, typename W>
bool Graph<T,W>::has_vertex(const T& v) const
{
    return (vertices.find(v) != vertices.end());
}

template <typename T, typename W>
bool Graph<T,W>::has_edge(const T& v1, const T& v2) 
{
    if (has_vertex(v1) && has_vertex(v2))
    {
        if (directed)
        {
            return (std::find_if(edges[v1].begin(), edges[v1].end(), [&v2](const std::pair<T,W>& ele){return ele.first == v2;}) != edges[v1].end());
        }
        else
        {
            return (std::find_if(edges[v1].begin(), edges[v1].end(), [&v2](const std::pair<T,W>& ele){return ele.first == v2;}) != edges[v1].end())
            && (std::find_if(edges[v2].begin(), edges[v2].end(), [&v1](const std::pair<T,W>& ele){return ele.first == v1;}) != edges[v2].end());
        }
    }

    return false;
}

template <typename T, typename W>
void Graph<T,W>::pV() const
{
    for(const auto& vidx : vertices)
    {
        std::cout << "Vertex: " << vidx.first << "\n";
    }
    std:: cout << "\n";
}

template <typename T, typename W>
void Graph<T,W>::pL() const
{
    for(const auto& [v, vec] : edges)
    {
        std::cout << "Vertex: " << v;
        bool point{ true };

        for (const auto& [adj, w] : vec)
        {
            if (point)
            {
                std::cout << " -> " << adj << " (w = " << w << ')'; 
                point = false;
            }
            else
            {
                std::cout << ", " << adj << " (w = " << w << ')'; 
            }
        }
        std::cout << '\n';
    }
    std::cout << "\n";
}

template <typename T, typename W>
void Graph<T,W>::pM()
{
    std::vector<std::vector<W>> matrix(numV, std::vector<W>(numV, 0));
    for (const auto& [v, vec] : edges)
    {
        for (const auto& [adj, w] : vec)
        {
            size_t idx{ vertices[v] };
            size_t idy{ vertices[adj] };
            matrix[idx][idy] = w;
        }
    }

    // printing the 2D matrix
    auto it = edges.begin();
    // int adv{};

    std::cout << std::string(10, ' ' );
    for (const auto& vvec : edges)
    {
        std::cout << std::setw(10) << std::left << vvec.first;
    }
    std::cout << '\n';
    

    for (int i = 0; i < numV; ++i)
    {
        std::cout << std::setw(10) << std::left << it->first;
        for (int j = 0; j < numV; ++j)
        {
            std::cout << std::setw(10) << matrix[i][j];
        }
        std::cout << '\n';
        std::advance(it, 1);
    }
}


#endif