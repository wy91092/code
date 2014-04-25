/*************************************************************************
	> File Name: main_s.cpp
	> Author: crooked
	> Mail:812665244@qq.com 
	> Created Time: Mon 14 Apr 2014 04:58:18 PM CST
 ************************************************************************/

#include"udp_c.h"
int main()
{
   Udp_c client;
   while(1)
   {
   client.send();
   client.receive();
   }
   return 0;
}
