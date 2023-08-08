import os
import glob

def remove():
    remove_exe = glob.glob("*.exe")
    for exe in remove_exe:
        os.remove(exe)

def move(no_move_files):
    filesList = glob.glob("*.cpp")
    for file in filesList:
        if (file not in no_move_files):
            os.system(f"move {file} ./Code")

def commit(commit_message):
    os.system("git add .")
    os.system(f"git commit -m \"{commit_message}\"")
    os.system("git push origin master")

def main(files, message):
    remove()
    move(no_move_files=files)
    commit(commit_message=message)


not_move_files = {"Rough.cpp", "test.cpp"}
commit_message = "Today I create automation name script and practise the competitive programming practice problem."

main(not_move_files, commit_message)
