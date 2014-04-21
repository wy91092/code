/*************************************************************************
	> File Name: copy3.cpp
	> Author: crooked
	> Mail:812665244@qq.com 
	> Created Time: Fri 18 Apr 2014 10:58:11 AM CST
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;
class String
{
   char *_str;
    public:
	   String()
	   {
	     _str=new char;
		 _str[0]=0;
	   }
       String(const char *s)
	   {
	     _str=new char[strlen(s)+1];
		 strcpy(_str,s);
	   }
	   String(const String &other)
	   {
	      _str=new char[strlen(other._str)+1];
          strcpy(_str,other._str);
	   }
	   void debug()
	   {
	   
	   cout<<_str<<endl;
	   }
	   ~String()
	   {
	   delete[] _str;
	   }
};
int main()
{
   String s1("hello");
   s1.debug();
   String s2(s1);
   s2.debug();

}
