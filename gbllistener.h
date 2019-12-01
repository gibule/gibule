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
using namespace std;


class GBLListener : public GBLThread
{
public:
    GBLListener();

    virtual void run();



};

#endif // GBLLISTENER_H
