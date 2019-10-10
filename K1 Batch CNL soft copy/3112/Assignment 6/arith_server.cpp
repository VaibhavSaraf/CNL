/* A simple server in the internet domain using TCP
   The port number is passed as an argument */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include<iostream>

using namespace std;

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
     int sockfd, newsockfd, portno,n1,n2,n3,un1,un2,un3,n4,result,result_conv;
     socklen_t clilen;
     int buffer[256];
     struct sockaddr_in serv_addr, cli_addr;
     int n;
     if (argc < 2) {
        fprintf(stderr,"ERROR, no port provided\n");
        exit(1);
     }
     sockfd = socket(AF_INET, SOCK_STREAM, 0);
     if (sockfd < 0)
        error("ERROR opening socket");
     bzero((char *) &serv_addr, sizeof(serv_addr));
     portno = atoi(argv[1]);
     serv_addr.sin_family = AF_INET;
     serv_addr.sin_addr.s_addr = INADDR_ANY;
     serv_addr.sin_port = htons(portno);
     if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
              error("ERROR on binding");
     listen(sockfd,5);
     clilen = sizeof(cli_addr);
     newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
     if (newsockfd < 0)
          error("ERROR on accept");
     n1 = read(newsockfd,&un1,sizeof(un1));
     un1 = ntohl(un1);

     if (n1 < 0)
         error("ERROR reading from socket");
     n2 = read(newsockfd,&un2,sizeof(un2));

     if (n2 < 0)
         error("ERROR reading from socket");
          un2 = ntohl(un2);

     n3 = read(newsockfd,&un3,sizeof(un3));
     if (n3 < 0)
         error("ERROR reading from socket");
          un3 = ntohl(un3);

     if(un3 == 1)
     {
        result = un1 + un2;
     }
     else if(un3 == 2)
     {

        result = un1 - un2;
     }
     else if(un3 == 3)
     {
        result = un1 * un2;
     }
     cout<<"The result is "<<result;

     n = write(newsockfd,"Server has computed the result",40);
     if (n < 0) error("ERROR writing to socket");


     close(newsockfd);
     close(sockfd);
     return 0;
}
