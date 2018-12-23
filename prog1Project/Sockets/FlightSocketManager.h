//
// Created by omri on 12/22/18.
//

#ifndef PROG1PROJECT_FlightSocketManager_H
#define PROG1PROJECT_FlightSocketManager_H

#include <map>
#include <string>

using namespace std;

/**
 * this class is responsible for manaing sockets and sending messages through them.
 */
class FlightSocketManager {

private:
    int _socketfd;

public:

    // constructor.
    FlightSocketManager(int _socketfd) : _socketfd(_socketfd) {}

    // sends a message through the socket.
    double recieve(string message);

    void send(string message);
};


#endif //PROG1PROJECT_FlightSocketManager_H