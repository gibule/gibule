#ifndef GBLSOCKET_H
#define GBLSOCKET_H
#include <iostream>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

using namespace std;

namespace  gbl {



class Sockaddress
{

public:
    Sockaddress(string s, ushort a);

    string getAddress();
    ushort getPort();


private:
    struct sockaddr_in ipadress;


};


class GBLSocket
{
public:
    GBLSocket();

};

}
#endif // GBLSOCKET_H
