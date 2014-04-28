#ifndef __MYTHREAD_H__
#define __MYTHREAD_H__
#include "Thread.h"
#include <iostream>
#include "MyCondition.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <netinet/in.h>
class ThreadPool ;
struct MyTask
{
	struct sockaddr_in  client ;
	std::string  express ;
};
class MyThread: public Thread
{
	public:
	MyThread()
	{
		 m_client_fd = socket(AF_INET, SOCK_DGRAM, 0) ;
		
	}
	void get_related(ThreadPool* pobj)
	{
		m_threadpool = pobj ;
	}
	void run();
		/*
	{
		while(true)
		{
			MyTask task;
			if( ! (m_threadpool->get_task(task)) )	
			{
				break ;
			}
			execute_task(task);
			sleep(1);
		}
	}*/
	private:
		void execute_task(MyTask& task)
		{
			int left , right ; 
			char op ;
			int result ;
			sscanf(task.express.c_str(), "%d%c%d", &left, &op, &right);
			switch(op)
			{
				case '+' : 
					result = left + right ;		
					break ;	
			}		
			sendto(m_client_fd, &result, sizeof(int), 0,(struct sockaddr*)&task.client ,16);
		}
		ThreadPool* m_threadpool ;
		int m_client_fd ;
};
#endif
