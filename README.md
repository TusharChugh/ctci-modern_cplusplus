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
2. Install GCC-5 or above
3. Make sure CC and CXX environment variables are pointing to the latest GCC version in /user/bin
4. Clone this repository and enter the repo directory
5. Build the code: ```bazel build ...```

## Run
1. Run test cases:  ```bazel run test:algorithms-test```
2. Run benchmarks:  ```bazel run test:algorithms-benchmark```

## Add new files/test
1. Do add new solution. Create a new 'example.h' file in the appropriate directory inside the include folder. Add corresponding test in test/'appropriate'/ directory. Do the same for benchmark


## Issue with build

### Upgrade gcc
### update cmake
[help](https://www.claudiokuenzler.com/blog/755/install-upgrade-cmake-3.10.1-ubuntu-14.04-trusty-alternatives#.W9zw2XXwbCI)
1. wget https://cmake.org/files/v3.12/cmake-3.12.4.tar.gz
2. tar -xvzf cmake-3.12.4.tar.gz
3. cd cmake-3.12.4
4. ./configure
5. make
6. sudo make install
7. sudo update-alternatives --install /usr/bin/cmake cmake /usr/local/bin/cmake 1 --force
8. cmake --version

### Update gcc
1. sudo add-apt-repository ppa:ubuntu-toolchain-r/test
2. sudo apt update
3. sudo apt install gcc-6
4. sudo apt install g++-6
5. sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-6 60 --slave /usr/bin/g++ g++ /usr/bin/g++-6 

## Todo's:
1. Add log tools like google logs
2. Add gsl (guideline support library)
3. Add code coverage