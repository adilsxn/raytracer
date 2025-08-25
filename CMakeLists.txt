cmake_minimum_required(VERSION 3.30 FATAL_ERROR)

project(raytracer VERSION 0.0.1 LANGUAGES CXX)

#Set the CPP standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#Compiler warnings
add_compile_options (-Wall -Wextra -Werror -Wpedantic)

# Output structure
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

#Source files
set(SRC_FILES 
    src/main.cpp
    src/vec3.hpp
)

#Add sources subdirectory
include_subdirectories(src)

#Main project executable
add_executable(rt ${SRC_FILES})

include (CTest)
enable_testing()


#Add tests subdirectory
include_subdirectories(test)

