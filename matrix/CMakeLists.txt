cmake_minimum_required(VERSION 3.0.0)
project(matrix VERSION 0.1.0)

add_executable(matrix
    src/main.cpp
    src/part_one/question_a.cpp
    src/part_one/question_b.cpp
    src/part_one/question_c.cpp
    src/part_one/question_d.cpp
    src/part_two/question.cpp

    src/matrix.h
    src/part_one/questions.h
    src/part_two/questions.h
)
target_include_directories(matrix PRIVATE
    src/
)
target_compile_options(matrix PRIVATE
    -Wall
    -pedantic
)