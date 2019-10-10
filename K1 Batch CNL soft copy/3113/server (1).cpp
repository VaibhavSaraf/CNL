#include<iostream>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fstream>
//#include<fcntl.h>
#define PORT 4589
using namespace std;

int main()
{

	    int socket_fd;
		char fname[1000];
		struct sockaddr_in serv_addr,cli_addr;
		unsigned int cli_len = sizeof(cli_addr);
		//create socket
		socket_fd = socket(AF_INET, SOCK_DGRAM, 0);

		if(socket_fd<0)
		{
			cout<<"Error opening in socket"<<endl;
			exit(EXIT_FAILURE);
		}

		bzero((char *)&serv_addr,sizeof(serv_addr));
		bzero((char *)&cli_addr,sizeof(cli_addr));
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

		int recv_len = recvfrom(socket_fd, fname,1000,0,(struct sockaddr *)&cli_addr,&cli_len);

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

		if(sendto(socket_fd,buff,filesize,0,(struct sockaddr *)&cli_addr,cli_len)<0)
		{
			cout<<"ERROR\n";
		}

		close(socket_fd);
	return 0;
}
