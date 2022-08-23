#ifndef UNIONFIND_HPP
#define UNIONFIND_HPP

#include <vector>
#include <iostream>
using std::vector;

class UnionFind
{
public:
    UnionFind(int size = 0);

    int find(int p);
    void unify(int p, int q);

    bool connected(int p, int q);
    int component_size(int p);

    int size();
    int components();


// private:
    int numE; // number of elements
    int numComponents; // number of components
    vector<int> sz;
    vector<int> id;
};

#endif
