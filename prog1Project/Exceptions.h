//
// Created by omri on 12/25/18.
//

#ifndef PROG1PROJECT_EXCEPTIONS_H
#define PROG1PROJECT_EXCEPTIONS_H

#include <exception>
#include <string>
using namespace std;

class BasicException : exception{
protected:
    const char* _message;

public:
    BasicException(string message):
            _message(message.c_str()) {}

    virtual const char* what() const throw() {
        return _message;
    }

};


class SymbolException : BasicException{
public:
    SymbolException(string message):
            BasicException(message) {};
};


class DevisionByZeroException: BasicException{
public:
    DevisionByZeroException(string m):
    BasicException(m) {};
};



class ServerException : BasicException{
public:
    ServerException(string message):
    BasicException(message) {};
};


class FlightsServerException : BasicException{
public:
    FlightsServerException(string message):
    BasicException(message) {};
};

class KeywordException : BasicException{
public:
    KeywordException(string message):
    BasicException(message) {};
};


class BadArgumentsException : BasicException{
public:
    BadArgumentsException(string message):
    BasicException(message) {};
};

class BracketsException : BasicException{
public:
    BracketsException(string message):
            BasicException(message) {};
};


class CommandException : BasicException{
public:
    CommandException(string message):
            BasicException(message) {};
};

class ConditionalException : BasicException{
public:
    ConditionalException(string message):
            BasicException(message) {};
};


#endif //PROG1PROJECT_EXCEPTIONS_H
