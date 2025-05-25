@echo off
g++ src/huffman.cpp src/main.cpp src/minHeap.cpp src/sideFunc.cpp -o HuffmanCoding
if %errorlevel% neq 0 (
    echo Build failed!
    exit /b %errorlevel%
)
HuffmanCoding.exe
