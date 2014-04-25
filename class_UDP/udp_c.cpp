/*************************************************************************
	> File Name: udp_c.cpp
	> Author: crooked
	> Mail:812665244@qq.com 
	> Created Time: Fri 25 Apr 2014 10:57:37 AM CST
 ************************************************************************/

#include"udp_c.h"

Udp_c::Udp_c()
{
  memset(recv_buf, 0, 128);
  memset(send_buf, 0, 128);
  client_fd=socket(AF_INET, SOCK_DGRAM, 0);
  if(client_fd==-1)
  {
     perror("socket!\n");
     exit(-1);
  }

  memset(&client_addr,0, sizeof(client_addr));
  memset(&server_addr,0, sizeof(server_addr));
  server_addr.sin_family=AF_INET;
  server_addr.sin_port=htons(atoi("6688"));
  server_addr.sin_addr.s_addr=inet_addr("192.168.21.135");
}
Udp_c::~Udp_c()
{
  close(client_fd);
}

void Udp_c::send()
{
 read(0,send_buf,128);
 sendto(client_fd,send_buf,strlen(send_buf),0,(struct sockaddr*)&server_addr,sizeof(server_addr));
}

void Udp_c::receive()
{
   socklen_t len=sizeof(server_addr);
   recvfrom(client_fd,recv_buf,128,0,(struct sockaddr*)&server_addr,&len);
   printf("%s\n",recv_buf);
}
