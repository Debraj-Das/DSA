import os
import glob
# Remove the all .exe files from the current repository
# add the staged files to the commit and commit the changes with a message
# push the changes to the remote repository

# / message for the commit
commit_message = "Create a Number Theory Header files for C++\
                   it contains all the basic functions for Number Theory"


# remove all .exe files from the current repository
for root, dirs, files in os.walk("."):
    for file in files:
        if (file.endswith(".exe")):
            os.remove(os.path.join(root, file))

print("All .exe files are removed from the current repository\n\n")

# commit and push the changes to the remote repository

# add the staged files to the commit
os.system("git add .")
# commit the changes with a message
os.system(f"git commit -m \"{commit_message}\"")
# push the changes to the remote repository
os.system("git push origin master")

print("All changes are commit and pushed to the remote repository\n\n")
