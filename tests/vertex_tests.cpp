#define CATCH_CONFIG_MAIN 
#include "catch_amalgamated.hpp"
#include "vertex.hpp"

TEST_CASE("Vertex", "[Vertex]") {
    Vertex v1("1", Color::Green);
    Vertex v2("2");
    v2.id = 1;
    Vertex v3("4", Color::White);
    v3.id = 2;
    Vertex v4("5");
    v4.id = 1;

    SECTION("Intitialization") {
        REQUIRE(v1.id == 0);
        REQUIRE(string(v1.name.data()) == "1");
        REQUIRE(v1.color == Color::Green);

        REQUIRE(v2.id == 1);
        REQUIRE(string(v2.name.data()) == "2");
        REQUIRE(v2.color == Color::Black);

        REQUIRE(v3.id == 2);
        REQUIRE(string(v3.name.data()) == "4");
        REQUIRE(v3.color == Color::White);
    }
    SECTION("Equality"){
        REQUIRE(v1 != v3);
        REQUIRE(v1 != v2);
        REQUIRE(v2 == v4);

    }
}