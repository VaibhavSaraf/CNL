#include<iostream>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#define PORT 9870
using namespace std;

int main()
{
	int sock_fd,n;
	struct sockaddr_in serv_addr, my_addr;
	struct hostent *server;
	char buffer[256];
	int slen = sizeof(serv_addr);
	 socklen_t remlen = sizeof(serv_addr);
	//create socket
	sock_fd = socket(AF_INET,SOCK_DGRAM,0);
	if(sock_fd < 0)
	{
		cout<<"Error opening in socket"<<endl;
		exit(EXIT_FAILURE);
	}
	server = gethostbyname("127.0.0.1");
	if(server==NULL)
	{
		cout<<"Error! No such host"<<endl;
		exit(EXIT_FAILURE);
	}

	struct hostent *gethostbyname(char *name);
	bzero((char *) & my_addr,sizeof(my_addr));
	my_addr.sin_family = AF_INET;
	bcopy((char *) server->h_addr,(char *) &my_addr.sin_addr.s_addr,server->h_length);
	serv_addr.sin_port = htons(0);

	if(bind(sock_fd,(struct sockaddr *)&my_addr,sizeof(my_addr))<0)
	{
		cout<<"Error in binding!!"<<endl;
		exit(EXIT_FAILURE);
	}

	bzero((char *) & serv_addr,sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);

	if(inet_aton(server->h_name,&serv_addr.sin_addr)==0)
	{
		 cout<<"ERROR IN INET"<<endl;
		 exit(EXIT_FAILURE);
	}

	while(1)
	{
		cout<<"Please enter the message: "<<endl;
		bzero(buffer,256);
		cin>>buffer;
		//cin.getline(buffer,15);
		n = sendto(sock_fd,buffer,strlen(buffer),0,(struct sockaddr *)&serv_addr,slen);
		if(n < 0)
		{
			cout<<"Error in writing to socket"<<endl;
		}
		bzero(buffer,256);
		n = recvfrom(sock_fd,buffer,255,0,(struct sockaddr *)&serv_addr,&remlen);
		if(n<0)
		{
			cout<<"Error in reading from socket"<<endl;
		}

		cout<<buffer;

		cout<<"Continue?y/n"<<endl;
		char c;
		cin>>c;
		if(c!='y')
			break;
	}
	close(sock_fd);
    return 0;
  }
