//
// Created by omri on 12/16/18.
//
#include "SymbolsDB.h"

const double SymbolsDB::UNINTILIZED_VAR_DEFAULT = 0;
map<string, double> SymbolsDB::_symbolTable;
map<string, string> SymbolsDB::_bindTable;


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
        throw("Symbol " + symbolName + " not Exsiss, can't assign.");

    // else, set the value of the symbol to symbolValue.
    _symbolTable[symbolName] = symbolValue;

    // if symbolName is binded to other variable, we will change the other also.
    if(_bindTable.count(symbolName) != 0) {
        string& other = _bindTable.at(symbolName);
        _symbolTable.at(other) = symbolValue;
    }

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

void SymbolsDB::bind(string var1, string var2) {

    if (!containsSymbol(var1) || !containsSymbol(var2))
        throw ("Can't bind if left or right expression is not decrlared.");

    // adds var1, var2 to bind table and also var 2, var 1.
    _bindTable[var1] = var2;
    _bindTable[var2] = var1;

    _symbolTable.at(var1) = _symbolTable.at(var2);
}
