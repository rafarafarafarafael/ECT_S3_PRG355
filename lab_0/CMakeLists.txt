cmake_minimum_required(VERSION 3.22)

project(lecture_01_p01 VERSION 1.0.0 LANGUAGES C CXX)

set(EXE_NAME "executable")

set(WHICH_PROBLEM 1)

if(WHICH_PROBLEM EQUAL 0)
    add_executable(${EXE_NAME} lecture_01_p1.cpp)
elseif(WHICH_PROBLEM EQUAL 1)
    add_executable(${EXE_NAME} lecture_01_p2.cpp)
endif()