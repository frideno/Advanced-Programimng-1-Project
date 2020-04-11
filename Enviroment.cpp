//
// created by omri & gal on 12/20/18.
//

#include "Enviroment.h"
#include <iostream>
#include "Utils.h"
#include "Interpreter.h"
#include "Databases/ConstsDB.h"


using namespace std;


void Enviroment::CommandlineOperation() {
// test parser:
    try {
        Interpreter *i = new Interpreter();

        string line = ConstsDB::ENDLINE_KEYWORD;
        while (line != "exit") {

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
                throw;
            } catch (...){
                cout << "unknown exception was thrown." << endl;
                delete i;
                throw;

            }

        }
        delete i;

    } catch (...) {
        throw;
    }

}


void Enviroment::runScriptFromFile(std::string &fileName) {

    ifstream file(fileName);
    if (file.is_open()) {
        Interpreter *i = new Interpreter();
        try {
            string line;
            while (getline(file, line)) {
                // if the command is to operate a script from file - run "../fileName"
                if (line.length() > 6 && line.substr(0, 3) == "run") {

                    string fileName = line.substr(5, line.length() - 6);
                    runScriptFromFile(fileName);
                }
                i->lexer(line);
                i->parser();

            }
        }   catch (BasicException& be) {
            cout <<  EXCEPTION_WAS_THROWN << " "  << " " << be.what() << endl;
            delete i;
            throw;

        } catch (...){
            cout << "unknown exception was thrown." << endl;
            delete i;
            ConstsDB::destroyAllDB();
            throw;

        }
    } else {
        cout << ">> File didn't found. GoodBye.";

    }
}

Enviroment::~Enviroment() {
    ConstsDB::destroyAllDB();

}
