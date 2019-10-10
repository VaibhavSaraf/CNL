#include<iostream>
#include<sys/socket.h>
#include <netdb.h>
#include<string.h>
#include<netinet/in.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/types.h>  /* for inet_aton */
#include<fstream>
#include<fcntl.h>

using namespace std;

int main()
{

 int fd = socket(AF_INET,SOCK_DGRAM,0);
 struct sockaddr_in myaddr; 
 struct sockaddr_in remaddr;
 int slen = sizeof(remaddr);
 socklen_t remlen = sizeof(remaddr);
 char*server = "192.168.6.10";
 char buff[1000];
 char buf[20000]; 
if(fd==-1)
  cout<<"SOCKET CREATED \n";
 
memset((void*)&myaddr,0,sizeof(myaddr));


myaddr.sin_family= AF_INET;
myaddr.sin_addr.s_addr = htonl(INADDR_ANY);
myaddr.sin_port = htons(0);   // CLIENT SOCKET'S addr

if(bind(fd,(struct sockaddr * )&myaddr,sizeof(myaddr)) < 0)
    {
     cout<<"ERROR IN BINDING \n";
     return 0; 
    }

memset((void*)&remaddr,0,sizeof(remaddr));
remaddr.sin_family= AF_INET;
remaddr.sin_port = htons(1300); 

 if(inet_aton(server,&remaddr.sin_addr)==0)
  {
   cout<<"ERROR IN INET"<<endl;
   return 0;
  }

cout<<"Enter the message to send\n";
cin>>buff;

if(sendto(fd,buff,1000,0,(struct sockaddr *)&remaddr,sizeof(remaddr))==-1)
 {
   cout<<"Error in sending \n";
     return 0;
 }
 
 cout<<"from server"<<endl;
 int recvlen = recvfrom(fd,buf,2000,0,(struct sockaddr*)&remaddr,&remlen);
cout<<"RECEIVED BYTES: "<<recvlen;

if(recvlen>0)
  cout<<"contents:"<<buf;
  
  return 0;
  
  }
  
 
 
