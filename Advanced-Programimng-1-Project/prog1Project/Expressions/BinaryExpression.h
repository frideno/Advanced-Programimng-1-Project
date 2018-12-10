//
// Created by omri on 12/10/18.
//

#ifndef PROG1PROJECT_BINARYEXPRESSION_H
#define PROG1PROJECT_BINARYEXPRESSION_H

#include "Expression.h"
/*
 * interface BinaryExpression, which is an Expression
 * has left and right expression, and
 * */
class BinaryExpression : public Expression {
private:

    std::string _sign;
    Expression* _left;
    Expression* _right;
public:

    // getter: returns left expression.
    Expression* getLeft() { return _left;};

    // getter: returns right expression.
    Expression* getRight() {return _right;};

    // getter: return the sign of the expression (string).
    std::string getSign() {return _sign;};

    // (abstract) constructor.
    BinaryExpression(Expression* left, Expression* right):
            _left(left), _right(right) {}

    // abstract method that the operation implements.
    virtual  double operation(double val1, double val2) = 0;

    double calculate() {
        return operation(_left->calculate(), _right->calculate());
    }
};

#endif //PROG1PROJECT_BINARYEXPRESSION_H
