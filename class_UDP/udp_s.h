/*************************************************************************
	> File Name: udp_s.h
	> Author: crooked
	> Mail:812665244@qq.com 
	> Created Time: Mon 14 Apr 2014 03:50:15 PM CST
 ************************************************************************/
#ifndef _UDP_S_H
#define _UDP_S_H
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
class Udp_s
{
  private:
     char recv_buf[128],send_buf[128];
	 int server_fd;
	 struct sockaddr_in server_addr,client_addr;
  public:
   Udp_s();   //socket, bind
   ~Udp_s();  //close
 //  void confirm();  //bind
   void send();     //send
   void receive();  //recv

};
#endif
