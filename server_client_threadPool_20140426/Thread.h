#ifndef __THREAD_H__
#define __THREAD_H__
#include "pthread.h"
#include <stdexcept>
class Thread
{

	private:
		pthread_t m_tid ;
		bool m_is_started ;
		pthread_attr_t m_attr ;
	protected:
		virtual void run() = 0 ;
		void* m_arg ;
		static void* thread_handle(void* arg); 
	public:
		Thread():m_tid(0),m_is_started(false)
	{
		pthread_attr_init(&m_attr);			
	}
		void start(void* arg = NULL)
		{
			
			if(!m_is_started)
			{	
				m_arg = arg ;
				if(pthread_attr_setdetachstate(&m_attr, PTHREAD_CREATE_DETACHED))
				{
					throw std::runtime_error("pthread_attr_setdetachstate");
					return  ;
				}	
				if(pthread_create(&m_tid, &m_attr, Thread::thread_handle, this))
				{
					throw std::runtime_error("pthread_create");
					return  ;
				}
			}
		}
		~Thread()
		{
			pthread_attr_destroy(&m_attr);
		}


};
void* Thread::thread_handle(void* arg)
{
	Thread* p = (Thread*)arg ;
	p -> run() ;	
}
#endif
