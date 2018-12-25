//
// Created by omri on 12/20/18.
//

#include "Enviroment.h"
#include <iostream>
#include "Utils.h"
#include "Interpreter.h"
#include "Databases/ConstsDB.h"


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
    if (Utils::to_number(option) == 1)
        FileOperation();
    else if (Utils::to_number(option) == 2)
        CommandlineOperation();
    else
        cout << ">> Wrong answer. GoodBye.";

}

void Enviroment::CommandlineOperation() {
// test parser:
    try {
        Interpreter *i = new Interpreter();

        string line = ConstsDB::ENDLINE_KEYWORD;
        while (line != "done") {

            try {
                // if the command is to operate a script from file - run "../fileName"
                if (line.length() > 6 && line.substr(0, 3) == "run") {
                    string fileName = line.substr(5, line.length() - 6);

                    runScriptFromFile(fileName);
                }
                // e
                // lse lex and parse the line.
                else {
                    i->lexer(line);
                    i->parser();
                }
                getline(cin, line);


                // get another line.
            } catch (BasicException& be) {
                cout << EXCEPTION_WAS_THROWN << " " << be.what() << endl;
                delete i;
                ConstsDB::destroyAllDB();
                exit(1);
            } catch (...){
                cout << "unknown exception was thrown." << endl;
                delete i;
                ConstsDB::destroyAllDB();
                exit(1);

            }

        }
    } catch (...) {
        exit(1);
    }

}

void Enviroment::FileOperation() {

    cout << endl << ">> Enter file name:" << endl << "<< ";
    string fileName;
    cin >> fileName;

    //  run from the file entered to terminal.
    runScriptFromFile(fileName);
}

void Enviroment::runScriptFromFile(std::string &fileName) {

    ifstream file( "../"  + fileName);
    if (file.is_open()) {
        Interpreter *i = new Interpreter();
        try {
            string line;
            while (getline(file, line)) {
                i->lexer(line);
                i->parser();

            }
        }   catch (BasicException& be) {
            cout <<  EXCEPTION_WAS_THROWN << " " << EXCEPTION_WAS_THROWN << " " << be.what() << endl;
            delete i;
            ConstsDB::destroyAllDB();
            exit(1);
        } catch (...){
            cout << "unknown exception was thrown." << endl;
            delete i;
            ConstsDB::destroyAllDB();
            exit(1);

        }
    ConstsDB::destroyAllDB();

    } else {
        cout << ">> File didn't found. GoodBye.";

    }
}
