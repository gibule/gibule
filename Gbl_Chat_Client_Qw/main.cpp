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
#include <dialog.h>
#include <QWidget>

//#include "gbl_worker.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog dialog;
    MainWindow w;
    GBL_Chat_Client client("192.168.0.111",1234);
    w.client=&client;
    dialog.client=&client;
    client.start();

    if (dialog.exec()==1)
    {


        w.show();

        return a.exec();
    }











}
