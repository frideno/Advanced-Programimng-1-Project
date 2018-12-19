cmake_minimum_required(VERSION 3.13)
project(prog1Project)

set(CMAKE_CXX_STANDARD 14)

set (ConstsDB.cpp ConstsDB.h SymbolsDB.cpp SymbolsDB.h SOURCE_FILES )
add_executable(prog1Project ${SOURCE_FILES})