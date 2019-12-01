#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <gblsocket.h>
#include <gbllistener.h>
using namespace std;
using namespace gbl;
int main ()
{




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
























    return 0;
}
