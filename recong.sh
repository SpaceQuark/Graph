#!/bin/bash

# Set the build directory
BUILD_DIR="build"

# Check if the build directory exists
if [ -d "$BUILD_DIR" ]; then
    echo "Navigating to the build directory..."
    cd "$BUILD_DIR" || { echo "Failed to enter build directory"; exit 1; }

    # Check if CMakeCache.txt exists
    if [ -f "CMakeCache.txt" ]; then
        echo "Deleting CMakeCache.txt..."
        rm -f "CMakeCache.txt"
    else
        echo "CMakeCache.txt not found. Proceeding..."
    fi

    # Run cmake and make
    echo "Running cmake..."
    cmake .. || { echo "CMake configuration failed"; exit 1; }

    echo "Running make..."
    make || { echo "Build failed"; exit 1; }

    echo "Reconfiguration and build completed successfully!"
else
    echo "Build directory not found. Please create it first or run the rebuild script."
    exit 1
fi
