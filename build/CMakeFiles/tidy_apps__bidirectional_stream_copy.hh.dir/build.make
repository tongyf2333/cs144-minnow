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

# Utility rule file for tidy_apps__bidirectional_stream_copy.hh.

# Include any custom commands dependencies for this target.
include CMakeFiles/tidy_apps__bidirectional_stream_copy.hh.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/tidy_apps__bidirectional_stream_copy.hh.dir/progress.make

CMakeFiles/tidy_apps__bidirectional_stream_copy.hh:
	clang-tidy --quiet -header-filter=.* -p=/home/tongyf/Desktop/minnow/build /home/tongyf/Desktop/minnow/apps/bidirectional_stream_copy.hh

CMakeFiles/tidy_apps__bidirectional_stream_copy.hh.dir/codegen:
.PHONY : CMakeFiles/tidy_apps__bidirectional_stream_copy.hh.dir/codegen

tidy_apps__bidirectional_stream_copy.hh: CMakeFiles/tidy_apps__bidirectional_stream_copy.hh
tidy_apps__bidirectional_stream_copy.hh: CMakeFiles/tidy_apps__bidirectional_stream_copy.hh.dir/build.make
.PHONY : tidy_apps__bidirectional_stream_copy.hh

# Rule to build all files generated by this target.
CMakeFiles/tidy_apps__bidirectional_stream_copy.hh.dir/build: tidy_apps__bidirectional_stream_copy.hh
.PHONY : CMakeFiles/tidy_apps__bidirectional_stream_copy.hh.dir/build

CMakeFiles/tidy_apps__bidirectional_stream_copy.hh.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tidy_apps__bidirectional_stream_copy.hh.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tidy_apps__bidirectional_stream_copy.hh.dir/clean

CMakeFiles/tidy_apps__bidirectional_stream_copy.hh.dir/depend:
	cd /home/tongyf/Desktop/minnow/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tongyf/Desktop/minnow /home/tongyf/Desktop/minnow /home/tongyf/Desktop/minnow/build /home/tongyf/Desktop/minnow/build /home/tongyf/Desktop/minnow/build/CMakeFiles/tidy_apps__bidirectional_stream_copy.hh.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/tidy_apps__bidirectional_stream_copy.hh.dir/depend

