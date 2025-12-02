#!/bin/bash
set -e
cd "$(dirname "$0")"
echo "Compiling with bundled stub..."
g++ -std=c++17 main.cpp raylib_stub.cpp -o skyproc_stub
echo "Launching..."
./skyproc_stub
