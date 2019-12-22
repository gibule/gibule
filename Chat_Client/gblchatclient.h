#ifndef GBLCHATCLIENT_H
#define GBLCHATCLIENT_H
#include "../GBL_Library/gblworker.h"

class GBLChatClient : public GBLWorker
{
public:
    GBLChatClient(string addr,unsigned short int port);
    void onstart();
    void onwork();
    void onstop();
    Sockaddress sa;
    GBLSocket socket;
    vector<string> recvmsg;
    vector<string> sndmsg;
};

#endif // GBLCHATCLIENT_H
