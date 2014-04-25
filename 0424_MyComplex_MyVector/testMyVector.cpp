/*************************************************************************
  > File Name: testMyVector.cpp
  > Author: Comst
  > Mail:750145240@qq.com 
  > Created Time: Thu 24 Apr 2014 04:47:06 PM CST
 ************************************************************************/

#include "MyVector.h"
#include <algorithm>
#include <functional>
#include <iostream>
void show(int i)
{
	std::cout << i << " " ;
}
int main(int argc, char* argv[] )
{
	int a[10] = {1,2,3,4,5,6,7,8,9,10} ;
	MyVector vector_obj1;  
	std::cout <<"size : " <<vector_obj1.size() << "capacity: " << vector_obj1.capacity() << " "<< __LINE__<<std::endl ;		
	MyVector vector_obj2(5);  //初始化一个含有5个元素的每个元素为0
	std::cout <<"size : " <<vector_obj1.size() << "capacity: " << vector_obj1.capacity() << " " <<__LINE__<<std::endl ;		
	std::for_each(vector_obj2.begin(), vector_obj2.end(), show);
	std::cout << std::endl ;

	MyVector vector_obj3(a, a + 10);  //用一个数组初始化
	std::cout <<"size : " <<vector_obj3.size() << "capacity: " << vector_obj3.capacity() << " "<<__LINE__<<std::endl ;		
	std::for_each(vector_obj3.begin(), vector_obj3.end(), show);
	std::cout << std::endl ;

	int num ;
	std::cin >> num ;
	for(int  i = 0 ; i < num ; i ++)
	vector_obj3.push_back(i);
	std::cout <<"size : " <<vector_obj3.size() << "capacity: " << vector_obj3.capacity() << " "<<__LINE__ << std::endl ;		
	std::for_each(vector_obj3.begin(), vector_obj3.end(), show);
	std::cout << std::endl ;

	std::cout <<"[3]" << vector_obj3[3] <<std::endl ;
	vector_obj3.insert(5, 50) ; //在第五个位置插入50
	std::cout <<"size : " <<vector_obj3.size() << "capacity: " << vector_obj3.capacity() << " "<<__LINE__<<std::endl ;		
	std::for_each(vector_obj3.begin(), vector_obj3.end(), show);
	std::cout << std::endl ;

	MyVector vector_obj4(vector_obj3);
	std::cout <<"size : " <<vector_obj4.size() << "capacity: " << vector_obj4.capacity() << " "<<__LINE__<< std::endl ;		
	std::for_each(vector_obj4.begin(), vector_obj4.end(), show);
	std::cout << std::endl ;

	MyVector vector_obj5 ;
	vector_obj5 = vector_obj3 ;
	std::cout <<"size : " <<vector_obj5.size() << "capacity: " << vector_obj5.capacity() << __LINE__<<std::endl ;		
	std::for_each(vector_obj5.begin(), vector_obj5.end(), show);
	std::cout << std::endl ;
	return 0 ;
}

