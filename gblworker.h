#ifndef GBLWORKER_H
#define GBLWORKER_H
#include <gblthread.h>
using namespace std;

class GBLWorker : public GBLThread
{
public:
   GBLWorker();

   virtual void run();

   virtual void onstart(){}
   virtual void onwork(){}
   virtual void onstop(){}

   int wsd;



};

#endif // GBLWORKER_H
