cmake_minimum_required(VERSION 3.30 FATAL_ERROR)

project(raytracer VERSION 0.0.1 LANGUAGES CXX)


set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#Set the CPP standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#Compiler warnings
add_compile_options (-Wall -Wextra -Werror -Wpedantic)

# Output structure
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include (cmake/CPM.cmake)

enable_testing()
#Add sources subdirectory
add_subdirectory(src)

#Add tests subdirectory
add_subdirectory(tests)

