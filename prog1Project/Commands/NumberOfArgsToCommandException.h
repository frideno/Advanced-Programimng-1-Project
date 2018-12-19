////
//// Created by omri on 12/15/18.
////
//
//#ifndef PROG1PROJECT_NUMBEROFARGSTOCOMMANDEXCEPTION_H
//#define PROG1PROJECT_NUMBEROFARGSTOCOMMANDEXCEPTION_H
//
//#include <exception>
//#include <string>
//// expeption of wrong number of args to command .
//class NumberOfArgsToCommandException: std::exception{
//
//private:
//    std::string _commandDescription = "";
//    int _expectedNumberOfArgs;
//    int _givenNumberOfArgs;
//public:
//    NumberOfArgsToCommandException(std::string commandDesc, int expected, int given):
//        _commandDescription(commandDesc), _expectedNumberOfArgs(expected), _givenNumberOfArgs(given) {};
//
//    virtual const char* what() const throw() {
//        return "Wrong number of Command arguments, in " + _commandDescription + " Command.\nExpected: " + std::to_string(_expectedNumberOfArgs) + " arguments, given " +
//                std::to_string(_givenNumberOfArgs) + " arguments.".c_str();
//    }
//};
//#endif //PROG1PROJECT_NUMBEROFARGSTOCOMMANDEXCEPTION_H
