/*************************************************************************
	> File Name: workshop.cpp
	> Author: crooked
	> Mail:812665244@qq.com 
	> Created Time: Tue 15 Apr 2014 07:49:49 PM CST
 ************************************************************************/
#include"workshop.h"
#include<iostream>
using namespace std;
WorkShop::WorkShop(std::size_t num_producer,std::size_t num_consumer,int p_sleep,int c_sleep):_queue(),_num_producer(num_producer),_num_consumer(num_consumer),_producers(_num_producer,Producer(& _queue, p_sleep)),_consumers(_num_consumer, Consumer(& _queue,c_sleep))
{}
WorkShop::~WorkShop(){}
void WorkShop::start()
{ 
	for(std::vector<Producer>::iterator iter=_producers.begin();iter!=_producers.end();++iter)
	{
	  iter->start();
	}
	for(std::vector<Consumer>::iterator iter=_consumers.begin();iter!=_consumers.end();++iter)
	{
	  iter->start();
	}
	for(std::vector<Producer>::iterator iter=_producers.begin();iter!=_producers.end();++iter)
	{
	  iter->join();
	}
	for(std::vector<Consumer>::iterator iter=_consumers.begin();iter!=_consumers.end();++iter)
	{
	  iter->join();
	}
}
