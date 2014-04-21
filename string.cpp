/*************************************************************************
	> File Name: string.cpp
	> Author: crooked
	> Mail:812665244@qq.com 
	> Created Time: Fri 18 Apr 2014 02:08:08 PM CST
 ************************************************************************/

#include"string.h"
namespace _str
{
  String::String()
  {
    _str= new char;
    _str[0]=0;
  }
  String::String(const char *s)
  {
    _str=new char[strlen(s)+1];
    strcpy(_str,s);
  }
  String::String(const String &s)
  {
    _str=new char[s.size()+1];
    strcpy(_str,s._str);
  }
  std::size_t String::size() const
  {
     return strlen(_str);
  }

  void String::debug()
  {
    std::cout<<_str <<std::endl;
  }

  String::~String()
  {
    delete[] _str;
  }

  String &String::operator =(const String &s)
  {
     delete[] _str;
	 _str=new char[s.size()+1];
     strcpy(_str, s._str);
     return *this;
  }


}
