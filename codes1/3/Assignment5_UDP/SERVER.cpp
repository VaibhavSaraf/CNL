#include<sys/socket.h>
#include<netinet/in.h>
#include<iostream>
#include<string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include<fstream>
#include<fcntl.h>

using namespace std;
int main()
{
 char fname[1000];
 char buff[2000];
 int fd = socket(AF_INET,SOCK_DGRAM,0);
 struct sockaddr_in myaddr; 
 struct sockaddr_in remaddr;
 socklen_t remlen = sizeof(remaddr);
 int slen = sizeof(remaddr);
if(fd<0)
  cout<<"ERROR";
else
 cout<<"Socket created "<<fd<<endl;


memset((void*)&myaddr,0,sizeof(myaddr));
memset((void*)&remaddr,0,sizeof(remaddr));
myaddr.sin_family= AF_INET;
myaddr.sin_addr.s_addr = htonl(INADDR_ANY);
myaddr.sin_port = htons(1300);

  if(bind(fd,(struct sockaddr * )&myaddr,sizeof(myaddr)) < 0)
    {
     cout<<"ERROR \n";
     return 0; 
    }

unsigned int alen = sizeof(myaddr);

    if(getsockname(fd,(struct sockaddr * )&myaddr,&alen)<0)
         {
          cout<<"GET SOCKNAME FAILED \n";
          return 0;
         }

cout<<"BIND COMPLETE , PORT NO : "<<ntohs(myaddr.sin_port)<<endl;

int recvlen = recvfrom(fd,fname,1000,0,(struct sockaddr*)&remaddr,&remlen);
cout<<"RECEIVED BYTES: "<<recvlen;

if(recvlen>0)
  cout<<"FILENAME:"<<fname;
fname[recvlen]='\0';


cout<<"filename send"<<endl;
int data = recvfrom(fd,buff,2000,0,(struct sockaddr*)&remaddr,&remlen);
cout<<"RECEIVED BYTES: "<<data;

if(data>0)
  cout<<"contents:"<<buff;
buff[data]='\0';

ofstream fin;
fin.open("fname",ios::out|ios::binary);
if(!fin)
{
cout<<"haha";}
fin.write(buff,data);
fin.close();

return 0;
}

