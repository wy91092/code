/*************************************************************************
	> File Name: copy2.cpp
	> Author: crooked
	> Mail:812665244@qq.com 
	> Created Time: Fri 18 Apr 2014 10:52:59 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;
class Array
{
   int *_p;
	public:
	   Array()
	   {
	     _p=new int;
	   }
	   ~Array()
	   {
	     delete _p;
	   }
	   void debug()
	   {
	    cout<<_p<<endl;
	   }
};
int main()
{
   Array a;
   a.debug();
  // Array a2(a);
  // a2.debug();   error free 2 times
}
