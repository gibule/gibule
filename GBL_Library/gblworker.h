#ifndef GBLWORKER_H
#define GBLWORKER_H
#include "gblthread.h"
#include "gblsocket.h"
using namespace std;
using namespace gbl;

class GBLWorker : public GBLThread
{
public:
   GBLWorker();

   virtual void run();

   virtual void onstart(){}
   virtual void onwork(){}
   virtual void onstop(){}

   GBLSocket wsd;



};

#endif // GBLWORKER_H
