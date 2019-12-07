#include "gblsocket.h"


namespace gbl  {

Sockaddress::Sockaddress()
{


}

 Sockaddress::Sockaddress(string s, unsigned short int a)
{
    inet_pton(AF_INET,s.c_str(),&ipaddress.sin_addr);
    ipaddress.sin_port=a;
    ipaddress.sin_family=AF_INET;
}

 std::string Sockaddress::getAddress()
 {
     char client_ip[98];

     inet_ntop(AF_INET,&ipaddress.sin_addr,client_ip,98);

     return std::string (client_ip);

 }

unsigned short int Sockaddress::getPort()
{
    return ipaddress.sin_port;
}

struct sockaddr_in* Sockaddress::getipaddress()
{

    return &ipaddress;


}
 int GBLSocket::init_socket()
{
    sd = socket(AF_INET, SOCK_STREAM, 0);
    return  (sd);

}

int GBLSocket::bind()
{

    int b=::bind(sd,(struct sockaddr*)sockaddress.getipaddress(),sizeof (sockaddr_in));

    return b;
}


GBLSocket :: GBLSocket(Sockaddress sockaddr) : sockaddress(sockaddr)
{

}





}
