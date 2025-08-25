cmake_minimum_required(VERSION 3.30 FATAL_ERROR)

# Enable the module to find or download 3rd party packages
include(cmake/CPM.cmake)

CPMAddPackage("gh:doctest/doctest@2.4.12")

#Setting the test source files variable
set(TEST_SOURCES 
)

#Create test executables
add_executable(unit_tests ${TEST_SOURCES})

#Link doctest lib 
target_link_libraries(unit_tests PRIVATE doctest::doctest)

#Include project headers
target_include_directories(unit_tests PRIVATE ${CMAKE_SOURCE_DIR}/src)

#Option linking parts of implementations
target_sources(unit_tests PRIVATE
    ${CMAKE_SOURCE_DIR}/src/vec3.cpp
)

#Registering tests to CTest
#doctest has a catch macro that runs all the tests automatically
add_test(NAME all_tests COMMAND unit_tests)
