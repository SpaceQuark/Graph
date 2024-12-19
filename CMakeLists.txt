# Minimum version of CMake required
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(Vertexium VERSION 2.0)

# Set the C++ standard for the project
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set output directories for binaries and libraries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Include directories where the header files are located
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add all source files
file(GLOB_RECURSE SOURCES "src/*.cpp" "algo/*.cpp")
list(REMOVE_ITEM SOURCES "${CMAKE_SOURCE_DIR}/src/main/main.cpp")

# Add the executable target, which is built from the source files
add_executable(Vertexium ${SOURCES} src/main/main.cpp)

# Optional: Add compile options (warnings)
target_compile_options(Vertexium PRIVATE -Wall -Wextra -Wpedantic -static-libstdc++ -static-libgcc)

# Optional: If you want to link external libraries, such as threading, etc.
# find_package(Threads REQUIRED)
# target_link_libraries(Vertexium PRIVATE Threads::Threads)

# Optional: Add version number
configure_file(include/Config.h.in Config.h)

set(CTEST_OUTPUT_ON_FAILURE TRUE)
set(CTEST_VERBOSE TRUE)
set(CMAKE_CTEST_ARGUMENTS "-V") 


# set(CMAKE_CTEST_ARGUMENTS "--output-on-failure" "--verbose")

find_package(Catch2 REQUIRED)
include(CTest)
include(Catch)

## Gather all test source files
file(GLOB_RECURSE TEST_SOURCES "tests/*.cpp")
message(STATUS "Test sources found: ${TEST_SOURCES}")

# Add the test executable
add_executable(Tests ${TEST_SOURCES} ${SOURCES})

# Enable compiler warnings for tests (optional but recommended)
target_compile_options(Tests PRIVATE -Wall -Wextra -Wpedantic)

# Link the test executable with Catch2
target_link_libraries(Tests PRIVATE Catch2::Catch2)

# Enable testing
enable_testing()

# Discover and register Catch2 tests with CTest
catch_discover_tests(Tests
    REPORTER console
    VERBOSE TRUE
    EXTRA_ARGS "--durations yes"
)

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    # Enable compiler flags for coverage
    target_compile_options(Tests PRIVATE -g --coverage)
    target_link_options(Tests PRIVATE --coverage)

    # Define a custom target for coverage
    add_custom_target(coverage
        COMMAND ${CMAKE_SOURCE_DIR}/generate_coverage.sh ${CMAKE_BINARY_DIR} ${CMAKE_SOURCE_DIR}
        COMMENT "Generating coverage report"
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    )
endif()