# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_SOURCE_DIR = /home/bigshow360/Documents/C++/DBT_Folder

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bigshow360/Documents/C++/DBT_Folder/build

# Include any dependencies generated for this target.
include Time/CMakeFiles/TimeTest_UT.dir/depend.make

# Include the progress variables for this target.
include Time/CMakeFiles/TimeTest_UT.dir/progress.make

# Include the compile flags for this target's objects.
include Time/CMakeFiles/TimeTest_UT.dir/flags.make

Time/CMakeFiles/TimeTest_UT.dir/TimeTest_UT.cpp.o: Time/CMakeFiles/TimeTest_UT.dir/flags.make
Time/CMakeFiles/TimeTest_UT.dir/TimeTest_UT.cpp.o: ../Time/TimeTest_UT.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bigshow360/Documents/C++/DBT_Folder/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Time/CMakeFiles/TimeTest_UT.dir/TimeTest_UT.cpp.o"
	cd /home/bigshow360/Documents/C++/DBT_Folder/build/Time && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TimeTest_UT.dir/TimeTest_UT.cpp.o -c /home/bigshow360/Documents/C++/DBT_Folder/Time/TimeTest_UT.cpp

Time/CMakeFiles/TimeTest_UT.dir/TimeTest_UT.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TimeTest_UT.dir/TimeTest_UT.cpp.i"
	cd /home/bigshow360/Documents/C++/DBT_Folder/build/Time && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bigshow360/Documents/C++/DBT_Folder/Time/TimeTest_UT.cpp > CMakeFiles/TimeTest_UT.dir/TimeTest_UT.cpp.i

Time/CMakeFiles/TimeTest_UT.dir/TimeTest_UT.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TimeTest_UT.dir/TimeTest_UT.cpp.s"
	cd /home/bigshow360/Documents/C++/DBT_Folder/build/Time && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bigshow360/Documents/C++/DBT_Folder/Time/TimeTest_UT.cpp -o CMakeFiles/TimeTest_UT.dir/TimeTest_UT.cpp.s

# Object files for target TimeTest_UT
TimeTest_UT_OBJECTS = \
"CMakeFiles/TimeTest_UT.dir/TimeTest_UT.cpp.o"

# External object files for target TimeTest_UT
TimeTest_UT_EXTERNAL_OBJECTS =

UnitTestBin/TimeTest_UT: Time/CMakeFiles/TimeTest_UT.dir/TimeTest_UT.cpp.o
UnitTestBin/TimeTest_UT: Time/CMakeFiles/TimeTest_UT.dir/build.make
UnitTestBin/TimeTest_UT: lib/libgtest.a
UnitTestBin/TimeTest_UT: lib/libgmock_main.a
UnitTestBin/TimeTest_UT: lib/libgmock.a
UnitTestBin/TimeTest_UT: lib/libgtest.a
UnitTestBin/TimeTest_UT: Time/CMakeFiles/TimeTest_UT.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bigshow360/Documents/C++/DBT_Folder/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../UnitTestBin/TimeTest_UT"
	cd /home/bigshow360/Documents/C++/DBT_Folder/build/Time && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TimeTest_UT.dir/link.txt --verbose=$(VERBOSE)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Executing TimeTest_UT"
	cd /home/bigshow360/Documents/C++/DBT_Folder/build/UnitTestBin && /home/bigshow360/Documents/C++/DBT_Folder/ExecuteTarget.sh /home/bigshow360/Documents/C++/DBT_Folder/build/UnitTestBin/TimeTest_UT

# Rule to build all files generated by this target.
Time/CMakeFiles/TimeTest_UT.dir/build: UnitTestBin/TimeTest_UT

.PHONY : Time/CMakeFiles/TimeTest_UT.dir/build

Time/CMakeFiles/TimeTest_UT.dir/clean:
	cd /home/bigshow360/Documents/C++/DBT_Folder/build/Time && $(CMAKE_COMMAND) -P CMakeFiles/TimeTest_UT.dir/cmake_clean.cmake
.PHONY : Time/CMakeFiles/TimeTest_UT.dir/clean

Time/CMakeFiles/TimeTest_UT.dir/depend:
	cd /home/bigshow360/Documents/C++/DBT_Folder/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bigshow360/Documents/C++/DBT_Folder /home/bigshow360/Documents/C++/DBT_Folder/Time /home/bigshow360/Documents/C++/DBT_Folder/build /home/bigshow360/Documents/C++/DBT_Folder/build/Time /home/bigshow360/Documents/C++/DBT_Folder/build/Time/CMakeFiles/TimeTest_UT.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Time/CMakeFiles/TimeTest_UT.dir/depend

