#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netdb.h>
int main(){
  struct addrinfo hints, * server;
  int r, sockfd, clientfd, option;
  struct sockaddr client_address;
  socklen_t client_len;
  const int buffer_size = 1024;
  char buffer [buffer_size];
  const char* http_data = 
    "HTTP/1.1 200 OK\r\n"
    "Connection: close\r\n"
    "Content-type: text/html\r\n\r\n"
    "<h1>Hello from your server!</h1>";
  printf("Configuring server...");
  memset(&hints, 0, sizeof(struct addrinfo));
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;
  r = getaddrinfo(0, "8080", &hints, &server);
  if(r!=0){
    perror("Failed.");
    exit(1);
  }
  puts("Done.");
  printf("Assign a socket...");
  sockfd = socket(
    server -> ai_family,
    server -> ai_socktype,
    server -> ai_protocol
  );
  if(sockfd == -1){
    perror("Failed.");
    exit(1);
  }
  puts("Done.");
  printf("binding socket....");
  r = bind(sockfd,server -> ai_addr,server -> ai_addrlen);
  if(r == -1){
    perror("Failed.");
    exit(1);
  }
  puts("Done.");
  printf("Listening.");
  r = listen(sockfd,1);
  if(r == -1){
    perror("failed.");
    exit(1);
  }
  puts("Done");
  printf("Accepting new connections.");
  client_len = sizeof(client_address);
  clientfd = accept(sockfd, &client_address, &client_len);
  if(clientfd == -1){
    perror("Failed.");
    exit(1);
  }
  printf("On file descriptor%d\n", clientfd);
  r = recv(clientfd,buffer, buffer_size, 0);
  if(r>0){
    printf("Received %d bytes: \n ---\n", r);
    for(int x = 0; x < r; x++){
      putchar(buffer[x]);
    }
  }
  r = send(clientfd,http_data,strlen(http_data), 0);
  if(r<1){
    perror("Send failed.");
    exit(1);
  }
  printf("sent %d bytes\n", r);
  close(clientfd);
  freeaddrinfo(server);
  close(sockfd);
  puts("Socket closed, done");
  return 0;
}
    
