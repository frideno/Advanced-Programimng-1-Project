//
// Created by omri on 12/17/18.
//

#include "ConditionParser.h"
#include "../Interperter.h"


void ConditionParser::doCommand(vector<string> args) {

    int i = 0;

    string conditionString = "";
    // parse the condition part;

    while(args[i] != "{") {
        conditionString += args[i];
        i++;
    }

    // if no condtion lexed, than exception.
    if (conditionString == "")
        throw ("Conditional has no opening brackets \"{\"");

    // moving i to skip {.
    i++;

    // interperter the shunting yard of expression into the condition, so we can caluclate it next.
    _condition = Interperter::shuntingYard(conditionString);

    // if last token is not } , expetion.
    if (args[args.size() - 1] != "}")
        throw ("Conditional missing closing brackets \"}\"");

    // getts the inside of the { } brackets so we can execute them.
    for(i; i < args.size(); i++)
        _statements.push_back(args[i]);

}

Expression *ConditionParser::getCondition() {
    return _condition;
}

vector<string> &ConditionParser::getStatements() {
    return _statements;
}
