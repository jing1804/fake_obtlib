# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zhang/workroom/fake_obtlib/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zhang/workroom/fake_obtlib/src/build

# Include any dependencies generated for this target.
include CMakeFiles/obt_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/obt_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/obt_test.dir/flags.make

CMakeFiles/obt_test.dir/main.cpp.o: CMakeFiles/obt_test.dir/flags.make
CMakeFiles/obt_test.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhang/workroom/fake_obtlib/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/obt_test.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/obt_test.dir/main.cpp.o -c /home/zhang/workroom/fake_obtlib/src/main.cpp

CMakeFiles/obt_test.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/obt_test.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhang/workroom/fake_obtlib/src/main.cpp > CMakeFiles/obt_test.dir/main.cpp.i

CMakeFiles/obt_test.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/obt_test.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhang/workroom/fake_obtlib/src/main.cpp -o CMakeFiles/obt_test.dir/main.cpp.s

CMakeFiles/obt_test.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/obt_test.dir/main.cpp.o.requires

CMakeFiles/obt_test.dir/main.cpp.o.provides: CMakeFiles/obt_test.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/obt_test.dir/build.make CMakeFiles/obt_test.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/obt_test.dir/main.cpp.o.provides

CMakeFiles/obt_test.dir/main.cpp.o.provides.build: CMakeFiles/obt_test.dir/main.cpp.o


# Object files for target obt_test
obt_test_OBJECTS = \
"CMakeFiles/obt_test.dir/main.cpp.o"

# External object files for target obt_test
obt_test_EXTERNAL_OBJECTS =

obt_test: CMakeFiles/obt_test.dir/main.cpp.o
obt_test: CMakeFiles/obt_test.dir/build.make
obt_test: obtlib/libRREService.a
obt_test: CMakeFiles/obt_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zhang/workroom/fake_obtlib/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable obt_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/obt_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/obt_test.dir/build: obt_test

.PHONY : CMakeFiles/obt_test.dir/build

CMakeFiles/obt_test.dir/requires: CMakeFiles/obt_test.dir/main.cpp.o.requires

.PHONY : CMakeFiles/obt_test.dir/requires

CMakeFiles/obt_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/obt_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/obt_test.dir/clean

CMakeFiles/obt_test.dir/depend:
	cd /home/zhang/workroom/fake_obtlib/src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zhang/workroom/fake_obtlib/src /home/zhang/workroom/fake_obtlib/src /home/zhang/workroom/fake_obtlib/src/build /home/zhang/workroom/fake_obtlib/src/build /home/zhang/workroom/fake_obtlib/src/build/CMakeFiles/obt_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/obt_test.dir/depend

