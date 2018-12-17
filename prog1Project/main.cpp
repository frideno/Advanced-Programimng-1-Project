#include <iostream>
#include "Expressions.h"
#include "Interperter.h"
#include <string>
#include <vector>
using namespace std;
int main() {
    // test for the expression interface:
     /*
    Plus* p = new Plus(new Mul(new Number(3), new Number(4)), new Number(3));
    cout << p->toString();
    cout << endl << p->calculate();
      */

     // test for the shunting yard string to string:
     Interperter* inter = new Interperter;
     string t2 = "var < 3";
      Expression* e = inter->shuntingYard(t2);
      cout << e->toString();
    return 0;
}