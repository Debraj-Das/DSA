# # remove all .exe files from the current repository
# import os
# for root, dirs, files in os.walk("."):
#     for file in files:
#         if (file.endswith(".exe")):
#             os.remove(os.path.join(root, file)) 


import os , glob 

for file in glob.glob("*.cpp"):
    if(file != "Rough.cpp"):
        os.system(f"move {file} ./CPP_files")
        print(f"Moved {file} to ./CPP_files\n")

print("All .cpp files are moved to ./CPP_files except Rough.cpp")

