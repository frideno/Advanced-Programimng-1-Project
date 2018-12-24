//
// Created by omri on 12/15/18.
//

#include "PrintCommand.h"
#include "../Interpreter.h"
#include "../Utils.h"
#include "../Databases/SymbolsDB.h"
#include "../Databases/ConstsDB.h"

void PrintCommand::doCommand() {
    string toPrint = args[0];

    // if we want to print a string in quatos, print it.
    if (toPrint[0] == '"' && toPrint[toPrint.length() -  1] == '"') {

        string withOutQuates = toPrint.substr(1, toPrint.length() - 2); // copies from pos =1, after the first quate.,
                                                                        // length - 2 chars ahead - all but quaots.
        cout << withOutQuates;
    } else {
        // getting next expression with shunting yard from args.

        vector<Expression*> extractedExpressions = Utils::blabla(args);
        cout << extractedExpressions[0]->calculate() << endl;

    }

}

bool PrintCommand::goBackArg(string &current) {

    // print command don't need to go back before print.
    return false;
}


bool PrintCommand::anotherArg(string &current) {

    // get until end of line.
    return current != ConstsDB::ENDLINE_KEYWORD;

}
