#include "gblchat.h"
#include "../GBL_Library/gbllistener.h"

GBLChat::GBLChat()
{

}

void GBLChat::onstart()
{
    cout << workers->size() << std::endl;
    listmtx->lock();
    map<string,GBLWorker*>::iterator it;
    for (it= workers->begin();it!=workers->end();it++)
    {
        cout<<it->first<<endl;
    }
    listmtx->unlock();
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
        std::cout << "Connection closed" << std::endl;
    }

    usleep(100);
}

void GBLChat::onstop()
{
    std::cout << "Thread Stopped" << std::endl;
}
