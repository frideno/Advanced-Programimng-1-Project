//
// Created by omri on 12/17/18.
//

#ifndef PROG1PROJECT_CONDITIONPARSER_H
#define PROG1PROJECT_CONDITIONPARSER_H

#include "../Command.h"
#include "../Expressions.h"
#include "../Interperter.h"
#include <vector>
#include <string>
#include <map>
using namespace std;

class ConditionParser : public Command{

private:

    // condition expression.
    Expression* _condition;

    // script of statements to execute:
    Interperter* _statesmentsInterpreter;
protected:

    //getters:

    Expression* getCondition();
    Interperter* getStatementsInterpreter();

    int _innerUseN = 1;

public:
    void doCommand(std::vector<std::string>& args) override;

    bool anotherArg(string &current)override;

    bool goBackArg(string &current) override;

    // clonable:
    Command* clone() { return new ConditionParser(*this);}

};


#endif //PROG1PROJECT_CONDITIONPARSER_H
