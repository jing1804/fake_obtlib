# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
include client/obtlib/CMakeFiles/RREService.dir/depend.make

# Include the progress variables for this target.
include client/obtlib/CMakeFiles/RREService.dir/progress.make

# Include the compile flags for this target's objects.
include client/obtlib/CMakeFiles/RREService.dir/flags.make

client/obtlib/CMakeFiles/RREService.dir/RREService_api.cpp.o: client/obtlib/CMakeFiles/RREService.dir/flags.make
client/obtlib/CMakeFiles/RREService.dir/RREService_api.cpp.o: ../client/obtlib/RREService_api.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhang/workroom/fake_obtlib/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object client/obtlib/CMakeFiles/RREService.dir/RREService_api.cpp.o"
	cd /home/zhang/workroom/fake_obtlib/src/build/client/obtlib && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RREService.dir/RREService_api.cpp.o -c /home/zhang/workroom/fake_obtlib/src/client/obtlib/RREService_api.cpp

client/obtlib/CMakeFiles/RREService.dir/RREService_api.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RREService.dir/RREService_api.cpp.i"
	cd /home/zhang/workroom/fake_obtlib/src/build/client/obtlib && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhang/workroom/fake_obtlib/src/client/obtlib/RREService_api.cpp > CMakeFiles/RREService.dir/RREService_api.cpp.i

client/obtlib/CMakeFiles/RREService.dir/RREService_api.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RREService.dir/RREService_api.cpp.s"
	cd /home/zhang/workroom/fake_obtlib/src/build/client/obtlib && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhang/workroom/fake_obtlib/src/client/obtlib/RREService_api.cpp -o CMakeFiles/RREService.dir/RREService_api.cpp.s

client/obtlib/CMakeFiles/RREService.dir/RREService_api.cpp.o.requires:

.PHONY : client/obtlib/CMakeFiles/RREService.dir/RREService_api.cpp.o.requires

client/obtlib/CMakeFiles/RREService.dir/RREService_api.cpp.o.provides: client/obtlib/CMakeFiles/RREService.dir/RREService_api.cpp.o.requires
	$(MAKE) -f client/obtlib/CMakeFiles/RREService.dir/build.make client/obtlib/CMakeFiles/RREService.dir/RREService_api.cpp.o.provides.build
.PHONY : client/obtlib/CMakeFiles/RREService.dir/RREService_api.cpp.o.provides

client/obtlib/CMakeFiles/RREService.dir/RREService_api.cpp.o.provides.build: client/obtlib/CMakeFiles/RREService.dir/RREService_api.cpp.o


# Object files for target RREService
RREService_OBJECTS = \
"CMakeFiles/RREService.dir/RREService_api.cpp.o"

# External object files for target RREService
RREService_EXTERNAL_OBJECTS =

client/obtlib/libRREService.a: client/obtlib/CMakeFiles/RREService.dir/RREService_api.cpp.o
client/obtlib/libRREService.a: client/obtlib/CMakeFiles/RREService.dir/build.make
client/obtlib/libRREService.a: client/obtlib/CMakeFiles/RREService.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zhang/workroom/fake_obtlib/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libRREService.a"
	cd /home/zhang/workroom/fake_obtlib/src/build/client/obtlib && $(CMAKE_COMMAND) -P CMakeFiles/RREService.dir/cmake_clean_target.cmake
	cd /home/zhang/workroom/fake_obtlib/src/build/client/obtlib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/RREService.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
client/obtlib/CMakeFiles/RREService.dir/build: client/obtlib/libRREService.a

.PHONY : client/obtlib/CMakeFiles/RREService.dir/build

client/obtlib/CMakeFiles/RREService.dir/requires: client/obtlib/CMakeFiles/RREService.dir/RREService_api.cpp.o.requires

.PHONY : client/obtlib/CMakeFiles/RREService.dir/requires

client/obtlib/CMakeFiles/RREService.dir/clean:
	cd /home/zhang/workroom/fake_obtlib/src/build/client/obtlib && $(CMAKE_COMMAND) -P CMakeFiles/RREService.dir/cmake_clean.cmake
.PHONY : client/obtlib/CMakeFiles/RREService.dir/clean

client/obtlib/CMakeFiles/RREService.dir/depend:
	cd /home/zhang/workroom/fake_obtlib/src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zhang/workroom/fake_obtlib/src /home/zhang/workroom/fake_obtlib/src/client/obtlib /home/zhang/workroom/fake_obtlib/src/build /home/zhang/workroom/fake_obtlib/src/build/client/obtlib /home/zhang/workroom/fake_obtlib/src/build/client/obtlib/CMakeFiles/RREService.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : client/obtlib/CMakeFiles/RREService.dir/depend
