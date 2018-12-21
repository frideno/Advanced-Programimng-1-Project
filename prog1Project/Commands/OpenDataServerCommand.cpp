//
// Created by omri on 12/15/18.
//

#include "OpenDataServerCommand.h"
#include "NumberOfArgsToCommandException.h"
#include <stdexcept>
#include "../Utils.h"

void OpenDataServerCommand::doCommand(vector<string> &args) {

    try {
        // tanslate port and rate to ints.

        int port = Utils::to_int(args[0]);
        int rate = Utils::to_int(args[1]);

        // open a thread to run the server.


    }
        // chatches invalid argument of to_int if port or rate are not ints.
    catch(const std::invalid_argument& e){

        throw("failed opening server, invalid argument PORT or RATE is not representing an int");
    }

}

bool OpenDataServerCommand::anotherArg(string &current) {

    // get const amout of anotehr args - 2.
    return Utils::getNArguments(_internalUseN);
}

bool OpenDataServerCommand::goBackArg(string &current) {
    // open data server command don't need to go back to read before the keyword.
    return false;
}
