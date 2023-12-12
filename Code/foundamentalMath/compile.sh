# compile the generator files(cpp) to create gen.exe 
g++ -Wall -std=c++17 gen.cpp -o gen

echo "gen.cpp complie to gen.exe done"

# compile the expected files(cpp) to create exp.exe
g++ -Wall -std=c++17 exp.cpp -o exp

echo "exp.cpp complie to exp.exe done"
