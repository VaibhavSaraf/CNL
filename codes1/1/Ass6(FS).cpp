#include<iostream>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fstream>
#define PORT 9876
using namespace std;

int main()
{
	int socket_fd,newsock_fd,n;
	unsigned int clilen;
	char fname[1000];
	struct sockaddr_in serv_addr,cli_addr;
	//create socket
	socket_fd = socket(AF_INET, SOCK_STREAM, 0);

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
	//listen
	if(listen(socket_fd,5))
	{
		cout<<"Error in listening"<<endl;
		exit(EXIT_FAILURE);
	}
	//accept
	clilen = sizeof(cli_addr);
	newsock_fd = accept(socket_fd,(struct sockaddr *) &cli_addr,&clilen);
	if(newsock_fd<0)
	{
		cout<<"Error on accept"<<endl;
		exit(EXIT_FAILURE);          //stdlib
	}
	//receive
	int recv_len = recv(newsock_fd, fname,1000,0);

			if(recv_len>0)
			{
				cout<<"Filename:"<<fname;
			}
			fname[recv_len]='\0';

			fstream fout;
			fout.open(fname, ios::in | ios::out | ios::binary);
			fout.seekg(0,ios::end);
			int filesize = fout.tellg();
			char *buff = new char[filesize];
			fout.seekg(0,ios::beg);
			fout.read(buff,filesize);

			if(send(newsock_fd,buff,filesize,0)<0)
			{
				cout<<"ERROR\n";
			}




	close(socket_fd);             //unistd
	return 0;
}
