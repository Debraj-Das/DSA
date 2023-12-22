# taking input files
if [ $# -eq 0 ]; then
  echo "Error: Please provide at least one C++ file to checking."
  exit 1
fi

# Compile the input files as code.exe
g++ -Wall -std=c++17 "$1" -o code 
echo "$1 complie to code done"

#compile the generator files(cpp) to create gen.exe 
g++ -Wall -std=c++17 gen.cpp -o gen
echo "gen.cpp complie to gen.exe done"

# compile the checker files(cpp) to create check.exe
g++ -Wall -std=c++17 check.cpp -o check
echo "check.cpp complie to check.exe done"

printf "\nChecking started :\n"

# starting the testing 1 to 100 generally
for((i = 1;i < 101 ; ++i)); do
    printf "TC $i :\n"
	./gen.exe  > inp.txt
	./code.exe < inp.txt > out.txt

	# if checker is used then below line
	./check < out.txt  

	#if return val is not 0 
	retVal=$?
	if [ $retVal -ne 0 ]; then
		echo "Exit code : $retVal"
		break 
	fi

done

# ./gen is a create input generated file inp.txt
# ./code is a create solution file out.txt
# ./check is take that out.txt and check solution is correct or not

