#ifndef UNIONFIND_HPP
#define UNIONFIND_HPP

#include "utils.hpp"

struct UnionFind
{
    UnionFind(uint64_t size_ = 0)
	: numComponents{size_}{
		sizes.resize(size_);
    	ids.resize(size_);

		for (uint64_t i = 0; i < size_; ++i) {
			sizes[i] = 1; // each compnent has a size of one
			ids[i] = i;
		}
	}

    uint64_t find(uint64_t p){
		uint64_t root = p; 
		while (root != ids[root]) {
			root = ids[root];
		}

		// Path compression: compress the path leading back to the root
		while (p != root){
			uint64_t next = ids[p];
			ids[p] = root;
			p = next;
		}

		return root;
	}
	
    void unify(uint64_t p, uint64_t q){
		if (connected(p, q)) {
			return;
		}

		uint64_t root1 = find(p);
		uint64_t root2 = find(q);

		if (root1 == root2)	{
			return;
		}
		if (sizes[root1] < sizes[root2]) 	{
			sizes[root2] += sizes[root1];
			ids[root1] = root2;
		} else {
			sizes[root1] += sizes[root2];
			ids[root2] = root1;
		}

		--numComponents;
	}

    bool connected(uint64_t p, uint64_t q){ return find(p) == find(q); }
    uint64_t component_size(uint64_t p) {return sizes[find(p)];}

    uint64_t size(){ return numE; }
    uint64_t components(){ return numComponents; }


// private:
    uint64_t numE; // number of elements
    uint64_t numComponents; // number of components
    vector<uint64_t> sizes;
    vector<uint64_t> ids;
};

#endif
