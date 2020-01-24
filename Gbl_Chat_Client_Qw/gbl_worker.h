#ifndef GBL_WORKER_H
#define GBL_WORKER_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QThread>
#include <iostream>
#include <map>
#include <vector>
#include <../GBL_Library/gblsocket.h>
using namespace std;
using namespace gbl;

class GBL_Worker : public QThread
{
public:
    GBL_Worker();
    virtual void run();
    virtual void onstart(){}
    virtual void onwork(){}
    virtual void onstop(){}





    std:: string peerAddress;

    GBLSocket wsd;


    map<string,GBL_Worker*> *workers;
    mutex *listmtx;
    vector <string> sendbuff;

};

#endif // GBL_WORKER_H
