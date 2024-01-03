# taking input files
if [ $# -eq 0 ]; then
  echo "Error: Please provide at least one C++ file to compile."
  exit 1
fi

# Compile the input files as code.exe
g++ -Wall -std=c++17 "$1" -o code 
echo "$1 complie to code done"

# compile the generator files(cpp) to create inputGen.exe 
g++ -Wall -std=c++17 inputGen.cpp -o gen
echo "gen.cpp complie to gen.exe done"

# compile the expected files(cpp) to create brute.exe
g++ -Wall -std=c++17 brute.cpp -o exp
echo "exp.cpp complie to exp.exe done"

# starting the testing 1 to 100 generally
for((i = 1;i < 101 ; ++i)); do
    printf "TC $i :\n"
	./gen.exe  > inp.txt
	./code.exe < inp.txt > out.txt

	# if expected value is used then below 2 lines
	./exp.exe < inp.txt > exp.txt
	diff -w exp.txt out.txt || break
	# diff -w <(./code < in.txt) <(./brute < in.txt) || break

done

rm gen.exe
rm code.exe
rm exp.exe

# there ./code if check files and gen is input ./gen file and ./brute is brute solution files
# inp.txt input file , out.txt output file and exp.txt is expected file
# link of editorial ->
# https://ali-ibrahim137.github.io/competitive/programming/2020/08/23/Stress-Testing.html
