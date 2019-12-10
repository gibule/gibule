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
#include <vector>
#include <gblworker.h>
using namespace std;

namespace gbl  {


typedef std::vector<char> ByteArray;

class Sockaddress
{
public:

    Sockaddress();
    Sockaddress(string s, unsigned short int a);

    std::string getAddress();

    unsigned short int getPort ();

    struct sockaddr_in *getipaddress();


    struct sockaddr_in ipaddress;

private:

};


class GBLSocket
{
public:
GBLSocket(Sockaddress sockaddr);

    int init_socket();
    Sockaddress sockaddress;

    int bind();
    bool sendData(ByteArray data);
    bool receiveData(ByteArray &data);

    int sd;

private:




};


}
#endif // GBLSOCKET_H
