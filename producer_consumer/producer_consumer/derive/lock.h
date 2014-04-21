/*************************************************************************
	> File Name: lock.h
	> Author: crooked
	> Mail:812665244@qq.com 
	> Created Time: Fri 11 Apr 2014 01:47:44 PM CST
 ************************************************************************/

#ifndef _LOCK_H_
#define _LOCK_H_
#include<pthread.h>
class Cond;
class Lock
{
   private:
	   pthread_mutex_t _mutex;
   public:
	friend class Cond;
	 Lock();
	 virtual ~Lock();
	 void  lock();
	 void  unlock();

};


#endif
