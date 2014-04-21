/*************************************************************************
	> File Name: cond.h
	> Author: crooked
	> Mail:812665244@qq.com 
	> Created Time: Fri 11 Apr 2014 05:02:04 PM CST
 ************************************************************************/

#ifndef _COND_H_
#define _COND_H_
#include<pthread.h>
#include"lock.h"
class Cond
{
 private:
	 pthread_cond_t _cond;
	 Lock *_p_lock;
 public:
     Cond(Lock *p_lock);
	 virtual ~Cond();
	 void wait();
     void signal();
     void broadcast();
};




#endif
