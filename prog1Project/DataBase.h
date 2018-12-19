//
// Created by omri on 12/16/18.
//

#ifndef PROG1PROJECT_DATABASE_H
#define PROG1PROJECT_DATABASE_H

#include "Expressions.h"
#include <string>
#include <map>
#include "Command.h"
#include "Commands/PrintCommand.h"
#include "Commands/WhileCommand.h"
#include "Commands/IfCommand.h"
#include "Commands/OpenDataServerCommand.h"
using namespace std;

class DataBase {

private:
    // symbol table-  variables name to their value.
    static map<string, double> _symbolTable;


    // initliztion of string names to command object map:
    static map<string, Command*> createCommandsByNames() {

        map<string&, Command*> m = {{ "if", new IfCommand() }, { "while", new WhileCommand() },
                                    { "openDataServer", OpenDataServerCommand() }, { "print", new PrintCommand() }};

        // TODO: insert var, connect, =, bind.
        return m;
    };

    // intiliztion of string names to keyword values map:

    static map<string, double> createKeywordValues() {
         map<string, double> m = {{ "true", 1 }, { "false", 0 }};
        return m;
    };

    // keyword defualt variables name to value.
    static  map<string, double> _keywordValues;

    // commands table - between name and command object.
    static  map<string, Command *> _commandsByNames;

public:

    // const values maps:

    // get a command object by name.
    static Command *getCommand(string name);

    static bool containsCommand(string name);

    // get a keyword value by name.
    static double getKeywordValue(string name);

    // check if a keyword exsists.
    static bool containsKeyword(string name);


    // dinamicly changed map:

    // get a symbol value named after name.
    static  double getsymbol(string& symbolName);

    // adds a (symbolName, symbol ovalue) to symbols map.
    static void addsymbol(string&  symbolName, double symbolValue);

    // removes a (symbolName, symbol value) from symbols map.
    static void removesymbol(string& symbolName);

};


#endif //PROG1PROJECT_DATABASE_H
