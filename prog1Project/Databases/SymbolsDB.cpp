//
// Created by omri on 12/16/18.
//
#include "SymbolsDB.h"

const double SymbolsDB::UNINTILIZED_VAR_DEFAULT = 0;
map<string, double> SymbolsDB::_symbolTable;


double SymbolsDB::getsymbol(string symbolName) {
    // if symbol doesn't exsists, throw expception;

    if(_symbolTable.count(symbolName) == 0)
        throw("Symbol "+ symbolName +" not Exists"); // TODO: add such exception.

    // else, return the symbol at symbolName from table.
    return _symbolTable.at(symbolName);
}

void SymbolsDB::setsymbol(string symbolName, double symbolValue) {

    // if symbol not exsists, throw exception.
    if(_symbolTable.count(symbolName) == 0)
        throw("Symbo " + symbolName + " not Exsiss, can't assign.");

    // else, set the value of the symbol to symbolValue.
    _symbolTable[symbolName] = symbolValue;

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
