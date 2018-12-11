//
// Created by omri on 12/10/18.
//

#ifndef PROG1PROJECT_NUMBER_H
#define PROG1PROJECT_NUMBER_H

#include "Expression.h"
#include <iostream>

class Number : public Expression{
private:

    double _value;
public:
    // constructor:
    Number(double num):
        _value(num) {};

    // getter for number:
    double getNumber() const {return _value;};

    // getter of num.
    double calculate() { return _value; };

    //output operator:
    friend std::ostream& operator<<(std::ostream& output, const Number& number) {
        output << number.toString();
        return output;
    }
    std::string toString() const  { return  std::to_string(_value);}

};
#endif //PROG1PROJECT_NUMBER_H
