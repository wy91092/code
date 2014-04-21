/*************************************************************************
	> File Name: producer.h
	> Author: crooked
	> Mail:812665244@qq.com 
	> Created Time: Tue 15 Apr 2014 01:56:53 PM CST
 ************************************************************************/

#ifndef _PRODUCER_H_
#define _PRODUCER_H_
#include<pthread.h>
#include"queue.h"
#include"thread.h"
class Producer:public Thread
{
   private:
      //pthread_t _tid;
      Queue *_p_queue;
   public:
      Producer(Queue *p_queue);
      virtual ~Producer();
	 // void start();
	 // static void *thread_func(void *arg);
	   void run();
	 // void join();
};
#endif
