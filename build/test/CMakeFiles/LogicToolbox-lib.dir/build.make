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
CMAKE_SOURCE_DIR = /home/nur/LogicToolboxLib

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nur/LogicToolboxLib/build

# Include any dependencies generated for this target.
include test/CMakeFiles/LogicToolbox-lib.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/LogicToolbox-lib.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/LogicToolbox-lib.dir/flags.make

test/CMakeFiles/LogicToolbox-lib.dir/hello.cpp.o: test/CMakeFiles/LogicToolbox-lib.dir/flags.make
test/CMakeFiles/LogicToolbox-lib.dir/hello.cpp.o: ../test/hello.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nur/LogicToolboxLib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/LogicToolbox-lib.dir/hello.cpp.o"
	cd /home/nur/LogicToolboxLib/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LogicToolbox-lib.dir/hello.cpp.o -c /home/nur/LogicToolboxLib/test/hello.cpp

test/CMakeFiles/LogicToolbox-lib.dir/hello.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LogicToolbox-lib.dir/hello.cpp.i"
	cd /home/nur/LogicToolboxLib/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nur/LogicToolboxLib/test/hello.cpp > CMakeFiles/LogicToolbox-lib.dir/hello.cpp.i

test/CMakeFiles/LogicToolbox-lib.dir/hello.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LogicToolbox-lib.dir/hello.cpp.s"
	cd /home/nur/LogicToolboxLib/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nur/LogicToolboxLib/test/hello.cpp -o CMakeFiles/LogicToolbox-lib.dir/hello.cpp.s

test/CMakeFiles/LogicToolbox-lib.dir/hello.cpp.o.requires:

.PHONY : test/CMakeFiles/LogicToolbox-lib.dir/hello.cpp.o.requires

test/CMakeFiles/LogicToolbox-lib.dir/hello.cpp.o.provides: test/CMakeFiles/LogicToolbox-lib.dir/hello.cpp.o.requires
	$(MAKE) -f test/CMakeFiles/LogicToolbox-lib.dir/build.make test/CMakeFiles/LogicToolbox-lib.dir/hello.cpp.o.provides.build
.PHONY : test/CMakeFiles/LogicToolbox-lib.dir/hello.cpp.o.provides

test/CMakeFiles/LogicToolbox-lib.dir/hello.cpp.o.provides.build: test/CMakeFiles/LogicToolbox-lib.dir/hello.cpp.o


# Object files for target LogicToolbox-lib
LogicToolbox__lib_OBJECTS = \
"CMakeFiles/LogicToolbox-lib.dir/hello.cpp.o"

# External object files for target LogicToolbox-lib
LogicToolbox__lib_EXTERNAL_OBJECTS =

lib/libLogicToolbox.so: test/CMakeFiles/LogicToolbox-lib.dir/hello.cpp.o
lib/libLogicToolbox.so: test/CMakeFiles/LogicToolbox-lib.dir/build.make
lib/libLogicToolbox.so: test/CMakeFiles/LogicToolbox-lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nur/LogicToolboxLib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library ../lib/libLogicToolbox.so"
	cd /home/nur/LogicToolboxLib/build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LogicToolbox-lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/LogicToolbox-lib.dir/build: lib/libLogicToolbox.so

.PHONY : test/CMakeFiles/LogicToolbox-lib.dir/build

test/CMakeFiles/LogicToolbox-lib.dir/requires: test/CMakeFiles/LogicToolbox-lib.dir/hello.cpp.o.requires

.PHONY : test/CMakeFiles/LogicToolbox-lib.dir/requires

test/CMakeFiles/LogicToolbox-lib.dir/clean:
	cd /home/nur/LogicToolboxLib/build/test && $(CMAKE_COMMAND) -P CMakeFiles/LogicToolbox-lib.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/LogicToolbox-lib.dir/clean

test/CMakeFiles/LogicToolbox-lib.dir/depend:
	cd /home/nur/LogicToolboxLib/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nur/LogicToolboxLib /home/nur/LogicToolboxLib/test /home/nur/LogicToolboxLib/build /home/nur/LogicToolboxLib/build/test /home/nur/LogicToolboxLib/build/test/CMakeFiles/LogicToolbox-lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/LogicToolbox-lib.dir/depend
