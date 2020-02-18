#include "gbl_chat_client.h"
#include "mainwindow.h"
//#include "dialog.h"

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
    //===============================REG====================
    vector<string> :: iterator it2;
    for (it2=sndreg.begin();it2!=sndreg.end();it2++)
    {
        socket.sendData(string("REG@")+*it2);
    }
    sndreg.clear();

    //===============================LOG====================
    vector<string> :: iterator it3;
    for (it3=sndlog.begin();it3!=sndlog.end();it3++)
    {
        socket.sendData(string("LOG@")+*it3);
    }
    sndlog.clear();



    //===============================Chat====================

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
//        if (s=="Accepted")
//        {
//            regresult="You have been successfully registered";
//        }
//        else if (s=="Declined")
//        {
//            regresult="The account name is already in use. Please choose another name";
//        }
//        else
//        {






//        }
        datalist.append(QString::fromStdString(s));
    }
}
void GBL_Chat_Client::onstop()
{
    socket.close();


}
