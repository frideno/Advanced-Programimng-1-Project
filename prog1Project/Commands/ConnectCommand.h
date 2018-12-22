
#ifndef PROG1PROJECT_ConnectCommand_H
#define PROG1PROJECT_ConnectCommand_H

#include "../Command.h"
#include <string>

using namespace std;

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