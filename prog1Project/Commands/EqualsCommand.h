//
// Created by omri on 12/18/18.
//

#ifndef PROG1PROJECT_EQUALSCOMMAND_H
#define PROG1PROJECT_EQUALSCOMMAND_H

#include "../Command.h"

class EqualsCommand: public Command {
public:
    void doCommand(vector<string> &args) override;

    bool anotherArg(string &current) override;

    bool goBackArg(string &current) override;

};


#endif //PROG1PROJECT_EQUALSCOMMAND_H
