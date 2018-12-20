//
// Created by omri on 12/18/18.
//

#ifndef PROG1PROJECT_SEMICOLONCOMMAND_H
#define PROG1PROJECT_SEMICOLONCOMMAND_H

#include "../Command.h"

class SemicolonCommand: public Command{
public:
    void doCommand(vector<string> &args) override {
        // do nothing as ;.
    }

    bool anotherArg(string &current) override {
        // ; command don't need no more arguments. it does nothing.
        return false;
    }

    bool goBackArg(string &current) override {
        // ; command don't need to go back before it. it does nothing.
        return false;
    }

    // clonable:
    Command* clone() { return new SemicolonCommand(*this);}
};
#endif //PROG1PROJECT_SEMICOLONCOMMAND_H
