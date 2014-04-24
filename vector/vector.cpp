/*************************************************************************
  > File Name: vector.cpp
  > Author: crooked
  > Mail:812665244@qq.com 
  > Created Time: Thu 24 Apr 2014 10:28:47 AM CST
 ************************************************************************/

#include"vector.h"
using namespace std;
MyVector::MyVector()
{
	_size=0;
	_capacity=0;
	_array=new int[_capacity]; 
}

MyVector::MyVector(int capacity)
{
	_size=0;
	_capacity=capacity;
	_array=new int[_capacity];
}

MyVector::MyVector(int *begin, int *end)
{
	_size=0;
	_capacity=(end-begin);
    _array=new int[_capacity]; 
	for(int i=0;i<(end-begin);i++)
	{
		_array[i]=begin[i];
		++_size;
	}
}

MyVector::MyVector(const MyVector &other)
{
	_size=other._size;
	_capacity=other._capacity;
	_array=new int[_capacity];
	for(int i=0;i<_size;i++)
	{
		_array[i]=other._array[i];
	}
}

MyVector &MyVector::operator=(const MyVector &other)
{
	int i;
	if(_capacity==other._capacity&&_size==other._size)
	{

		for( i=0; i<_size;i++)
		{
			if(_array[i]!=other._array[i]) break;
		}

		if(i<_size-1)
		{
			delete []_array;
			_array=new int[other._capacity];
			for( i=0;i<other._size;i++)
			{
				_array[i]=other._array[i];
			}
		}
	}
	else
	{
		delete []_array;
		_array=new int[other._capacity];
		for( i=0;i<other._size;i++)
		{
			_array[i]=other._array[i];
		}

	}
	return *this;
}
int MyVector::operator[](int num)
{
	return _array[num];
}
void MyVector::push_back(int num)
{
    if(_capacity==0)
	{ 
		++_capacity;
		_array=new int[_capacity];
	}
		if(_size<_capacity)
	{
		_array[_size]=num;
	}
	else
	{
		MyVector tmp(_capacity);
		for(int i=0;i<_capacity;i++)
		{
			tmp._array[i]=_array[i];
		}
		delete []_array;
		_capacity=_capacity*2;
		_array=new int[_capacity];
		for(int i=0;i<_capacity/2;i++)
		{
			_array[i]=tmp._array[i];
		}
		_array[_size]=num;
	}
	++_size;
}
int MyVector::size()
{
	return _size;
}
int MyVector::capacity()
{
	return _capacity;
}
void MyVector::insert(int pos , int num)
{
	if(_size<_capacity)
	{
		for(int i=_size;i>pos;i--)
		{
			_array[i]=_array[i-1];
		}
		_array[pos]=num;
	}
	else
	{
		MyVector tmp(_capacity);
		for(int i=0;i<_capacity;i++)
		{
			tmp._array[i]=_array[i];
		}
		delete []_array;
		_capacity=2*_capacity;
		_array=new int[_capacity];
		for(int i=0;i<_capacity/2;i++)
		{
			_array[i]=tmp._array[i];
		}
		for(int i=_size;i>pos;i--)
		{
			_array[i]=_array[i-1];
		}
		_array[pos]=num;
	}
	++_size;
}
MyVector::~MyVector()
{
	delete []_array;
}
