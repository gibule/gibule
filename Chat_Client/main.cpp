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

using namespace gbl;
using namespace std;

int main()
{
    Sockaddress sa("127.0.0.1", 1234);
    GBLSocket socket(sa);
    socket.init_socket();
   if(socket.connect())
       std::cout << "OK" << std::endl;
   else
       std::cout << "ERROR" << std::endl;

    socket.sendData(string ("Yes connected Yes"));

    sleep(5);

    socket.close();


    return 0;
}
