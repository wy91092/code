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
Consumer::Consumer(Queue *p_queue):_p_queue(p_queue)
{
	srand(10001);
}
Consumer::~Consumer(){}
/*void Consumer::start()
{
  pthread_create(&_tid,NULL,thread_func,this);
}
void *Consumer::thread_func(void *arg)
{
  Consumer *p_thread=static_cast<Consumer*>(arg);
  p_thread->run();
  return NULL;
}*/
void Consumer::run()
{
   while(true)
   {
     int num=_p_queue->consumer();
	 std::cout <<"consumer a num : "<<num<<std::endl;
   }
}
/*
void Consumer::join()
{
  pthread_join(_tid,NULL);
}*/
