# Algorithms and Data structure

[![Build Status](https://travis-ci.org/TusharChugh/ctci-modern_cplusplus.svg?branch=master)](https://travis-ci.org/TusharChugh/ctci-modern_cplusplus) 

This repository contains the solutions to cracking the coding interview/LeetCode in C++. Most of the solutions available on other repositories are mostly follow C style coding. This repo attempts to follow modern C++ guidelines.
In addition, this contains test cases and benchmarking to evaluate the correcting and the running time of the algorithms. 

The build is based on Bazel offered by Google. It also uses Gtest for implementing test cases and google benchmarks for benchmarking running time. 

## Project structure
```
algorithms-practice
    ├──include
    │  └── arrays_strings
    │      ├── BUILD
    │      └── example.h
    │
    ├──tests
    │  ├── test
    │  │   └── arrays_strings
    │  │       └── example_test.cpp
    │  ├── benchmark
    │  │   └── arrays_strings
    │  │       └── example_benchmark.cpp
    │  └── BUILD
    ├──third_party
    │  ├── gtest.BUILD
    │  └── benchmark.BUILD
    └── WORKSPACE
```

## Build Code (Inclduing gtest and google benchmark)
1. [Install bazel](https://docs.bazel.build/versions/master/install.html)
2. Clone this repository and enter the repo directory
3. Build the code: ```bazel build ...```

## Run
1. Run test cases:  ```bazel run test:algorithms-test```
2. Run benchmarks:  ```bazel run test:algorithms-benchmark```

## Add new files/test
1. Do add new solution. Create a new 'example.h' file in the appropriate directory inside the include folder. Add corresponding test in test/'appropriate'/ directory. Do the same for benchmark

## Todo's:
1. Add log tools like google logs
2. Add gsl (guideline support library)
3. Add code coverage