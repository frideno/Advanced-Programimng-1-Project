//
// Created by omri on 12/20/18.
//

#include "Enviroment.h"
#include <string>
#include <iostream>
#include "Utils.h"
#include "Interperter.h"


using namespace std;

// asks for input - if to operate from command line - 2, or file - 1, and operates.
void Enviroment::operation() {

    // user dialog;
    string option;
    cout << ">> At what platform would you like to program at?" << endl;
    cout << ">> For input from FILE press 1." << endl << ">> For input from TERMINAL press 2." << endl << endl;
    cout << "<< ";
    cin >> option;
    cout << endl ;
    if (Utils::to_int(option) == 1)
        FileOperation();
    else if (Utils::to_int(option) == 2)
        CommandlineOperation();
    else
        cout << ">> Wrong answer. GoodBye.";

}

void Enviroment::CommandlineOperation() {
// test parser:
    try {
        Interperter* i = new Interperter();

        string line = ";";
        while (line != "done") {
            i->lexer(line);
            i->parser();
            getline(cin, line);

        }
    } catch (exception e) {
        cout << e.what();
    }
}

void Enviroment::FileOperation() {

    cout << endl << ">> Enter file name:" << endl << "<< ";
    string fileName;
    cin >> fileName;

    ifstream file("../prac");
    if (file.is_open()) {
        Interperter* i = new Interperter();
        string line;
        while (getline(file, line)) {
            i->lexer(line);
            i->parser();
            getline(cin, line);

        }


    } else {
        cout << ">> File didn't found. GoodBye.";

    }

}
