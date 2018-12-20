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
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include "Databases/SymbolsDB.h"

int main() {
    ifstream file("../prac");
    char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)) != NULL)
        printf("Current working dir: %s\n", cwd);
    if(file.is_open()) {
        // test lexer:
        vector<string> vs = Interperter::lexer(file);
//        for(int i = 0; i < vs.size(); i++) {
//
//            cout << vs[i] << ",";
//            if(vs[i] == ";")
//                cout << endl;
//        }

    // test parser:
    try {
        Interperter::parser(vs);
        cout <<endl << "x: " << SymbolsDB::getsymbol("x");
    } catch (exception e) {
        cout << e.what();
    }

    } else {
        cout << "could not open file";
    }

}