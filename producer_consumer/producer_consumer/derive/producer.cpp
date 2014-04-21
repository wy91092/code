/*************************************************************************
	> File Name: producer.cpp
	> Author: crooked
	> Mail:812665244@qq.com 
	> Created Time: Tue 15 Apr 2014 02:20:37 PM CST
 ************************************************************************/

#include<iostream>
#include<stdlib.h>
#include<unistd.h>
#include"producer.h"
Producer::Producer(Queue *p_queue):_p_queue(p_queue)
{
  
}
Producer::~Producer()
{

}
/*void Producer::start()
{
   pthread_create(&_tid, NULL, thread_func, this);
}
void *Producer::thread_func(void *arg)
{
   Producer* p_thread=static_cast<Producer*>(arg);
   p_thread->run();
   return NULL;
}*/
void Producer::run()
{
    while(true)
	{
	   int tmp =rand()%1024;
	   std::cout<<"product a num: "<<tmp <<std::endl;
	   _p_queue->product(tmp);
	   sleep(1);
	}
}
/*void Producer::join()
{
  pthread_join(_tid,NULL);
}*/
