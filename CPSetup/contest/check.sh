TC=100
if [ $# -gt 0 ] && [[ "$1" =~ ^[0-9]+$ ]]; then
  TC=$1
fi

g++ -Wall -std=c++17 solution.cpp -o sol 
echo "solution complielation done"

g++ -Wall -std=c++17 generator.cpp -o gen
echo "generator complielation done"

g++ -Wall -std=c++17 checker.cpp -o check
echo "checker complielation done"

for((i = 1;i <= $TC ; ++i)); do
    printf "TC $i :\n"
	./gen.exe > in.txt
	./sol.exe < in.txt > out.txt

	printf "$(cat in.txt) \n$(cat out.txt)" > inout.txt
   ./check.exe < inout.txt > err.txt

	retVal=$?
	if [ $retVal -ne 0 ]; then
		echo "Exit code : $retVal"
		break 
	fi

done

rm sol.exe
rm gen.exe
rm check.exe