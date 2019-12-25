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
    //    s.resize(100);
    vector<string>s1;
    map<string, vector<string>> d;


    if(wsd.receiveData(s))
    {
        split(s,"@",s1);



        cout << s <<  "Your IP IS: "<<"\t"<<s1.at(0)<<endl;


        unsigned long int size=s1.size();
        for (ulong i=1; i<size; i++)
        {
            cout<<"Message is"<<"\t"<<s1.at(i)<<endl;
        }

    }

    map <string,GBLWorker*>::iterator it;
    mtx.lock();
    for (it=workers->begin();it!=workers->end();it++)
    {
        if(it->first==s1.at(0))
        {
            it->second->sendbuff.push_back(s1.at(1));

        }
    }
    mtx.unlock();
    vector <string>:: iterator it2;
    mtx.lock();
    for (it2=sendbuff.begin();it2!=sendbuff.end();  it2++)
    {

        wsd.sendData(*it2);
    }
     mtx.unlock();

    if(wsd.getState()==ssDisconnected)
    {
        stop();
        cout << "Connection closed" << std::endl;
    }

    usleep(100);
}

void GBLChat::onstop()
{
    cout << "Thread Stopped" << std::endl;
}
