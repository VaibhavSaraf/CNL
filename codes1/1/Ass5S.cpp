#include<iostream>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
//#include<arpa/inet.h>
#define PORT 9870
using namespace std;

int main()
{
	int socket_fd,n;
	char buffer[256];
	struct sockaddr_in serv_addr,cli_addr;
	//create socket
	socket_fd = socket(AF_INET, SOCK_DGRAM, 0);

	if(socket_fd<0)
	{
		cout<<"Error opening in socket"<<endl;
		exit(EXIT_FAILURE);
	}
	//cout<<"Ready"<<endl;
	//binding socket to port
	bzero((char *)&serv_addr,sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);
	serv_addr.sin_addr.s_addr = INADDR_ANY;


	if(bind(socket_fd,(struct sockaddr *) &serv_addr,sizeof(serv_addr))<0)
	{
		cout<<"Error on binding"<<endl;
		exit(EXIT_FAILURE);
	}
	cout<<"Ready"<<endl;

	unsigned int alen = sizeof(serv_addr);

	if(getsockname(socket_fd,(struct sockaddr *) &serv_addr,&alen)<0)
	{
		cout<<"get socket name failed"<<endl;
		exit(EXIT_FAILURE);
	}

	cout<<"Bind completes , PORT No: "<<ntohs(serv_addr.sin_port)<<endl;


	socklen_t cli_len = sizeof(cli_addr);
	while(1)
	{
		//read
		bzero(buffer,256);
		n =recvfrom(socket_fd,buffer,255,0,(struct sockaddr *)&cli_addr,&cli_len);
		if(n==0)
		{
			cout<<"GoodBye!!"<<endl;
			break;
		}
		if(n<0)
		{
			cout<<"Error reading from socket"<<endl;
		}

		cout<<"client says : "<<buffer<<endl;
		//write
		cout<<"Do you want to reply?"<<endl;
		char c;
		cin>>c;
		if(c!='y')
			break;
		//bzero(buffer,256);
		cout<<"Enter your reply: "<<endl;
		//cin.getline(buffer,15);
		char* s= new char[256];
		cin>>s;
		//cin.getline(s,15);
		n = sendto(socket_fd,s,strlen(s),0,(struct sockaddr *)&cli_addr,sizeof(cli_addr));
		if(n<0)
		{
			cout<<"Error writing to socket";
		}

	}
	close(socket_fd);             //unistd
	return 0;
}
