//
// created by omri & gal on 12/10/18.
//

#ifndef PROG1PROJECT_SMALLER_H
#define PROG1PROJECT_SMALLER_H


#include "../BinaryExpression.h"

class Smaller : public BinaryExpression {

public:

    // constructor.
    Smaller(Expression* left, Expression* right):
        BinaryExpression("<", left, right) {}

    // the implementation of operation - Smaller.
    double operation(double var1, double var2) {return var1 < var2;};
};


#endif //PROG1PROJECT_SMALLER_H
