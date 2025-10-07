cmake_minimum_required(VERSION 3.30 FATAL_ERROR)

CPMAddPackage("gh:doctest/doctest@2.4.12")

#Setting the test source files variable
set(RT_TEST_SOURCES
   test_vec3.cpp
)

#Create test executables
add_executable(rt_tests ${RT_TEST_SOURCES})

target_include_directories(rt_tests PRIVATE ${CMAKE_SOURCE_DIR}/src)

#Link doctest lib
target_link_libraries(rt_tests PRIVATE doctest::doctest)

target_compile_features(rt_tests  PRIVATE cxx_std_23)

#Registering tests to CTest
#NOTE: doctest has a catch macro that runs all the tests automatically
add_test(NAME vec3_tests COMMAND rt_tests)
