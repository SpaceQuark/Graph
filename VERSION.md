# Version 1.0

- Refactored graph architecture for greater flexibility; no longer template-based while retaining full dynamic functionality.
- Utilizes several new C++20 features to enhance performance and code readability
- Replaced previous testing framework with Catch2 for more efficient and modern testing capabilities.
- Thorough testing of algorithm implementations via online judges

# Version 0.22

- Added Kahn's algorithm along with Bipartite checker (network flow)
- Next version will include more graph applications

# Version 0.21

- Added TSP and Eulerian algorithms
- wrote several new googletests for previous algorithms (MST) and for graph object.

# Version 0.2

- Fixed printing of adjacency matrix (row and column headers match corresponding entries)
- Fixed issue of updating indexes after deletion of vertex
- Added Many new algorithms (Bellman-Ford, Floyd-Warshall, Prims, Kruskals, Tarjan SCC, Topological Sort, Connected components, find tree center, SSSP on DAG Bridges and Articulation Points)
- Added a new Union Find data structure (used in Kruskals)
- Updated CMakeList to support googletests
- Wrote several new googletests to check validity of the written algorithms (tpp files)

# Version 0.11

- Updated the member function that allows printing an adjacency list
- Updated keywords for several member functions (isDirected, isWeighted)
- Removed old/unused forward declarations
- Added Dijkstra's Algorithm

# Version 0.1

- Fixed issues relating to directed-ness and weight of a graph
- Added iterative DFS and BFS algorithms

# Version 0.0

- Added basic vertex and edge operations (mutators and accessors)
- Created member print functions
