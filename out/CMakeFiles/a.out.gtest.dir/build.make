# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/quarkz/projects/Graph

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/quarkz/projects/Graph/out

# Include any dependencies generated for this target.
include CMakeFiles/a.out.gtest.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/a.out.gtest.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/a.out.gtest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/a.out.gtest.dir/flags.make

CMakeFiles/a.out.gtest.dir/gtest/APSPTest.cpp.o: CMakeFiles/a.out.gtest.dir/flags.make
CMakeFiles/a.out.gtest.dir/gtest/APSPTest.cpp.o: ../gtest/APSPTest.cpp
CMakeFiles/a.out.gtest.dir/gtest/APSPTest.cpp.o: CMakeFiles/a.out.gtest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/quarkz/projects/Graph/out/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/a.out.gtest.dir/gtest/APSPTest.cpp.o"
	/usr/bin/clang++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/a.out.gtest.dir/gtest/APSPTest.cpp.o -MF CMakeFiles/a.out.gtest.dir/gtest/APSPTest.cpp.o.d -o CMakeFiles/a.out.gtest.dir/gtest/APSPTest.cpp.o -c /home/quarkz/projects/Graph/gtest/APSPTest.cpp

CMakeFiles/a.out.gtest.dir/gtest/APSPTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a.out.gtest.dir/gtest/APSPTest.cpp.i"
	/usr/bin/clang++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/quarkz/projects/Graph/gtest/APSPTest.cpp > CMakeFiles/a.out.gtest.dir/gtest/APSPTest.cpp.i

CMakeFiles/a.out.gtest.dir/gtest/APSPTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a.out.gtest.dir/gtest/APSPTest.cpp.s"
	/usr/bin/clang++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/quarkz/projects/Graph/gtest/APSPTest.cpp -o CMakeFiles/a.out.gtest.dir/gtest/APSPTest.cpp.s

CMakeFiles/a.out.gtest.dir/gtest/BridgesArticulationTest.cpp.o: CMakeFiles/a.out.gtest.dir/flags.make
CMakeFiles/a.out.gtest.dir/gtest/BridgesArticulationTest.cpp.o: ../gtest/BridgesArticulationTest.cpp
CMakeFiles/a.out.gtest.dir/gtest/BridgesArticulationTest.cpp.o: CMakeFiles/a.out.gtest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/quarkz/projects/Graph/out/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/a.out.gtest.dir/gtest/BridgesArticulationTest.cpp.o"
	/usr/bin/clang++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/a.out.gtest.dir/gtest/BridgesArticulationTest.cpp.o -MF CMakeFiles/a.out.gtest.dir/gtest/BridgesArticulationTest.cpp.o.d -o CMakeFiles/a.out.gtest.dir/gtest/BridgesArticulationTest.cpp.o -c /home/quarkz/projects/Graph/gtest/BridgesArticulationTest.cpp

CMakeFiles/a.out.gtest.dir/gtest/BridgesArticulationTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a.out.gtest.dir/gtest/BridgesArticulationTest.cpp.i"
	/usr/bin/clang++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/quarkz/projects/Graph/gtest/BridgesArticulationTest.cpp > CMakeFiles/a.out.gtest.dir/gtest/BridgesArticulationTest.cpp.i

CMakeFiles/a.out.gtest.dir/gtest/BridgesArticulationTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a.out.gtest.dir/gtest/BridgesArticulationTest.cpp.s"
	/usr/bin/clang++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/quarkz/projects/Graph/gtest/BridgesArticulationTest.cpp -o CMakeFiles/a.out.gtest.dir/gtest/BridgesArticulationTest.cpp.s

CMakeFiles/a.out.gtest.dir/gtest/EulerianTest.cpp.o: CMakeFiles/a.out.gtest.dir/flags.make
CMakeFiles/a.out.gtest.dir/gtest/EulerianTest.cpp.o: ../gtest/EulerianTest.cpp
CMakeFiles/a.out.gtest.dir/gtest/EulerianTest.cpp.o: CMakeFiles/a.out.gtest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/quarkz/projects/Graph/out/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/a.out.gtest.dir/gtest/EulerianTest.cpp.o"
	/usr/bin/clang++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/a.out.gtest.dir/gtest/EulerianTest.cpp.o -MF CMakeFiles/a.out.gtest.dir/gtest/EulerianTest.cpp.o.d -o CMakeFiles/a.out.gtest.dir/gtest/EulerianTest.cpp.o -c /home/quarkz/projects/Graph/gtest/EulerianTest.cpp

CMakeFiles/a.out.gtest.dir/gtest/EulerianTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a.out.gtest.dir/gtest/EulerianTest.cpp.i"
	/usr/bin/clang++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/quarkz/projects/Graph/gtest/EulerianTest.cpp > CMakeFiles/a.out.gtest.dir/gtest/EulerianTest.cpp.i

CMakeFiles/a.out.gtest.dir/gtest/EulerianTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a.out.gtest.dir/gtest/EulerianTest.cpp.s"
	/usr/bin/clang++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/quarkz/projects/Graph/gtest/EulerianTest.cpp -o CMakeFiles/a.out.gtest.dir/gtest/EulerianTest.cpp.s

CMakeFiles/a.out.gtest.dir/gtest/ExampleTest.cpp.o: CMakeFiles/a.out.gtest.dir/flags.make
CMakeFiles/a.out.gtest.dir/gtest/ExampleTest.cpp.o: ../gtest/ExampleTest.cpp
CMakeFiles/a.out.gtest.dir/gtest/ExampleTest.cpp.o: CMakeFiles/a.out.gtest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/quarkz/projects/Graph/out/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/a.out.gtest.dir/gtest/ExampleTest.cpp.o"
	/usr/bin/clang++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/a.out.gtest.dir/gtest/ExampleTest.cpp.o -MF CMakeFiles/a.out.gtest.dir/gtest/ExampleTest.cpp.o.d -o CMakeFiles/a.out.gtest.dir/gtest/ExampleTest.cpp.o -c /home/quarkz/projects/Graph/gtest/ExampleTest.cpp

CMakeFiles/a.out.gtest.dir/gtest/ExampleTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a.out.gtest.dir/gtest/ExampleTest.cpp.i"
	/usr/bin/clang++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/quarkz/projects/Graph/gtest/ExampleTest.cpp > CMakeFiles/a.out.gtest.dir/gtest/ExampleTest.cpp.i

CMakeFiles/a.out.gtest.dir/gtest/ExampleTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a.out.gtest.dir/gtest/ExampleTest.cpp.s"
	/usr/bin/clang++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/quarkz/projects/Graph/gtest/ExampleTest.cpp -o CMakeFiles/a.out.gtest.dir/gtest/ExampleTest.cpp.s

CMakeFiles/a.out.gtest.dir/gtest/GraphTest.cpp.o: CMakeFiles/a.out.gtest.dir/flags.make
CMakeFiles/a.out.gtest.dir/gtest/GraphTest.cpp.o: ../gtest/GraphTest.cpp
CMakeFiles/a.out.gtest.dir/gtest/GraphTest.cpp.o: CMakeFiles/a.out.gtest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/quarkz/projects/Graph/out/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/a.out.gtest.dir/gtest/GraphTest.cpp.o"
	/usr/bin/clang++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/a.out.gtest.dir/gtest/GraphTest.cpp.o -MF CMakeFiles/a.out.gtest.dir/gtest/GraphTest.cpp.o.d -o CMakeFiles/a.out.gtest.dir/gtest/GraphTest.cpp.o -c /home/quarkz/projects/Graph/gtest/GraphTest.cpp

CMakeFiles/a.out.gtest.dir/gtest/GraphTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a.out.gtest.dir/gtest/GraphTest.cpp.i"
	/usr/bin/clang++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/quarkz/projects/Graph/gtest/GraphTest.cpp > CMakeFiles/a.out.gtest.dir/gtest/GraphTest.cpp.i

CMakeFiles/a.out.gtest.dir/gtest/GraphTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a.out.gtest.dir/gtest/GraphTest.cpp.s"
	/usr/bin/clang++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/quarkz/projects/Graph/gtest/GraphTest.cpp -o CMakeFiles/a.out.gtest.dir/gtest/GraphTest.cpp.s

CMakeFiles/a.out.gtest.dir/gtest/MSTTest.cpp.o: CMakeFiles/a.out.gtest.dir/flags.make
CMakeFiles/a.out.gtest.dir/gtest/MSTTest.cpp.o: ../gtest/MSTTest.cpp
CMakeFiles/a.out.gtest.dir/gtest/MSTTest.cpp.o: CMakeFiles/a.out.gtest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/quarkz/projects/Graph/out/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/a.out.gtest.dir/gtest/MSTTest.cpp.o"
	/usr/bin/clang++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/a.out.gtest.dir/gtest/MSTTest.cpp.o -MF CMakeFiles/a.out.gtest.dir/gtest/MSTTest.cpp.o.d -o CMakeFiles/a.out.gtest.dir/gtest/MSTTest.cpp.o -c /home/quarkz/projects/Graph/gtest/MSTTest.cpp

CMakeFiles/a.out.gtest.dir/gtest/MSTTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a.out.gtest.dir/gtest/MSTTest.cpp.i"
	/usr/bin/clang++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/quarkz/projects/Graph/gtest/MSTTest.cpp > CMakeFiles/a.out.gtest.dir/gtest/MSTTest.cpp.i

CMakeFiles/a.out.gtest.dir/gtest/MSTTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a.out.gtest.dir/gtest/MSTTest.cpp.s"
	/usr/bin/clang++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/quarkz/projects/Graph/gtest/MSTTest.cpp -o CMakeFiles/a.out.gtest.dir/gtest/MSTTest.cpp.s

CMakeFiles/a.out.gtest.dir/gtest/SSSPTest.cpp.o: CMakeFiles/a.out.gtest.dir/flags.make
CMakeFiles/a.out.gtest.dir/gtest/SSSPTest.cpp.o: ../gtest/SSSPTest.cpp
CMakeFiles/a.out.gtest.dir/gtest/SSSPTest.cpp.o: CMakeFiles/a.out.gtest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/quarkz/projects/Graph/out/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/a.out.gtest.dir/gtest/SSSPTest.cpp.o"
	/usr/bin/clang++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/a.out.gtest.dir/gtest/SSSPTest.cpp.o -MF CMakeFiles/a.out.gtest.dir/gtest/SSSPTest.cpp.o.d -o CMakeFiles/a.out.gtest.dir/gtest/SSSPTest.cpp.o -c /home/quarkz/projects/Graph/gtest/SSSPTest.cpp

CMakeFiles/a.out.gtest.dir/gtest/SSSPTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a.out.gtest.dir/gtest/SSSPTest.cpp.i"
	/usr/bin/clang++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/quarkz/projects/Graph/gtest/SSSPTest.cpp > CMakeFiles/a.out.gtest.dir/gtest/SSSPTest.cpp.i

CMakeFiles/a.out.gtest.dir/gtest/SSSPTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a.out.gtest.dir/gtest/SSSPTest.cpp.s"
	/usr/bin/clang++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/quarkz/projects/Graph/gtest/SSSPTest.cpp -o CMakeFiles/a.out.gtest.dir/gtest/SSSPTest.cpp.s

CMakeFiles/a.out.gtest.dir/gtest/SearchTest.cpp.o: CMakeFiles/a.out.gtest.dir/flags.make
CMakeFiles/a.out.gtest.dir/gtest/SearchTest.cpp.o: ../gtest/SearchTest.cpp
CMakeFiles/a.out.gtest.dir/gtest/SearchTest.cpp.o: CMakeFiles/a.out.gtest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/quarkz/projects/Graph/out/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/a.out.gtest.dir/gtest/SearchTest.cpp.o"
	/usr/bin/clang++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/a.out.gtest.dir/gtest/SearchTest.cpp.o -MF CMakeFiles/a.out.gtest.dir/gtest/SearchTest.cpp.o.d -o CMakeFiles/a.out.gtest.dir/gtest/SearchTest.cpp.o -c /home/quarkz/projects/Graph/gtest/SearchTest.cpp

CMakeFiles/a.out.gtest.dir/gtest/SearchTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a.out.gtest.dir/gtest/SearchTest.cpp.i"
	/usr/bin/clang++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/quarkz/projects/Graph/gtest/SearchTest.cpp > CMakeFiles/a.out.gtest.dir/gtest/SearchTest.cpp.i

CMakeFiles/a.out.gtest.dir/gtest/SearchTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a.out.gtest.dir/gtest/SearchTest.cpp.s"
	/usr/bin/clang++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/quarkz/projects/Graph/gtest/SearchTest.cpp -o CMakeFiles/a.out.gtest.dir/gtest/SearchTest.cpp.s

CMakeFiles/a.out.gtest.dir/gtest/TSPTest.cpp.o: CMakeFiles/a.out.gtest.dir/flags.make
CMakeFiles/a.out.gtest.dir/gtest/TSPTest.cpp.o: ../gtest/TSPTest.cpp
CMakeFiles/a.out.gtest.dir/gtest/TSPTest.cpp.o: CMakeFiles/a.out.gtest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/quarkz/projects/Graph/out/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/a.out.gtest.dir/gtest/TSPTest.cpp.o"
	/usr/bin/clang++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/a.out.gtest.dir/gtest/TSPTest.cpp.o -MF CMakeFiles/a.out.gtest.dir/gtest/TSPTest.cpp.o.d -o CMakeFiles/a.out.gtest.dir/gtest/TSPTest.cpp.o -c /home/quarkz/projects/Graph/gtest/TSPTest.cpp

CMakeFiles/a.out.gtest.dir/gtest/TSPTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a.out.gtest.dir/gtest/TSPTest.cpp.i"
	/usr/bin/clang++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/quarkz/projects/Graph/gtest/TSPTest.cpp > CMakeFiles/a.out.gtest.dir/gtest/TSPTest.cpp.i

CMakeFiles/a.out.gtest.dir/gtest/TSPTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a.out.gtest.dir/gtest/TSPTest.cpp.s"
	/usr/bin/clang++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/quarkz/projects/Graph/gtest/TSPTest.cpp -o CMakeFiles/a.out.gtest.dir/gtest/TSPTest.cpp.s

CMakeFiles/a.out.gtest.dir/gtest/TopSortTest.cpp.o: CMakeFiles/a.out.gtest.dir/flags.make
CMakeFiles/a.out.gtest.dir/gtest/TopSortTest.cpp.o: ../gtest/TopSortTest.cpp
CMakeFiles/a.out.gtest.dir/gtest/TopSortTest.cpp.o: CMakeFiles/a.out.gtest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/quarkz/projects/Graph/out/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/a.out.gtest.dir/gtest/TopSortTest.cpp.o"
	/usr/bin/clang++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/a.out.gtest.dir/gtest/TopSortTest.cpp.o -MF CMakeFiles/a.out.gtest.dir/gtest/TopSortTest.cpp.o.d -o CMakeFiles/a.out.gtest.dir/gtest/TopSortTest.cpp.o -c /home/quarkz/projects/Graph/gtest/TopSortTest.cpp

CMakeFiles/a.out.gtest.dir/gtest/TopSortTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a.out.gtest.dir/gtest/TopSortTest.cpp.i"
	/usr/bin/clang++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/quarkz/projects/Graph/gtest/TopSortTest.cpp > CMakeFiles/a.out.gtest.dir/gtest/TopSortTest.cpp.i

CMakeFiles/a.out.gtest.dir/gtest/TopSortTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a.out.gtest.dir/gtest/TopSortTest.cpp.s"
	/usr/bin/clang++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/quarkz/projects/Graph/gtest/TopSortTest.cpp -o CMakeFiles/a.out.gtest.dir/gtest/TopSortTest.cpp.s

CMakeFiles/a.out.gtest.dir/gtest/gtestmain.cpp.o: CMakeFiles/a.out.gtest.dir/flags.make
CMakeFiles/a.out.gtest.dir/gtest/gtestmain.cpp.o: ../gtest/gtestmain.cpp
CMakeFiles/a.out.gtest.dir/gtest/gtestmain.cpp.o: CMakeFiles/a.out.gtest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/quarkz/projects/Graph/out/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/a.out.gtest.dir/gtest/gtestmain.cpp.o"
	/usr/bin/clang++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/a.out.gtest.dir/gtest/gtestmain.cpp.o -MF CMakeFiles/a.out.gtest.dir/gtest/gtestmain.cpp.o.d -o CMakeFiles/a.out.gtest.dir/gtest/gtestmain.cpp.o -c /home/quarkz/projects/Graph/gtest/gtestmain.cpp

CMakeFiles/a.out.gtest.dir/gtest/gtestmain.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a.out.gtest.dir/gtest/gtestmain.cpp.i"
	/usr/bin/clang++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/quarkz/projects/Graph/gtest/gtestmain.cpp > CMakeFiles/a.out.gtest.dir/gtest/gtestmain.cpp.i

CMakeFiles/a.out.gtest.dir/gtest/gtestmain.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a.out.gtest.dir/gtest/gtestmain.cpp.s"
	/usr/bin/clang++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/quarkz/projects/Graph/gtest/gtestmain.cpp -o CMakeFiles/a.out.gtest.dir/gtest/gtestmain.cpp.s

CMakeFiles/a.out.gtest.dir/app/Support/UnionFind.cpp.o: CMakeFiles/a.out.gtest.dir/flags.make
CMakeFiles/a.out.gtest.dir/app/Support/UnionFind.cpp.o: ../app/Support/UnionFind.cpp
CMakeFiles/a.out.gtest.dir/app/Support/UnionFind.cpp.o: CMakeFiles/a.out.gtest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/quarkz/projects/Graph/out/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/a.out.gtest.dir/app/Support/UnionFind.cpp.o"
	/usr/bin/clang++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/a.out.gtest.dir/app/Support/UnionFind.cpp.o -MF CMakeFiles/a.out.gtest.dir/app/Support/UnionFind.cpp.o.d -o CMakeFiles/a.out.gtest.dir/app/Support/UnionFind.cpp.o -c /home/quarkz/projects/Graph/app/Support/UnionFind.cpp

CMakeFiles/a.out.gtest.dir/app/Support/UnionFind.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a.out.gtest.dir/app/Support/UnionFind.cpp.i"
	/usr/bin/clang++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/quarkz/projects/Graph/app/Support/UnionFind.cpp > CMakeFiles/a.out.gtest.dir/app/Support/UnionFind.cpp.i

CMakeFiles/a.out.gtest.dir/app/Support/UnionFind.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a.out.gtest.dir/app/Support/UnionFind.cpp.s"
	/usr/bin/clang++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/quarkz/projects/Graph/app/Support/UnionFind.cpp -o CMakeFiles/a.out.gtest.dir/app/Support/UnionFind.cpp.s

# Object files for target a.out.gtest
a_out_gtest_OBJECTS = \
"CMakeFiles/a.out.gtest.dir/gtest/APSPTest.cpp.o" \
"CMakeFiles/a.out.gtest.dir/gtest/BridgesArticulationTest.cpp.o" \
"CMakeFiles/a.out.gtest.dir/gtest/EulerianTest.cpp.o" \
"CMakeFiles/a.out.gtest.dir/gtest/ExampleTest.cpp.o" \
"CMakeFiles/a.out.gtest.dir/gtest/GraphTest.cpp.o" \
"CMakeFiles/a.out.gtest.dir/gtest/MSTTest.cpp.o" \
"CMakeFiles/a.out.gtest.dir/gtest/SSSPTest.cpp.o" \
"CMakeFiles/a.out.gtest.dir/gtest/SearchTest.cpp.o" \
"CMakeFiles/a.out.gtest.dir/gtest/TSPTest.cpp.o" \
"CMakeFiles/a.out.gtest.dir/gtest/TopSortTest.cpp.o" \
"CMakeFiles/a.out.gtest.dir/gtest/gtestmain.cpp.o" \
"CMakeFiles/a.out.gtest.dir/app/Support/UnionFind.cpp.o"

# External object files for target a.out.gtest
a_out_gtest_EXTERNAL_OBJECTS =

bin/a.out.gtest: CMakeFiles/a.out.gtest.dir/gtest/APSPTest.cpp.o
bin/a.out.gtest: CMakeFiles/a.out.gtest.dir/gtest/BridgesArticulationTest.cpp.o
bin/a.out.gtest: CMakeFiles/a.out.gtest.dir/gtest/EulerianTest.cpp.o
bin/a.out.gtest: CMakeFiles/a.out.gtest.dir/gtest/ExampleTest.cpp.o
bin/a.out.gtest: CMakeFiles/a.out.gtest.dir/gtest/GraphTest.cpp.o
bin/a.out.gtest: CMakeFiles/a.out.gtest.dir/gtest/MSTTest.cpp.o
bin/a.out.gtest: CMakeFiles/a.out.gtest.dir/gtest/SSSPTest.cpp.o
bin/a.out.gtest: CMakeFiles/a.out.gtest.dir/gtest/SearchTest.cpp.o
bin/a.out.gtest: CMakeFiles/a.out.gtest.dir/gtest/TSPTest.cpp.o
bin/a.out.gtest: CMakeFiles/a.out.gtest.dir/gtest/TopSortTest.cpp.o
bin/a.out.gtest: CMakeFiles/a.out.gtest.dir/gtest/gtestmain.cpp.o
bin/a.out.gtest: CMakeFiles/a.out.gtest.dir/app/Support/UnionFind.cpp.o
bin/a.out.gtest: CMakeFiles/a.out.gtest.dir/build.make
bin/a.out.gtest: /usr/lib/x86_64-linux-gnu/libgtest.a
bin/a.out.gtest: CMakeFiles/a.out.gtest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/quarkz/projects/Graph/out/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Linking CXX executable bin/a.out.gtest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/a.out.gtest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/a.out.gtest.dir/build: bin/a.out.gtest
.PHONY : CMakeFiles/a.out.gtest.dir/build

CMakeFiles/a.out.gtest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/a.out.gtest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/a.out.gtest.dir/clean

CMakeFiles/a.out.gtest.dir/depend:
	cd /home/quarkz/projects/Graph/out && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/quarkz/projects/Graph /home/quarkz/projects/Graph /home/quarkz/projects/Graph/out /home/quarkz/projects/Graph/out /home/quarkz/projects/Graph/out/CMakeFiles/a.out.gtest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/a.out.gtest.dir/depend

