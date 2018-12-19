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

public:
    bool anotherArg(string &current) override;

    void doCommand(vector<string> &args) override;

    bool goBackArg(string &current) override;

};


#endif //PROG1PROJECT_PRINTCOMMAND_H
