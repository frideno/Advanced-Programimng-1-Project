#include <iostream>

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "Interperter.h"

using namespace std;;

#include <unistd.h>
#include <stdio.h>
#include <limits.h>

int main() {
    ifstream file("prac");

    if(file.is_open()) {
        vector<string> vs = Interperter::lexer(file);
        for(int i = 0; i < vs.size(); i++) {
            cout << vs[i] << ",";
        }
    } else {
        cout << "coud not open file";
    }

}