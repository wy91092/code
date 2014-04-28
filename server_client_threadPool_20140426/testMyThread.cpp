#include "ThreadPool.h"
#include "MySocket.h"
#include <string.h>
#include <fstream>
void MyThread::run()
{
#ifndef NDEBUG
	std::cout << "thread run" << std::endl ;
#endif
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
}

int main(int argc, char* argv[])
{
	std::ifstream fin(argv[1]);
	std::string ip, port ;
	fin >>ip >> port ;
	std::cout << ip <<" " << port << std::endl ;
	const int len = 1024;
	char buf[len] ;
	MySocket asocket(ip, port);
	ThreadPool myThreadPool ;
	myThreadPool.threadpool_work() ;
	while(true)
	{	
		memset(buf, 0, len);
		asocket.recv_message(buf, len);
		//MyTask* p = new MyTask();
		//p ->express = buf ;
		//p -> pclient = new (struct sockaddr_in );
		//*(p -> pclient) = asocket.get_client(); 
		MyTask task ;
		task.express = buf ;
		task.client = asocket.get_client();
		myThreadPool.allocate_task(task);
	}
	myThreadPool.threadpool_stop() ;
	return 0 ;
}
