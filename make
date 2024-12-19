#!/bin/bash

# Set the build directory
BUILD_DIR="build"

# Check if the build directory exists
if [ -d "$BUILD_DIR" ]; then
    echo "Navigating to $BUILD_DIR..."
    cd "$BUILD_DIR" || { echo "Failed to enter $BUILD_DIR"; exit 1; }
else
    echo "Build directory $BUILD_DIR does not exist. Please create it first by running cmake."
    exit 1
fi

# Run make
echo "Running make..."
make || { echo "Make failed."; exit 1; }

echo "Make completed successfully."
