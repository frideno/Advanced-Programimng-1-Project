//
// Created by omri on 12/10/18.
//

#ifndef PROG1PROJECT_Var_H
#define PROG1PROJECT_Var_H

#include "../Expression.h"
#include <iostream>
#include <cmath>
#include "../DataBase.cpp"

class Var : public Expression{
private:

   std::string _varName;
public:
    // constructor:
    explicit Var(std::string varName):
        _varName(varName) {};

    // getter for Var:
    std::string getVar() const {return _varName;};

    // getter of num.
    double calculate() { return DataBase::getsymbol(_varName); };

    //output operator:
    friend std::ostream& operator<<(std::ostream& output, const Var& Var) {
        output << Var.toString();
        return output;
    }
    std::string toString() const {return _varName; }
};
#endif //PROG1PROJECT_Var_H
