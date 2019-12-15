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

using namespace std;

namespace gbl  {


typedef vector<char> ByteArray;

class Sockaddress
{
public:

    Sockaddress();
    Sockaddress(string s, unsigned short int a);

    string getAddress();

    unsigned short int getPort ();

    struct sockaddr_in *getipaddress();


    struct sockaddr_in ipaddress;

private:

};


class GBLSocket
{
public:

    GBLSocket();
    GBLSocket(Sockaddress sockaddr);

    int init_socket();
    Sockaddress sockaddress;

    int bind();
    bool sendData(ByteArray data);
    bool receiveData(ByteArray &data);
    bool connect();
    bool sendData(string data);
    bool receiveData(string &data);
    void close();


    int sd;

private:




};


}
#endif // GBLSOCKET_H
