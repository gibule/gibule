#ifndef GBL_CHAT_CLIENT_H
#define GBL_CHAT_CLIENT_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <gbl_worker.h>

class GBL_Chat_Client : public GBL_Worker
{
public:
    GBL_Chat_Client();
    GBL_Chat_Client(string addr,unsigned short int port);
    void onstart();
    void onwork();
    void onstop();


    Sockaddress sa;
    GBLSocket socket;
    vector<string> recvmsg;
    vector<string> sndmsg;

};

#endif // GBL_CHAT_CLIENT_H
