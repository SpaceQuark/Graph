#define CATCH_CONFIG_MAIN 
#include "catch_amalgamated.hpp"
#include "Graph.hpp"

TEST_CASE("Graph", "[Graph]") {
    // Graph g1(true, false, false);
    // Graph g2(false, true, true, vector<Vertex>{{Vertex("w"), Vertex("x"), Vertex("y", Color::White), Vertex("z")}});

    // // Test when the optional vertices is empty
    // SECTION("Intitialization (no optional vertices)") {
    //     // for (const auto& vertex : g1.vertices) {
    //     //     cout << "g1" << endl;
    //     //     vertex.print();
    //     // }
    //     // cout << endl;

    //     // for (const auto& vertex : g2.vertices) {
    //     //     cout << "g2" << endl;
    //     //     vertex.print();
    //     // }
    //     // cout << endl;


    //     REQUIRE(g1[V].empty());  // Should have no vertices
    //     REQUIRE(g1[E].empty());  // Should have no edges
    //     REQUIRE(g1.is_undirected() == true);   
    //     REQUIRE(g1.is_weighted() == false);    
    //     REQUIRE(g1.is_flows() == false);      
    // } 

    // SECTION("Intitialization (with optional vertices)") {
    //     REQUIRE(g2[V].size() == 4); 
    //     REQUIRE(g2[E].empty());    
    //     REQUIRE(g2.is_undirected() == false);   
    //     REQUIRE(g2.is_weighted() == true);    
    //     REQUIRE(g2.is_flows() == true);      

    //     REQUIRE(g2[V][0].id == 0);
    //     REQUIRE(g2[V][1].id == 1);
    //     REQUIRE(g2[V][2].id == 2);
    //     REQUIRE(g2[V][3].id == 3);

    //     REQUIRE(g2[V][0].color == Color::Black);
    //     REQUIRE(g2[V][2].color == Color::White);
    // } 

    // SECTION("Add Vertex"){
    //     // g1.add_vertex(Vertex("o", Color::White));
    //     // g1.add_vertex(Vertex("p", Color::Blue));

    //     // REQUIRE(g1.get_numV() == 2); 
    //     // REQUIRE(g1.vertices[0].id == 0);
    //     // REQUIRE(g1.vertices[0].color == Color::White);
    //     // REQUIRE(g1.vertices[1].color == Color::Blue);
    // }

    // // SECTION("Delete Vertex"){
    // //     // WIP
    // // }



}

// TEST_CASE("Graph constructor initializes correctly with a non-empty vertex list", "[Graph]") {
//     // Test when the optional vertices contains a few vertices
//     std::vector<Vertex> vertices = { Vertex("x"), Vertex(1), Vertex(2) };
//     Graph graph(true, false, false, vertices);

//     REQUIRE(graph.get_numV() == 3);        // There should be 3 vertices
//     // REQUIRE(graph.vertices.size() == 6);  // Constructor adds 3 extra vertices, so 6 in total
//     REQUIRE(graph.vertices[0].id == 0);  // Ensure vertex ids are set correctly