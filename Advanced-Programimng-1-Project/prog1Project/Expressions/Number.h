//
// Created by omri on 12/10/18.
//

#ifndef PROG1PROJECT_NUMBER_H
#define PROG1PROJECT_NUMBER_H
class Number {
private:

    double _value;
public:
    // constructor:
    Number(double num):
        _value(num) {};

    // getter of num.
    double calculate() { return _value; };

};
#endif //PROG1PROJECT_NUMBER_H
