#ifndef GBLTHREAD_H
#define GBLTHREAD_H
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
using namespace std;



class GBLThread
{
public:
    GBLThread();
    virtual ~GBLThread();

    virtual void run();
    void start();
    void wait();


private:
    thread thr;
    bool running;


};

#endif // GBLTHREAD_H
