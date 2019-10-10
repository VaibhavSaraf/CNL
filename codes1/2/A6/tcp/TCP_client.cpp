#include<iostream>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<string.h>
using namespace std;
int main()
{
  int socket_fd, dummy=0;
  sockaddr_in sock_addr_obj;
  socket_fd = socket(AF_INET, SOCK_STREAM, 6);
  if(socket_fd<0)
    {
      cout<<"Error in socket creation"<<endl;
      exit(1);
    }
  if(setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &dummy, sizeof(dummy)))
    {
      cout<<"Error in configuration of socket file."<<endl;
      exit(1);
    }
  sock_addr_obj.sin_family = AF_INET;
  sock_addr_obj.sin_port = htons(8000);
  sock_addr_obj.sin_addr.s_addr = INADDR_ANY;
  if(connect(socket_fd, (sockaddr*)&sock_addr_obj, 16))
    {
      cout<<"Applying port and address information to socket failed."<<endl;
      exit(1);
    }
  char msg[] = "Hey there!! TCP communication successful";
  int msg_len = strlen(msg);
  dummy=0;
  send(socket_fd, msg, msg_len, 0);
  shutdown(socket_fd, SHUT_RDWR);
}
