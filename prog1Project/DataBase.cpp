//
// Created by omri on 12/16/18.
//

#include "DataBase.h"

//intilizing const maps:
map<string, Command*> DataBase::_commandsByNames = DataBase::createCommandsByNames();

map<string, double> DataBase::_keywordValues = DataBase::createKeywordValues();;


double DataBase::getsymbol(string &symbolName) {
    // if command doesn't exsists, throw expception;

    if(_symbolTable.count(symbolName) == 0)
        throw("Symbol "+ symbolName +" not Exists"); // TODO: add such exception.

    // else, return the comomand at symbolName from table.
    return _symbolTable.at(symbolName);
}

void DataBase::addsymbol(string& symbolName, double symbolValue) {
    _symbolTable[symbolName] = symbolValue;

}

void DataBase::removesymbol(string &symbolName) {
    map<string, double>::iterator it = _symbolTable.find(symbolName);
    _symbolTable.erase(symbolName);
}

Command *DataBase::getCommand(string name) {
    if(_commandsByNames.count(name) != 0) {
        return  _commandsByNames.at(name);
    }
    else {
        throw("Command (keyword) name is not defined");
    }
}

double DataBase::getKeywordValue(string name) {
    if(_commandsByNames.count(name) != 0) {
        return  _keywordValues.at(name);
    }
    else {
        throw("Keyword is not defined");
    }
}
bool DataBase::containsKeyword(string name) {
    return _keywordValues.count(name) != 0;
}

bool DataBase::containsCommand(string name) {
    return _commandsByNames.count(name) != 0;
}
