#include "gblthread.h"

GBLThread::GBLThread()
{

}

GBLThread::~GBLThread()
{

}


void GBLThread::start()
{
    running=true;
    thr=thread(&GBLThread::run,this);
}

void GBLThread::stop()
{
    running=false;
}

bool GBLThread::isRunning()
{
    return  running;
}

void GBLThread::run()
{

}

void GBLThread::wait()
{
    thr.join();
}
