cmake_minimum_required(VERSION 3.13)
project(prog1Project)

set(CMAKE_CXX_STANDARD 14)

add_executable(prog1Project main.cpp Interperter.cpp cmake-build-debug/Interperter.h Expressions/Expression.h Expressions/BinaryExpression.h Expressions/UnaryExpression.h "Expressions/Expressions -_operators/Plus.h" Expressions/Number.h)