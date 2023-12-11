for((i = 1;i < 101 ; ++i)); do
    printf "\nTestCase $i :\n"
    ./gen  > inp.txt
	./brute < inp.txt > exp.txt
	./a < inp.txt > out.txt
	diff -w exp.txt out.txt || break
done

# there ./a if check files and gen is input ./gen file and ./brute is brute solution files
# inp.txt input file , out.txt output file and exp.txt is expected file

# Sample files 
# diff -w <(./a < in.txt) <(./brute < in.txt) || break
# ./a < int > out1
# ./brute < int > out2
# diff -w out1 out2 || break