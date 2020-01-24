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
//     fstream f;
//     string a;
//     vector <string> v;

//     f.open("/home/dato/Projects/gibule/gibule/socket.cnfg",fstream::in);
//     while(!f.eof())
//     {
//         f>>a;
//         split(a,"=",v);



//     }
//     f.close();
    sd = socket(AF_INET, SOCK_STREAM,0);
    state = ssNew;
    return  (sd);
}

void GBLSocket::setState(SocketState ss)
{
    state = ss;
}

SocketState GBLSocket::getState()
{
    return state;
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
   //::perror("error:");
   if(c==0)
       state=ssConnected;
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
    ssize_t r = ::recv(sd,static_cast<char*>(data.data()),256,MSG_DONTWAIT);
    if(r==0)
    {
        state = ssDisconnected;
    }
    return r > 0;
}

bool GBLSocket :: sendData(string data)
{

    //std::cout << data << std::endl;
    ::send(sd,static_cast<const char*>(data.data()),data.size(),0);
   return true;

}

bool GBLSocket :: receiveData(string &data)
{
    char buf[256];
    ssize_t r = ::recv(sd,buf,256,MSG_DONTWAIT);
    if(r > 0)
    {
        data=string(buf,static_cast<size_t>(r));
    }
    else if(r==0)
    {
        state = ssDisconnected;
    }
    std::cout << "============  " << r << " state= " << state << std::endl;
    return r > 0;
}





}
