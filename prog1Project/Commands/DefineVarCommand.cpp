//
// Created by omri on 12/18/18.
//

#include "DefineVarCommand.h"
#include "../Utils.h"
#include "../Databases/SymbolsDB.cpp"
#include "../Databases/ConstsDB.cpp"

void DefineVarCommand::doCommand(vector<string> &args) {

    string varName = args[0];

    // if the variable name is a command keyword.
    if (ConstsDB::containsCommand(varName)) {
        throw ("Variable with name of language keyword is not allowed");
    }

    // defualt value of unintilize varialbe.
    SymbolsDB::addsymbol(varName);
}

bool DefineVarCommand::anotherArg(string &current) {

    return Utils::getNArguments(_internalUseN);

    // varCommand defined by: "var x"


}

bool DefineVarCommand::goBackArg(string &current) {
    // varCommand is not need anything before var.
    return false;
}
