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
#include"workshop.h"
int main()
{
  WorkShop A(1,3,1,3);   //参数含义：生产这数量， 消费者数量， 生产者生产频率， 消费者消费频率
  A.start();
  return 0;
}
