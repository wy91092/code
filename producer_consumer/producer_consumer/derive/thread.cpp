/*************************************************************************
	> File Name: thread.cpp
	> Author: crooked
	> Mail:812665244@qq.com 
	> Created Time: Mon 14 Apr 2014 01:37:42 PM CST
 ************************************************************************/

#include"thread.h"
#include<iostream>
using namespace std;
Thread::Thread():_tid(0)
{}
Thread::~Thread()
{}
void * Thread::thread_func(void *arg)
{
 Thread *p_thread=static_cast<Thread*>(arg);
 p_thread->run();
 return NULL;
}
/*void Thread::run()
{
  for(size_t ix=0;ix!=_num;++ix)
  {
    sleep(1);
    cout << " haha"  <<endl;
  }
}*/
void Thread::join()
{
  pthread_join(_tid, NULL);
}
void Thread::start()
{
   pthread_create(&_tid, NULL, thread_func, this);
}
