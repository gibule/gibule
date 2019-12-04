#include <iostream>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


using namespace std;

int main()
{

    char a[24]="/home/levan/45";
    int fd=open(a,O_CREAT|O_RDWR);
    int s=11;
    write(fd,(int *)&s, sizeof (int));
    close(fd);

    int sd=socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in ipaddr;
    string v="192.168.0.113";

    inet_pton(AF_INET,v.c_str(),&ipaddr.sin_addr);
    ipaddr.sin_port=1234;
    ipaddr.sin_family=AF_INET;

    int y=bind(sd, (struct sockaddr*)&ipaddr,sizeof (sockaddr_in));
    perror("ss");
    if (y==0)
    {
        cout << "binded" << endl;
    }
    else
        cout<<"not binded"<<endl;


    int l=listen(sd,5);
    if (l==0)
        cout << "listening"<<endl;


    struct sockaddr_in clientadd;
    socklen_t slen=sizeof (sockaddr_in);
    int clientsocket=accept(sd,(struct sockaddr*) &clientadd, &slen);
    if(clientsocket==-1)
        cout << "error"<<endl;
    else {

        //    char a[40];
        //    read(clientsocket,(char*)&a, sizeof (a));
        //      printf("%s",a);

        int a=recv(clientsocket,(char*)&a,sizeof (a),0);
        printf("%s",a);




    }


    cout<<"utataia"<<endl;

    char client_ip[100];
    inet_ntop(AF_INET,&clientadd.sin_addr,client_ip,100);
    printf("%s\n",client_ip);

    close(sd);
    close(clientsocket);

    return 0;
}
