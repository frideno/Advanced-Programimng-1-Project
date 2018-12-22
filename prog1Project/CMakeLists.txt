cmake_minimum_required(VERSION 3.13)
project(prog1Project)

set(CMAKE_CXX_STANDARD 14)

set (SOURCE_FILES main.cpp Command.h Expression.h Expressions.h Interperter.h Interperter.cpp Utils.h Utils.cpp  Enviroment.cpp Enviroment.h)
set (COMMANDS_SOURCE_FILES Commands/ConditionParser.h Commands/ConditionParser.cpp Commands/DefineVarCommand.h Commands/DefineVarCommand.cpp Commands/EqualsCommand.cpp Commands/EqualsCommand.h Commands/IfCommand.h Commands/IfCommand.cpp Commands/OpenDataServerCommand.cpp Commands/OpenDataServerCommand.h Commands/PrintCommand.cpp Commands/PrintCommand.h Commands/SemicolonCommand.h Commands/WhileCommand.h Commands/WhileCommand.cpp)
set (EXPRESSIONS_SOURCE_FILES Expressions/ExpressionFactory.cpp Expressions/ExpressionFactory.h Expressions/Number.h Expressions/UnaryExpression.h Expressions/Var.h Expressions/BooleanExpressions/Bigger.h Expressions/BooleanExpressions/Equals.h Expressions/BooleanExpressions/NotEquals.h Expressions/BooleanExpressions/Smaller.h Expressions/Expressions_operators/Div.h Expressions/Expressions_operators/Mul.h Expressions/Expressions_operators/Minus.h Expressions/Expressions_operators/Plus.h Expressions/Expressions_operators/Pow.h Expressions/Expressions_operators/Neg.h)
set (DATABASES_SOUCE_FILES Databases/ConstsDB.cpp Databases/ConstsDB.h Databases/SymbolsDB.cpp Databases/SymbolsDB.h)

add_executable(prog1Project ${DATABASES_SOURCE_FILES} ${COMMANDS_SOURCE_FILES} ${EXPRESSIONS_SOURCE_FILES} ${SOURCE_FILES})