cmake_minimum_required(VERSION 2.8.8)

# Define the project
project(UnitTest)

# Third-party library
include(ExternalProject)

set(TARGET_NAME SquareRoot_UT)
add_executable(${TARGET_NAME} ./${TARGET_NAME}.cpp
)

add_test(NAME ${TARGET_NAME} COMMAND ${TARGET_NAME})

if (CMAKE_VERSION VERSION_LESS "3.1")
  add_definitions(-std=c++11)
else()
  set(CMAKE_CXX_STANDARD 11)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
  set(CMAKE_CXX_EXTENSIONS OFF)
endif()

if (POLICY CMP0048)
  cmake_policy(SET CMP0048 NEW)
endif (POLICY CMP0048)

project(googletest-distribution)
set(GOOGLETEST_VERSION 1.8.1)

# Enable testing
include(CTest)
enable_testing()

include(CMakeDependentOption)
include(GNUInstallDirs)


# Set this in your environment variables if you want it somewhere else
if (NOT DEFINED GTEST_HOME)
set(GTEST_HOME "/home/bigshow360/Documents/googletest-release-1.8.1/googletest")
endif(NOT DEFINED GTEST_HOME)

if (NOT DEFINED CP_UT_HOME)
set(CP_UT_HOME "${CP_HOME}/UnitTest")
endif(NOT DEFINED CP_UT_HOME)

# Locate GTest
find_package(GTest REQUIRED)


# This is required for googletest
find_package(Threads REQUIRED)

include_directories(${GTEST_HOME}/googletest/include
${GTEST_HOME}/googlemock/include)

target_link_libraries(${TARGET_NAME} 
  -Wl,--start-group
  gtest 
	gtest_main
	Threads::Threads
  -Wl,--start-group)

set_target_properties(${TARGET_NAME} PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/UnitTestBin")

#cmake CMakeLists.txt
#make
#If you want to split the tests over multiple files you need to 
#add the files to the line add_executable(runTests tests.cpp newFile.cpp) 
#in CMakeLists.txt

#mkdir build
#cd build
#cmake ../
#make