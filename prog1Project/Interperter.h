/*
     Created by omri on 12/9/18.
*/

#ifndef PROG1PROJECT_LEXER_H
#define PROG1PROJECT_LEXER_H
#include <vector>
#include <string>
#include <map>
#include <fstream>
#include "Command.h"
#include "Expressions.h"
using namespace std;
/*
 *  class Interperter:
 *  constits of few main functionalities:
 *  to lexe from file or command line into strings array
 *  to parse from the string array into the map of variables - commands.
 *  to
*/

class Interperter {
private:
    map<string, double> _symbolTable;
   // map<string, Command> _commandsTable;


    // shunting-yard algorithm - from string of expression in infix - to vector of strings representing numbers
    // and operators, in prefix.
    vector<char> shuntingYard_infixToPostfix(string exp);

    // ‫‪Shunting-yard‬‬ of Dikstra - parse a string into a Expression (only binaries expressions).
    Expression* shuntingYard_postfixToExpression(vector<char>& exp);
public:

    // lexer - from file, gets the next line of command into string[].
    vector<string> lexer(ifstream& script);

    // parser - from a commmandLine representing a command, parse it into command and do it.
    void parser(vector<string> command);

    Expression* shuntingYard(string expression);


};
#endif //PROG1PROJECT_LEXER_H
