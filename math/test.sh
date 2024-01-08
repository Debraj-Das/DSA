# taking input files
if [ $# -eq 0 ]; then
  echo "Error: Please provide at least one C++ file to testing."
  exit 1
fi

# Compile the input files as code.exe
g++ -Wall -std=c++17 "$1" -o code 
echo "$1 complie to code done"

# compile the generator files(cpp) to create gen.exe 
g++ -Wall -std=c++17 gen.cpp -o gen
echo "gen.cpp complie to gen.exe done"

# compile the expected files(cpp) to create exp.exe
g++ -Wall -std=c++17 exp.cpp -o exp
echo "exp.cpp complie to exp.exe done"

# starting the testing 1 to 100 generally
for((i = 1;i < 101 ; ++i)); do
    printf "TC $i :\n"
	./gen.exe  > inp.txt
	./code.exe < inp.txt > out.txt

	retVal=$?
	if [ $retVal -ne 0 ]; then
		echo "Exit code : $retVal"
		break 
	fi

	./exp.exe < inp.txt > exp.txt
	diff -w exp.txt out.txt || break

done

# ./gen is a create input generated file inp.txt
# ./code is a create solution file out.txt
# ./exp is create correct solution file exp.txt

