# Testing is a art of software development

## Introduction

It is a process of evaluating a system or its component with the intent to find whether it satisfies the specified requirements or not. Here we will discuss about the different types of testing for competitive programming. For testing we will using shell scripts.so you can use any shell script like bash, zsh, git bash, fish, etc. And for interactor testing we will need python command.

## Types of Testing in competitive programming

1. stress testing
2. validation testing
3. interactor testing

## Stress Testing

In stress testing, we compare the output of the brute expected solution with the output of the optimized solution using random test cases.
For that we need solution.cpp, expected.cpp, generator.cpp, and test.sh files.

- [solution.cpp](../CPSetup/test/solution.cpp)
- [expected.cpp](../CPSetup/test/expected.cpp)
- [generator.cpp](../CPSetup/test/generator.cpp)
- [test.sh](../CPSetup/scripts/test.sh)
- [How to use](#) // it will be added soon

## Validation Testing

In validation testing, we validate the output of the optimized solution with the output of the brute expected solution using random test cases.
For that we need solution.cpp, checker.cpp, generator.cpp, and check.sh files.

- [solution.cpp](../CPSetup/test/solution.cpp)
- [checker.cpp](../CPSetup/test/checker.cpp)
- [generator.cpp](../CPSetup/test/generator.cpp)
- [check.sh](../CPSetup/scripts/check.sh)
- [How to use](#) // it will be added soon

## Interactor Testing

In interactor testing, we will test the interaction problem using interact program.
For that we need solution.cpp, interact.cpp, generator.cpp, and interact.sh files.

- [solution.cpp](../CPSetup/test/solution.cpp)
- [interact.cpp](../CPSetup/test/interact.cpp)
- [generator.cpp](../CPSetup/test/generator.cpp)
- [interact.sh](../CPSetup/scripts/interact.sh)
- [How to use](#) // it will be added soon
