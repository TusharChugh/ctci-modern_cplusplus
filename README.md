# Algrotihms and Data structure

This repository contains the solutions to cracking the coding interview/LeetCode in C++. Most of the solutions available on other repositories are mostly follow C style coding. This repo attempts to follow modern C++ guidelines.
In addition, this contains test cases and benchmarking to evaluate the correcting and the running time of the algorithms. 

The build is based on Bazel offered by Google. It also uses Gtest for implementing test cases and google benchmarks for benchmarking running time. 

## Build 
1. [Install bazel](https://docs.bazel.build/versions/master/install.html)
2. Clone this repository and enter the repo directory
3. Build the code: ```bazel build ...```

## Run
1. Run test cases:  bazel run test:algorithms-test
2. Run benchmarks:  bazel run test:algorithms-benchmark

## Todo's:
1. Add log tools like google logs
2. Add gsl (guideline support library)
3. Add CI (travis) and code coverage