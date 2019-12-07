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
#include "gblthread.h"
#include <gblsocket.h>
#include <gblworker.h>
#include <vector>
using namespace std;
using namespace gbl;

class GBLListener : public GBLThread
{
public:
    GBLListener(Sockaddress addr);

    virtual void run();


    GBLSocket listenSocket;

    vector<GBLWorker*> workers;


};

#endif // GBLLISTENER_H
