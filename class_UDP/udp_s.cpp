/*************************************************************************
	> File Name: udp_s.cpp
	> Author: crooked
	> Mail:812665244@qq.com 
	> Created Time: Mon 14 Apr 2014 04:30:53 PM CST
 ************************************************************************/

#include"udp_s.h"
Udp_s::Udp_s()
{
   memset(recv_buf,0,128);
   memset(send_buf,0,128);
   server_fd=socket(AF_INET, SOCK_DGRAM, 0);
   if(server_fd==-1)
   {
//	 throw std::runtime_error("error");
     perror("socket!");
	 exit(-1);
   }
   memset(&client_addr,0,sizeof(client_addr));
   memset(&server_addr,0,sizeof(server_addr));
   server_addr.sin_family=AF_INET;
   server_addr.sin_port=htons(atoi("6688"));
  // server_addr.sin_port=htons(6688);
   server_addr.sin_addr.s_addr=inet_addr("192.168.21.128");
   //server_addr.sin_addr.s_addr=htonl(INADDR_ANY);
   if((bind(server_fd,(const struct sockaddr*)&server_addr,sizeof(server_addr)))==-1)
   {
    // throw std::runtime_error("bind~");
	   perror("bind");
        exit(-1);
   }
}
Udp_s::~Udp_s()
{
  close(server_fd);
}
//void Udp_s::confirm()
void Udp_s::send()
{
  strcpy(send_buf, "I see you!\n");
  sendto(server_fd,send_buf,strlen(send_buf),0,(struct sockaddr*)&client_addr,sizeof(client_addr));

}
void Udp_s::receive()
{
  socklen_t len=sizeof(client_addr);
  recvfrom(server_fd,recv_buf,128, 0,(struct sockaddr*)&client_addr,&len);
  char ip[32]="";
  printf("%s\n",recv_buf);

}

