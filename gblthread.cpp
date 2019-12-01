#include "gblthread.h"

GBLThread::GBLThread()
{

}

GBLThread::~GBLThread()
{

}


void GBLThread::start()
{
    thr=thread(&GBLThread::run,this);
}

void GBLThread::run()
{

}

void GBLThread::wait()
{
    thr.join();
}
