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
    vector<string> _statements;
protected:

    //getters:

    Expression* getCondition();
    vector<string>& getStatements();

public:
    void doCommand(std::vector<std::string> args) override;

};


#endif //PROG1PROJECT_CONDITIONPARSER_H
