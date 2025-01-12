#!/bin/bash

TC=10
if [ $# -gt 0 ] && [[ "$1" =~ ^[0-9]+$ ]]; then
  TC=$1
fi

g++ -Wall -std=c++17 solution.cpp -o sol.out
echo "solution complielation done"

g++ -Wall -std=c++17 generator.cpp -o gen.out
echo "generator complielation done"

g++ -Wall -std=c++17 expected.cpp -o exp.out
echo "expected complielation done"

comp=0
for((i = 1;i <= $TC ; ++i)); do
	comp=0
   printf "TC $i :\n"
	./gen.out  > in.txt
	./sol.out < in.txt > out.txt
	./exp.out < in.txt > exp.txt
	diff -Bw exp.txt out.txt || break
	comp=1
done

rm sol.out gen.out exp.out
if [ $comp -eq 1 ]; then
    rm in.txt out.txt exp.txt
fi
