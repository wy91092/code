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
      Queue *_p_queue;
	  int _p_sleep;
   public:
      Producer(Queue *p_queue,int p_sleep);
      virtual ~Producer();
	   void run();
};
#endif
