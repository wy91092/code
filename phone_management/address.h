/*************************************************************************
	> File Name: address.h
	> Author: crooked
	> Mail:812665244@qq.com 
	> Created Time: Tue 22 Apr 2014 10:31:19 AM CST
 ************************************************************************/
#ifndef ADDRESS_H_
#define ADDRESS_H_
#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include<string.h>
class Address
{
  bool Status;
  char Name[31];
  char Phone[21];
	public:
  Address(){Status=true;}
  std::string GetName() const;
  std::string GetPhone() const;
  bool isEmpty();
  void Enter( std::string &name, std::string &phone);
  void Set();
  void Clear();
};
#endif
