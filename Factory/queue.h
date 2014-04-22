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
#include"noncopyable.h"
class Queue:public noncopyable
{
  private:
	  std::queue<int> _queue;
	  Lock _lock;
	  Cond _full;
	  Cond _empty;
	  std::queue<int>::size_type _queue_size;
  public:

	  Queue(std::queue<int>::size_type queue_size);
	  virtual ~Queue();

	  int consumer();
	  void product(int num);
      
	  typedef std::queue<int>::size_type __queue_size;
};

#endif




