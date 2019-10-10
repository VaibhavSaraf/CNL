#include<iostream>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<fstream>
#define PORT 4589
using namespace std;

int main()
{
	int sock_fd;
	struct sockaddr_in serv_addr, my_addr;
	struct hostent *server;
	char buffer[1000];
	char buff2[20000];
	unsigned int slen = sizeof(serv_addr);
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

	cout<<"Enter the filename"<<endl;
	cin>>buffer;

	if(sendto(sock_fd,buffer,1000,0,(struct sockaddr*)&serv_addr,slen)<0)
	{
		cout<<"Error in sending \n";
		exit(EXIT_FAILURE);
	}

	int recvlen = recvfrom(sock_fd,buff2,20000,0,(struct sockaddr*)&serv_addr,&slen);

	if(recvlen>0)
	  {
	  buff2[recvlen]='\0';
	  cout<<"Client buff: "<<buff2;
	  }
	ofstream fout;
	fout.open("abc.txt",ios::out | ios::binary);

	if(!fout)
	{
		cout<<"error"<<endl;
	}
		fout.write(buff2,recvlen);
	fout.close();

	close(sock_fd);
    return 0;
  }
