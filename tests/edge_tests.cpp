#define CATCH_CONFIG_MAIN 
#include "catch_amalgamated.hpp"
#include "vertex.hpp"
#include "edge.hpp"
#include <variant>

TEST_CASE("Edge", "[Edge]") {
    // Vertex v1("1", Color::Green);
    // Vertex v2("2", Color::Red);
    // v2.id = 5;
    // Vertex v3("3", Color::Blue);
    // v3.id = 10;

    // Edge e1(&v1, &v2, 100.8, Color::Yellow, 50.0, 200.5);
    // Edge e2(&v1, &v3, 105.5, Color::Black, 30.2, 150.7);
    // Edge e3(&v1, &v2, 10.8, Color::Green, 50.0, 250.0);
    // Edge e4(&v1, &v2, 100.8, Color::Yellow, 50.0, 200.5);

    // SECTION("Intitialization") {
    //     REQUIRE(e1.x == &v1);
    //     REQUIRE(e1.y == &v2);
    //     REQUIRE(e1.weight == 100.8);
    //     REQUIRE(e1.color == Color::Yellow);
    //     REQUIRE(e1.flow == 50.0);
    //     REQUIRE(e1.capacity == 200.5);

    //     REQUIRE(e2.x == &v1);
    //     REQUIRE(e2.y == &v3);
    //     REQUIRE(e2.weight == 105.5);
    //     REQUIRE(e2.color == Color::Black);
    //     REQUIRE(e2.flow == 30.2);
    //     REQUIRE(e2.capacity == 150.7);
    // }

    // SECTION("Equality"){
    //     REQUIRE(!e1.comp(e2));   
    //     REQUIRE(!e1.comp(e3));  
    //     REQUIRE(e1.comp(e4)); 

    //     REQUIRE(e1 != e2);   
    //     REQUIRE(e1 == e3);  
    //     REQUIRE(e1 == e4); 
    // }

}
