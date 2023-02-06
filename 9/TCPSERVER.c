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
    
    int newSocket;
    struct sockaddr_in newAddr;
    
    socklen_t addr_size;
    char buf[1024];
    
    sockfd = socket(PF_INET,SOCK_STREAM,0);
    printf("Server Socket created Successfully..\n");
    memset(&serverAddr, '\0' , sizeof(serverAddr));
    
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    
    bind(sockfd,(struct sockaddr*)& serverAddr,sizeof(serverAddr));
    printf("Socket successfully binded\n");
    
    listen(sockfd,6);
    printf("Listening...\n");
    
    newSocket = accept(sockfd, (struct sockaddr*) & newAddr, &addr_size);
    
    int n;
    while(1){
        bzero(buf,1024);
        
        read(newSocket, buf , sizeof(buf));
        printf("From client: %s\t To client: ",buf);
        bzero(buf,1024);
        n=0;
        
        while((buf[n++] = getchar()) != '\n')
           ;
           
        write(newSocket, buf, sizeof(buf));
        
        if(strcmp("exit",buf) != 0){
            printf("Server Exit..\n");
            break;
            }
            }
    
    
    close(sockfd);


}
