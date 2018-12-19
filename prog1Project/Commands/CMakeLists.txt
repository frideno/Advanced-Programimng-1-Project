cmake_minimum_required(VERSION 3.13)
project(prog1Project)

set(CMAKE_CXX_STANDARD 14)

set (SOURCE_FILES ConditionParser.h ConditionParser.cpp DefineVarCommand.h DefineVarCommand.cpp EqualsCommand.cpp EqualsCommand.h IfCommand.h IfCommand.cpp OpenDataServerCommand.cpp
        OpenDataServerCommand.h PrintCommand.cpp PrintCommand.h SemicolonCommand.h WhileCommand.h WhileCommand.cpp)
add_executable(prog1Project ${SOURCE_FILES})