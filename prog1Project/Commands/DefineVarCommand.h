//
// Created by omri on 12/18/18.
//

#ifndef PROG1PROJECT_DEFINEVARCOMMAND_H
#define PROG1PROJECT_DEFINEVARCOMMAND_H

#include "../Command.h"

class DefineVarCommand : public Command{

private:
    int _internalUseN = 1;

public:
    bool goBackArg(string &current) override;

    void doCommand(vector<string> &args) override;

    bool anotherArg(string &current) override;

    // clonable:
    Command* clone() { return new DefineVarCommand(*this);}
};


#endif //PROG1PROJECT_DEFINEVARCOMMAND_H
