/*************************************************************************
	> File Name: udp_c.h
	> Author: crooked
	> Mail:812665244@qq.com 
	> Created Time: Fri 25 Apr 2014 10:54:12 AM CST
 ************************************************************************/
#ifndef _UDP_C_H_
#define _UDP_C_H

#include<iostream>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdexcept>
class Udp_c
{
  private:
     char recv_buf[128],send_buf[128];
	 int client_fd;
	 struct sockaddr_in server_addr,client_addr;
  public:
	 Udp_c();  //socket, connect
	 ~Udp_c();  //close
	 void send();  //send
	 void receive();  //recv
};
#endif
