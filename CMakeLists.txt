cmake_minimum_required(VERSION 3.10)
project(HuffmanCoding)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add source files
set(SOURCES
    src/main.cpp
    src/huffman.cpp
    src/minHeap.cpp
    src/sideFunc.cpp
)

# Include header files
include_directories(include)

# Add the executable
add_executable(huffman_coding ${SOURCES})

add_custom_target(run_terminal
    COMMAND start cmd /k ${CMAKE_BINARY_DIR}/Debug/huffman_coding.exe
    DEPENDS huffman_coding
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

# Copy data directory to build/
file(COPY ${CMAKE_SOURCE_DIR}/data DESTINATION ${CMAKE_BINARY_DIR})