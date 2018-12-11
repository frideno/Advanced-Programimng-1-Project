#include <iostream>
#include "Expressions.h"
using namespace std;
int main() {
    Plus* p = new Plus(new Mul(new Number(3), new Number(4)), new Number(3));
    cout << p->toString();
    cout << endl << p->calculate();
    return 0;
}