//
// Created by omri on 12/15/18.
//

#include "PrintCommand.h"
#include "NumberOfArgsToCommandException.h"
#include "../Interperter.h"
#include "../Utils.h"
#include "../Databases/SymbolsDB.h"

void PrintCommand::doCommand(vector<string> &args) {
    string toPrint = args[0];

    // if we want to print a string in quatos, print it.
    if (toPrint[0] == '"' && toPrint[toPrint.length() -  1] == '"') {

        string withOutQuates = toPrint.substr(1, toPrint.length() - 2); // copies from pos =1, after the first quate.,
                                                                        // length - 2 chars ahead - all but quaots.
        cout << withOutQuates;
    } else {
        cout << SymbolsDB::getsymbol(toPrint);
    }

}

bool PrintCommand::goBackArg(string &current) {

    // print command don't need to go back before print.
    return false;
}


bool PrintCommand::anotherArg(string &current) {

    // get const amout of anotehr args - 1.
    return Utils::getNArguments(_internalUseN);

}
