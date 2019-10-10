#include<iostream>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#define PORT 9123
using namespace std;

int main()
{
	int sock_fd;
	struct sockaddr_in serv_addr;
	struct hostent *server;
	//create socket
	sock_fd = socket(AF_INET,SOCK_STREAM,0);
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
	bzero((char *) & serv_addr,sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	bcopy((char *) server->h_addr,(char *) &serv_addr.sin_addr.s_addr,server->h_length);
	serv_addr.sin_port = htons(PORT);

	if(connect(sock_fd,(struct sockaddr *)&serv_addr,sizeof(serv_addr))<0)
	{
		cout<<"ERROR connecting";
		exit(EXIT_FAILURE);
	}

		char num[10];
		char operation[5];
		char result[256];

		while(1)
		{
			bzero((char*)result,sizeof(result));
			cout<<"Enter the trignometric function(sin,cos,tan,asin,acos,atan) and number"<<endl;
			cin>>operation;
		if(send(sock_fd,operation,strlen(operation),0)<0)
		{
			cout<<"Error in sending \n";
			exit(EXIT_FAILURE);
		}
		cin>>num;
			if(send(sock_fd,num,strlen(num),0)<0)
			{
				cout<<"Error in sending \n";
				exit(EXIT_FAILURE);
			}
		if(recv(sock_fd,result,256,0)<0)
		{
			cout<<"Error in receiving \n";
			exit(EXIT_FAILURE);
		}
		cout<<"Answer is : "<<result<<endl;
		}

	close(sock_fd);
    return 0;
  }
