//
// Created by omri on 12/17/18.
//

#ifndef PROG1PROJECT_WHILECOMMAND_H
#define PROG1PROJECT_WHILECOMMAND_H

#include "../Command.h"
#include "ConditionParser.h"

class WhileCommand :public ConditionParser{
public:
    void doCommand(std::vector<std::string>& args) override;

    // clonable:
    Command* clone() { return new WhileCommand(*this);}

};


#endif //PROG1PROJECT_WHILECOMMAND_H
