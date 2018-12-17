//
// Created by omri on 12/15/18.
//

#ifndef PROG1PROJECT_OPENDATASERVER_H
#define PROG1PROJECT_OPENDATASERVER_H

#include "../Command.h"

class OpenDataServerCommand: public Command {

    // do command override.
    void doCommand(std::vector<std::string> args);
};
#endif //PROG1PROJECT_OPENDATASERVER_H
