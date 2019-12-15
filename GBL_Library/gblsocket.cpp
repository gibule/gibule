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

GBLSocket::GBLSocket()
{

}


void GBLSocket::close()
{
    ::close(sd);
}

 int GBLSocket::init_socket()
{
    sd = socket(AF_INET, SOCK_STREAM, 0);
    return  (sd);

}

int GBLSocket::bind()
{
//    int b=::bind(sd,(struct sockaddr*)sockaddress.getipaddress(),sizeof (sockaddr_in));
    int b=::bind(sd,reinterpret_cast<struct sockaddr*>(sockaddress.getipaddress()),sizeof (sockaddr_in));
    return b;
}
bool GBLSocket::connect()
{

   int c= ::connect(sd,reinterpret_cast<struct sockaddr*>(sockaddress.getipaddress()),sizeof (sockaddr_in));

   ::perror("error:");
   return c==0;

}

GBLSocket :: GBLSocket(Sockaddress sockaddr) : sockaddress(sockaddr)
{

}

bool GBLSocket :: sendData(ByteArray data)
{
     ::send(sd,static_cast<char*>(data.data()),data.size(),0);
    return true;
}

bool GBLSocket :: receiveData(ByteArray &data)
{
//    ::recv(sd,(char*)data.data(), data.size(),MSG_DONTWAIT);
    ::recv(sd,static_cast<char*>(data.data()),data.size(),MSG_DONTWAIT);
    return true;
}

bool GBLSocket :: sendData(string data)
{

    std::cout << data << std::endl;
    ::send(sd,static_cast<const char*>(data.data()),data.size(),0);
   return true;

}

bool GBLSocket :: receiveData(string &data)
{
    //std::cout << "===============================" << std::endl;
    char *buf=(char*)malloc(255);
    size_t sz=255;
    //::recv(sd,buf,sz,MSG_DONTWAIT);
    ssize_t r = ::recv(sd,buf,sz,0);
    if(r > 0)
    {
        data=string(buf,(size_t)r);
    }

    std::cout << "============  " << r << std::endl;

    return r > 0;

    //std::cout << buf << std::endl;

}





}
