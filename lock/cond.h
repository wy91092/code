/*************************************************************************
	> File Name: cond.h
	> Author: crooked
	> Mail:812665244@qq.com 
	> Created Time: Fri 11 Apr 2014 05:02:04 PM CST
 ************************************************************************/

#ifndef _COND_H_
#define _COND_H_
#include<pthread.h>
class Cond
{
 private:
	 pthread_cond_t _cond;
 public:
     Cond();
	 ~Cond();
	 void wait();
     void signal();
     void broadcast();
};




#endif
