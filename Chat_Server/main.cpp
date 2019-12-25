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
#include <gblchat.h>
#include <fstream>
#include <string>


using namespace std;
using namespace gbl;
int main ()
{


    Sockaddress sa("127.0.0.1", 1234);

    GBLListener<GBLChat> listener(sa);
    listener.start();
    while(1)
    {

    }



   /*
    GBLSocket g(Sockaddress("127.0.0.1", 1234));
    int b = g.sockaddress.getPort();
    string ip = g.sockaddress.getAddress();
    cout << b << endl;
    cout << ip << endl;
    int socket =g.socket_descriptor();

    int d =g.bind();
    if (d==0)

        cout<<"binded"<<endl;
    perror("sdads");
    GBLListener listener;
    listener.start();


    sleep(1);

    while(1)
    {
        std::cout << "main" << std::endl;
        sleep(1);
    }

    listener.wait();
*/

    return 0;
}
