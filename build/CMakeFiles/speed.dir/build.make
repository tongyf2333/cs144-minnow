# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
CMAKE_COMMAND = /snap/cmake/1435/bin/cmake

# The command to remove a file.
RM = /snap/cmake/1435/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tongyf/Desktop/minnow

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tongyf/Desktop/minnow/build

# Utility rule file for speed.

# Include any custom commands dependencies for this target.
include CMakeFiles/speed.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/speed.dir/progress.make

CMakeFiles/speed:
	/snap/cmake/1435/bin/ctest --output-on-failure --timeout 12 -R '_speed_test'

CMakeFiles/speed.dir/codegen:
.PHONY : CMakeFiles/speed.dir/codegen

speed: CMakeFiles/speed
speed: CMakeFiles/speed.dir/build.make
.PHONY : speed

# Rule to build all files generated by this target.
CMakeFiles/speed.dir/build: speed
.PHONY : CMakeFiles/speed.dir/build

CMakeFiles/speed.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/speed.dir/cmake_clean.cmake
.PHONY : CMakeFiles/speed.dir/clean

CMakeFiles/speed.dir/depend:
	cd /home/tongyf/Desktop/minnow/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tongyf/Desktop/minnow /home/tongyf/Desktop/minnow /home/tongyf/Desktop/minnow/build /home/tongyf/Desktop/minnow/build /home/tongyf/Desktop/minnow/build/CMakeFiles/speed.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/speed.dir/depend

