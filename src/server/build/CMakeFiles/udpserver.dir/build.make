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
CMAKE_SOURCE_DIR = /home/zhang/workroom/fake_obtlib/src/server

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zhang/workroom/fake_obtlib/src/server/build

# Include any dependencies generated for this target.
include CMakeFiles/udpserver.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/udpserver.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/udpserver.dir/flags.make

CMakeFiles/udpserver.dir/main.cpp.o: CMakeFiles/udpserver.dir/flags.make
CMakeFiles/udpserver.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhang/workroom/fake_obtlib/src/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/udpserver.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/udpserver.dir/main.cpp.o -c /home/zhang/workroom/fake_obtlib/src/server/main.cpp

CMakeFiles/udpserver.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/udpserver.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhang/workroom/fake_obtlib/src/server/main.cpp > CMakeFiles/udpserver.dir/main.cpp.i

CMakeFiles/udpserver.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/udpserver.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhang/workroom/fake_obtlib/src/server/main.cpp -o CMakeFiles/udpserver.dir/main.cpp.s

CMakeFiles/udpserver.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/udpserver.dir/main.cpp.o.requires

CMakeFiles/udpserver.dir/main.cpp.o.provides: CMakeFiles/udpserver.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/udpserver.dir/build.make CMakeFiles/udpserver.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/udpserver.dir/main.cpp.o.provides

CMakeFiles/udpserver.dir/main.cpp.o.provides.build: CMakeFiles/udpserver.dir/main.cpp.o


CMakeFiles/udpserver.dir/udpserver.cpp.o: CMakeFiles/udpserver.dir/flags.make
CMakeFiles/udpserver.dir/udpserver.cpp.o: ../udpserver.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhang/workroom/fake_obtlib/src/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/udpserver.dir/udpserver.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/udpserver.dir/udpserver.cpp.o -c /home/zhang/workroom/fake_obtlib/src/server/udpserver.cpp

CMakeFiles/udpserver.dir/udpserver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/udpserver.dir/udpserver.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhang/workroom/fake_obtlib/src/server/udpserver.cpp > CMakeFiles/udpserver.dir/udpserver.cpp.i

CMakeFiles/udpserver.dir/udpserver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/udpserver.dir/udpserver.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhang/workroom/fake_obtlib/src/server/udpserver.cpp -o CMakeFiles/udpserver.dir/udpserver.cpp.s

CMakeFiles/udpserver.dir/udpserver.cpp.o.requires:

.PHONY : CMakeFiles/udpserver.dir/udpserver.cpp.o.requires

CMakeFiles/udpserver.dir/udpserver.cpp.o.provides: CMakeFiles/udpserver.dir/udpserver.cpp.o.requires
	$(MAKE) -f CMakeFiles/udpserver.dir/build.make CMakeFiles/udpserver.dir/udpserver.cpp.o.provides.build
.PHONY : CMakeFiles/udpserver.dir/udpserver.cpp.o.provides

CMakeFiles/udpserver.dir/udpserver.cpp.o.provides.build: CMakeFiles/udpserver.dir/udpserver.cpp.o


CMakeFiles/udpserver.dir/handler.cpp.o: CMakeFiles/udpserver.dir/flags.make
CMakeFiles/udpserver.dir/handler.cpp.o: ../handler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhang/workroom/fake_obtlib/src/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/udpserver.dir/handler.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/udpserver.dir/handler.cpp.o -c /home/zhang/workroom/fake_obtlib/src/server/handler.cpp

CMakeFiles/udpserver.dir/handler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/udpserver.dir/handler.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhang/workroom/fake_obtlib/src/server/handler.cpp > CMakeFiles/udpserver.dir/handler.cpp.i

CMakeFiles/udpserver.dir/handler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/udpserver.dir/handler.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhang/workroom/fake_obtlib/src/server/handler.cpp -o CMakeFiles/udpserver.dir/handler.cpp.s

CMakeFiles/udpserver.dir/handler.cpp.o.requires:

.PHONY : CMakeFiles/udpserver.dir/handler.cpp.o.requires

CMakeFiles/udpserver.dir/handler.cpp.o.provides: CMakeFiles/udpserver.dir/handler.cpp.o.requires
	$(MAKE) -f CMakeFiles/udpserver.dir/build.make CMakeFiles/udpserver.dir/handler.cpp.o.provides.build
.PHONY : CMakeFiles/udpserver.dir/handler.cpp.o.provides

CMakeFiles/udpserver.dir/handler.cpp.o.provides.build: CMakeFiles/udpserver.dir/handler.cpp.o


# Object files for target udpserver
udpserver_OBJECTS = \
"CMakeFiles/udpserver.dir/main.cpp.o" \
"CMakeFiles/udpserver.dir/udpserver.cpp.o" \
"CMakeFiles/udpserver.dir/handler.cpp.o"

# External object files for target udpserver
udpserver_EXTERNAL_OBJECTS =

udpserver: CMakeFiles/udpserver.dir/main.cpp.o
udpserver: CMakeFiles/udpserver.dir/udpserver.cpp.o
udpserver: CMakeFiles/udpserver.dir/handler.cpp.o
udpserver: CMakeFiles/udpserver.dir/build.make
udpserver: CMakeFiles/udpserver.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zhang/workroom/fake_obtlib/src/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable udpserver"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/udpserver.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/udpserver.dir/build: udpserver

.PHONY : CMakeFiles/udpserver.dir/build

CMakeFiles/udpserver.dir/requires: CMakeFiles/udpserver.dir/main.cpp.o.requires
CMakeFiles/udpserver.dir/requires: CMakeFiles/udpserver.dir/udpserver.cpp.o.requires
CMakeFiles/udpserver.dir/requires: CMakeFiles/udpserver.dir/handler.cpp.o.requires

.PHONY : CMakeFiles/udpserver.dir/requires

CMakeFiles/udpserver.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/udpserver.dir/cmake_clean.cmake
.PHONY : CMakeFiles/udpserver.dir/clean

CMakeFiles/udpserver.dir/depend:
	cd /home/zhang/workroom/fake_obtlib/src/server/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zhang/workroom/fake_obtlib/src/server /home/zhang/workroom/fake_obtlib/src/server /home/zhang/workroom/fake_obtlib/src/server/build /home/zhang/workroom/fake_obtlib/src/server/build /home/zhang/workroom/fake_obtlib/src/server/build/CMakeFiles/udpserver.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/udpserver.dir/depend
