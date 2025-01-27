#!/bin/bash

# Exit immediately if a command fails
set -e

# Compile the C program with clang
echo "Compiling the C program with clang..."
clang -o rod_cutter -Wall -g rod_cutter.c

# Check input files exist
if [[ ! -f "test1.txt" || ! -f "test2.txt" || ! -f "test3.txt" || ! -f "test4.txt" ]]; then
    echo "Error: One or more input files are missing."
    exit 1
fi

# Run the rod_cutter program with individual rod lengths and corresponding files
echo "Running rod_cutter with parameters..."
echo "Test 1: Rod length = 45"
./rod_cutter 45 "test1.txt"
echo "Test 2: Rod length = 300"
./rod_cutter 300 "test2.txt"
echo "Test 3: Rod length = 87"
./rod_cutter 87 "test3.txt"
echo "Test 4: Rod length = 56"
./rod_cutter 56 "test4.txt"

# End of script
echo "All tests executed. Compare results with TESTS.md file."
