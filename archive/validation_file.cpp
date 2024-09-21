/**
      ___           ___         ___           ___           ___                         ___           ___           ___           ___     
     /  /\         /  /\       /  /\         /  /\         /  /\          ___          /__/\         /  /\         /  /\         /__/|    
    /  /:/_       /  /::\     /  /::\       /  /:/        /  /:/_        /  /\         \  \:\       /  /::\       /  /::\       |  |:|    
   /  /:/ /\     /  /:/\:\   /  /:/\:\     /  /:/        /  /:/ /\      /  /::\         \  \:\     /  /:/\:\     /  /:/\:\      |  |:|    
  /  /:/ /::\   /  /:/~/:/  /  /:/~/::\   /  /:/  ___   /  /:/ /:/_    /  /:/\:\    ___  \  \:\   /  /:/~/::\   /  /:/~/:/    __|  |:|    
 /__/:/ /:/\:\ /__/:/ /:/  /__/:/ /:/\:\ /__/:/  /  /\ /__/:/ /:/ /\  /  /:/~/::\  /__/\  \__\:\ /__/:/ /:/\:\ /__/:/ /:/___ /__/\_|:|____
 \  \:\/:/~/:/ \  \:\/:/   \  \:\/:/__\/ \  \:\ /  /:/ \  \:\/:/ /:/ /__/:/ /:/\:\ \  \:\ /  /:/ \  \:\/:/__\/ \  \:\/:::::/ \  \:\/:::::/
  \  \::/ /:/   \  \::/     \  \::/       \  \:\  /:/   \  \::/ /:/  \  \:\/:/__\/  \  \:\  /:/   \  \::/       \  \::/~~~~   \  \::/~~~~ 
   \__\/ /:/     \  \:\      \  \:\        \  \:\/:/     \  \:\/:/    \  \::/        \  \:\/:/     \  \:\        \  \:\        \  \:\     
     /__/:/       \  \:\      \  \:\        \  \::/       \  \::/      \__\/          \  \::/       \  \:\        \  \:\        \  \:\    
     \__\/         \__\/       \__\/         \__\/         \__\/                       \__\/         \__\/         \__\/         \__\/    

**/

#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.cpp"
#else
#define dbg(...)
#define dbgArr(...)
#endif

// using std::erase_if;

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
enum EdgeKey {E};
enum AdjListKey {AL};
enum AdjMatrixKey {AM};


struct Vertex {
    uint64_t id;       
    array<char, 50> name;        
    Color color;      

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

namespace std {
    template <>
    struct hash<Vertex> {
        size_t operator()(const Vertex& v) const {
            return hash<uint64_t>{}(v.id);  
        }
    };
    template <>
    struct hash<Edge> {
        size_t operator()(const Edge& e) const {
            size_t h1 = hash<uint64_t>{}(e.x_id); 
            size_t h2 = hash<uint64_t>{}(e.y_id); 

            return h1 ^ (h2 << 1);
        }
    };
}

using VertexList = vector<Vertex>;
using EdgeSet = unordered_set<Edge>;
using AdjList = vector<unordered_set<uint64_t>>;
using AdjMatrix = vector<vector<bool>>;

class Graph
{
public:
    explicit Graph(size_t num_vertices_ = 0, bool undirected_ = true, bool weighted_ = false, bool flows_ = false)
        : vertices{VertexList{}}, edges{EdgeSet{}}, adj_list{vector<unordered_set<uint64_t>>{}}, adj_matrix{vector<vector<bool>>{}}, undirected{undirected_}, weighted{weighted_}, flows{flows_}
    {
        while (num_vertices_ > 0)
        {
            vertices.emplace_back();
            vertices.back().id = vertices.size()-1;
            cout << "Added " << vertices.back() << endl;
            --num_vertices_;
        }
    }
    // destructor
    virtual ~Graph() = default;

    const VertexList& operator[](VertexKey key) const
    {
        if (key == V) {
            return vertices;
        }
        throw invalid_argument("Invalid key for access");
    }
    const EdgeSet& operator[](EdgeKey key) const
    {
        if (key == E) {
            return edges;
        }
        throw invalid_argument("Invalid key for access");
    }
    const AdjList& operator[](AdjListKey key) const
    {
        if (stale_adj_list){
            static const AdjList empty_adj_list{};
            return empty_adj_list;
        }
        if (key == AL) {
            return adj_list;
        }
        throw invalid_argument("Invalid key for access");
    }
    const AdjMatrix& operator[](AdjMatrixKey key) const
    {
        if (stale_adj_matrix){
            static const AdjMatrix empty_adj_matrix{};
            return empty_adj_matrix;
        }
        if (key == AM) {
            return adj_matrix;
        }
        throw invalid_argument("Invalid key for access");
    }

    bool is_undirected() const
    {
        return undirected;
    }
    bool is_weighted() const
    {
        return weighted;
    }
    bool is_flows() const
    {
        return flows;
    }


    void add_vertex(const uint64_t& v_id, const char* name = "", Color color = Color::Black){
        if (!has_vertex(v_id)){

            vertices.emplace_back(name, color);
            vertices.back().id = vertices.size()-1;
            cout << "Added " << vertices.back() << endl;
        } else{
            cerr << "Vertex " << v_id << " already exists!" << endl;
        }

        this->stale_adj_list = true;
        this->stale_adj_matrix = true;
    }
    void del_vertex(const uint64_t& v_id){
        if (has_vertex(v_id)){
            vertices.erase(vertices.begin()+v_id);
            
            erase_if(edges,
                [&v_id](const Edge& e) {
                    return e.x_id == v_id || e.y_id == v_id;  // Remove edges involving the vertex
                }), edges.end();
            

            for (auto& vertex : vertices) {
                if (vertex.id > v_id) {
                    vertex.id--;  // Decrement ID
                }
            }

            this->stale_adj_list = true;
            this->stale_adj_matrix = true;
        }
        else{
            cout << "Vertex " << v_id << " doesn't exist in this graph!" << endl;
        }
    }

    void add_edge(uint64_t v_id, uint64_t w_id, const double& weight = 0.0, Color color = Color::Black, const double& flow = 0.0, const double& capacity = 0.0){
        if (!has_vertex(v_id)){
            add_vertex(v_id);
            v_id = vertices.size() - 1;
        }

        if (!has_vertex(w_id)){
            add_vertex(w_id);
            w_id = vertices.size() - 1;
        }

        Edge edge(v_id, w_id, weight, color, flow, capacity);

        if (!has_edge(v_id, w_id))
        {
            edges.insert(edge);
            if (undirected){
                Edge swapped_edge(edge.y_id, edge.x_id, edge.weight, edge.color, edge.flow, edge.capacity);
                edges.insert(swapped_edge);
            }
        }
        else
        {
            cerr << "Edge " << edge.x_id << " -> " << edge.y_id << " already exists in the graph." << endl;
        }

        this->stale_adj_list = true;
        this->stale_adj_matrix = true;
    }
    void del_edge(uint64_t v_id, uint64_t w_id){
        if (v_id >= vertices.size() || w_id >= vertices.size()){
            cerr << "Invalid vertices ids." << endl;
            return;
        }

        Edge temp_edge{v_id, w_id};
        auto it = edges.find(temp_edge);
        
        if (it != edges.end()) {
            edges.erase(it);
            cout << "Edge " << v_id << " -> " << w_id << " deleted." << endl;

            if (undirected){
                Edge swapped_temp_edge{w_id, v_id};
                edges.erase(edges.find(swapped_temp_edge));
                cout << "Edge " << w_id << " -> " << v_id << " deleted." << endl;

            }

            this->stale_adj_list = true;
            this->stale_adj_matrix = true;

        } else {
            cerr << "Edge " << v_id << " -> " << w_id << " not found." << endl;
        }
    }

    bool has_vertex(const uint64_t& v_id) const{
        return v_id < vertices.size();
    }
    bool has_edge(const uint64_t& v_id, const uint64_t& w_id) const{
        if (v_id >= vertices.size() || w_id >= vertices.size()){
            return false;
        }

        Edge temp_edge{v_id, w_id};
        return edges.contains(temp_edge);
    }

    void build_adj_list(){
        if (stale_adj_list)
        {
            cout << "Building adjacency list..." << endl;
            for (auto& set : adj_list) {
                set.clear();  // Clear each unordered_set<Edge*> in the vector
            }
            adj_list.clear();  // Clear the vector itself


            size_t n = vertices.size();
            adj_list.resize(n);
            for (const Edge& edge : edges) {
                adj_list[edge.x_id].insert(edge.y_id);  // Add the edge to the adjacency list for vertex x
            }
            stale_adj_list = false;
        }
    }
    void build_adj_matrix(){
        if (stale_adj_matrix)
        {
            cout << "Building adjacency matrix..." << endl;
            size_t n = vertices.size();
            adj_matrix.resize(n);                // Resize outer vector to hold n rows
            for (size_t i = 0; i < n; ++i) {
                adj_matrix[i].resize(n, 0);      // Resize each row to have n columns, initialize with 0
            }

            for (const Edge& edge : edges) {
                adj_matrix[edge.x_id][edge.y_id] = 1;  // Add the edge to the adjacency list for vertex x
            }
            stale_adj_matrix = false;
        }
    }

