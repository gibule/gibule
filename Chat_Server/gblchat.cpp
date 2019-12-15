#include "gblchat.h"


GBLChat::GBLChat()
{

}

void GBLChat::onstart()
{
cout << "gamovida" << endl;
}
void GBLChat::onwork()
{
    std::string s;
    s.resize(100);
    if(wsd.receiveData(s))
        cout << s << endl;
    if(wsd.getState()==ssDisconnected)
    {
        stop();
        std::cout << "Connection closed, Thread Stoped" << std::endl;
    }

    usleep(100);
}

void GBLChat::onstop()
{

}
