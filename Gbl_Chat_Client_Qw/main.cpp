#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <../GBL_Library/gblsocket.h>
#include <../GBL_Library/gbllistener.h>
#include <istream>
#include <fstream>

#include <gbl_chat_client.h>
#include <mutex>

//#include "gbl_worker.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

//    GBL_Worker worker;
//    w.worker=&worker;
//    worker.start();



     GBL_Chat_Client client("192.168.0.106",1234);
     client.start();
//    while(true)
//    {
//        char c[1024];
//        cin.getline(c,1024);
//        string s=string(c);


//        mtx.lock();

//        client.sndmsg.push_back(s);
//        mtx.unlock();
//        usleep(100);
//    }


    return a.exec();
}
