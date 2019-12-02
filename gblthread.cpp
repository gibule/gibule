#include "gblthread.h"

GBLThread::GBLThread()
{
}


void GBLThread::run()
{
}

void GBLThread::start()
{
    running=true;
    thr=thread(&GBLThread::run,this);
}

void GBLThread::wait()
{
    thr.join();
}

GBLThread::~GBLThread()
{


}
