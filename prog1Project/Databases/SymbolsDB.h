//
// Created by omri on 12/16/18.
//

#ifndef PROG1PROJECT_DATABASE_H
#define PROG1PROJECT_DATABASE_H

#include "../Expressions.h"
#include <string>
#include <map>
#include "../Command.h"
#include "../Sockets/FlightDataGetterSetter.h"

using namespace std;

class SymbolsDB {

private:
    // symbol table-  variables name to their value.
    static const double UNINTILIZED_VAR_DEFAULT;
    static map<string, double> _symbolTable;
    static map<string, string> _bindTable;  // TODO: check if maybe change to <string, list<string>> if you can be binded to more than one.
    static FlightDataGetterSetter* _socketManager;

    // returns if the symbolName starts and ends with paraheses means it is a source var.
public:
    static bool isSourceSymbol(string symbolName);

    // earase a parantheses from source symbol string.
    static string getPath(string sourceSymbolName);

public:

    // dinamicly changed map methods:

    // get a symbol value named after name.
    static  double getSymbol(string symbolName);

    // add a symbol by defualt value;
    static void addSymbol(string symbolName);


    // adds a (symbolName, symbol ovalue) to symbols map.
    static void setSymbol(string  symbolName, double symbolValue);

    // removes a (symbolName, symbol value) from symbols map.
    static void removeSymbol(string symbolName);

    // return if a symbol named symbolName is in the symbolTable.
    static bool containsSymbol(string symbolName);

    // binds two var names between them - adds to bind map, and set var1 to be var2.
    static void bind(string var1, string var2);

    // check if two vars with those names are binded in bind map.
    static bool isBinded(string var1, string var2);

    static vector<string> getSymbolsNames();

    // set the flightGear socket to be as teh sockfd.
    static void setSocket(int sockfd);

    // get the socket sender.
    static FlightDataGetterSetter *get_socketManager();

};



#endif //PROG1PROJECT_DATABASE_H
