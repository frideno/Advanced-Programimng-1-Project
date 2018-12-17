//
// Created by omri on 12/11/18.
//

#ifndef ADVANCED_PROGRAMIMNG_1_PROJECT_COMMAND_H
#define ADVANCED_PROGRAMIMNG_1_PROJECT_COMMAND_H

#include <string>
#include <vector>
/**
 *  Command interface.
 *  we can do a command out of string array representing a command.
 */
 class Command {

 public:
     virtual void doCommand(std::vector<std:: string> args) = 0;
     //virtual int numberOfArgumentsNedded() = 0;
 };
#endif //ADVANCED_PROGRAMIMNG_1_PROJECT_COMMAND_H
