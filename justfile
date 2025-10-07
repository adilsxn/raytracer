
# Configure CMake
configure:
    cmake -S . -B build

# Build the project
build:
    cmake --build build

# Run tests
test:
    ctest --test-dir build
