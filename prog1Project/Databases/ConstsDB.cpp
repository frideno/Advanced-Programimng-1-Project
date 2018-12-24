//
// Created by omri on 12/18/18.
//

#include "ConstsDB.h"
#include "../Commands/Creators.h"
//intilizing const maps:

const string ConstsDB::ENDLINE_KEYWORD = ";";

// inner use to intilize maps:

map<string, CommandCreator*> ConstsDB::createCommandsByNames() {

map<string, CommandCreator*> m =
        {{ "if", new IfCommandCreator() }, { "while", new WhileCommandCreator() },
         { "openDataServer", new OpenDataServerCommandCreator() }, { "print", new PrintCommandCreator()} ,
         {ConstsDB::ENDLINE_KEYWORD, new SemicolonCommandCreator()}, {"=", new EqualsCommandCreator()},
         {"var", new DefineVarCommandCreator()}, {"connect", new ConnectCommandCreator()}, {"sleep", new SleepCommandCreator()}
        };

    // TODO: insert var, connect, =, bind.
    return m;
};

// now create the maps:
map<string, CommandCreator*> ConstsDB::_commandsByNames = ConstsDB::createCommandsByNames();

map<string, double> ConstsDB::_keywordValues = ConstsDB::createKeywordValues();

map<string, double> ConstsDB::createKeywordValues() {
    map<string, double> m = {{ "true", 1 }, { "false", 0 }};
    return m;
};

Command* ConstsDB::createCommand(string name, vector<string>& args) {
    if(_commandsByNames.count(name) != 0) {
        // TODO: CHANGE TO FACTORY.
        return _commandsByNames.at(name)->create(args);
    }
    else {
        throw("Command (keyword) name is not defined");
    }

}

CommandCreator *ConstsDB::getCommand(string name) {
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

