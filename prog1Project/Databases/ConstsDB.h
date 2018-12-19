//
// Created by omri on 12/18/18.
//

#ifndef PROG1PROJECT_CONSTSDB_H
#define PROG1PROJECT_CONSTSDB_H

#include "../Expressions.h"
#include <string>
#include <map>
#include "../Command.h"
#include "../Commands/PrintCommand.h"
#include "../Commands/WhileCommand.h"
#include "../Commands/IfCommand.h"
#include "../Commands/SemicolonCommand.h"
#include "../Commands/EqualsCommand.h"
#include "../Commands/DefineVarCommand.h"
#include "../Commands/OpenDataServerCommand.h"

class ConstsDB {

private:

// initliztion of string names to command object map:
    static map<string, Command*> createCommandsByNames();

    // intiliztion of string names to keyword values map:

    static map<string, double> createKeywordValues();

    // keyword defualt variables name to value.
    static map<string, double> _keywordValues;

    // commands table - between name and command object.
    static  map<string, Command *> _commandsByNames;

public:
    static char ENDLINE_KEYWORD[1];

    // get a command object by name.
    static Command *getCommand(string name);

    static bool containsCommand(string name);

    // get a keyword value by name.
    static double getKeywordValue(string name);

    // check if a keyword exsists.
    static bool containsKeyword(string name);

};

#endif //PROG1PROJECT_CONSTSDB_H
