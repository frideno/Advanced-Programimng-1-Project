//
// Created by omri on 12/15/18.
//

#ifndef PROG1PROJECT_OPENDATASERVER_H
#define PROG1PROJECT_OPENDATASERVER_H

#include "../Command.h"
#include <string>
#include "../Sockets/FlightDataGetterSetter.h"


using namespace std;

class OpenDataServerCommand: public Command {
private:
    int _sockfd = 0;

    // list of all symbolNames for flight.
    static const vector<string> _flightSymbols;

    // take all flight symbols from server to maps.
    void getAllFlightSymbols();

    // opens a server socket, that can recieve data from client - flight simulator.
    void openServer(int port, int rate);

    void task1(vector<string>& args);

protected:

    vector<string>& args;
public:

    // constructor:
    OpenDataServerCommand(vector<string>& v):
        args(v) {};

    // command method:
        bool goBackArg(string &current) override;

    void doCommand() override;

    bool anotherArg(string &current) override;


};
#endif //PROG1PROJECT_OPENDATASERVER_H
