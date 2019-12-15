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
    sleep(1);
}

void GBLChat::onstop()
{

}
