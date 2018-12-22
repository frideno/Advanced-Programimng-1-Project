
#include "OpenDataServerCommand.h"
#include "NumberOfArgsToCommandException.h"
#include <stdexcept>
#include "../Utils.h"
include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <thread>

using namespace std;

void ConnectCommand::doCommand(vector<string> &args) {
    thead t1(task1, args);
}

/*
* task1 will be responsible of opening a client at the specified ip and port (two of the argumnets in args).
* this client socket will allow us to change variables in the fightgear and update values according to the information
* we will get from the final client. this task will run in it's own thread, simultaneously with another threads so that
* we could run our program faster while making io requests.
*/
void task1(vector<string>& args) {

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
    {
        throw("problems creating socket!");
    }

    //	Create a hint structure for the server we're connecting with
    int port = args[1];
    string ipAddress = args[0];

    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(port);
    inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);

    //	Connect to the server on the socket
    int connectRes = connect(sock, (sockaddr*)&hint, sizeof(hint));
    if (connectRes == -1)
    {
        throw("problem connecting to socket!");
    }

    //	While loop:
    char buf[4096];
    string userInput;


    do {
        
        /*
        //		Enter lines of text
        cout << "> ";
        getline(cin, userInput);

        //		Send to server
        int sendRes = send(sock, userInput.c_str(), userInput.size() + 1, 0);
        if (sendRes == -1)
        {
            cout << "Could not send to server! Whoops!\r\n";
            continue;
        }

        //		Wait for response
        memset(buf, 0, 4096);
        int bytesReceived = recv(sock, buf, 4096, 0);
        if (bytesReceived == -1)
        {
            cout << "There was an error getting response from server\r\n";
        }
        else
        {
            //		Display response
            cout << "SERVER> " << string(buf, bytesReceived) << "\r\n";
        }
        
        
        */ //here we should send information to the flightgear. that information will come from the user,
           //and we will need to change it to be suitable to the flightgear variables and send it the data.
        
        
    } while(true);

    //	Close the socket
    close(sock);

}

bool ConnectCommand::anotherArg(string &current) {

    // get const amout of anotehr args - 2.
    return Utils::getNArguments(_internalUseN);
}

bool ConnectCommand::goBackArg(string &current) {
    // connect command don't need to go back to read before the keyword.
    return false;
}
