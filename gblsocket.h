#ifndef GBLSOCKET_H
#define GBLSOCKET_H
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <thread>
#include <atomic>
#include <mutex>
using namespace std;

namespace gbl  {



class Sockaddress
{
public:
    Sockaddress(string s, unsigned short int a);

    std::string getAddress();

    unsigned short int getPort ();

    struct sockaddr_in *getipaddress();



private:


struct sockaddr_in ipaddress;






};


class GBLSocket
{
public:
GBLSocket(Sockaddress sockaddr);

    int socket_descriptor();
    Sockaddress sockaddress;

    int bind();


private:

    int sd;


};


}
#endif // GBLSOCKET_H
