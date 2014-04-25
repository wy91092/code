/*************************************************************************
	> File Name: testexplicit.cpp
	> Author: Comst
	> Mail:750145240@qq.com 
	> Created Time: Thu 24 Apr 2014 05:48:10 PM CST
 ************************************************************************/

#include<iostream>
#include "MyComplex.h"
using namespace std;
void func(MyComplex obj)
{
cout << __LINE__ << endl ;	
}
int main()
{
	func(3);
return 0 ;


}

