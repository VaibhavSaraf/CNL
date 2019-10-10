#include<iostream>
#include<unistd.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

int main()
{
  int server_socket_fd, dummy=1, client_socket_fd;
  sockaddr_in server_sock_addr_obj;
  server_socket_fd = socket(AF_INET, SOCK_STREAM, 6);
  if(server_socket_fd < 0)
    {
      cout<<"Socket creation failed."<<endl;
      exit(1);   
    }
  if(setsockopt(server_socket_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &dummy, sizeof(int)))
    {
      cout<<"Configuring the socket file failed."<<endl;
      exit(1);
    }
  server_sock_addr_obj.sin_family = AF_INET;
  server_sock_addr_obj.sin_port = htons(8000);
  server_sock_addr_obj.sin_addr.s_addr = INADDR_ANY;
  // if(inet_pton(AF_INET, "127.0.0.1", &server_sock_addr_obj.sin_addr.s_addr)<=0)
  //   {
  //     cout<<"IP addr representation failed."<<endl;
  //     exit(1);
  //   }

  if(bind(server_socket_fd, (sockaddr*)&server_sock_addr_obj, 16) < 0)
    {
      cout<<"Socket connection failed."<<endl;
      exit(1);
    }
  if(listen(server_socket_fd, 3)<0)
    {
      cout<<"Error in listening at given port"<<endl;
      exit(1);
    }
  dummy=16;
  if((client_socket_fd = accept(server_socket_fd, (sockaddr*)&server_sock_addr_obj, (socklen_t*)&dummy)) < 0)
    {
      cout<<"Error in accepting connection."<<endl;
      exit(1);
    }
  char buffer[1024];
  int bytes_read = read(client_socket_fd, buffer, 1024);
  cout<<buffer<<endl;
  shutdown(client_socket_fd, SHUT_RDWR);
  shutdown(server_socket_fd, SHUT_RDWR);
}


