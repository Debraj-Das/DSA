TC=100
if [ $# -gt 0 ] && [[ "$1" =~ ^[0-9]+$ ]]; then
  TC=$1
fi

g++ -Wall -std=c++17 solution.cpp -o sol 
echo "solution complielation done"

g++ -Wall -std=c++17 generator.cpp -o gen
echo "generator complielation done"

g++ -Wall -std=c++17 expected.cpp -o exp
echo "expected complielation done"

comp=0
for((i = 1;i <= $TC ; ++i)); do
	comp=0
   printf "TC $i :\n"
	./gen.exe  > in.txt
	./sol.exe < in.txt > out.txt
	./exp.exe < in.txt > exp.txt
	diff -w exp.txt out.txt || break
	comp=1
done

rm sol.exe gen.exe exp.exe
if [ $comp -eq 1 ]; then
    rm in.txt out.txt exp.txt
fi
