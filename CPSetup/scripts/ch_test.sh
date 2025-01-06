#!/bin/bash

# Input file check
if [ $# -eq 0 ]; then
  echo "Error: Please provide the solution file as an argument"
  exit 1
fi

file_name="$1"
file_name_without_extension="${file_name%.*}"

test_count_file="${file_name_without_extension}_test_count.txt"

echo "Test count file: $test_count_file"

test_cases=1

if [ -f "$test_count_file" ]; then
	read test_cases < "$test_count_file"
	if ! [[ "$test_cases" =~ ^[0-9]+$ ]] || (( test_cases <= 0 )); then
		echo "Error: Invalid test count in $test_count_file. Using default 1."
		test_cases=1
	fi
fi

echo "Number of test cases: $test_cases"

executable_name="${file_name_without_extension}.exe"
g++ -Wall -std=c++17 "$file_name" -o "$executable_name"

if [ $? -ne 0 ]; then
  echo "Error: Compilation failed"
  exit 1
else
  echo "Compilation done"
fi

echo "=== Test Results ==="
for ((i = 1; i <= test_cases; i++)); do
  input_file="${file_name_without_extension}_test_${i}_input.txt"
  output_file="${file_name_without_extension}_test_${i}_result.txt"
  expected_file="${file_name_without_extension}_test_${i}_output.txt"

  ./"$executable_name" < "$input_file" > "$output_file"

  if diff -Bw "$expected_file" "$output_file" > /dev/null; then
    result="Test $i: PASSED"
  else
    result="Test $i: FAILED - Differences:"
    diff_output=$(diff -Bw "$expected_file" "$output_file") # Capture diff output
    result+="\n$diff_output"
  fi

  echo "$result"
  echo ""
done

exit 0
