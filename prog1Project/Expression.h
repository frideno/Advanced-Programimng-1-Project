//
// Created by omri on 12/10/18.
//

#ifndef PROG1PROJECT_EXPRESSION_H
#define PROG1PROJECT_EXPRESSION_H

#include <string>

/*
 * Expression interface:
 * has a function of calculate the value of the expression..
 * */

class Expression {
public :

    virtual double calculate() = 0;
    virtual std::string toString() const = 0;

};
#endif //PROG1PROJECT_EXPRESSION_H
