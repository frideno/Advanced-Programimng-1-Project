//
// Created by omri on 12/17/18.
//

#include "ConditionParser.h"
#include "../Interperter.h"

Expression *ConditionParser::getCondition() {
    return _condition;
}

vector<string> &ConditionParser::getStatements() {
    return _statements;
}

void ConditionParser::doCommand(vector<string>& args) {

    int i = 0;

    vector<string> conditionVec;

    // lex the condition part;

    while(args[i] != "{") {
        conditionVec.push_back(args[i]);
        i++;
    }

    // if no condtion lexed, than exception.
    if (conditionVec.size() == 0)
        throw ("Conditional has no condition declared");

    // moving i to skip {.
    i++;

    // interperter the shunting yard of expression into the condition, so we can caluclate it next.
    _condition = Interperter::shuntingYard(conditionVec);

    // if last token is not } , expetion.
    if (args[args.size() - 1] != "}")
        throw ("Conditional missing closing brackets \"}\"");

    // getts the inside of the { } brackets so we can execute them.
    for(i; i < args.size(); i++)
        _statements.push_back(args[i]);

}

bool ConditionParser::anotherArg(string &current) {

    // stop when a } sign show, and the balance of { and } are 0.

    static int balance = 0;

    // if the current token is {, we raise the balance by 1, becuase another } will come before ours.

    if(current == "{")
        balance++;

    // if the current token is }, we take the balance off by 1, because a matching { was there before.
    if(current == "}") {
        balance--;

        // if the } is here, and a balance of } achieved, then we can stop reading characters.
        if(balance == 0)
            return false;

        if (balance < 0)
            throw("an unappropriate } was defined, without suited {");
    }

    // continue reading if it was not } with balance of 0.
    return true;
}

bool ConditionParser::goBackArg(string &current) {

    // condition parser dont need to read things before the keyword.
    return false;
}
