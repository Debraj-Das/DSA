#!/bin/bash

# taking input files
if [ $# -eq 0 ]; then
  echo "Error: Please provide the solution file as an argument"
  exit 1
fi

test_cases=1
if [ $# -gt 2 ] && [[ "$2" =~ ^[0-9]+$ ]]; then
  test_cases=$2
fi

g++ -Wall -std=c++17 "$1" -o sol.out

if [ $? -ne 0 ]; then
  echo "Error: Compilation failed"
  exit 1
else
  echo "Compilation done"
fi

echo -e "\n=== Test Results ==="

for ((i = 1; i <= test_cases; i++)); do
  input="in${i}.txt"
  output="out${i}.txt"
  expected="exp${i}.txt"

  # Run the program with the current input file and redirect output
  ./sol.out < "$input" > "$output"

  # Compare the program output with the expected output
  if diff -Bw "$expected" "$output" > /dev/null; then
	printf "Test $i: PASSED\n"
  else
	printf "Test $i: FAILED\n"
	printf "input:\n"
	cat "$input"
	printf "\nexpected vs output\n"
	printf "$(diff -Bw "$expected" "$output")"
  fi
done

printf "\n\n"
