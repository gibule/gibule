#include "gbllistener.h"

GBLListener::GBLListener()
{

}

void GBLListener::run()
{
    while(1)
    {
        cout<<"Listener"<<endl;
        sleep(2);
    }

}
