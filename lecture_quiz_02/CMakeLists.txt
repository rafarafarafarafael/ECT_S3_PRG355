cmake_minimum_required(VERSION 3.22)

project(lecture_quiz_02 VERSION 1.0.0 LANGUAGES C CXX)

set(EXE_NAME "executable")

add_library(CoinBank STATIC coinbank.cpp)
add_library(GumBallMachine STATIC gumballmachine.cpp)

add_executable(${EXE_NAME} lecture_quiz_02.cpp)

target_link_libraries(${EXE_NAME} PUBLIC CoinBank GumBallMachine)