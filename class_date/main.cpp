/*************************************************************************
	> File Name: main.cpp
	> Author: crooked
	> Mail:812665244@qq.com 
	> Created Time: Tue 15 Apr 2014 10:29:49 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include"date.h"
int main()
{
  Date today, Olympicday(2004,8,13);
  cout <<"Today(the computer`s day) is:";
  today.print_ymd();
  cout <<"After 365 days, the date is: ";
  today+=365;
  today.print_ymd();
  Date testday(2,28);
  cout <<"the test date is: ";
  testday.print_ymd();
  Date nextday =testday+1;
  cout <<"the next day is: ";
  nextday.print_ymd();
  today.SystemDate();
  cout <<"the Athens Olympic Games openday is : ";
  Olympicday.print_mdy();
  cout <<"And after "<<Olympicday-today;
  cout<<"days,the Athens Olympic Games will open."<<endl;
  int _year,_month,_day;
  cin>>_year;
  cin>>_month;
  cin>>_day;
  Date Birth(_year,_month,_day);
  today.IsBirth(Birth);
  return 0;
}
