//
// Created by omri on 12/15/18.
//

#include "OpenDataServerCommand.h"
#include <stdexcept>
#include "../Utils.h"
#include "../Databases/SymbolsDB.h"
#include "../Databases/ConstsDB.h"
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

const vector<string> OpenDataServerCommand::_flightSymbols = {"\"/instrumentation/airspeed-indicator/indicated-speed-kt\"","\"/instrumentation/altimeter/indicated-altitude-ft\"","\"/instrumentation/altimeter/pressure-alt-ft\"","\"/instrumentation/attitude-indicator/indicated-pitch-deg\"","\"/instrumentation/attitude-indicator/indicated-roll-deg\"","\"/instrumentation/attitude-indicator/internal-pitch-deg\"","\"/instrumentation/attitude-indicator/internal-roll-deg\"","\"/instrumentation/encoder/indicated-altitude-ft\"","\"/instrumentation/encoder/pressure-alt-ft\"","\"/instrumentation/gps/indicated-altitude-ft\"","\"/instrumentation/gps/indicated-ground-speed-kt\"","\"/instrumentation/gps/indicated-vertical-speed\"","\"/instrumentation/heading-indicator/indicated-heading-deg\"","\"/instrumentation/magnetic-compass/indicated-heading-deg\"","\"/instrumentation/slip-skid-ball/indicated-slip-skid\"","\"/instrumentation/turn-indicator/indicated-turn-rate\"","\"/instrumentation/vertical-speed-indicator/indicated-speed-fpm\"","\"/controls/flight/aileron\"","\"/controls/flight/elevator\"","\"/controls/flight/rudder\"","\"/controls/flight/flaps\"","\"/controls/engines/engine/throttle\"","\"/engines/engine/rpm\""};

void OpenDataServerCommand::openServer(int port, int rate) {


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
    //fcntl(sockfd, F_SETFL, fcntl(sockfd, F_GETFL, 0) | O_NONBLOCK);
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t*)&clilen);

    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }

    _sockfd = sockfd;
}

void OpenDataServerCommand::getAllFlightSymbols() {

    char buffer[1024];
    bzero(buffer,1024);
    int n = read(_sockfd,buffer, 1024);

    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    // translate the values from strings into a vector of string of double symbol values.
    string allValuesStrWithCommas(buffer);
    vector<string> allValuesStr = Utils::strSplit(allValuesStrWithCommas, ',');

    // translate the string values to double value.

    vector<double> allValuesDouble;
    for (int i = 0; i < allValuesStr.size(); i++) {
        allValuesDouble.push_back(Utils::to_number(allValuesStr[i]));
    }

    // if the number of recieved values is not like the number of requested numbers, throw exception.
    if (_flightSymbols.size() != allValuesDouble.size())
        throw("Error occured on reciving sampled flights symbols values.");

    // if its fine, sets the symbols at the symbol Table to be the values in allValuesDouble mathcing the order.

    for (int i = 0; i < _flightSymbols.size(); i++) {
        SymbolsDB::setSymbol(_flightSymbols[i], allValuesDouble[i]);
    }

    //0.000000,0.000000,1.193444,12.000000,40.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,270.010010,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000
}

void OpenDataServerCommand::doCommand() {

    thread tDataServer(&OpenDataServerCommand::task1, this, ref(args));
    tDataServer.join();

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

    // tring to tanslate port and rate to ints -from the args.
    try {

        // extracting next two expressions from the args.
        vector<Expression*> extractedExpressions = Utils::blabla(args);
        if (extractedExpressions.size() != 2)
            throw;

        port = (int) extractedExpressions[0]->calculate();
        rate = extractedExpressions[1]->calculate();

        cout << port << "---"  << rate << endl;
    }

    // chatches invalid argument of to_number if port or rate are not ints.
    catch(const std::invalid_argument& e){

        throw("failed opening server, invalid argument PORT or RATE is not representing an int");
    }


    // open server at port, that reads reads rate times a second.

    openServer(port, rate);

    // forever, sample all flight symbols.
    while(true) {

        // get all flight symbols from the client - the simulator.
        getAllFlightSymbols();

        // wait time so that it will be Hz = 10 times a second.

    }

}


bool OpenDataServerCommand::anotherArg(string &current) {

    // get until end of line.
    return current != ConstsDB::ENDLINE_KEYWORD;
}

bool OpenDataServerCommand::goBackArg(string &current) {
    // open data server command don't need to go back to read before the keyword.
    return false;
}
