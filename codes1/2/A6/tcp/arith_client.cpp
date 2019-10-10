#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include<iostream>

using namespace std;

void error(const char *msg)
{
    cerr<<msg;
    exit(0);
}

int main(int argc, char *argv[])
{
    int sockfd, portno, n, choice,op1,op2,n1,n2,n3,n4,un1,un2,un3,result,result_conv;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[256];
    if (argc < 3) {
       fprintf(stderr,"usage %s hostname port\n", argv[0]);
       exit(0);
    }
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
        error("ERROR connecting");

    cout<<"Please enter the option of the operation to be performed \n1.Addition \n2.Subtraction \n3.Multiplication";
    cin>>choice;
    cout<<"Please enter the first operand";
    cin>>op1;
    cout<<"Please enter the second operand";
    cin>>op2;

    un1 = htonl(op1);

    un2 = htonl(op2);
    un3 = htonl(choice);

    //send(sockfd, &un2, sizeof(uint32_t), flags);
    n1 = write(sockfd,&un1,sizeof(un1));
    if (n1 < 0)
         error("ERROR writing to socket");
    n2 = write(sockfd,&un2,sizeof(un2));
    if (n2 < 0)
         error("ERROR writing to socket");
    n3 = write(sockfd,&un3,sizeof(un3));
    if (n3 < 0)
         error("ERROR writing to socket");
    bzero(buffer,256);
    n = read(sockfd,buffer,255);
    if (n < 0)
         error("ERROR reading from socket");
    cout<<buffer;
    
    close(sockfd);
    return 0;
}
