//
// Created by omri on 12/15/18.
//

#ifndef PROG1PROJECT_PRINTCOMMAND_H
#define PROG1PROJECT_PRINTCOMMAND_H

#include "../Command.h"

/**
 * PrintCommand class-
 * Command that prints a message.
 */
class PrintCommand : public Command{

    // do command override.
    void doCommand(std::vector<std:: string> args);

};


#endif //PROG1PROJECT_PRINTCOMMAND_H