//
// Created by omri on 12/12/18.
//

#ifndef PROG1PROJECT_EXPRESSIONFACTORY_H
#define PROG1PROJECT_EXPRESSIONFACTORY_H

#include "Expression.h"
class ExpressionFactory {

public:

    // create functions, which create expression by the token representing them.
    //Expression* create(char function, Expression* exp);
    static Expression* create(char operatora, Expression* left, Expression* right);

    // helping function to determine if a char represent one of our operators.
    static bool isOperator(char token);

    // helping function to determine if a char represent one of our operators, that is left associative,
    // means that a~b~c = (a~b)~c.
    static bool isLeftAccociative(char operat);

};


#endif //PROG1PROJECT_EXPRESSIONFACTORY_H
