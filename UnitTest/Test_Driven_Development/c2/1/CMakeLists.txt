cmake_minimum_required(VERSION 2.6)
 
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 
# Link runTests with what we want to test and the GTest and pthread library
add_executable(SoundexTest_UT main.cpp) 

target_link_libraries(SoundexTest_UT ${GTEST_LIBRARIES} pthread)


#project(chapterFirstExample)
#cmake_minimum_required(VERSION 2.6)

#include_directories($ENV{GMOCK_HOME}/include $ENV{GMOCK_HOME}/gtest/include)
#link_directories($ENV{GMOCK_HOME}/mybuild $ENV{GMOCK_HOME}/gtest/mybuild)
#add_definitions(-std=c++0x)
#set(CMAKE_CXX_FLAGS "${CMAXE_CXX_FLAGS} -Wall")

#set(sources 
#   main.cpp
#   SoundexTest.cpp)
#add_executable(test ${sources})
#target_link_libraries(test pthread)
#target_link_libraries(test gmock)
#target_link_libraries(test gtest)


#g++ SoundexTest.cpp -lgtest -lgtest_main -pthread

