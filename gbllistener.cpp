#include "gbllistener.h"

GBLListener::GBLListener(Sockaddress addr) : listenSocket(addr)
{

}

void GBLListener::run()
{
    int sock=listenSocket.init_socket();
    if (listenSocket.bind()==0)
    {
        cout << "binded"<< endl;
    }
    else
    {
        cout << "bind error"<< endl;
    }

    if (listen(sock,10)==0)
    {
     cout <<"Listening"<<endl;
    }
    else
    {
        cout << "deaf" << endl;
    }
    while(1)
    {
        Sockaddress peeraddress;
        socklen_t peersize;
        int clientSD=accept(listenSocket.sd,(struct sockaddr*)&peeraddress.ipaddress,&peersize);
        std::cout << "======== " <<  peersize << std::endl;
        if (clientSD>0)
        {
            cout << "Accepted" << peeraddress.getAddress() << peeraddress.getPort() << endl;
            GBLWorker *w;
            w=new  GBLWorker();
            w->wsd=clientSD;
            w->start();
            workers.push_back(w);

        }
        sleep(2);
    }

}
