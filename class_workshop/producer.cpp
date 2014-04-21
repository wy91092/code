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
Producer::Producer(Queue *p_queue,int p_sleep):_p_queue(p_queue),_p_sleep(p_sleep)
{
  
}
Producer::~Producer()
{

}
void Producer::run()
{
    while(true)
	{
	   int tmp =rand()%1024;
	   std::cout<<"product a num: "<<tmp <<std::endl;
	   _p_queue->product(tmp);
	   sleep(_p_sleep);
	}
}
