//
// Created by omri on 12/15/18.
//

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

void OpenDataServerCommand::doCommand(vector<string> &args) {
    thead t1(task1, args);
}

/*
* task1 will be responsible of opening a server at the specified port (one of the argumnets in args).
* from this server we will listen to the fightgear and update values according to the information
* he will deliver us. this task will run in it's own thread, simultaneously with another threads so that
* we could run our program faster while making io requests.
*/
void task1(vector<string>& args) {
 // Create a socket
    int listening = socket(AF_INET, SOCK_STREAM, 0);
    if (listening == -1)
    {
        throw("can't create socket!");
    }
 
    // Bind the ip address and port to a socket
    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(args[0]);
    inet_pton(AF_INET, "0.0.0.0", &hint.sin_addr);
 
    bind(listening, (sockaddr*)&hint, sizeof(hint));
 
    // Tell Winsock the socket is for listening
    listen(listening, SOMAXCONN);
 
    // Wait for a connection
    sockaddr_in client;
    socklen_t clientSize = sizeof(client);
 
    int clientSocket = accept(listening, (sockaddr*)&client, &clientSize);
 
    char host[NI_MAXHOST];      // Client's remote name
    char service[NI_MAXSERV];   // Service (i.e. port) the client is connect on
 
    memset(host, 0, NI_MAXHOST);
    memset(service, 0, NI_MAXSERV);
 
    if (getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0)
    {
        cout << host << " connected on port " << service << endl;
    }
    else
    {
        inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
        cout << host << " connected on port " << ntohs(client.sin_port) << endl;
    }
 
    // Close listening socket
    close(listening);
 
    // While loop: accept and echo message back to client
    char buf[4096];
 
    while (true)
    {
        memset(buf, 0, 4096);
 
        // Wait for client to send data
        int bytesReceived = recv(clientSocket, buf, 4096, 0);
        if (bytesReceived == -1)
        {
            throw("Error in recv()");
        }
 
        if (bytesReceived == 0)
        {
            throw("Client disconnected");
        }
        
        /*
        cout << string(buf, 0, bytesReceived) << endl;
 
        // Echo message back to client
        send(clientSocket, buf, bytesReceived + 1, 0);
        */
        
        //here we should update the current data according to what the client sent to us............
    }
 
    // Close the socket
    close(clientSocket);
}

bool OpenDataServerCommand::anotherArg(string &current) {

    // get const amout of anotehr args - 2.
    return Utils::getNArguments(_internalUseN);
}

bool OpenDataServerCommand::goBackArg(string &current) {
    // open data server command don't need to go back to read before the keyword.
    return false;
}
