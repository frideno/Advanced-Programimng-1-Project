//
// Created by omri on 12/15/18.
//

#ifndef PROG1PROJECT_OPENDATASERVER_H
#define PROG1PROJECT_OPENDATASERVER_H

#include "../Command.h"

class OpenDataServerCommand: public Command {
public:
    bool goBackArg(string &current) override;

    void doCommand(vector<string> &args) override;

    bool anotherArg(string &current) override;

    // clonable:
    Command* clone() { return new OpenDataServerCommand(*this);}

private:
    int _internalUseN = 2;
};
#endif //PROG1PROJECT_OPENDATASERVER_H
