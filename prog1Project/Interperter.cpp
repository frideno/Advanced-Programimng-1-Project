/*
     Created by Omri and Gal on 12/9/18.
*/

#include "Interperter.h"
#include "Databases/ConstsDB.h"
#include <stack>
#include <algorithm>
#include "Databases/SymbolsDB.h"
#include "Expressions/ExpressionFactory.h"
#include "Utils.h"
#include "Expressions/Var.h"
/**
 * Shuting yard algortim -
 * get string @expression and return combined work of two functions
 * 1st - turns the infix expression to prefix expression as a vector of tokens (operators and numbers),
 * 2nd- turns the vector into an Expression object.
 *
 * */
Expression* Interperter::shuntingYard(vector<string>& tokens) {

    vector<string> postfixVector = shuntingYard_infixToPostfix(tokens);

    // use 2nd function on the result of the 1st.
    return shuntingYard_postfixToExpression(postfixVector);

}

/**
 * shunting yard algorithm - the string to vector of tokens (operators and numbers) part -
 * converts mathematical expression specified in infix notation, into prefix
 * [ for example - 3 * 4 + 5 ---> +(5, *(3, 4))]
 */
vector<string> Interperter::shuntingYard_infixToPostfix(vector<string>& tokens) {

    string prefix;
    vector<string> outputQueue;
    stack<string> operatorsStack;

    // while there is a token to read:
    std::map<string, int> op_precedence (ExpressionFactory::getOperatorsPrecedence());




    for(string& token: tokens) {
        if(ExpressionFactory::isNumber(token)) {

            outputQueue.push_back(token);
            // cout << "Add " << token << " to output" << endl;
        } else if (ExpressionFactory::isOperator(token)){
            while(!operatorsStack.empty() && operatorsStack.top() != "(" && ((op_precedence.at(operatorsStack.top()) > op_precedence.at(token))
                    || (op_precedence.at(operatorsStack.top()) == op_precedence.at(token) && ExpressionFactory::isLeftAccociative(token)))) {
                //cout << "Pop stack to output " << token << endl;
                outputQueue.push_back(operatorsStack.top());
                operatorsStack.pop();
            }
            operatorsStack.push(token);
            //cout << "Push " << token << " to stack" << endl;
        } else if(token == "(")
                operatorsStack.push(token);
        else if(token == ")") {
            while (!operatorsStack.empty() && operatorsStack.top() != "(") {
                outputQueue.push_back(operatorsStack.top());
                operatorsStack.pop();
                //cout << "Pop stack to output " << token << endl;
            }
            operatorsStack.pop();
            //cout << "Pop stack " << token << endl;

        }
    }
    while (!operatorsStack.empty()){
        outputQueue.push_back(operatorsStack.top());

        //cout << "Pop stack to output " << operatorsStack.top() << endl;

        operatorsStack.pop();

    }

    return outputQueue;

}

/*
 * Shunting yard algorithm second part - of our own -
 * turns the vector of tokens exp, and turn it into Expression object.
 * */
Expression* Interperter::shuntingYard_postfixToExpression(vector<string>& exp){

    int n = exp.size();

    /*
     * else, we can know that the last token in exp is an operator token, so as for what it is
     * we can make the expression, where the right value of it will be starting from exp sub string of
     * n -1, and the left will be at teh sub string of k , where k is the place right expression end at.
     */

    string token = exp[n-1];
    if(!ExpressionFactory::isOperator(token)) {

        // if the last token was not an operator,  then we want to just create a Number/varialbe out of it.
        exp.pop_back();
        double number;
        if (ExpressionFactory::isNumber(token)) {
          return new Number(Utils::to_int(token)); // cast from string of number , to int of the number.
        }
        // else, it is a variable, so we want to return it.
        else {

            // if the variable is a command keyword.
            if (ConstsDB::containsCommand(token)) {
                throw ("Variable with name of language keyword is not allowed");
            }
            // if the variable is a keyword like TRUE, FALSE, we will give it a keyword value by the map.
            if (ConstsDB::containsKeyword(token)) {
                return new Number(ConstsDB::getKeywordValue(token));
            }
            if (!SymbolsDB::containsSymbol(token)) {
                throw ("no symbol named " + token + "is defined.");
            } else {
                return new Var(token);
            }
        }

    } else {

        // if last token is operator, as said, we can remove it, and preform the function at the refrenced exp,
        // acutally modifing it, then get the right and left expressions.

        exp.pop_back();
        Expression* right = shuntingYard_postfixToExpression(exp);
        Expression* left = shuntingYard_postfixToExpression(exp);

        //create the result from the factory.

        Expression* result = ExpressionFactory::create(token, left, right);
        return result;

    }


}

void addTokenIfStartedNew(vector<string>& tokens, string& check1) {
    if(check1 != "") {
        tokens.push_back(check1);
        check1 = "";
    }
}


vector<string> Interperter::lexer(ifstream& script) {
    /*
     *
     * The lexer should read the source code character by character, and send tokens to the parser.

        After each token, it should use the next character cto decide what kind of token to read.

        if c is a digit, collect an integer as long as you read digits
        if c is a letter, collect an identifier as long as you read identifier characters (digit, letter, ')
        if c is a double quote, collect a string literal as long as you read characters other than a double quote
        if c is space character (i.e. space, newline, or tab), ignore it and read next character
     * */

    vector<string> tokens;

    // read from script to array of strings.
    for(string line; getline(script, line);)
    {
        string tmpNumber = "";
        string tmpOperator = "";
        string tmpVariable = "";
        string tmpString = "";
        bool stringFollow = false;
        for(char& c:line)
        {

            // if we following a string in qoutes, anything gets in the string.
            if (stringFollow) {

                // if we get a closing ", then save the string.
                if (c == '"') {
                    tokens.push_back(tmpString);
                    stringFollow = false;
                }

                    // else recieve the char into the string.
                else
                    tmpString += c;

            }
                // if not, seperate by char:
            else {


                // if the char is space, we will ignore it and submit all tmps.
                if (c == ' ')  {
                    addTokenIfStartedNew(tokens, tmpNumber);
                    addTokenIfStartedNew(tokens, tmpVariable);
                    addTokenIfStartedNew(tokens, tmpOperator);
                }

                    // if the char is a digit, we will add it to the tmp number, that gains near digits.
                else if (isdigit(c)) {

                    //if an operaqtor came before digit, we will push it to tokens.
                    addTokenIfStartedNew(tokens, tmpOperator);

                    // but if it was letter before digits, its fine because we can have variables with
                    //  both letters and digits. else it is a number.
                    if (tmpVariable != "") {
                        tmpVariable += c;
                    } else {
                        tmpNumber += c;
                    }
                    // if it is a letter or an underscore:
                } else if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == '_') {

                    addTokenIfStartedNew(tokens, tmpNumber);
                    addTokenIfStartedNew(tokens, tmpOperator);
                    tmpVariable += c;
                }
                    // if it is a quotes mark, we start writing into a string and save the others.
                else if (c == '"') {
                    addTokenIfStartedNew(tokens, tmpNumber);
                    addTokenIfStartedNew(tokens, tmpOperator);
                    stringFollow = true;
                }

                    // else, it is an operator or brackets, so we will add the last tmp number created, if it is not empty,
                    // and reset it, and add the the operator to the tokens.
                else {
                    addTokenIfStartedNew(tokens, tmpNumber);
                    addTokenIfStartedNew(tokens, tmpVariable);
                    tmpOperator += c;
                }
            }

            // push an indicator of end of line.
        }

        // adds the variables that gained after the loop if not added before.
        addTokenIfStartedNew(tokens, tmpNumber);
        addTokenIfStartedNew(tokens, tmpOperator);
        addTokenIfStartedNew(tokens, tmpVariable);
        tokens.push_back(ConstsDB::ENDLINE_KEYWORD);


    }
    return tokens;
}


void Interperter::parser(vector<string> commands) {

    int index = 0;

    // while the index is before teh end of commands size.
    while(index < commands.size()) {

        vector<string> args;

        // gain vars until a keyword.
        while (!ConstsDB::containsCommand(commands[index])) {
            args.push_back(commands[index]);
            index++;
        }

        // creates a command by the command keyword.
        Command* com = ConstsDB::getCommand(commands[index]);

        // substruct index backwards while the command ask for go back
        while(com->goBackArg(commands[index])) {
            index--;
        }
        // skip the keyword:
        index++;

        // adds a args while the command ask for another.
        while(com->anotherArg(commands[index])) {
            args.push_back(commands[index]);
            index++;
        }

        // command object do the command on the arguments list.
        com->doCommand(args);

        // skips the last argument to move to next keyword.
        index++;
    }

//    int index = 0;
//    while (index < commands.size()) {
//
//        // create a command by the map of commands:
//        Command* c = ConstsDB::getCommand(commands[index]);
//
//        // creates the variables to command by all tokens until another command word;
//        vector<string&> variables;
//
//        // if the command is a block - we recieve variables until }.
//        if (c->isBlockCommand()) {
//            int bracketMaazan = 0;
//            while (commands[index] != "}" || (commands[index] == "}" && bracketsMaazan != 0)) {
//
//                // for each {, we increase maazan by 1, and for each } decrease, so know that is the right } at end.
//                variables.push_back(commands[index]);
//                index++;
//
//                if (commands[index] == "{")
//                    bracketMaazan ++;
//            }
//            // push the }.
//            variables.push_back(commands[index]);
//        }
//
//        // else, just get the few next variables by the command property.
//        else {
//
//        }
//
//        // do command of c.
//        c->doCommand(variables);
//
//        // TODO: check number of variables is not wrong.
//    }


}
