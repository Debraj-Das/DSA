# taking input files
if [ $# -eq 0 ]; then
  echo "Error: Please provide at least one C++ file to compile."
  exit 1
fi

# Compile the input files as code.exe
g++ -Wall -std=c++17 "$1" -o code 
echo "$1 complie to code done"


./code.exe < inp.txt > out.txt
diff -w exp.txt out.txt || break

