/*
     Created by Omri and Gal on 12/9/18.
*/
#include "Interperter.h"
#include "Expressions/ExpressionFactory.cpp"

#include <stack>
#include <algorithm>

/**
 * Shuting yard algortim -
 * get string @expression and return combined work of two functions
 * 1st - turns the infix expression to prefix expression as a vector of tokens (operators and numbers),
 * 2nd- turns the vector into an Expression object.
 *
 * */
Expression* Interperter::shuntingYard(string expression) {

    vector<string> tokens = filterExpressionString(expression);
    // use 1st function.
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
    std::map<string, int> op_precedence;
    op_precedence["+"] = 10;
    op_precedence["-"] = 10;
    op_precedence["*"] = 20;
    op_precedence["/"] = 20;
    op_precedence["^"] = 30;


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
    if(ExpressionFactory::isNumber(token)) {

        // if the last token was a number, then we want to just create a Number out of it.
        exp.pop_back();
        return new Number((int) stoi(token, nullptr, 10)); // cast from string of number , to int of the number.

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

// filter string representing expression into vector of tokens - (numbers, operators and brackets).

vector<string> Interperter::filterExpressionString(string expression) {

    // intilize tokens vector to empty.

    vector<string> tokens;
    string tmpNumber = "";

    // for each char at the expression:

    for(int i = 0; i < expression.length(); i++) {

        char c = expression[i];
        // if the char is space, we will ignore it.
        if(c == ' ') {
            continue;
        }

        // if the char is a digit, we will add it to the tmp number, that gains near digits.
        else if(isdigit(c)) {
            tmpNumber += c;
        }

        // else, it is an operator or brackets, so we will add the last tmp number created, if it is not empty,
        // and reset it, and add the the operator to the tokens.
        else {
            if(tmpNumber != "") {
                tokens.push_back(tmpNumber);
                tmpNumber = "";
            }
            // add the operator or brackets, to the tokens.
            string token = "";
            token += c;
            tokens.push_back(token);
        }
    }
    // add to tokens the last number created if exists.
    if(tmpNumber != "")
        tokens.push_back(tmpNumber);

    return tokens;

}
