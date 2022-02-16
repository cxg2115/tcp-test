#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<assert.h>
#include<string.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>

int main()
{
    int sockfd=socket(AF_INET,SOCK_STREAM,0);
    assert(sockfd!=-1);
    struct sockaddr_in ser,cli;
    memset(&ser,0,sizeof(ser));
    ser.sin_family=AF_INET;
    ser.sin_port=htons(5799);
    ser.sin_addr.s_addr=inet_addr("192.168.0.111");
    int res=connect(sockfd,(struct sockaddr*)&ser,sizeof(ser));
    assert(res!=-1);
    while(1)
    {
        char sendbuf[128]={0};
        printf("input:");
        scanf("%s",sendbuf);
        printf("\n");
        send(sockfd,sendbuf,strlen(sendbuf),0);

        char recvbuff[128]={0};
        recv(sockfd,recvbuff,127,0);
        printf("%s\n",recvbuff);
    }
    close(sockfd);
}

