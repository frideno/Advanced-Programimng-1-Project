//
// Created by omri on 12/12/18.
//

#include "ExpressionFactory.h"
#include "Expressions_operators/Div.h"
#include "Expressions_operators/Plus.h"
#include "Expressions_operators/Minus.h"
#include "Expressions_operators/Mul.h"
#include "Expressions_operators/Pow.h"

// create expression by the token representing them.
Expression *ExpressionFactory::create(char operatora, Expression *left, Expression *right) {
    if(operatora == '+')
        return new Plus(left, right);
    if(operatora == '-')
        return new Minus(left, right);
    if(operatora == '*')
        return new Mul(left, right);
    if(operatora == '/')
        return new Div(left, right);
    if(operatora == '^')
        return new Pow(left, right);
    // if the operator is unknown, return nullptr.
    return nullptr;
}

// helping function to determine if a char represent one of our operators.

bool ExpressionFactory::isOperator(char token) {
    if (token == '+' ||
        token == '-' ||
        token == '*' ||
        token == '/' ||
        token == '^')
    {
        return true;
    } else {
        return false;
    }
}


// helping function to determine if a char represent one of our operators, that is left associative,
// means that a~b~c = (a~b)~c.
bool ExpressionFactory::isLeftAccociative(char operat) {
    if(operat == '/' )
        return true;
    else
        return false;
}
