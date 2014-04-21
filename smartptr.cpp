/*************************************************************************
  > File Name: smartptr.cpp
  > Author: crooked
  > Mail:812665244@qq.com 
  > Created Time: Mon 21 Apr 2014 01:52:22 PM CST
 ************************************************************************/
#include"smartptr.h"
#include<iostream>

SmartPtr::SmartPtr():_ptr(NULL){}
SmartPtr::SmartPtr(Student *ptr):_ptr(ptr){}
SmartPtr::~SmartPtr()
{
	delete _ptr;
}
void SmartPtr::reset_ptr(Student *ptr)
{
	if(ptr!=_ptr)
	{
		delete _ptr;
		_ptr=ptr;
	}
}
const Student* SmartPtr::get_ptr() const
{
	return _ptr;
}

Student *SmartPtr::operator->()
{
   return _ptr;
}
const Student *SmartPtr::operator->() const
{
	return _ptr;
}

Student &SmartPtr::operator*()
{
   return *_ptr;
}
const Student &SmartPtr::operator*() const
{
   return *_ptr;
}
