/*************************************************************************
	> File :Name: server.c
	> Author: crooked
	> Mail:812665244@qq.com 
	> Created Time: Wed 02 Apr 2014 02:22:39 PM CST
 ************************************************************************/

#include"udp.h"
int main(int argc, char *argv[])
{
  int iret,client_fd;
  char recv_buf[128], send_buf[128];
  struct sockaddr_in server_addr, client_addr;

  //socket
  client_fd=socket(AF_INET, SOCK_DGRAM, 0);
  if(client_fd==-1)
  {
     perror("socket!\n");
     exit(-1);
  }

  //connect
  memset(&server_addr,0, sizeof(server_addr));
  server_addr.sin_family=AF_INET;
  server_addr.sin_port=htons(atoi(argv[2]));
  server_addr.sin_addr.s_addr=inet_addr(argv[1]);
  
  //send/sendto
  while(1)
  {
  memset(send_buf, 0, 128);
  read(0, send_buf, 128);
  //strcpy(send_buf, "you suckers !\n");
  sendto(client_fd,send_buf,strlen(send_buf),0,(struct sockaddr*)&server_addr,sizeof(server_addr));
  

  //recv/recvfrom
  memset(&server_addr, 0, sizeof(server_addr));
  memset(recv_buf, 0, 128);
  int len=sizeof(server_addr);
  recvfrom(client_fd, recv_buf,128,0,(struct sockaddr*)&server_addr,&len);
  char ip[32]="";
  //printf("receive from ip:%s,port:%d, message:%s\n",inet_ntoa(server_addr.sin_addr),ntohs(server_addr.sin_port),recv_buf);
  printf("%s\n", recv_buf);
  }
  //close
  close(client_fd);
  return 0;  
}
