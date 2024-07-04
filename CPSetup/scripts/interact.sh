#!/bin/bash

runner=~/Desktop/DSA/CPSetup/scripts/runner.py

TC=10
if [ $# -gt 0 ] && [[ "$1" =~ ^[0-9]+$ ]]; then
  TC=$1
fi

g++ -Wall -std=c++17 solution.cpp -o sol 
echo "solution complielation done"

g++ -Wall -std=c++17 interact.cpp -o inter
echo "interact compilation done"

for ((i=1;i<=$TC;i++)); do
    echo "TC $i :"

    python $runner \
     --command1-stdout-prefix "S: " \
     --command2-stdout-prefix "I: " \
     --command1-stderr-prefix "SE: " \
     --command2-stderr-prefix "IE: " \
     ./sol.exe ./inter.exe > out.txt
 
    if [ "$(awk 'NF{p=$0}END{print p}' out.txt)" != "I: AC" ] 
    then
        echo "Interaction:"
        cat out.txt
        exit
    fi
    comp=1
done


if [ $comp -eq 1 ]; then
   rm out.txt inter.exe sol.exe
fi