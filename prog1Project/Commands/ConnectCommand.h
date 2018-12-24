
#ifndef PROG1PROJECT_ConnectCommand_H
#define PROG1PROJECT_ConnectCommand_H

#include "../Command.h"
#include <string>

using namespace std;

class ConnectCommand: public Command {
private:
    int _socketfd;

protected:

    vector<string>& args;

public:

    // constructor:
    ConnectCommand(vector<string>& v):
        args(v) {};

    bool goBackArg(string &current) override;

    void doCommand() override;

    bool anotherArg(string &current) override;



private:
    int _internalUseN = 2;
};
#endif //PROG1PROJECT_OPENDATASERVER_H
