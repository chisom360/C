include_directories("${PROJECT_SOURCE_DIR}")
include_directories(${GTEST_HOME}/googletest/include
	${GTEST_HOME}/googlemock/include)

set(TARGET_NAME TimeTest_UT)

# Test TimeClass
add_executable(${TARGET_NAME} ./${TARGET_NAME}.cpp
)

target_link_libraries(${TARGET_NAME} gtest gmock_main)
#add_test(NAME ${TARGET_NAME} COMMAND ${TARGET_NAME})

set_target_properties(${TARGET_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/UnitTestBin")
    
add_custom_command(TARGET ${TARGET_NAME} POST_BUILD
    COMMAND "${UUT_SILENT_EXEC_CMD}" "${CMAKE_BINARY_DIR}/UnitTestBin/${TARGET_NAME}"
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/UnitTestBin
    COMMENT "Executing ${TARGET_NAME}")