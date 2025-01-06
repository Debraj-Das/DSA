#!/bin/bash

# taking input files
if [ $# -eq 0 ]; then
  echo "Error: Please provide the solution file as an argument"
  exit 1
fi

# Compile the input files as code.exe
g++ -Wall -std=c++17 "$1" -o sol

if [ $? -ne 0 ]; then
  echo "Error: Compilation failed"
  exit 1
else
  echo "Compilation done"
fi

input=in.txt
output=out.txt
expected=exp.txt

if [ $# -gt 1 ]; then
  input=$2
fi


./sol.exe < $input > $output
diff -w $expected $output

if [ $? -eq 0 ]; then
    rm sol.exe $output
fi