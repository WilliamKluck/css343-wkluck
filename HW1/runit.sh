#!/bin/bash

# Remove executable
echo "Removing previous executable: rm -f ./a"
rm -f ./a.out
rm -f ./a

# Compile
echo "Compiling: clang++ -g -std=c++11 -Wall -Wextra -Wno-sign-compare main.cpp"
clang++ -g -std=c++11 -Wall -Wextra -Wno-sign-compare main.cpp -o a.out

# Execute
echo "Executing: ./a.out"
./a.out 2