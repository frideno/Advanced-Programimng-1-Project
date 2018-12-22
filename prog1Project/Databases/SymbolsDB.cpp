//
// Created by omri on 12/16/18.
//
#include "SymbolsDB.h"

const double SymbolsDB::UNINTILIZED_VAR_DEFAULT = 0;
map<string, double> SymbolsDB::_symbolTable;
map<string, string> SymbolsDB::_bindTable;
FlightSocketManager* SymbolsDB::_socketManager = nullptr;

double SymbolsDB::getsymbol(string symbolName) {
    // if symbol doesn't exsists, throw expception;

    // if it is a symbol describes an source path, get it from the flights server - last value, update the table.

    if (isSourceSymbol(symbolName))
    {
        _symbolTable[symbolName] = _socketManager->recieve("get " + getPath(symbolName));
    }

    if(_symbolTable.count(symbolName) == 0)
        throw("Symbol "+ symbolName +" not Exists"); // TODO: add such exception.

    // else, return the symbol at symbolName from table.

    return _symbolTable.at(symbolName);
}

void SymbolsDB::setsymbol(string symbolName, double symbolValue) {

    // if symbol not exsists, throw exception.

//    if(_symbolTable.count(symbolName) == 0)
//        throw("Symbol " + symbolName + " not Exsiss, can't assign.");

    // else, set the value of the symbol to symbolValue.

    _symbolTable[symbolName] = symbolValue;

    // if it is a symbol describes an source path, send a request to the server to set this symbol at thems also.

    if (isSourceSymbol(symbolName)) {
        _socketManager->send("set " + getPath(symbolName) + " " + to_string(symbolValue));
    }

    // if symbolName is binded to other variable, we will change the other also.

    if(_bindTable.count(symbolName) != 0) {
        string& other = _bindTable.at(symbolName);
        _symbolTable.at(other) = symbolValue;

        //  if the other is source symbol change it in server.

        if (isSourceSymbol(other)) {
            _socketManager->send("set " + getPath(other) + " " + to_string(symbolValue));
        }
    }

}
bool SymbolsDB::isSourceSymbol(string token) {
    return (token.length() > 2 && token[0] == '"' && token[token.length() - 1] == '"');
}

string SymbolsDB::getPath(string sourceSymbolName) {

   if (sourceSymbolName.length() > 3) {
       sourceSymbolName =  sourceSymbolName.substr(1, sourceSymbolName.length() - 2);

       // if the path start with / , cancel it.
       if (sourceSymbolName[0] == '/')
           sourceSymbolName = sourceSymbolName.substr(1, sourceSymbolName.length() - 1);
   }
   return sourceSymbolName;
}



void SymbolsDB::removesymbol(string symbolName) {
    map<string, double>::iterator it = _symbolTable.find(symbolName);
    _symbolTable.erase(symbolName);
}

bool SymbolsDB::containsSymbol(string symbolName) {
    return _symbolTable.count(symbolName) != 0;
}

void SymbolsDB::addsymbol(string symbolName) {
    _symbolTable[symbolName] = UNINTILIZED_VAR_DEFAULT;
}

bool SymbolsDB::isBinded(string var1, string var2) {

    // if one is binded to the other in the map, return true;

    if((_bindTable.count(var1) != 0 && _bindTable.at(var1) == var2)
        || (_bindTable.count(var1) != 0 && _bindTable.at(var1) == var2))
        return true;

    // else, return false;
    return false;
}

void SymbolsDB::setSocket(int sockfd) {
    _socketManager = new FlightSocketManager(sockfd);
}

FlightSocketManager *SymbolsDB::get_socketManager() {
    return _socketManager;
}

void SymbolsDB::bind(string var1, string var2) {

//    if (!containsSymbol(var1) || !containsSymbol(var2))
//        throw ("Can't bind if left or right expression is not decrlared.");

    // adds var1, var2 to bind table and also var 2, var 1.
    _bindTable[var1] = var2;
    _bindTable[var2] = var1;

}
