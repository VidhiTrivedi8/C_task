#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<strings.h>
#include<unistd.h>

#include<sys/socket.h>
#include<sys/types.h>

#include<netinet/in.h>
#include<arpa/inet.h>

#define PORT 5555

void main(){
      
      int sockfd;
      struct sockaddr_in serverAddr;
      char buf[1024];
      
      sockfd = socket(PF_INET,SOCK_STREAM,0);
      printf("Client Socket created Successfully .. \n");
      
      memset(&serverAddr,'\0', sizeof(serverAddr));
      serverAddr.sin_family = AF_INET;
      serverAddr.sin_port = htons(PORT);
      serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
      
      connect(sockfd, (struct sockaddr*)&serverAddr,sizeof(serverAddr));
      printf("Connected to Server Successfully..\n");
      
      int n;
      
      while(1){
          bzero(buf,sizeof(buf));
          printf("Enter the string : ");
          n=0;
          while((buf[n++] = getchar()) != '\n') ;
          write(sockfd,buf,sizeof(buf));
          bzero(buf,sizeof(buf));
          read(sockfd,buf,sizeof(buf));
          
          printf("From Server : %s",buf);
          if((strncmp("exit",buf))!=0){
            printf("Client Exit...\n");
            break;
          }
        }
      
      
      
      close(sockfd);

}

