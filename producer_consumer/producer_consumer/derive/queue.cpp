/*************************************************************************
  > File Name: queue.cpp
  > Author: crooked
  > Mail:812665244@qq.com 
  > Created Time: Tue 15 Apr 2014 02:11:47 PM CST
 ************************************************************************/
#include"queue.h"
#include<stdlib.h>
#include<unistd.h>
Queue::Queue():_queue(),_lock(),_cond(&_lock)
{
	srand(10000);
}
Queue::~Queue(){}
int Queue::consumer()
{
	_lock.lock();
	int ret;
	while(_queue.empty())
	{
		_cond.wait();
	}
	ret=_queue.front();
	_queue.pop();
	_lock.unlock();
	return ret;
}
void Queue::product(int num)
{
	_lock.lock();
	_queue.push(num);
	_cond.signal();
	_lock.unlock();
}
