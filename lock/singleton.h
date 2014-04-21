/*************************************************************************
	> File Name: singleton.h
	> Author: crooked
	> Mail:812665244@qq.com 
	> Created Time: Fri 11 Apr 2014 07:59:38 PM CST
 ************************************************************************/

#ifndef _SINGLETON_H_
#define _SINGLETON_H_
#include"lock.h"
class Singleton
{
  public:
	  static Singleton *get_instance();
  private:
	  Singleton()
	  {
	  }
	  static Singleton *_p_instance;
	  static Lock _lock;


};


#endif
