#include<iostream>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fstream>
#define PORT 9876
using namespace std;

int main()
{
	int sock_fd;
	struct sockaddr_in serv_addr;
	struct hostent *server;
	char buffer[1000];
	char buff2[20000];
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

	cout<<"Enter the filename"<<endl;
		cin>>buffer;

		if(send(sock_fd,buffer,1000,0)<0)
		{
			cout<<"Error in sending \n";
			exit(EXIT_FAILURE);
		}

		int recvlen = recv(sock_fd,buff2,20000,0);

		if(recvlen>0)
		  {
		  buff2[recvlen]='\0';
		  cout<<"Client buff: "<<buff2;
		  }
		ofstream fout;
		fout.open("abc.odt",ios::out | ios::binary);

		if(!fout)
		{
			cout<<"error"<<endl;
		}
			fout.write(buff2,recvlen);
		fout.close();
	close(sock_fd);
    return 0;
  }
