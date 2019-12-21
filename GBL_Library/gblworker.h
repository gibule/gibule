#ifndef GBLWORKER_H
#define GBLWORKER_H
#include <map>
#include "gblthread.h"
#include "gblsocket.h"
using namespace std;
using namespace gbl;


template <class T>
class GBLListener;

class GBLWorker : public GBLThread
{
public:
   GBLWorker();

   virtual void run();

   virtual void onstart(){}
   virtual void onwork(){}
   virtual void onstop(){}

   string peerAddress;

   GBLSocket wsd;
   //GBLListener<GBLWorker> *listener;

   map<string,GBLWorker*> *workers;
   mutex *listmtx;


};

#endif // GBLWORKER_H
