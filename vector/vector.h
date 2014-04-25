/*************************************************************************
	> File Name: vector.h
	> Author: crooked
	> Mail:812665244@qq.com 
	> Created Time: Thu 24 Apr 2014 10:16:15 AM CST
 ************************************************************************/

#ifndef _VECTOR_H_
#define _VECTOR_H_
#include<vector>
#include<iostream>
class MyVector
{
	private:
		//std::vector<int> _vec;
	   int _size;
		int _capacity;
	   int *_array;
  public:
	  MyVector();
	  MyVector(int capacity);
	  MyVector(const MyVector &);
	  MyVector(int *, int *);
     ~MyVector();

	  MyVector &operator=(const MyVector &);
	  int& operator[](const int);

       
	  void push_back(const int );
	 const int size() const;
	 const int capacity() const;
	  void insert(const int,const int);
};

#endif
