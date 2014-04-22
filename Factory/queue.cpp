/*************************************************************************
  > File Name: queue.cpp
  > Author: crooked
  > Mail:812665244@qq.com 
  > Created Time: Tue 15 Apr 2014 02:11:47 PM CST
 ************************************************************************/
#include"queue.h"
#include<stdlib.h>
#include<unistd.h>
#include<iostream>
Queue::Queue(std::queue<int>::size_type queue_size):_queue(),_lock(),_full(&_lock),_empty(&_lock),_queue_size(queue_size)
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
		std::cout<<"you can consume~"<<std::endl;
		_full.wait();
	}
	ret=_queue.front();
	_queue.pop();
	_empty.signal();
	_lock.unlock();
	return ret;
}
void Queue::product(int num)
{
	_lock.lock();
	while(_queue.size()==_queue_size)
	{
	  std::cout<<"full,cannot product anymore~"<<std::endl;
	  _empty.wait();
	}
	_queue.push(num);
	_full.signal();
	_lock.unlock();
}
