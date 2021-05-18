cmake_minimum_required(VERSION 3.19)
project(laba2)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(googletest)
add_executable(laba2 main.cpp DinamicArray.h LinkedList.h Sequence.h ArraySequence.h LinkedListSequence.h Complex.h Matrix.h Tests_DA.cpp SquareMatrix.h menu.cpp menu.h)
include_directories(googletest/googletest/include)
target_link_libraries(laba2 gtest gtest_main)