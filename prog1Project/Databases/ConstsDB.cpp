//
// Created by omri on 12/18/18.
//

#include "ConstsDB.h"
//intilizing const maps:

const string ConstsDB::ENDLINE_KEYWORD = ";";

// inner use to intilize maps:

map<string, Command*> ConstsDB::createCommandsByNames() {

map<string, Command*> m =
        {{ "if", new IfCommand() }, { "while", new WhileCommand() },
         { "openDataServer", new OpenDataServerCommand() }, { "print", new PrintCommand()} ,
         {ConstsDB::ENDLINE_KEYWORD, new SemicolonCommand()}, {"=", new EqualsCommand()},
         {"var", new DefineVarCommand()}
        };

    // TODO: insert var, connect, =, bind.
    return m;
};

// now create the maps:
map<string, Command*> ConstsDB::_commandsByNames = ConstsDB::createCommandsByNames();

map<string, double> ConstsDB::_keywordValues = ConstsDB::createKeywordValues();

map<string, double> ConstsDB::createKeywordValues() {
    map<string, double> m = {{ "true", 1 }, { "false", 0 }};
    return m;
};

Command* ConstsDB::createCommand(string name) {
    if(_commandsByNames.count(name) != 0) {
        // TODO: CHANGE TO FACTORY.
        return _commandsByNames.at(name)->clone();
    }
    else {
        throw("Command (keyword) name is not defined");
    }

}

Command *ConstsDB::getCommand(string name) {
    if(_commandsByNames.count(name) != 0) {
        return  _commandsByNames.at(name);
    }
    else {
        throw("Command (keyword) name is not defined");
    }
}

double ConstsDB::getKeywordValue(string name) {
    if(_commandsByNames.count(name) != 0) {
        return  _keywordValues.at(name);
    }
    else {
        throw("Keyword is not defined");
    }
}
bool ConstsDB::containsKeyword(string name) {
    return _keywordValues.count(name) != 0;
}

bool ConstsDB::containsCommand(string name) {
    return _commandsByNames.count(name) != 0;
}

