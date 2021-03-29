cmake_minimum_required(VERSION 3.17)
project(Postfix_Infix C)

set(CMAKE_C_STANDARD 99)

add_executable(Postfix_Infix main.c math.trans/math_trans.c math.trans/math_trans.h)