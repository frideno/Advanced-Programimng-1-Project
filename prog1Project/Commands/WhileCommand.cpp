//
// Created by omri on 12/17/18.
//

#include "WhileCommand.h"

void WhileCommand::doCommand(std::vector<std::string>& args) {

    // do parent condition parser to get the condition and statements.
    ConditionParser::doCommand(args);

    while(getCondition()->calculate() > 0) {
        getStatementsInterpreter()->parser();

    }

}
