cmake_minimum_required(VERSION 3.13)
project(Sorter)

set(CMAKE_CXX_STANDARD 14)

add_executable(Sorter main.cpp ArrayOfNumbers.cpp ArrayOfNumbers.hh OrderOfArray.hh MergeSorting.cpp MergeSorting.hh Quicksort.cpp Quicksort.hh Introsort.cpp Introsort.hh)