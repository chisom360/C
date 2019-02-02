cmake_minimum_required(VERSION 3.8)
project(UnitTest)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS 
"${CMAKE_CXX_FLAGS} \
-fno-exceptions \
-fprofile-arcs \
-ftest-coverage \
-std=gnu++11 \
-g \
-fexceptions \
-pthread \
-Wall \
-Wextra \
-Wfatal-errors \
-Wno-enum-compare \
-Wno-unused-variable \
-Wno-unknown-pragmas \
-Wno-c++0x-compat \
-Wno-write-strings \
-Wno-unused-parameter \
-Wno-reorder \
-Wno-unused-function \
-Wno-conversion-null \
-Wno-sign-compare \
-Wno-type-limits \
-Wno-extra \
-Wno-switch \
-Wno-parentheses \
-Wno-return-type \
-Wno-format \
-Wno-delete-non-virtual-dtor \
-Wno-unused-but-set-variable \
-Wno-comment"
)

set(CMAKE_CXX_FLAGS_GUI 
"${CMAKE_CXX_FLAGS} \
-fno-exceptions \
-fprofile-arcs \
-ftest-coverage \
-std=gnu++11 \
-g \
-fexceptions \
-pthread \
-Wall \
-Wextra \
-Wfatal-errors \
-Wno-enum-compare \
-Wno-unused-variable \
-Wno-unknown-pragmas \
-Wno-c++0x-compat \
-Wno-write-strings \
-Wno-unused-parameter \
-Wno-reorder \
-Wno-unused-function \
-Wno-conversion-null \
-Wno-sign-compare \
-Wno-type-limits \
-Wno-extra \
-Wno-switch \
-Wno-parentheses \
-Wno-return-type \
-Wno-format \
-Wno-delete-non-virtual-dtor \
-Wno-unused-but-set-variable \
-Wno-comment"

)

#option (SKIP_AUTO_REBUILD_LIBS "Skip automatically rebuilding libraries (ON/OFF)" OFF)
#option (EXEC_UT_ON_BUILD "Execute UnitTests when rebuilt (ON/OFF)" OFF)
include(${PROJECT_SOURCE_DIR}/CMakeLocal.txt OPTIONAL)

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in
        googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )

# Prevent GoogleTest from overriding our compiler/linker options
# when building with Visual Studio
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This adds
# the following targets: gtest, gtest_main, gmock
# and gmock_main
add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
        ${CMAKE_BINARY_DIR}/googletest-build)

# The gtest/gmock targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include"
            "${gmock_SOURCE_DIR}/include")
endif()

# Now simply link your own targets against gtest, gmock,
# etc. as appropriate


enable_testing()

# Used to execute a given command but ignore the result.  Useful for running unit tests on build.
# Usage should be "${UUT_SILENT_EXEC_CMD} ${TARGET_CMD}"
set(UUT_SILENT_EXEC_CMD ${PROJECT_SOURCE_DIR}/ExecuteTarget.sh)

#set(SOURCE_FILES library.cpp library.h)
#add_library(TestExample ${SOURCE_FILES})


#add_subdirectory(test)
add_subdirectory(Time)
add_subdirectory(Soundex)
