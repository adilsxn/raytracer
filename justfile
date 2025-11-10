default: run
# Configure CMake
configure:
    cmake -S . -B build

# Build the project
build:
    cmake --build build

run: build
    ./build/bin/rt_core >  image.ppm
# Run tests
test:
    ctest --test-dir build
