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
CMAKE_SOURCE_DIR = /home/zhang/workroom/fake_obtlib/src/gtest

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zhang/workroom/fake_obtlib/src/gtest/build

# Include any dependencies generated for this target.
include CMakeFiles/utest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/utest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/utest.dir/flags.make

CMakeFiles/utest.dir/test.cpp.o: CMakeFiles/utest.dir/flags.make
CMakeFiles/utest.dir/test.cpp.o: ../test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhang/workroom/fake_obtlib/src/gtest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/utest.dir/test.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/utest.dir/test.cpp.o -c /home/zhang/workroom/fake_obtlib/src/gtest/test.cpp

CMakeFiles/utest.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/utest.dir/test.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhang/workroom/fake_obtlib/src/gtest/test.cpp > CMakeFiles/utest.dir/test.cpp.i

CMakeFiles/utest.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/utest.dir/test.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhang/workroom/fake_obtlib/src/gtest/test.cpp -o CMakeFiles/utest.dir/test.cpp.s

CMakeFiles/utest.dir/test.cpp.o.requires:

.PHONY : CMakeFiles/utest.dir/test.cpp.o.requires

CMakeFiles/utest.dir/test.cpp.o.provides: CMakeFiles/utest.dir/test.cpp.o.requires
	$(MAKE) -f CMakeFiles/utest.dir/build.make CMakeFiles/utest.dir/test.cpp.o.provides.build
.PHONY : CMakeFiles/utest.dir/test.cpp.o.provides

CMakeFiles/utest.dir/test.cpp.o.provides.build: CMakeFiles/utest.dir/test.cpp.o


CMakeFiles/utest.dir/home/zhang/workroom/fake_obtlib/src/client/obtlib/RREService_api.cpp.o: CMakeFiles/utest.dir/flags.make
CMakeFiles/utest.dir/home/zhang/workroom/fake_obtlib/src/client/obtlib/RREService_api.cpp.o: /home/zhang/workroom/fake_obtlib/src/client/obtlib/RREService_api.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhang/workroom/fake_obtlib/src/gtest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/utest.dir/home/zhang/workroom/fake_obtlib/src/client/obtlib/RREService_api.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/utest.dir/home/zhang/workroom/fake_obtlib/src/client/obtlib/RREService_api.cpp.o -c /home/zhang/workroom/fake_obtlib/src/client/obtlib/RREService_api.cpp

CMakeFiles/utest.dir/home/zhang/workroom/fake_obtlib/src/client/obtlib/RREService_api.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/utest.dir/home/zhang/workroom/fake_obtlib/src/client/obtlib/RREService_api.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhang/workroom/fake_obtlib/src/client/obtlib/RREService_api.cpp > CMakeFiles/utest.dir/home/zhang/workroom/fake_obtlib/src/client/obtlib/RREService_api.cpp.i

CMakeFiles/utest.dir/home/zhang/workroom/fake_obtlib/src/client/obtlib/RREService_api.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/utest.dir/home/zhang/workroom/fake_obtlib/src/client/obtlib/RREService_api.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhang/workroom/fake_obtlib/src/client/obtlib/RREService_api.cpp -o CMakeFiles/utest.dir/home/zhang/workroom/fake_obtlib/src/client/obtlib/RREService_api.cpp.s

CMakeFiles/utest.dir/home/zhang/workroom/fake_obtlib/src/client/obtlib/RREService_api.cpp.o.requires:

.PHONY : CMakeFiles/utest.dir/home/zhang/workroom/fake_obtlib/src/client/obtlib/RREService_api.cpp.o.requires

CMakeFiles/utest.dir/home/zhang/workroom/fake_obtlib/src/client/obtlib/RREService_api.cpp.o.provides: CMakeFiles/utest.dir/home/zhang/workroom/fake_obtlib/src/client/obtlib/RREService_api.cpp.o.requires
	$(MAKE) -f CMakeFiles/utest.dir/build.make CMakeFiles/utest.dir/home/zhang/workroom/fake_obtlib/src/client/obtlib/RREService_api.cpp.o.provides.build
.PHONY : CMakeFiles/utest.dir/home/zhang/workroom/fake_obtlib/src/client/obtlib/RREService_api.cpp.o.provides

CMakeFiles/utest.dir/home/zhang/workroom/fake_obtlib/src/client/obtlib/RREService_api.cpp.o.provides.build: CMakeFiles/utest.dir/home/zhang/workroom/fake_obtlib/src/client/obtlib/RREService_api.cpp.o


CMakeFiles/utest.dir/home/zhang/workroom/fake_obtlib/src/server/handler.cpp.o: CMakeFiles/utest.dir/flags.make
CMakeFiles/utest.dir/home/zhang/workroom/fake_obtlib/src/server/handler.cpp.o: /home/zhang/workroom/fake_obtlib/src/server/handler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhang/workroom/fake_obtlib/src/gtest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/utest.dir/home/zhang/workroom/fake_obtlib/src/server/handler.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/utest.dir/home/zhang/workroom/fake_obtlib/src/server/handler.cpp.o -c /home/zhang/workroom/fake_obtlib/src/server/handler.cpp

CMakeFiles/utest.dir/home/zhang/workroom/fake_obtlib/src/server/handler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/utest.dir/home/zhang/workroom/fake_obtlib/src/server/handler.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhang/workroom/fake_obtlib/src/server/handler.cpp > CMakeFiles/utest.dir/home/zhang/workroom/fake_obtlib/src/server/handler.cpp.i

CMakeFiles/utest.dir/home/zhang/workroom/fake_obtlib/src/server/handler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/utest.dir/home/zhang/workroom/fake_obtlib/src/server/handler.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhang/workroom/fake_obtlib/src/server/handler.cpp -o CMakeFiles/utest.dir/home/zhang/workroom/fake_obtlib/src/server/handler.cpp.s

CMakeFiles/utest.dir/home/zhang/workroom/fake_obtlib/src/server/handler.cpp.o.requires:

.PHONY : CMakeFiles/utest.dir/home/zhang/workroom/fake_obtlib/src/server/handler.cpp.o.requires

CMakeFiles/utest.dir/home/zhang/workroom/fake_obtlib/src/server/handler.cpp.o.provides: CMakeFiles/utest.dir/home/zhang/workroom/fake_obtlib/src/server/handler.cpp.o.requires
	$(MAKE) -f CMakeFiles/utest.dir/build.make CMakeFiles/utest.dir/home/zhang/workroom/fake_obtlib/src/server/handler.cpp.o.provides.build
.PHONY : CMakeFiles/utest.dir/home/zhang/workroom/fake_obtlib/src/server/handler.cpp.o.provides

CMakeFiles/utest.dir/home/zhang/workroom/fake_obtlib/src/server/handler.cpp.o.provides.build: CMakeFiles/utest.dir/home/zhang/workroom/fake_obtlib/src/server/handler.cpp.o


CMakeFiles/utest.dir/home/zhang/workroom/fake_obtlib/src/server/udpserver.cpp.o: CMakeFiles/utest.dir/flags.make
CMakeFiles/utest.dir/home/zhang/workroom/fake_obtlib/src/server/udpserver.cpp.o: /home/zhang/workroom/fake_obtlib/src/server/udpserver.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhang/workroom/fake_obtlib/src/gtest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/utest.dir/home/zhang/workroom/fake_obtlib/src/server/udpserver.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/utest.dir/home/zhang/workroom/fake_obtlib/src/server/udpserver.cpp.o -c /home/zhang/workroom/fake_obtlib/src/server/udpserver.cpp

CMakeFiles/utest.dir/home/zhang/workroom/fake_obtlib/src/server/udpserver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/utest.dir/home/zhang/workroom/fake_obtlib/src/server/udpserver.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhang/workroom/fake_obtlib/src/server/udpserver.cpp > CMakeFiles/utest.dir/home/zhang/workroom/fake_obtlib/src/server/udpserver.cpp.i

CMakeFiles/utest.dir/home/zhang/workroom/fake_obtlib/src/server/udpserver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/utest.dir/home/zhang/workroom/fake_obtlib/src/server/udpserver.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhang/workroom/fake_obtlib/src/server/udpserver.cpp -o CMakeFiles/utest.dir/home/zhang/workroom/fake_obtlib/src/server/udpserver.cpp.s

CMakeFiles/utest.dir/home/zhang/workroom/fake_obtlib/src/server/udpserver.cpp.o.requires:

.PHONY : CMakeFiles/utest.dir/home/zhang/workroom/fake_obtlib/src/server/udpserver.cpp.o.requires

CMakeFiles/utest.dir/home/zhang/workroom/fake_obtlib/src/server/udpserver.cpp.o.provides: CMakeFiles/utest.dir/home/zhang/workroom/fake_obtlib/src/server/udpserver.cpp.o.requires
	$(MAKE) -f CMakeFiles/utest.dir/build.make CMakeFiles/utest.dir/home/zhang/workroom/fake_obtlib/src/server/udpserver.cpp.o.provides.build
.PHONY : CMakeFiles/utest.dir/home/zhang/workroom/fake_obtlib/src/server/udpserver.cpp.o.provides

CMakeFiles/utest.dir/home/zhang/workroom/fake_obtlib/src/server/udpserver.cpp.o.provides.build: CMakeFiles/utest.dir/home/zhang/workroom/fake_obtlib/src/server/udpserver.cpp.o


# Object files for target utest
utest_OBJECTS = \
"CMakeFiles/utest.dir/test.cpp.o" \
"CMakeFiles/utest.dir/home/zhang/workroom/fake_obtlib/src/client/obtlib/RREService_api.cpp.o" \
"CMakeFiles/utest.dir/home/zhang/workroom/fake_obtlib/src/server/handler.cpp.o" \
"CMakeFiles/utest.dir/home/zhang/workroom/fake_obtlib/src/server/udpserver.cpp.o"

# External object files for target utest
utest_EXTERNAL_OBJECTS =

utest: CMakeFiles/utest.dir/test.cpp.o
utest: CMakeFiles/utest.dir/home/zhang/workroom/fake_obtlib/src/client/obtlib/RREService_api.cpp.o
utest: CMakeFiles/utest.dir/home/zhang/workroom/fake_obtlib/src/server/handler.cpp.o
utest: CMakeFiles/utest.dir/home/zhang/workroom/fake_obtlib/src/server/udpserver.cpp.o
utest: CMakeFiles/utest.dir/build.make
utest: CMakeFiles/utest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zhang/workroom/fake_obtlib/src/gtest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable utest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/utest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/utest.dir/build: utest

.PHONY : CMakeFiles/utest.dir/build

CMakeFiles/utest.dir/requires: CMakeFiles/utest.dir/test.cpp.o.requires
CMakeFiles/utest.dir/requires: CMakeFiles/utest.dir/home/zhang/workroom/fake_obtlib/src/client/obtlib/RREService_api.cpp.o.requires
CMakeFiles/utest.dir/requires: CMakeFiles/utest.dir/home/zhang/workroom/fake_obtlib/src/server/handler.cpp.o.requires
CMakeFiles/utest.dir/requires: CMakeFiles/utest.dir/home/zhang/workroom/fake_obtlib/src/server/udpserver.cpp.o.requires

.PHONY : CMakeFiles/utest.dir/requires

CMakeFiles/utest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/utest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/utest.dir/clean

CMakeFiles/utest.dir/depend:
	cd /home/zhang/workroom/fake_obtlib/src/gtest/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zhang/workroom/fake_obtlib/src/gtest /home/zhang/workroom/fake_obtlib/src/gtest /home/zhang/workroom/fake_obtlib/src/gtest/build /home/zhang/workroom/fake_obtlib/src/gtest/build /home/zhang/workroom/fake_obtlib/src/gtest/build/CMakeFiles/utest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/utest.dir/depend

