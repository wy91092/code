/*************************************************************************
	> File Name: main_s.cpp
	> Author: crooked
	> Mail:812665244@qq.com 
	> Created Time: Mon 14 Apr 2014 04:58:18 PM CST
 ************************************************************************/

#include"udp_s.h"
int main()
{
   Udp_s server;
   while(1)
   {
   server.receive();
   server.send();
   }
   return 0;
}
