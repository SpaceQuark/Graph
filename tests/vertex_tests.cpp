#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp"
#include "vertex.hpp"
#include <unordered_set>

TEST_CASE("Vertex Construction and Basic Properties", "[vertex]") {
    SECTION("Default Constructor") {
        Vertex v1(1);
        REQUIRE(v1.id == 1);
        REQUIRE(std::string(v1.name.data()) == "");
    }

    SECTION("Constructor with name") {
        Vertex v2(2, std::string("MyVertex")); // Use std::string
        REQUIRE(v2.id == 2);
        REQUIRE(std::string(v2.name.data()) == "MyVertex");
    }

    SECTION("Constructor with long name") {
        std::string longName = "ThisIsAVeryLongNameThatWillBeTruncatedBecauseItExceedsTheFiftyCharacterLimit";
        Vertex v3(3, longName);
        REQUIRE(v3.id == 3);
        REQUIRE(std::string(v3.name.data()).size() == 49); // Check if truncated (Assuming max 50 characters including \0)
        REQUIRE(std::string(v3.name.data()) == longName.substr(0, 49)); // Compare against truncated expected string
    }
}


TEST_CASE("Vertex Equality", "[vertex]") {
    Vertex v1(1);
    Vertex v2(1);
    Vertex v3(2);

    REQUIRE(v1 == v2);
    REQUIRE_FALSE(v1 == v3);
}

TEST_CASE("Vertex Printing", "[vertex]") {
    Vertex v1(1, std::string("TestVertex"));  // Use std::string
    std::stringstream ss;
    ss << v1;
    REQUIRE(ss.str() == "1");
}

// TEST_CASE("ColorVertex Construction and Basic Properties", "[colorvertex]") {
//     SECTION("Default Constructor") {
//         ColorVertex cv1(1);
//         REQUIRE(cv1.id == 1);
//         REQUIRE(std::string(cv1.name.data()) == "");
//         REQUIRE(cv1.color == Color::Black);
//     }

//     SECTION("Constructor with name and color") {
//         ColorVertex cv2(2, std::string("MyColorVertex"), Color::Red);  // Use std::string
//         REQUIRE(cv2.id == 2);
//         REQUIRE(std::string(cv2.name.data()) == "MyColorVertex");
//         REQUIRE(cv2.color == Color::Red);
//     }
//     SECTION("Constructor with long name") {
//          std::string longName = "ThisIsAVeryLongNameThatWillBeTruncatedBecauseItExceedsTheFiftyCharacterLimit";

//         ColorVertex cv3(3, longName, Color::Green);
//         REQUIRE(cv3.id == 3);
//         REQUIRE(std::string(cv3.name.data()).size() == 49);
//           REQUIRE(std::string(cv3.name.data()) == longName.substr(0,49));
//         REQUIRE(cv3.color == Color::Green);
//     }
// }



// TEST_CASE("ColorVertex Printing", "[colorvertex]") {
//     ColorVertex cv1(1, std::string("TestColorVertex"), Color::Blue);  // Use std::string
//     std::stringstream ss;
//     ss << cv1;
//     REQUIRE(ss.str() == "1");
// }

// TEST_CASE("Vertex Hashing", "[vertex][hash]") {
//     Vertex v1(1);
//     Vertex v2(1);
//     Vertex v3(2);

//     std::hash<Vertex> hasher;
//     REQUIRE(hasher(v1) == hasher(v2));
//     REQUIRE(hasher(v1) != hasher(v3));
// }

// TEST_CASE("Vertex in unordered_set", "[vertex][unordered_set]"){
//     Vertex v1(1);
//     Vertex v2(1);
//     Vertex v3(2);
//     std::unordered_set<Vertex> vertices;
//     vertices.insert(v1);
//     vertices.insert(v2);
//     vertices.insert(v3);
    
//     REQUIRE(vertices.size() == 2);

// }

// TEST_CASE("ColorVertex in unordered_set", "[colorvertex][unordered_set]"){
//     ColorVertex cv1(1);
//     ColorVertex cv2(1);
//     ColorVertex cv3(2);
//     std::unordered_set<Vertex> vertices;
//     vertices.insert(cv1);
//     vertices.insert(cv2);
//     vertices.insert(cv3);
    
//     REQUIRE(vertices.size() == 2);

// }