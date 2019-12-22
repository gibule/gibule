#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "gblchatclient.h"
#include <../GBL_Library/gblsocket.h>
#include <../GBL_Library/gbllistener.h>

using namespace gbl;
using namespace std;

int main()
{
    GBLChatClient client("127.0.0.1",1234);

    client.start();
    while(true)
    {   string s;
        cin  >> s;

        client.sndmsg.push_back(s);

        usleep(100);
    }

    return 0;
}
