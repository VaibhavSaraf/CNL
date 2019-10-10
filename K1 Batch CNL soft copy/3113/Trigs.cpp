#include<iostream>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<math.h>
#include<stdio.h>
#define PORT 9123
#define pi 22/7
using namespace std;

int main()
{
	int socket_fd,newsock_fd;
	unsigned int clilen;
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
	char num[10];
	float NUM,NUM2;
	char operation[5];
	char result[256];
	int recv_len;
	float ans;

	while(1)
	{
	//receive
		ans =0;
	   recv_len = recv(newsock_fd, operation,5,0);
            if(recv_len>0)
			{
				operation[recv_len]='\0';
				cout<<"Function is:"<<operation<<endl;
			}
            recv_len = recv(newsock_fd, num,10,0);
             if(recv_len>0)
             {
            	num[recv_len]='\0';
            	cout<<"Number is:"<<num<<endl;
            	NUM2 = atof(num);
             }
             NUM = (NUM2 * pi)/180;

             if(!strcmp(operation ,"sin"))
            	 ans = sin(NUM);
             else if(!strcmp(operation ,"cos"))
            	 ans = cos(NUM);
             else if(!strcmp(operation ,"tan"))
                  ans = tan(NUM);
             else if(!strcmp(operation ,"asin"))
             {
            	 ans = asin(NUM2);
            	// ans = (ans*180)/pi;
             }
             else if(!strcmp(operation ,"acos"))
             {
            	 ans = acos(NUM2);
            	// ans = (ans*180)/pi;
             }
             else if(!strcmp(operation ,"atan"))
             {
            	 ans = acos(NUM2);
            	 //ans = (ans*180)/pi;
             }


             bzero((char *)result,sizeof(result));
             sprintf(result,"%f",ans);

			if(send(newsock_fd,result,strlen(result),0)<0)
			{
				cout<<"ERROR\n";
			}
			ans =0;

	}

	close(socket_fd);             //unistd
	return 0;
}
