#ifndef __THREADPOOL_H__
#define __THREADPOOL_H__
#include "MyThread.h"
#include <vector>
#include <queue>
#include <time.h>
class ThreadPool 
{
	public:
		ThreadPool(const int num = 12):m_threads(num),m_mutex(),m_cond(m_mutex),m_on(false)
		{
			std::vector<MyThread>::iterator iter = m_threads.begin();
			for(; iter != m_threads.end(); iter ++)
			{
				iter -> get_related(this);
			}
		} 		
		void threadpool_work()
		{
			if(!m_on)
			{
				m_on = true ;
#ifndef NDEBUG
				std::cout << "ThreadPool started !" << std::endl;
#endif
				std::vector<MyThread>::iterator iter = m_threads.begin();
				for(; iter != m_threads.end(); iter ++)
				{
					iter -> start();
				}
					
			}
		}
		void threadpool_stop()
		{
			if(m_on)
			{
				m_on = false ;
				m_cond.notifyall();
			}
		}
		bool allocate_task(MyTask p)
		{
			m_mutex.lock();
			//MyTask task ;
			//make_task(task);
			m_tasks.push(p);
#ifndef NDEBUG
				std::cout << "Task add !" << std::endl;
#endif
			m_mutex.unlock();
			m_cond.notifyall();
		}		
		bool get_task(MyTask& task)
		{
			m_mutex.lock();
			while( m_on &&m_tasks.empty())
			{
	 		m_cond.wait();
			}
			if(!m_on)
			{
				m_mutex.unlock();
				m_cond.notifyall();
				return false ;
			}else if(!m_tasks.empty())
			{
				task =  m_tasks.front();
				m_tasks.pop();
				m_mutex.unlock();
				//m_cond.notifyall();
#ifndef NDEBUG
				std::cout << "Task get !" << std::endl;
#endif
				return true ;
			}

		}
	private:
		ThreadPool(const ThreadPool& obj);
		ThreadPool& operator =(const ThreadPool& obj);
		std::vector<MyThread> m_threads ;
		std::queue<MyTask> m_tasks ;
		MyMutex m_mutex ;
		MyCondition m_cond ;
		bool m_on ;
	

	
};
#endif
