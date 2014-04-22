/*************************************************************************
	> File Name: workshop.h
	> Author: crooked
	> Mail:812665244@qq.com 
	> Created Time: Tue 15 Apr 2014 07:39:24 PM CST
 ************************************************************************/

#ifndef _WORKSHOP_H_
#define _WORKSHOP_H_
#include<vector>
#include"producer.h"
#include"consumer.h"
#include"queue.h"
class WorkShop
{ 
	private:
		Queue::__queue_size _size;
		Queue  _queue;
		std::size_t _num_producer;
		std::size_t _num_consumer;
		std::vector<Producer> _producers;
		std::vector<Consumer> _consumers;
	public:
        WorkShop(std::size_t num_producer,std::size_t num_consumer,Queue::__queue_size size,int c_sleep,int p_sleep);
		~WorkShop();
		void start();
 
};
#endif
