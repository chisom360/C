# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_SOURCE_DIR = /home/bigshow360/Documents/C++/UnitTest

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bigshow360/Documents/C++/UnitTest/build

# Include any dependencies generated for this target.
include CMakeFiles/SquareRoot_UT.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SquareRoot_UT.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SquareRoot_UT.dir/flags.make

CMakeFiles/SquareRoot_UT.dir/SquareRoot_UT.cpp.o: CMakeFiles/SquareRoot_UT.dir/flags.make
CMakeFiles/SquareRoot_UT.dir/SquareRoot_UT.cpp.o: ../SquareRoot_UT.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bigshow360/Documents/C++/UnitTest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SquareRoot_UT.dir/SquareRoot_UT.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SquareRoot_UT.dir/SquareRoot_UT.cpp.o -c /home/bigshow360/Documents/C++/UnitTest/SquareRoot_UT.cpp

CMakeFiles/SquareRoot_UT.dir/SquareRoot_UT.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SquareRoot_UT.dir/SquareRoot_UT.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bigshow360/Documents/C++/UnitTest/SquareRoot_UT.cpp > CMakeFiles/SquareRoot_UT.dir/SquareRoot_UT.cpp.i

CMakeFiles/SquareRoot_UT.dir/SquareRoot_UT.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SquareRoot_UT.dir/SquareRoot_UT.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bigshow360/Documents/C++/UnitTest/SquareRoot_UT.cpp -o CMakeFiles/SquareRoot_UT.dir/SquareRoot_UT.cpp.s

# Object files for target SquareRoot_UT
SquareRoot_UT_OBJECTS = \
"CMakeFiles/SquareRoot_UT.dir/SquareRoot_UT.cpp.o"

# External object files for target SquareRoot_UT
SquareRoot_UT_EXTERNAL_OBJECTS =

UnitTestBin/SquareRoot_UT: CMakeFiles/SquareRoot_UT.dir/SquareRoot_UT.cpp.o
UnitTestBin/SquareRoot_UT: CMakeFiles/SquareRoot_UT.dir/build.make
UnitTestBin/SquareRoot_UT: CMakeFiles/SquareRoot_UT.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bigshow360/Documents/C++/UnitTest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable UnitTestBin/SquareRoot_UT"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SquareRoot_UT.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SquareRoot_UT.dir/build: UnitTestBin/SquareRoot_UT

.PHONY : CMakeFiles/SquareRoot_UT.dir/build

CMakeFiles/SquareRoot_UT.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SquareRoot_UT.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SquareRoot_UT.dir/clean

CMakeFiles/SquareRoot_UT.dir/depend:
	cd /home/bigshow360/Documents/C++/UnitTest/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bigshow360/Documents/C++/UnitTest /home/bigshow360/Documents/C++/UnitTest /home/bigshow360/Documents/C++/UnitTest/build /home/bigshow360/Documents/C++/UnitTest/build /home/bigshow360/Documents/C++/UnitTest/build/CMakeFiles/SquareRoot_UT.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SquareRoot_UT.dir/depend

