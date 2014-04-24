/*************************************************************************
	> File Name: test_Complex.cpp
	> Author: crooked
	> Mail:812665244@qq.com 
	> Created Time: Thu 24 Apr 2014 09:40:36 AM CST
 ************************************************************************/
#include"Complex.h"
#include<iostream>
using namespace std;

int main()
{
   Complex obj1;
   Complex obj2(3,4);
   cout<<obj2<<endl;
   Complex obj3,obj4;
   
   cin >> obj3>>obj4;
   cout<<obj2+obj3<<endl;
   cout<<obj2-obj3<<endl;
   cout<<obj2*obj4<<endl;
   cout<<(obj2==obj3)<<endl;

   Complex obj5(obj2);
   cout <<obj5<<endl;;
   
   Complex obj6;
   obj6=obj2;
   cout<<obj6<<endl;
   return 0;
}
