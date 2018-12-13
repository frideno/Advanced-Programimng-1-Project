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
Expression *ExpressionFactory::create(string operatora, Expression *left, Expression *right) {
    if(operatora == "+")
        return new Plus(left, right);
    if(operatora == "-")
        return new Minus(left, right);
    if(operatora == "*")
        return new Mul(left, right);
    if(operatora == "/")
        return new Div(left, right);
    if(operatora == "^")
        return new Pow(left, right);
    // if the operator is unknown, return nullptr.
    return nullptr;
}

// helping function to determine if a string represent one of our operators.

bool ExpressionFactory::isOperator(string token) {
    if (token == "+" ||
        token == "-" ||
        token == "*" ||
        token == "/" ||
        token == "^"
        )  {
        return true;
    } else {
        return false;
    }
}

// helping function to determine if a string represent number.
bool ExpressionFactory::isNumber(string token) {

    // check out that the string is not empty.
    if(token == "")
        return false;

    // iterating over the string to see if there is a char that is not a digit:
    for(int i = 0; i < token.length(); i++) {
        char c = token[i];
        if (!isdigit(c))
            return false;
    }
    // if all chars are digits, its a number.
    return true;
}

// helping function to determine if a char represent one of our operators, that is left associative,
// means that a~b~c = (a~b)~c.
bool ExpressionFactory::isLeftAccociative(string operat) {
    if(operat == "/" )
        return true;
    else
        return false;
}

