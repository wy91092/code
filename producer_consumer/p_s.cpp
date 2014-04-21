/*************************************************************************
	> File Name: p_s.cpp
	> Author: crooked
	> Mail:812665244@qq.com 
	> Created Time: Tue 15 Apr 2014 11:23:47 AM CST
 ************************************************************************/

#include<iostream>
#include<pthread.h>
#include<queue>
#include<string>
#include<stdlib.h>
using namespace std;

std::queue<int> Q;
pthread_mutex_t mutex;
pthread_cond_t full;
pthread_cond_t empty;

void *producer_func(void *arg)
{
  srand(time(NULL));
  while(true)
	{
  pthread_mutex_lock(&mutex);
  int num1= rand()%100;
  while(Q.size()==5)
  {
	std::cout<<"full full full!!"<<std::endl;
    pthread_cond_wait(&empty,&mutex);
  }
	  Q.push(num1);
  cout<<"push a num "<<num1<<endl;
  pthread_cond_signal(&full);
  pthread_mutex_unlock(&mutex);
	sleep(1);
	}	
  return NULL;
}
void *consumer_func(void *arg)
{  
   while(true)
   {
	pthread_mutex_lock(&mutex);
   while(Q.empty()){
	std::cout<<"empty empty empty!!"<<std::endl;;
	  pthread_cond_wait(&full,&mutex);}
   int num=Q.front();
   Q.pop();
   cout<<"get a num: "<<num <<endl;
   pthread_cond_signal(&empty);
   pthread_mutex_unlock(&mutex);
   sleep(5);
   }
	return NULL;
}


int main()
{
   pthread_mutex_init(&mutex,NULL);
   pthread_cond_init(&full,NULL);
   pthread_cond_init(&empty,NULL);

   pthread_t a,b;
   pthread_create(&a,NULL,producer_func,NULL);
   pthread_create(&b,NULL,consumer_func,NULL);

   pthread_join(a,NULL);
   pthread_join(b,NULL);

   pthread_mutex_destroy(&mutex);
   pthread_cond_destroy(&full);
   pthread_cond_destroy(&empty);
}
