#!/bin/bash

# Remove executable
echo "Removing previous executable: rm -f ./a"
rm -f ./myhw

# Compile
echo "Compiling: clang++ -g -std=c++11 -Wall -Wextra -Wno-sign-compare main.cpp"
clang++ -g -std=c++11 -Wall -Wextra -Wno-sign-compare main.cpp -o myhw

# Execute
echo "Executing: ./myhw"
./myhw $@