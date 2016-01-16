#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>

int main(int argc, char *argv[]){
 int socket_desc;
 struct sockaddr_in server;

 socket_desc=socket(AF_INET,SOCK_STREAM,0);

 if (socket_desc == -1){
  printf("Could not create socket");
 }
 
 server.sin_addr.s_addr=inet_addr("74.125.239.110");
 server.sin_family = AF_INET;
 server.sin_port = htons(80);

 // connect to the remote server
 if (connect(socket_desc, (struct sockaddr *)&server, sizeof(server))<0){
  puts("conncet error");
  return 1;
 }

 puts("Connceted");
 return 0; 
}
