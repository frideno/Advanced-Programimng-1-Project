
#include "ConnectCommand.h"
#include "NumberOfArgsToCommandException.h"
#include <stdexcept>
#include "../Utils.h"
#include "../Databases/SymbolsDB.h"
#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <thread>
#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>

#include <string.h>

using namespace std;

void task(vector<string>& args);

void ConnectCommand::doCommand(vector<string> &args) {
    thread t1(task, ref(args));
    t1.join();
}

/*
* task1 will be responsible of opening a client at the specified ip and port (two of the argumnets in args).
* this client socket will allow us to change variables in the fightgear and update values according to the information
* we will get from the final client. this task will run in it's own thread, simultaneously with another threads so that
* we could run our program faster while making io requests.
*/
void task(vector<string>& args) {

        int sockfd, port, n;
        struct sockaddr_in serv_addr;
        struct hostent *server;

        char buffer[256];

        try {
            port = (int) Utils::to_number(args[1]);
            server = gethostbyname(args[0].c_str());


        }
        catch (exception& e){
            throw ("failed connecting to server, invalid argument PORT or RATE is not representing an int");
        }
        /* Create a socket point */
        sockfd = socket(AF_INET, SOCK_STREAM, 0);

        if (sockfd < 0) {
            perror("ERROR opening socket");
            exit(1);
        }


        if (server == NULL) {
            fprintf(stderr,"ERROR, no such host\n");
            exit(0);
        }

        bzero((char *) &serv_addr, sizeof(serv_addr));
        serv_addr.sin_family = AF_INET;
        bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
        serv_addr.sin_port = htons(port);

        /* Now connect to the server */
        if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
            perror("ERROR connecting");
            exit(1);
        }

        /* Now ask for a message from the user, this message
           * will be read by server
        */

        SymbolsDB::setSocket(sockfd);



}

bool ConnectCommand::anotherArg(string &current) {

    // get const amout of anotehr args - 2.
    return Utils::getNArguments(_internalUseN);
}

bool ConnectCommand::goBackArg(string &current) {
    // open data server command don't need to go back to read before the keyword.
    return false;
}
