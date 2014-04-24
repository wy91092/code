/*************************************************************************
	> File Name: test_vector.cpp
	> Author: crooked
	> Mail:812665244@qq.com 
	> Created Time: Thu 24 Apr 2014 10:32:05 AM CST
 ************************************************************************/
#include"vector.h"
#include<iostream>
using namespace std;
int main()
{
  int a[10]={1,2,3,4,5,6,7,8,9,10};
  MyVector obj1(0);
  MyVector obj2(a,a+10);
  cout<<obj2[4]<<endl;
  obj1.push_back(1);
  obj1.push_back(2);
  obj1.push_back(3);
  obj1.push_back(4);
  obj1.push_back(5);
  obj1.push_back(6);
  cout<<obj1[0]<<endl;
  cout<<obj1[1]<<endl;
  cout<<obj1[2]<<endl;
  cout<<obj1[3]<<endl;
  cout<<obj1[4]<<endl;
  cout<<obj1[5]<<endl;
  cout<<"obj1.size= "<<obj1.size()<<endl;
  cout<<"obj1.capacity= "<<obj1.capacity()<<endl;
  MyVector obj3(10);
  int num;
  cin >>num;
  for(int i=0;i!=num;i++)
  {
    obj3.push_back(i);
  }
  cout<<"obj3.size= "<<obj3.size()<<endl;
  cout<<"obj3.capacity= "<<obj3.capacity()<<endl;
  cout<<obj3[0]<<endl;
  cout<<obj3[1]<<endl;
  cout<<obj3[2]<<endl;
  cout<<obj3[3]<<endl;
  cout<<obj3[4]<<endl;
  cout<<obj3[5]<<endl;
  obj3.insert(3,50);
  cout<<obj3[3]<<endl;

  MyVector obj4(obj3);
  cout<<obj4[1]<<endl;
  MyVector obj5;
  obj5=obj3;
  cout<<obj5[3]<<endl;
  cout<<obj5[1]<<endl;
  
}

