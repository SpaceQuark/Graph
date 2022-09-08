# Graph Library

A modern and efficient graph object library
The goal of this project is to provide a lightweight and user-friendly graph library using modern C++ functionalities.

Future versions would include more formal testing, official documentation, C++ 20 concepts, and working GUI.

[![Generic badge](https://img.shields.io/badge/C++-17-blue.svg?style=flat&logo=c%2B%2B)](https://en.cppreference.com/w/cpp/17)
[![Generic badge](https://img.shields.io/badge/CMake-3.16+-blue.svg)](https://cmake.org/cmake/help/latest/release/3.16.html)

## Dependencies
The project requires CLang 14 (https://releases.llvm.org/14.0.0/tools/clang/docs/ReleaseNotes.html) and CMake 3.16 (https://cmake.org/) or more

## How to compile
This libary is header-only. To install first clone this repository with 

```
 $ git clone https://github.com/SpaceQuark/Graph-Library
'''
```



You can then build (compile) and run this project by typing 
'''bash 
./build app
'''
and 
'''bash 
./run app
''' 
in the terminal

## Example Code
Users can easily create a graph object (in the example below, an integral, weighted, undirected graph)

'''C++
#include "Graph.hpp"

int main()
{
    Graph<int, int> g;

    // Adding edges to graph object
    g.add_edge(1,2,5);
    g.add_edge(2,4,10);

    // printing edge list
    g.pEL();

    /* prints
    Start: 1 End: 2 Weight 5
    Start: 2 End: 1 Weight 5
    Start: 2 End: 4 Weight 10
    Start: 4 End: 2 Weight 10
    */
}
'''
