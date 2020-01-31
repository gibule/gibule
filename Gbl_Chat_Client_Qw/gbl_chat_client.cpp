#include "gbl_chat_client.h"
#include "mainwindow.h"


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

    vector<string> :: iterator it2;
    for (it2=sndreg.begin();it2!=sndreg.end();it2++)
    {
        socket.sendData(string("REG@")+*it2);
    }
    sndreg.clear();

//=================================================================================

    vector<string> :: iterator it;
    for (it=sndmsg.begin();it!=sndmsg.end();it++)
    {
        socket.sendData(string("192.168.0.112@")+*it);
    }
    sndmsg.clear();
    sleep(1);

    string s;


    if(socket.receiveData(s))
    {
        cout << s << endl;
        datalist.append(QString::fromStdString(s));
    }
}
void GBL_Chat_Client::onstop()
{
    socket.close();


}
