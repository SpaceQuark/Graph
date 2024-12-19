#ifndef EDGE_HPP
#define EDGE_HPP

#include "utils.hpp"
#include "vertex.hpp" // Assuming vertex.hpp is included for Vertex definition

enum EdgeKey {E};

/*
  Edge structure representing a connection between two vertices with the following properties:

  - x: The starting vertex of the edge.
  - y: The ending vertex of the edge.
  - undirected: whether the edge is undirected or not (default value of true)
  - weight: The weight of the edge (default value of 0).
  - color: The color of the edge, represented by an enum Color (default value of Black).
  - flow: The current flow on the edge (default value of 0).
  - capacity: The maximum capacity of the edge (default value of 0).
*/

using std::decay_t;
using std::enable_if_t;
using std::is_same_v;


// template <typename T = int64_t>
struct Edge {

    // static_assert(std::is_arithmetic<T>::value, "Template parameter T must be a numeric type.");

    uint64_t x_id;        
    uint64_t y_id;
    Color color;  
    int64_t weight;        
    int64_t flow;     
    int64_t capacity; 
    
    // Constructor: Accepts T for weight, flow, and capacity
    // Edge(uint64_t x_id_, uint64_t y_id_, T weight_ = 0, Color color_ = Color::Black, T flow_ = 0, T capacity_ = 0)
    //     : x_id(x_id_), y_id(y_id_), weight(weight_), color(color_), flow(flow_), capacity(capacity_) {}

    Edge(uint64_t x_id_, uint64_t y_id_, int64_t weight_, Color color_ = Color::Black, int64_t flow_ = 0, int64_t capacity_ = 0)
        // requires std::same_as<T, int64_t>
        : x_id(x_id_), y_id(y_id_), weight(weight_), color(color_), flow(flow_), capacity(capacity_) {}


    // Partial comparison: compares only x_id and y_id
    bool operator==(const Edge& other) const {
        return x_id == other.x_id && y_id == other.y_id; 
    }

    // Print function to display edge information
    friend std::ostream& operator<<(std::ostream& os, const Edge& e) {
        os << e.x_id << " -> " << e.y_id;
        return os;
    }

    virtual void print() const {
        std::cout << "Edge from Vertex " << x_id << " to Vertex " << y_id
                  << ", Weight: " << weight
                  << ", Color: " << to_string(color)
                  << ", Flow: " << flow
                  << ", Capacity: " << capacity << std::endl;
    }
};

// Hash function for Edge (specialization of std::hash)
namespace std {
    template <typename T>
    struct hash<Edge<T>> {
        size_t operator()(const Edge<T>& e) const {
            size_t seed = hash<uint64_t>{}(e.x_id);
            seed ^= hash<uint64_t>{}(e.y_id) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            return seed;
        }
    };
}
#endif // EDGE_HPP
