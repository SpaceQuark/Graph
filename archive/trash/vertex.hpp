#ifndef VERTEX_HPP
#define VERTEX_HPP

#include "utils.hpp"

struct Color {
    enum Value : uint8_t{
        Red,
        Green,
        Blue,
        Yellow,
        Black,
        White
    };

    Value value;

    Color(Value v) : value(v) {}

    inline string to_string() const {
        switch (value) {
            case Red: return "Red";
            case Green: return "Green";
            case Blue: return "Blue";
            case Yellow: return "Yellow";
            case Black: return "Black";
            case White: return "White";
            default: return "Unknown";
        }
    }


    bool operator==(const Color& other) const{
        return value == other.value;
    }

    bool operator==(Value other_value) const{
        return value == other_value;
    }
};


enum VertexKey {V};

/*
    Vertex structure representing a node with three key properties:

    - id: A unique identifier for the vertex 
    - color: The color of the vertex (default value of black)
    - name: A fixed-size character array to store the vertex name (default value of )
*/
struct Vertex {
    uint64_t id;       
    array<char, 50> name;        
    Color color;      

    // Constructor
    Vertex(const char* name_ = "", Color color_ = Color::Black) : id(0), color(color_) {
        size_t result = snprintf(name.data(), name.size(), "%s", name_);

        if (result >= name.size()) {
            cerr << "Warning: name truncated to fit into 50 characters." << endl;
        }
    }

    bool operator==(const Vertex& other) const{
        return id == other.id;
    }

    bool comp(const Vertex& other) const{
        return id == other.id && name.data() == other.name.data() && color == other.color;
    }

    // print function to display vertex information
    friend ostream& operator<<(ostream& os, const Vertex& v) {
        os << v.id;
        return os;
    }

    void print(){
        cout << " Vertex ID: " << id << ", Name: " << name.data() << ", Color: " << color.to_string() << endl;
    }
};

namespace std {
    template <>
    struct hash<Vertex> {
        size_t operator()(const Vertex& v) const {
            size_t h1 = hash<uint64_t>{}(v.id);  
            // size_t h2 = hash<string_view>{}(v.name.data());  
            // size_t h3 = hash<uint8_t>{}(v.color.value);  

            // // Combine the hashes using XOR and bit-shifting
            return h1;
            //  ^ (h2 << 1) ^ (h3 << 2);
        }
    };
}

#endif // VERTEX_HPP
