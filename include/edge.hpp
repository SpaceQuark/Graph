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

struct Edge {
    uint64_t x_id;        
    uint64_t y_id;
    double weight;    
    Color color;      
    double flow;     
    double capacity; 

    // Constructor 1: Accepts double for weight, flow, and capacity
    Edge(uint64_t x_id_, uint64_t y_id_, double weight_ = 0.0, Color color_ = Color::Black, double flow_ = 0.0, double capacity_ = 0.0)
        : x_id(x_id_), y_id(y_id_), weight(weight_), color(color_), flow(flow_), capacity(capacity_) {}

    // Edge(const Edge&) = delete;
    // Edge& operator=(const Edge&) = delete;


    // partial comparison
    bool operator==(const Edge& other) const {
        return x_id == other.x_id && y_id == other.y_id; 
    }

    // full comparison
    bool comp(const Edge& other) const{
        return x_id == other.x_id && y_id == other.y_id && weight == other.weight && flow == other.flow && capacity == other.capacity;
    }


    // Print function to display edge information
    friend ostream& operator<<(ostream& os, const Edge& e) {
        os << e.x_id << " -> " << e.y_id;
        return os;
    }

    void print(){
        cout << "Edge from Vertex " << x_id << " to Vertex " << y_id
           << ", Weight: " << weight << ", Color: " << color.to_string()
           << ", Flow: " << flow << ", Capacity: " << capacity << endl;
    }

};

// Hash function for Edge (specialization of std::hash)
namespace std {
    template <>
    struct hash<Edge> {
        size_t operator()(const Edge& e) const {
            size_t h1 = hash<uint64_t>{}(e.x_id); 
            size_t h2 = hash<uint64_t>{}(e.y_id); 
            // size_t h3 = hash<double>{}(e.weight);  
            // size_t h4 = hash<uint8_t>{}(e.color.value);  
            // size_t h5 = hash<double>{}(e.flow);  
            // size_t h6 = hash<double>{}(e.capacity); 

            // // Combine the hashes using XOR and bit-shifting
            return h1 ^ (h2 << 1);
            //  ^ (h3 << 2) ^ (h4 << 3) ^ (h5 << 4) ^ (h6 << 5);
        }
    };
}
#endif // EDGE_HPP
