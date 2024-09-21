#ifndef EDGE_HPP
#define EDGE_HPP

#include "vertex.hpp" // Assuming vertex.hpp is included for Vertex definition
#include <variant>
#include <type_traits> // For std::decay_t

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
using num_type = std::variant<int64_t, double>;

struct Edge {
    Vertex* x;        
    Vertex* y;
    num_type weight;    
    Color color;      
    num_type flow;     
    num_type capacity; 

    // Constructor 1: Accepts int64_t for weight, flow, and capacity
    Edge(Vertex* x_, Vertex* y_, int64_t weight_ = 0, Color color_ = Color::Black, int64_t flow_ = 0, int64_t capacity_ = 0)
        : x(x_), y(y_), weight(weight_), color(color_), flow(flow_), capacity(capacity_) {}

    // Constructor 2: Accepts double for weight, flow, and capacity
    Edge(Vertex* x_, Vertex* y_, double weight_ = 0.0, Color color_ = Color::Black, double flow_ = 0.0, double capacity_ = 0.0)
        : x(x_), y(y_), weight(weight_), color(color_), flow(flow_), capacity(capacity_) {}

    // Edge(const Edge&) = delete;
    // Edge& operator=(const Edge&) = delete;


    bool operator==(const Edge& other) const {
        return (*x == *other.x && *y == *other.y);
    
    }
    // Print function to display edge information
    void print() const {
        cout << "Edge from Vertex " << x->id << " to Vertex " << y->id
             << ", Weight: ";
             visit([](const auto& arg) { cout << arg; }, weight);
             cout << ", Color: " << color.to_string()
             << ", Flow: ";
             visit([](const auto& arg) { cout << arg; }, flow);
             cout << ", Capacity: ";
             visit([](const auto& arg) { cout << arg; }, capacity);
             cout << endl;
    }

};

inline size_t hash_variant(const num_type& var) {
    return visit([](auto&& arg) -> size_t {
        return hash<decay_t<decltype(arg)>>{}(arg);  // Hash either int64_t or double
    }, var);
}

// Hash function for Edge (specialization of std::hash)
namespace std {
    template <>
    struct hash<Edge> {
        size_t operator()(const Edge& e) const {
            size_t h1 = hash<Vertex*>{}(e.x); 
            size_t h2 = hash<Vertex*>{}(e.y); 
            size_t h3 = hash_variant(e.weight);  
            size_t h4 = hash<uint8_t>{}(e.color.value);  
            size_t h5 = hash_variant(e.flow);  
            size_t h6 = hash_variant(e.capacity); 

            // Combine the hashes using XOR and bit-shifting
            return h1 ^ (h2 << 1) ^ (h3 << 2) ^ (h4 << 3) ^ (h5 << 4) ^ (h6 << 5);
        }
    };
}
#endif // EDGE_HPP
