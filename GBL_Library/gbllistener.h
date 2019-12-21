#ifndef GBLLISTENER_H
#define GBLLISTENER_H
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <thread>
#include <atomic>
#include <mutex>
#include <vector>
#include <map>

#include "gblthread.h"
#include "gblsocket.h"
#include "gblworker.h"

using namespace std;
using namespace gbl;

template <class T>
class GBLListener : public GBLThread
{
public:
    GBLListener(Sockaddress addr) : listenSocket(addr){}


    void run()
    {
        int sock=listenSocket.init_socket();
        if (listenSocket.bind()==0)
        {
            cout << "binded"<< endl;
        }
        else
        {
            cout << "bind error"<< endl;
            perror(0);
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
            socklen_t peersize=sizeof(struct sockaddr_in);
            test = 1234;
            int clientSD=accept(listenSocket.sd,(struct sockaddr*)&peeraddress.ipaddress,&peersize);
            std::cout << "======== " <<  peersize << std::endl;
            if (clientSD>0)
            {
                cout << "Accepted peer: " << peeraddress.getAddress() << ":" << peeraddress.getPort() << endl;
                GBLWorker *w;
                w=new  T();
                w->peerAddress=peeraddress.getAddress();
                w->wsd.sd=clientSD;
                w->wsd.setState(ssConnected);
                w->workers = &workers;
                w->listmtx=&mtx;
                mtx.lock();
                workers.insert(pair<string,GBLWorker*>(w->peerAddress,w));
                mtx.unlock();

                w->start();

            }
            sleep(2);
        }
    }

    GBLSocket listenSocket;

    int test;
    map<string,GBLWorker*> workers;


};

#endif // GBLLISTENER_H
