
#ifndef PROG1PROJECT_ConnectCommand_H
#define PROG1PROJECT_ConnectCommand_H

#include "../Command.h"
#include <string>

using namespace std;

class ConnectCommand: public Command {
private:
    int _socketfd;
public:
    bool goBackArg(string &current) override;

    void doCommand(vector<string> &args) override;

    bool anotherArg(string &current) override;

    // clonable:
    Command* clone() { return new ConnectCommand(*this);}


private:
    int _internalUseN = 2;
};
#endif //PROG1PROJECT_OPENDATASERVER_H
