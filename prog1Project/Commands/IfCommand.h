//
// Created by omri on 12/17/18.
//

#ifndef PROG1PROJECT_IfCOMMAND_H
#define PROG1PROJECT_IfCOMMAND_H

#include "../Command.h"
#include "ConditionParser.h"

class IfCommand: public ConditionParser{
public:
    void doCommand(std::vector<std::string>& args) override;

    // clonable:
    Command* clone() { return new IfCommand(*this);}

};


#endif //PROG1PROJECT_IfCOMMAND_H
