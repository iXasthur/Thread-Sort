cmake_minimum_required(VERSION 3.17)
project(Thread_Sort)

set(CMAKE_CXX_STANDARD 20)

add_executable(Thread_Sort main.cpp io/FileReader.h sort/LinesSorter.h io/FileWriter.h sort/utils/SortTask.h sort/utils/SortQueue.h sort/MergeSorter.h)