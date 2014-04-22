/*************************************************************************
	> File Name: address.cpp
	> Author: crooked
	> Mail:812665244@qq.com 
	> Created Time: Tue 22 Apr 2014 10:40:30 AM CST
 ************************************************************************/

#include"address.h"
using namespace std;
string Address::GetName() const
{
   string s=Name;
   return s;
}
string Address::GetPhone() const
{
   string s=Phone;
   return s;
}
bool Address::isEmpty(){return Status;}
void Address::Enter(string &name,string &phone)
{
   int len=name.length();
   if(len>30) len=30;
   name.copy(Name, len, 0);
   Name[len]=0;
   len=phone.length();
   if(len>20) len=20;
   phone.copy(Phone, len, 0);
   Phone[len]=0;
}
void Address::Set(){Status=false;}
void Address::Clear(){Status=true;}

