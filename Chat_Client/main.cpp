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
#include <istream>
#include <fstream>
#include <../GBL_Library/gblutility.h>

using namespace gbl;
using namespace std;

int main()
{
    fstream f;
    string a;
    vector <string> v;

//    f.open("/home/dato/Projects/gibule/gibule/client.cnfg",fstream::in);
//    while(!f.eof())
//    {
//        f>>a;
//        split(a,"=",v);


//    }




//    GBLChatClient client(v.at(1),stoi(v.at(3)));
GBLChatClient client("192.168.111",1234);
    client.start();
    while(true)
    {
        char c[1024];
        cin.getline(c,1024);
        string s=string(c);
       // cout<<s<<endl;

        client.mtx.lock();

        client.sndmsg.push_back(s);

        client.mtx.unlock();
        usleep(100);
    }

    return 0;
}
