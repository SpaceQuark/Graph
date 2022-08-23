#include "Support/UnionFind.hpp"

UnionFind::UnionFind(int size)
{
    numComponents = numE = size;
    sz.resize(size);
    id.resize(size);
    for (int i = 0; i < size; ++i)
    {
        sz[i] = 1; // each compnent has a size of one
        id[i] = i;
    }
}

int UnionFind::find(int p)
{
    // Find the root of the component
    int root = p; 
    while (root != id[root])
    {
        root = id[root];
    }

    // Path compression: compress the path leading back to the root
    // This gives the amortized time complexity
    while (p != root)
    {
        // swap id[p] and root
        int next = id[p];
        id[p] = root;
        p = next;
    }

    return root;
}

void UnionFind::unify(int p, int q)
{
    // Elements are already in the same group
    if (connected(p, q))
    {
        return;
    }

    int root1 = find(p);
    int root2 = find(q);

    // Merge smaller component set into the larger one
    if (root1 == root2)
    {
        return;
    }
    if (sz[root1] < sz[root2]) 
    {
        sz[root2] += sz[root1];
        id[root1] = root2;
    } else {
        sz[root1] += sz[root2];
        id[root2] = root1;
    }

    --numComponents;
}

bool UnionFind::connected(int p, int q)
{
    return find(p) == find(q);
}

int UnionFind::component_size(int p)
{
    return sz[find(p)];
}

int UnionFind::size()
{
    return numE;
}

int UnionFind::components()
{
    return numComponents;
}