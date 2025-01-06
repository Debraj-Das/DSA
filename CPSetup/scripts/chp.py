from fastapi import FastAPI, Body
import re 
import os
import random

app = FastAPI()

@app.post("/")
async def receive_problem(problem: dict = Body(...)):
    """
    Receives a JSON object containing problem data and logs it.
    """

    name = problem["name"]
    contest = problem["group"]
    url = problem["url"]
    memoryLimit = problem["memoryLimit"]
    timeLimit = problem["timeLimit"]
    tests = problem["tests"]

    print("problem received successfully")

    with open("/home/debraj/Desktop/DSA/CPSetup/Main_Boiler_Template.cpp", "r") as f:
        template = f.read()

    match = re.search(r"/([^/]+)$", url)
    if match:
        file_name = match.group(1)
    else:
        file_name = str(random.randint(1000, 100000000))

    file_name = os.path.join(os.getcwd(), file_name)

    with open(file_name+ "_test_count.txt", "w") as f:
        f.write(str(len(tests)))

    for i, test in enumerate(tests):
        with open(file_name+ f"_test_{i+1}_input.txt", "w") as f:
            f.write(test["input"])

        with open(file_name+f"_test_{i+1}_output.txt", "w") as f:
            f.write(test["output"])

    with open(file_name + ".cpp", "w") as f:
        f.write("/*\n")
        f.write(f"\tProblem Name: {name}\n")
        f.write(f"\tContest: {contest}\n")
        f.write(f"\tURL: {url}\n")
        f.write(f"\tMemory Limit: {memoryLimit} MB\n")
        f.write(f"\tTime Limit: {timeLimit} ms\n")
        f.write("*/\n\n")
        f.write(template)

    print("problem work successfully")
    return {"message": "Problem received successfully"}


if __name__ == "__main__":
    import uvicorn
    uvicorn.run(app, host="0.0.0.0", port=10045)
