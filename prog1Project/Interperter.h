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
    map<string, Command> _commandsTable;
public:
    // lexer - from file, gets the next line of command into string[].
    vector<string> lexer(ifstream& script);

    // parser - from a commmandLine representing a command, parse it into command and do it.
    void parser(vector<string> command);

    // ‫‪Shunting-yard‬‬ of Dikstra - parse a string into a Expression (only binaries expressions).
    Expression* shunting-yard(string exp);

};
#endif //PROG1PROJECT_LEXER_H
