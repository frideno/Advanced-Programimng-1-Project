//
// Created by omri on 12/17/18.
//

#include "IfCommand.h"

void IfCommand::doCommand(std::vector<std::string>& args) {

    // do parent condition parser to get the condition and statements.
    ConditionParser::doCommand(args);

    if(getCondition()->calculate() > 0) {
        Interperter::parser(getStatements());
    }

}
