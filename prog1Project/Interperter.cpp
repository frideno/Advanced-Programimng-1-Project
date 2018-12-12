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

    // TODO: make the expression paser of 1st function , work with spaces in the string.
    // TODO: make the epxression parser of 1st function, work with numbers that are more than one digit, then changing from char to string the tokens.
    // use 1st function.
    vector<char> postfixVector = shuntingYard_infixToPostfix(expression);

    // use 2nd function on the result of the 1st.
    return shuntingYard_postfixToExpression(postfixVector);

}

/**
 * shunting yard algorithm - the string to vector of tokens (operators and numbers) part -
 * converts mathematical expression specified in infix notation, into prefix
 * [ for example - 3 * 4 + 5 ---> +(5, *(3, 4))]
 */
vector<char> Interperter::shuntingYard_infixToPostfix(string exp) {

    string prefix;
    vector<char> outputQueue;
    stack<char> operatorsStack;

    // while there is a token to read:
    std::map<char, int> op_precedence;
    op_precedence['+'] = 10;
    op_precedence['-'] = 10;
    op_precedence['*'] = 20;
    op_precedence['/'] = 20;
    op_precedence['^'] = 30;


    for(char& token: exp) {
        if(isdigit(token)) {

            outputQueue.push_back(token);
            // cout << "Add " << token << " to output" << endl;
        } else if (ExpressionFactory::isOperator(token)){
            while(!operatorsStack.empty() && operatorsStack.top() != '(' && ((op_precedence.at(operatorsStack.top()) > op_precedence.at(token))
                    || (op_precedence.at(operatorsStack.top()) == op_precedence.at(token) && ExpressionFactory::isLeftAccociative(token)))) {
                //cout << "Pop stack to output " << token << endl;
                outputQueue.push_back(operatorsStack.top());
                operatorsStack.pop();
            }
            operatorsStack.push(token);
            //cout << "Push " << token << " to stack" << endl;
        } else if(token == '(')
                operatorsStack.push(token);
        else if(token == ')') {
            while (!operatorsStack.empty() && operatorsStack.top() != '(') {
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
Expression* Interperter::shuntingYard_postfixToExpression(vector<char>& exp){

    int n = exp.size();

    /*
     * else, we can know that the last token in exp is an operator token, so as for what it is
     * we can make the expression, where the right value of it will be starting from exp sub string of
     * n -1, and the left will be at teh sub string of k , where k is the place right expression end at.
     */

    char token = exp[n-1];
    if(isdigit(token)) {

        // if the last token was a number, then we want to just create a Number out of it.
        exp.pop_back();
        return new Number(token - '0'); // cast from char of number , to int of the number.

    } else if(ExpressionFactory::isOperator(token)) {

        // if last token is operator, as said, we can remove it, and preform the function at the refrenced exp,
        // acutally modifing it, then get the right and left expressions.

        exp.pop_back();
        Expression* right = shuntingYard_postfixToExpression(exp);
        Expression* left = shuntingYard_postfixToExpression(exp);

        //create the result from the factory.

        Expression* result = ExpressionFactory::create(token, left, right);
        return result;

    } else {
        // if token is not a number or an operator, there must be a syntax mistake.
        return nullptr;
    }


}
