#ifndef __MYMUTEX_H__
#define __MYNUTEX_H__
#include <pthread.h>
class MyMutex
{
	public:
		friend class MyCondition ;
		MyMutex()
		{
			pthread_mutex_init(&m_mutex, NULL);
		}
		void lock()
		{
			pthread_mutex_lock(&m_mutex);
		}
		void unlock()
		{
			pthread_mutex_unlock(&m_mutex);
		}
		~MyMutex()
		{
			pthread_mutex_destroy(&m_mutex);
		}
	private:
		pthread_mutex_t m_mutex ;
		MyMutex(const MyMutex& obj);
		MyMutex& operator = (const MyMutex& obj);
		
};
#endif
