/*************************************************************************
  > File Name: consumer.cpp
  > Author: crooked
  > Mail:812665244@qq.com 
  > Created Time: Tue 15 Apr 2014 02:32:48 PM CST
 ************************************************************************/

#include<iostream>
#include<stdlib.h>
#include<unistd.h>
#include"consumer.h"
Consumer::Consumer(Queue *p_queue,int c_sleep):_p_queue(p_queue),_c_sleep(c_sleep)
{
	srand(10001);
}
Consumer::~Consumer(){}
void Consumer::run()
{
   while(true)
   {
     int num=_p_queue->consumer();
	 std::cout <<"consumer a num : "<<num<<std::endl;
     sleep(_c_sleep);
   }
}
