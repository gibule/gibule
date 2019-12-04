#include "gblsocket.h"

using namespace std;

namespace gbl {



Sockaddress::Sockaddress(string s, ushort a)
{
    inet_pton(AF_INET,s.c_str(),&ipadress.sin_addr);
    ipadress.sin_port=a;
    ipadress.sin_family=AF_INET;
}

std::string Sockaddress::getAddress()
{
char client_ip[100];
inet_ntop(AF_INET,&ipadress.sin_addr,client_ip,100);
return std::string(client_ip);


}





ushort Sockaddress::getPort()
{
    return ipadress.sin_port;

}



GBLSocket::GBLSocket()
{

}

}
