#cmake_minimum_required(VERSION 2.6)
 
# Locate GTest
#find_package(GTest REQUIRED)
#include_directories(${GTEST_INCLUDE_DIRS})
 
# Link runTests with what we want to test and the GTest and pthread library
#add_executable(SquareRoot_UT SquareRoot_UT.cpp)
#add_executable(Root_UT Root_UT.cpp)

#target_link_libraries(SquareRoot_UT ${GTEST_LIBRARIES} pthread)
#target_link_libraries(Root_UT ${GTEST_LIBRARIES} pthread)

cmake_minimum_required(VERSION 2.8.8)

# Define the project
project(UnitTest)

# Third-party library
include(ExternalProject)

set(PROJECT_SOURCES Root.cpp)

#option(gtest_build_samples "Build gtest's sample programs." ON)

set(TARGET_NAME SquareRoot_UT)
#set(TARGET_NAME Root_UT)
add_executable(${TARGET_NAME} ./${TARGET_NAME}.cpp)

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

# This must be set in the root directory for the tests to be run by
# 'make test' or ctest.
enable_testing()

include(CMakeDependentOption)
include(GNUInstallDirs)


# Specify where third-party libraries are located
link_directories(${CMAKE_BINARY_DIR}
   ${gtest_binary_dir})

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
  
 # add_custom_command(TARGET ${TARGET_NAME} POST_BUILD
  #COMMAND "${UUT_SILENT_EXEC_CMD}" "${CMAKE_BINARY_DIR}/UnitTestBin/${TARGET_NAME}"
  #WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/UnitTestBin
  #COMMENT "Executing ${TARGET_NAME}") 
