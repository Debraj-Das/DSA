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

g++ -Wall -std=c++17 "$1" -o sol

if [ $? -ne 0 ]; then
  echo "Error: Compilation failed"
  exit 1
else
  echo "Compilation done"
fi

results=()
for ((i = 1; i <= test_cases; i++)); do
  input="input${i}.txt"
  output="output${i}.txt"
  expected="exp${i}.txt"

  # Run the program with the current input file and redirect output
  ./sol.exe < "$input" > "$output"

  # Compare the program output with the expected output
  if diff -w "$expected" "$output" > /dev/null; then
    result="Test $i: PASSED"
  else
    result="Test $i: FAILED - Differences for Test $i:"
    result+="\n$(diff -w "$expected" "$output")"
  fi

  # Store the result in the array
  results+=("\n$result\n")
done

# Display all results
echo -e "\n=== Test Results ==="
for result in "${results[@]}"; do
  echo -e "$result"
done
