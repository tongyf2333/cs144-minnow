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

# Include any dependencies generated for this target.
include apps/CMakeFiles/webget_sanitized.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include apps/CMakeFiles/webget_sanitized.dir/compiler_depend.make

# Include the progress variables for this target.
include apps/CMakeFiles/webget_sanitized.dir/progress.make

# Include the compile flags for this target's objects.
include apps/CMakeFiles/webget_sanitized.dir/flags.make

apps/CMakeFiles/webget_sanitized.dir/codegen:
.PHONY : apps/CMakeFiles/webget_sanitized.dir/codegen

apps/CMakeFiles/webget_sanitized.dir/webget.cc.o: apps/CMakeFiles/webget_sanitized.dir/flags.make
apps/CMakeFiles/webget_sanitized.dir/webget.cc.o: /home/tongyf/Desktop/minnow/apps/webget.cc
apps/CMakeFiles/webget_sanitized.dir/webget.cc.o: apps/CMakeFiles/webget_sanitized.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/tongyf/Desktop/minnow/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object apps/CMakeFiles/webget_sanitized.dir/webget.cc.o"
	cd /home/tongyf/Desktop/minnow/build/apps && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT apps/CMakeFiles/webget_sanitized.dir/webget.cc.o -MF CMakeFiles/webget_sanitized.dir/webget.cc.o.d -o CMakeFiles/webget_sanitized.dir/webget.cc.o -c /home/tongyf/Desktop/minnow/apps/webget.cc

apps/CMakeFiles/webget_sanitized.dir/webget.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/webget_sanitized.dir/webget.cc.i"
	cd /home/tongyf/Desktop/minnow/build/apps && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tongyf/Desktop/minnow/apps/webget.cc > CMakeFiles/webget_sanitized.dir/webget.cc.i

apps/CMakeFiles/webget_sanitized.dir/webget.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/webget_sanitized.dir/webget.cc.s"
	cd /home/tongyf/Desktop/minnow/build/apps && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tongyf/Desktop/minnow/apps/webget.cc -o CMakeFiles/webget_sanitized.dir/webget.cc.s

# Object files for target webget_sanitized
webget_sanitized_OBJECTS = \
"CMakeFiles/webget_sanitized.dir/webget.cc.o"

# External object files for target webget_sanitized
webget_sanitized_EXTERNAL_OBJECTS =

apps/webget_sanitized: apps/CMakeFiles/webget_sanitized.dir/webget.cc.o
apps/webget_sanitized: apps/CMakeFiles/webget_sanitized.dir/build.make
apps/webget_sanitized: apps/libstream_sanitized.a
apps/webget_sanitized: src/libminnow_sanitized.a
apps/webget_sanitized: util/libutil_sanitized.a
apps/webget_sanitized: apps/CMakeFiles/webget_sanitized.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/tongyf/Desktop/minnow/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable webget_sanitized"
	cd /home/tongyf/Desktop/minnow/build/apps && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/webget_sanitized.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
apps/CMakeFiles/webget_sanitized.dir/build: apps/webget_sanitized
.PHONY : apps/CMakeFiles/webget_sanitized.dir/build

apps/CMakeFiles/webget_sanitized.dir/clean:
	cd /home/tongyf/Desktop/minnow/build/apps && $(CMAKE_COMMAND) -P CMakeFiles/webget_sanitized.dir/cmake_clean.cmake
.PHONY : apps/CMakeFiles/webget_sanitized.dir/clean

apps/CMakeFiles/webget_sanitized.dir/depend:
	cd /home/tongyf/Desktop/minnow/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tongyf/Desktop/minnow /home/tongyf/Desktop/minnow/apps /home/tongyf/Desktop/minnow/build /home/tongyf/Desktop/minnow/build/apps /home/tongyf/Desktop/minnow/build/apps/CMakeFiles/webget_sanitized.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : apps/CMakeFiles/webget_sanitized.dir/depend

