#ifndef GRAPH_TPP
#define GRAPH_TPP

template <typename V, typename W>
Graph<V,W>::Graph(bool digraph, bool weight)
    : vertices{}, edges{}, numV{}, numE{}, directed{digraph}, weighted{weight} {}

template <typename V, typename W>
Graph<V,W>::Graph(const vectV& vs, bool digraph, bool weight)
    : edges{}, numV{}, numE{}, directed{digraph}, weighted{weight} 
{
    for (const auto& v : vs)
    {
        vertices.insert({v, numV++});
    }
}

template <typename V, typename W>
void Graph<V,W>::add_vertex(const V& v)
{
    if (!has_vertex(v))
    {
        vertices.insert({v, numV++});
        edges[v] = vector<pair<V, W>>();
    }
    else
    {
        std::cerr << "Vertex already exist in this graph" << '\n';
    }
}

template <typename V, typename W>
void Graph<V,W>::del_vertex(const V& v)
{

    if (has_vertex(v))
    {
        // size_t idx = vertices[v];
        vertices.erase(v);
        edges.erase(v);

        // reset ids (indexes)
        numV = 0;
        for (const auto& vidx : vertices)
        {
            vertices[vidx.first] = numV++;
        }

        // remove vertex via erase remove idiom
        for (auto& [from, vec] : edges)
        {
            vec.erase(std::remove_if(vec.begin(), vec.end(), [&v](const pair<V,W>& ele)
            {return ele.first == v;}), vec.end());
        }
        
    }
    else
    {
        std::cerr << "Vertex doesn't exist in this graph" << '\n';
    }
}

template <typename V, typename W>
void Graph<V,W>::add_edge(const V& v1, const V& v2)
{
    if (!has_edge(v1,v2))
    {
        if (!has_vertex(v1))
        {
            vertices.insert({v1, numV++});
            edges[v1] = vector<pair<V, W>>();
        }

        if (!has_vertex(v2))
        {
            vertices.insert({v2, numV++});
            edges[v2] = vector<pair<V, W>>();
        }


        edges[v1].push_back({v2, 1});
        if (!directed)
        {
            edges[v2].push_back({v1, 1});
        }
        
        ++numE;
    }
    else
    {
        std::cerr << "An edge already exists" << '\n';
    }
}

template <typename V, typename W>
void Graph<V,W>::add_edge(const V& v1, const V& v2, const W& w)
{
    if (!has_edge(v1,v2))
    {
        if (!has_vertex(v1))
        {
            vertices.insert({v1, numV++});
            edges[v1] = vector<pair<V, W>>();
        }

        if (!has_vertex(v2))
        {
            vertices.insert({v2, numV++});
            edges[v2] = vector<pair<V, W>>();
        }

        edges[v1].push_back({v2, w});
        if (!directed)
        {
            edges[v2].push_back({v1, w});
        }
        
        ++numE;
    }
    else
    {
        std::cerr << "An edge already exists" << '\n';
    }
}

template <typename V, typename W>
void Graph<V,W>::del_edge(const V& v1, const V& v2)
{
    // remove edge via erase remove idiom
    if (has_vertex(v1) && has_vertex(v2))
    {
        edges[v1].erase(std::remove_if(edges[v1].begin(), edges[v1].end(), [&v2](const pair<V,W>& ele){return ele.first == v2;}), edges[v1].end());
        
        if (!directed)
        {
            edges[v2].erase(std::remove_if(edges[v2].begin(), edges[v2].end(), [&v1](const pair<V,W>& ele){return ele.first == v1;}), edges[v2].end());
        }
        --numE;
    }
    else
    {
        std::cerr << "One of the provided vertex doesn'V exist in this graph" << '\n';
    }
}

template <typename V, typename W>
int Graph<V,W>::total_edges() const
{
    return numE;
}

template <typename V, typename W>
pair<unordered_map<V,int>, unordered_map<V,int>> Graph<V,W>::in_out_degree() const
{
    unordered_map<V,int> in;
    unordered_map<V,int> out;

    for (const auto& vidx : vertices)
    {
        in.insert({vidx.first, 0});
        out.insert({vidx.first, 0});
    }

    for (const auto& [from, vec] : edges)
    {
        for (const auto& [to, w] : vec)
        {
            ++out[from];
            ++in[to];
        }
    }

    return {in, out};
}

template <typename V, typename W>
inline bool Graph<V,W>::is_directed() const
{
    return directed;
}

template <typename V, typename W>
inline bool Graph<V,W>::is_weighted() const
{
    return weighted;
}

template <typename V, typename W>
bool Graph<V,W>::has_vertex(const V& v) const
{
    return (vertices.find(v) != vertices.end());
}

template <typename V, typename W>
bool Graph<V,W>::has_edge(const V& v1, const V& v2) 
{
    if (has_vertex(v1) && has_vertex(v2))
    {
        if (directed)
        {
            return (std::find_if(edges[v1].begin(), edges[v1].end(), [&v2](const pair<V,W>& ele){return ele.first == v2;}) != edges[v1].end());
        }
        else
        {
            return (std::find_if(edges[v1].begin(), edges[v1].end(), [&v2](const pair<V,W>& ele){return ele.first == v2;}) != edges[v1].end())
            && (std::find_if(edges[v2].begin(), edges[v2].end(), [&v1](const pair<V,W>& ele){return ele.first == v1;}) != edges[v2].end());
        }
    }

    return false;
}

template <typename V, typename W>
auto Graph<V,W>::AM() ->matW
{
    matW matrix(numV, vectW(numV, PINF<W>));

    for (const auto& [from, vec] : edges)
    {
        for (const auto& [to, w] : vec)
        {
            size_t idx{ vertices[from] };
            size_t idy{ vertices[to] };
            matrix[idx][idy] = w;
        }
    }

    for (const auto& [v, index] : vertices)
    {
        matrix[index][index] = 0;
    }

    return matrix;
}

template <typename V, typename W>
auto Graph<V,W>::EL() const -> vector<wEdge>
{
    vector<std::tuple<V,V,W>> edgeList{};
    for (const auto& [from, vec] : edges)
    {
        for (const auto& [to, w] : vec)
        {
            edgeList.push_back({from, to, w});
        }
    }
    return edgeList;
}

template <typename V, typename W>
void Graph<V,W>::pV() const
{
    for(const auto& [v, idx] : vertices)
    {
        std::cout << "Vertex: " << v << " id: " << idx  << "\n";
    }
    std:: cout << "\n";
}

template <typename V, typename W>
void Graph<V,W>::pL() const
{
    for(const auto& [from, vec] : edges)
    {
        std::cout << "Vertex: " << from;
        bool point{ true };

        for (const auto& [to, w] : vec)
        {
            if (point)
            {
                std::cout << " -> " << to << " (w = " << w << ')'; 
                point = false;
            }
            else
            {
                std::cout << ", " << to << " (w = " << w << ')'; 
            }
        }
        std::cout << '\n';
    }
    std::cout << "\n";
}

template <typename V, typename W>
void Graph<V,W>::pM()
{
    matW matrix = AM();

    // Create a temporary vector lookup
    vectV lookup(numV);

    for (const auto& [v, idx] : vertices)
    {
        lookup[idx] = v;
    }

    // printing the 2D matrix
    std::cout << std::string(10, ' ' );
    for (const auto& v : lookup)
    {
        std::cout << std::setw(10) << std::left << v;
    }
    std::cout << '\n';
    

    for (int i = 0; i < numV; ++i)
    {
        std::cout << std::setw(10) << std::left << lookup[i];
        for (int j = 0; j < numV; ++j)
        {
            if (matrix[i][j] == PINF<W> || matrix[i][j] == gmax<W>)
            {
                std::cout << std::setw(12) << "\u221E";
            }
            else
            {
               std::cout << std::setw(10) << matrix[i][j];
            }
        }
        std::cout << '\n';
    }
}

template <typename V, typename W>
void Graph<V,W>::pEL() const
{
    for (const auto& [from, to, w] : EL())
    {
        std::cout << "Start: " << from << " End: "<< to << " Weight: " << w << std::endl;
    }
}


#endif