cmake_minimum_required(VERSION 3.0.0)
project(matrix VERSION 0.1.0)

add_executable(matrix
    src/main.cpp
    src/question_one.cpp
    src/question_two.cpp

    src/matrix.h
    src/questions.h
)
target_include_directories(matrix PRIVATE
    src/
)
target_compile_options(matrix PRIVATE
    -Wall
    -pedantic
)