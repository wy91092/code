/*************************************************************************
  > File Name: consumer.h
  > Author: crooked
  > Mail:812665244@qq.com 
  > Created Time: Tue 15 Apr 2014 02:29:43 PM CST
 ************************************************************************/

#ifndef _CONSUMER_H_
#define _CONSUMER_H_
#include<pthread.h>
#include"queue.h"
#include"thread.h"
class Consumer:public Thread
{
	private:
		int _c_sleep;
		Queue *_p_queue;
	public:
		Consumer(Queue *p_queue,int c_sleep);
		virtual ~Consumer();
		void run();
};
#endif
