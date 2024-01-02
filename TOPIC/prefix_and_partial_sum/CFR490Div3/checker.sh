# taking input files
if [ $# -eq 0 ]; then
  echo "Error: Please provide at least one C++ file to compile."
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

# starting the testing 1 to 100 generally
for((i = 1;i < 1001 ; ++i)); do
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


# there ./code if check files and gen is input ./gen file and ./brute is brute solution files
# inp.txt input file , out.txt output file and exp.txt is expected file

