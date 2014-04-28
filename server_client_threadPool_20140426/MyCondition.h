#ifndef __MYCONDITION_H__
#define __MYCONDITION_H__
#include "MyMutex.h"
class MyCondition
{
	public:
	MyCondition(MyMutex& mutex):m_mutex(mutex)
	{	
		if(pthread_cond_init(&m_cond, NULL))
		{
			throw std::runtime_error("pthread_cond_init");
		}
	}
	void wait()
	{
		pthread_cond_wait(&m_cond, &m_mutex.m_mutex);
	}
	void notify()
	{
		pthread_cond_signal(&m_cond);
	}
	void notifyall()
	{
		pthread_cond_broadcast(&m_cond);
	}
	~MyCondition()
	{
		pthread_cond_destroy(&m_cond);
	}
	private:
	MyCondition(const MyCondition& obj);
	MyCondition& operator = (const MyCondition& obj) ;
	pthread_cond_t m_cond ;
	MyMutex& m_mutex ;
};
#endif
