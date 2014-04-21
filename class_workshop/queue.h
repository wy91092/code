/*************************************************************************
	> File Name: queue.h
	> Author: crooked
	> Mail:812665244@qq.com 
	> Created Time: Tue 15 Apr 2014 02:07:54 PM CST
 ************************************************************************/

#ifndef _QUEUE_H_
#define _QUEUE_H_
#include<queue>
#include"cond.h"
#include"lock.h"
class Queue
{
  private:
	  std::queue<int> _queue;
	  Lock _lock;
	  Cond _cond;
  public:
	  Queue();
	  virtual ~Queue();

	  int consumer();
	  void product(int num);
};

#endif




