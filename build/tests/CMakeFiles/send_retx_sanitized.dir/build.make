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
include tests/CMakeFiles/send_retx_sanitized.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tests/CMakeFiles/send_retx_sanitized.dir/compiler_depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/send_retx_sanitized.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/send_retx_sanitized.dir/flags.make

tests/CMakeFiles/send_retx_sanitized.dir/codegen:
.PHONY : tests/CMakeFiles/send_retx_sanitized.dir/codegen

tests/CMakeFiles/send_retx_sanitized.dir/send_retx.cc.o: tests/CMakeFiles/send_retx_sanitized.dir/flags.make
tests/CMakeFiles/send_retx_sanitized.dir/send_retx.cc.o: /home/tongyf/Desktop/minnow/tests/send_retx.cc
tests/CMakeFiles/send_retx_sanitized.dir/send_retx.cc.o: tests/CMakeFiles/send_retx_sanitized.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/tongyf/Desktop/minnow/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/send_retx_sanitized.dir/send_retx.cc.o"
	cd /home/tongyf/Desktop/minnow/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tests/CMakeFiles/send_retx_sanitized.dir/send_retx.cc.o -MF CMakeFiles/send_retx_sanitized.dir/send_retx.cc.o.d -o CMakeFiles/send_retx_sanitized.dir/send_retx.cc.o -c /home/tongyf/Desktop/minnow/tests/send_retx.cc

tests/CMakeFiles/send_retx_sanitized.dir/send_retx.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/send_retx_sanitized.dir/send_retx.cc.i"
	cd /home/tongyf/Desktop/minnow/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tongyf/Desktop/minnow/tests/send_retx.cc > CMakeFiles/send_retx_sanitized.dir/send_retx.cc.i

tests/CMakeFiles/send_retx_sanitized.dir/send_retx.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/send_retx_sanitized.dir/send_retx.cc.s"
	cd /home/tongyf/Desktop/minnow/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tongyf/Desktop/minnow/tests/send_retx.cc -o CMakeFiles/send_retx_sanitized.dir/send_retx.cc.s

# Object files for target send_retx_sanitized
send_retx_sanitized_OBJECTS = \
"CMakeFiles/send_retx_sanitized.dir/send_retx.cc.o"

# External object files for target send_retx_sanitized
send_retx_sanitized_EXTERNAL_OBJECTS =

tests/send_retx_sanitized: tests/CMakeFiles/send_retx_sanitized.dir/send_retx.cc.o
tests/send_retx_sanitized: tests/CMakeFiles/send_retx_sanitized.dir/build.make
tests/send_retx_sanitized: tests/libminnow_testing_sanitized.a
tests/send_retx_sanitized: src/libminnow_sanitized.a
tests/send_retx_sanitized: util/libutil_sanitized.a
tests/send_retx_sanitized: tests/CMakeFiles/send_retx_sanitized.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/tongyf/Desktop/minnow/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable send_retx_sanitized"
	cd /home/tongyf/Desktop/minnow/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/send_retx_sanitized.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/send_retx_sanitized.dir/build: tests/send_retx_sanitized
.PHONY : tests/CMakeFiles/send_retx_sanitized.dir/build

tests/CMakeFiles/send_retx_sanitized.dir/clean:
	cd /home/tongyf/Desktop/minnow/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/send_retx_sanitized.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/send_retx_sanitized.dir/clean

tests/CMakeFiles/send_retx_sanitized.dir/depend:
	cd /home/tongyf/Desktop/minnow/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tongyf/Desktop/minnow /home/tongyf/Desktop/minnow/tests /home/tongyf/Desktop/minnow/build /home/tongyf/Desktop/minnow/build/tests /home/tongyf/Desktop/minnow/build/tests/CMakeFiles/send_retx_sanitized.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : tests/CMakeFiles/send_retx_sanitized.dir/depend

