/*************************************************************************
	> File Name: noncopyable.h
	> Author: crooked
	> Mail:812665244@qq.com 
	> Created Time: Tue 22 Apr 2014 04:56:55 PM CST
 ************************************************************************/

#ifndef NONCOPYABLE_H_
#define NONCOPYABLE_H_

class noncopyable
{
   protected:
	   noncopyable(){}
	   ~noncopyable(){}
   private:
	   noncopyable(const noncopyable&);
       noncopyable &operator=(const noncopyable &);
};
#endif
