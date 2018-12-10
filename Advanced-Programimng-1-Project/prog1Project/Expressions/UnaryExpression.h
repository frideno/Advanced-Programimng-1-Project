//
// Created by omri on 12/10/18.
//

#ifndef PROG1PROJECT_UNARYEXPRESSION_H
#define PROG1PROJECT_UNARYEXPRESSION_H

#include "Expression.h"
/*
 * interface UnaryExpression, which is an Expression of only one expression.
 * */
class BinaryExpression : public Expression {
private:
    Expression* _expression;
    // returns the expression..
    Expression* getExpresssion() {
        return _expression;
    }

    // abstract method that the operation implements.
    virtual  double operation(double val) = 0;

    double calculate() {
        return operation(_expression->calculate());
    }
};
#endif //PROG1PROJECT_UNARYEXPRESSION_H
