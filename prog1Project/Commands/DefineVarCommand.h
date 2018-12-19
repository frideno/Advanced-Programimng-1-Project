//
// Created by omri on 12/18/18.
//

#ifndef PROG1PROJECT_DEFINEVARCOMMAND_H
#define PROG1PROJECT_DEFINEVARCOMMAND_H

#include "../Command.h"

class DefineVarCommand : public Command{
public:
    bool goBackArg(string &current) override;

public:
    void doCommand(vector<string> &args) override;

    bool anotherArg(string &current) override;
};


#endif //PROG1PROJECT_DEFINEVARCOMMAND_H
