/*
     Created by Omri and Gal on 12/9/18.
*/
#include "Interperter.h"
#include "Expressions/Expression.h"
#include <stack>
#include <algorithm>
#include <queue>


bool isOperator(char token);

/**
 * shunting yard algorithm -
 * converts mathematical expression specified in infix notation, into prefix
 * [ for example - 3 * 4 + 5 ---> +(5, *(3, 4))]
 */
Expression* Interperter::shuntingYard(string exp) {

    Expression* prefix;
    queue<char> outputQueue;
    stack<char> operatorsStack;
    char token;

    // reverse the expression for convinency. (removing char from the end).
    std::reverse(exp.begin(), exp.end());
    // while there is a token to read:
    while (exp != "") {

        // read the first character we have now to token.
        token = exp[exp.length() - 1];

        // if token is a digit, we just push it to the
        if(isdigit(token))
            outputQueue.push(token);
        if(isOperator(token))
            operatorsStack.push(token);

// TODO: contine function.

    }
    return prefix;
}

// helping function to determine if a char represent one of our operators.
bool isOperator(char token) {
    if (token == '+' ||
        token == '-' ||
        token == '*' ||
        token == '/')
    {
        return true;
    } else {
        return false;
    }

}
