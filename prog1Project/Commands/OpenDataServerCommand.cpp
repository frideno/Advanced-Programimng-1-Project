//
// Created by omri on 12/15/18.
//

#include "OpenDataServerCommand.h"
#include "NumberOfArgsToCommandException.h"
#include <stdexcept>
#include "../Utils.h"
#include "../Databases/SymbolsDB.h"
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include <thread>
#include <iostream>
#include <fcntl.h>

using namespace std;

const vector<string> OpenDataServerCommand::_FlightSymbols = {"\"/instrumentation/airspeed-indicator/indicated-speed-kt\"","\"/instrumentation/altimeter/indicated-altitude-ft\"","\"/instrumentation/altimeter/pressure-alt-ft\"","\"/instrumentation/attitude-indicator/indicated-pitch-deg\"","\"/instrumentation/attitude-indicator/indicated-roll-deg\"","\"/instrumentation/attitude-indicator/internal-pitch-deg\"","\"/instrumentation/attitude-indicator/internal-roll-deg\"","\"/instrumentation/encoder/indicated-altitude-ft\"","\"/instrumentation/encoder/pressure-alt-ft\"","\"/instrumentation/gps/indicated-altitude-ft\"","\"/instrumentation/gps/indicated-ground-speed-kt\"","\"/instrumentation/gps/indicated-vertical-speed\"","\"/instrumentation/heading-indicator/indicated-heading-deg\"","\"/instrumentation/magnetic-compass/indicated-heading-deg\"","\"/instrumentation/slip-skid-ball/indicated-slip-skid\"","\"/instrumentation/turn-indicator/indicated-turn-rate\"","\"/instrumentation/vertical-speed-indicator/indicated-speed-fpm\"","\"/controls/flight/aileron\"","\"/controls/flight/elevator\"","\"/controls/flight/rudder\"","\"/controls/flight/flaps\"","\"/controls/engines/engine/throttle\"","\"/engines/engine/rpm\""};

void task1(vector<string>& args);

void OpenDataServerCommand::getAllFlightSymbols() {

    string symbol;
    for(int i = 0; i < symbolsNames.size(); i++) {
        symbol = symbolsNames[i];
        double value = _socketManager->recieve("get " + symbol);
        SymbolsDB::setsymbol("\"" + symbol + "\"", value);
    }
}

void OpenDataServerCommand::doCommand(vector<string> &args) {

    //void (OpenDataServerCommand::*func)(vector<string>&);
    //func = &OpenDataServerCommand::task1;
    thread tDataServer(&OpenDataServerCommand::task1, this,  ref(args));

    tDataServer.join();
//    thread t_1(x, 0);
//
//    // joins it to main thread after it ends.
//    t_1.join();
}

/*
* task1 will be responsible of opening a server at the specified port (one of the argumnets in args).
* from this server we will listen to the fightgear and update values according to the information
* he will deliver us. this task will run in it's own thread, simultaneously with another threads so that
* we could run our program faster while making io requests.
*/
void OpenDataServerCommand::task1(vector<string>& args) {

    int port;
    double rate;

    // tring to tanslate port and rate to ints.
    try {
        port = (int) Utils::to_number(args[0]);
        rate = Utils::to_number(args[1]);
    }

    // chatches invalid argument of to_number if port or rate are not ints.
    catch(const std::invalid_argument& e){

        throw("failed opening server, invalid argument PORT or RATE is not representing an int");
    }

    int sockfd, newsockfd, clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int  n;

    /* First call to socket() function */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    /* Initialize socket structure */
    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);

    /* Now bind the host address using bind() call.*/
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    /* Now start listening for the clients, here process will
       * go in sleep mode and will wait for the incoming connection
    */

    listen(sockfd,5);
    clilen = sizeof(cli_addr);

    /* Accept actual connection from the client */
    fcntl(sockfd, F_SETFL, fcntl(sockfd, F_GETFL, 0) | O_NONBLOCK);
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t*)&clilen);

    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }

    /* If connection is established then start communicating */
    bzero(buffer,256);
    n = read( newsockfd,buffer,255 );

    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    printf("Here is the message: %s\n",buffer);

    /* Write a response to the client */
    n = write(newsockfd,"I got your message",18);

    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    _socketManager = new FlightSocketManager(sockfd);
    while(true) {
        getAllFlightSymbols();
    }

}


bool OpenDataServerCommand::anotherArg(string &current) {

    // get const amount of args - 2.
    return Utils::getNArguments(_internalUseN);
}

bool OpenDataServerCommand::goBackArg(string &current) {
    // open data server command don't need to go back to read before the keyword.
    return false;
}
