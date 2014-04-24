/*************************************************************************
  > File Name: expression.cpp
  > Author: crooked
  > Mail:812665244@qq.com 
  > Created Time: Thu 24 Apr 2014 08:37:31 PM CST
 ************************************************************************/
#include"expression.h"
using namespace std;

int main()
{
	string infix;
	while(1)
	{
		cin>>infix;
		string postfix=getPostfixExp(infix);
		cout<<postfix<<endl;
		cout<<postfixCalculate(postfix)<<endl;
	}
	return 0;
}
