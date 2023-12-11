# Check if any arguments are provided
if [ $# -eq 0 ]; then
  echo "Error: Please provide at least one C++ file to compile."
  exit 1
fi

# Loop through each provided argument
for file in "$@"; do
  # Extract filename without extension
  filename="${file%.*}"

  # Check if file exists and is a C++ source file
  if [ ! -f "$file" -o "${file: -4}" != ".cpp" ]; then
    echo "Error: '$file' is not a valid C++ source file."
    continue
  fi

  # Compile the C++ file
  g++ "$file" -o "$filename"

  # Check if compilation was successful
  if [ $? -eq 0 ]; then
	  echo "Successfully compiled '$file' to '$filename'."
	  printf "Run (yes/y) : "
	  read -r answer
	  #echo "Your password is $run."
	  if [[ "$answer" =~ ^(yes|y)$ ]]; then
		  time ./$filename
	  fi
  else
    echo "Error: Compilation of '$file' failed."
  fi
done

