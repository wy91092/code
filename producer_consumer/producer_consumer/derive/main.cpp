/*************************************************************************
	> File Name: main.cpp
	> Author: crooked
	> Mail:812665244@qq.com 
	> Created Time: Tue 15 Apr 2014 02:46:42 PM CST
 ************************************************************************/

#include<iostream>
#include"queue.h"
#include"producer.h"
#include"consumer.h"
int main()
{
  Queue Q;
  Producer p(&Q);
  Consumer c(&Q);

  p.start();
  c.start();
  
  
  p.join();
  c.join();

  return 0;
}
