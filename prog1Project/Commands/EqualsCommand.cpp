//
// Created by omri on 12/18/18.
//

#include "EqualsCommand.h"
#include "../Utils.h"
#include "../Databases/ConstsDB.h"
#include "../Databases/SymbolsDB.h"
void EqualsCommand::doCommand(vector<string> &args) {
    // TODO: handle bind.
    // arguments are: varName, = , ..... (expression).

    string varName = args[0];
    vector<string> expressionArgs(args.begin() + 2, args.end());

    // creates an expression with shunting yard.
    Expression* e = Interperter::shuntingYard(expressionArgs);

    // assign value of expression to varName;
    SymbolsDB::setsymbol(varName, e->calculate());

}

bool EqualsCommand::anotherArg(string &current) {
    // get the whole line.
    return !(current == ";");   //TODO
}

bool EqualsCommand::goBackArg(string &current) {

    // go back 1, to a var name to assigned to.
    Utils::getNArguments(1);
}
