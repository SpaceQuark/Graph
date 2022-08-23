#ifndef TRAVELLINGSALESMAN_TPP
#define TRAVELLINGSALESMAN_TPP

/*
Travelling Salesman Problem (TSP)

Hamiltonian cycle (path that visites every node once) 

We want to find the hamiltonian cycle of minimum cost.
Note: finding optimal solution is extremely hard (NP complete)

DP improves TSP from O(n!) to O(n^2*2^n)

1. start by choosing a starting node
2. Compute and store the optimal value from S to each node
   This will solve TSp problem for all paths of length n = 2

3. To computer for paths of length 3, we need to store
   set of visited nodes in the subpath, and index of last visited
   node in the path

There are N possible vertices that we could ahve visited last and 2^N
subsets of visited vertices. Therefore, the space necessary to store the answer 
for each subproblem is bounded by O(N*2^N)

In Progress....

*/


#endif
