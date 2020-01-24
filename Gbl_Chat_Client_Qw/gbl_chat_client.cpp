#include "gbl_chat_client.h"


GBL_Chat_Client::GBL_Chat_Client()
{


}
GBL_Chat_Client::GBL_Chat_Client(string addr, unsigned short int port)
{
    sa=Sockaddress(addr,port);
    socket=GBLSocket(sa);
}

void GBL_Chat_Client::onstart()
{


    socket.init_socket();
    if(socket.connect())
        std::cout << "OK" << std::endl;
    else
        std::cout << "ERROR" << std::endl;
}
void GBL_Chat_Client::onwork()
{


    vector<string> :: iterator it;
    for (it=sndmsg.begin();it!=sndmsg.end();it++)
    {
        socket.sendData(string("127.0.0.1@")+*it);
    }
    sndmsg.clear();
    sleep(1);

    string s;


    if(socket.receiveData(s))
        cout << s << endl;
}
void GBL_Chat_Client::onstop()
{
    socket.close();


}
