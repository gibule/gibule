#include "gblchatclient.h"

GBLChatClient::GBLChatClient(string addr, unsigned short int port)
{

    sa=Sockaddress(addr,port);
    socket=GBLSocket(sa);
}
void GBLChatClient::onstart()
{


    socket.init_socket();
    if(socket.connect())
        std::cout << "OK" << std::endl;
    else
        std::cout << "ERROR" << std::endl;

}

void GBLChatClient::onwork()
{

  //      socket.sendData(string ("Message from client: ")+std::to_string());
    vector<string> :: iterator it;
    for (it=sndmsg.begin();it!=sndmsg.end();it++)
    {
        socket.sendData(string("127.0.0.1@")+*it);
    }
    sndmsg.clear();
    sleep(1);

    string s;
    //s.resize(100);

    if(socket.receiveData(s))
        cout << s << endl;
}
void GBLChatClient::onstop()
{
    socket.close();


}
