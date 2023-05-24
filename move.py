import os
import glob

# move all .cpp files to ./CPP_files except Rough.cpp
for file in glob.glob("*.cpp"):
    if (file != "Rough.cpp"):
        os.system(f"move {file} ./CPP_files")
        print(f"Moved {file} to ./CPP_files\n")

print("All .cpp files are moved to ./CPP_files except Rough.cpp\n\n")
