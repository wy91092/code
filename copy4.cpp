/*************************************************************************
	> File Name: copy4.cpp
	> Author: crooked
	> Mail:812665244@qq.com 
	> Created Time: Fri 18 Apr 2014 11:33:57 AM CST
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
class Test
{
    public:
		Test(){}
	private:
		Test(const Test &t){}
};
int main()
{
   Test t;
   //Test t2(t);
}
