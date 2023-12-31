#!/bin/bash
# Compile the program with code coverage flags and generate report

# Basedon information from
# https://github.com/mapbox/cpp/blob/master/docs/coverage.md

PROG=$0
EXE="./a.out-code-coverage"
# How we want to call our executable, 
# possibly with some command line parameters
EXEC_PROGRAM="$EXE $@"
PROFDATA=$EXE.profdata
CC=clang++

rm $EXE $PROFDATA default.profraw 2>/dev/null

programs=($CC "llvm-profdata" "llvm-cov")
for p in "${programs[@]}"; do
    if ! hash $CC 2>/dev/null; then
        echo "ERROR: $PROG: cannot find $CC executable"
        exit 1
    fi
done

$CC -g -std=c++11 -fprofile-instr-generate -fcoverage-mapping main.cpp -o $EXE

if [ ! -f $EXE ]; then
    echo "ERROR: $PROG: Failed to create executable"
    exit 1
fi

# Execute the program
$EXEC_PROGRAM > /dev/null

if [ ! -f "default.profraw" ]; then
    echo "ERROR: $PROG: Failed to create default.profraw data"
    exit 1
fi

llvm-profdata merge default.profraw -output=$PROFDATA

if [ ! -f $PROFDATA ]; then
    echo "ERROR: $PROG: Failed to create $PROFDATA"
else
    llvm-cov report -show-functions=1 -Xdemangler=llvm-cxxfilt $EXE -instr-profile=$PROFDATA main.cpp
    
    llvm-cov show $EXE -instr-profile=$PROFDATA
fi

rm -rf a.out* $EXE $PROFDATA default.profraw 2>/dev/null
