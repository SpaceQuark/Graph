#!/bin/bash
set -e

# Check if both CMake binary and source directories are provided
if [ $# -lt 2 ]; then
    echo "Usage: $0 <CMAKE_BINARY_DIR> <CMAKE_SOURCE_DIR>"
    exit 1
fi

CMAKE_BINARY_DIR="$1"
CMAKE_SOURCE_DIR="$2"

echo "Running gcov..."
# Ensure correct quoting for paths with spaces
find "${CMAKE_BINARY_DIR}/CMakeFiles" -name "*.gcda" -exec sh -c 'gcov -o "${CMAKE_BINARY_DIR}/$(dirname "$1")" "$1"' sh {} \;

echo "Capturing coverage data with lcov..."
lcov --capture --directory "${CMAKE_BINARY_DIR}" --output-file coverage.info --ignore-errors inconsistent 

# Filter the captured data *after* capturing
# lcov --remove coverage.info "/usr/include/*" "${CMAKE_SOURCE_DIR}/tests/*" --output-file coverage_filtered.info

echo "Generating HTML coverage report with genhtml..."
genhtml --output-directory coverage coverage_filtered.info --ignore-errors inconsistent #Use filtered info file

echo "Coverage report generated in ${CMAKE_BINARY_DIR}/coverage"