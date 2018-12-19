//
// Created by omri on 12/15/18.
//

#include "PrintCommand.h"
#include "NumberOfArgsToCommandException.h"
#include "../Interperter.h"
#include "../Utils.h"


void PrintCommand::doCommand(vector<string> &args) {
    return;
}

bool PrintCommand::goBackArg(string &current) {

    // print command don't need to go back before print.
    return false;
}


bool PrintCommand::anotherArg(string &current) {

    // get const amout of anotehr args - 1.
    return Utils::getNArguments(1);

}
