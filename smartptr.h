/*************************************************************************
  > File Name: smartptr.h
  > Author: crooked
  > Mail:812665244@qq.com 
  > Created Time: Mon 21 Apr 2014 01:49:34 PM CST
 ************************************************************************/
#ifndef _SMARTPTR_
#define _SMARTPTR_
#include<iostream>
#include<string>
class Student
{
	public:
		Student(int id,const std::string &name):_id(id),_name(name){}
		void print()
		{
			std::cout<<_id<<" "<<_name<<std::endl;
		}
	private:
		int _id;
		std::string _name;

};
class SmartPtr
{
	public:
		SmartPtr();
		SmartPtr(Student *ptr);
		~SmartPtr();
		void reset_ptr(Student *ptr);
        const Student * get_ptr() const;
		
		Student *operator->();
		const Student *operator->() const;

		Student &operator*();
		const Student &operator*() const;
	private:
		Student *_ptr;
		SmartPtr(const SmartPtr &); 
		SmartPtr &operator=(const SmartPtr &);

}; 

#endif

