/*************************************************************************
	> File Name: date.cpp
	> Author: crooked
	> Mail:812665244@qq.com 
	> Created Time: Tue 15 Apr 2014 09:49:17 AM CST
 ************************************************************************/
#include<string>
#include<ctime>
#include<iostream>
using namespace std;
#include"date.h"
//静态成员初始化
const int Date::days[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
//构造函数
Date::Date(int y, int m, int d)
{
 SetDate(y,m,d);
}
Date::Date(int m,int d)
{
 SetDate(m,d);
}
Date::Date()
{
  SystemDate();
}
void Date::SystemDate()
{
  tm *gm;
  time_t t=time(NULL);
  gm=gmtime(&t);
  year =1900 +gm->tm_year;
  month=gm->tm_mon+1;
  day=gm->tm_mday;
}
void Date::SetDate(int yy, int mm, int dd)
{
  month=(mm>=1&&mm<=12) ?mm:1;
  year=(yy>=1900&&yy<=2100)?yy:1900;
  if(month ==2 && IsLeapYear(year))
	  day=(dd>=1&&dd<=29)? dd:1;
  else day=(dd>=1&&dd<=days[month])?dd:1;
}
void Date::SetDate(int mm, int dd)
{
  tm *gm;
  time_t t=time(NULL);
  gm=gmtime(&t);
  month =(mm>=1 && mm<=12) ?mm :1;
  year =1900 +gm->tm_year;
  if(month==2&&IsLeapYear(year))
	  day=(dd>=1&&dd<=29) ?dd:1;
  else day=(dd>=1 &&dd<=days[month]) ?dd:1;
}
const Date &Date::operator +(int days)
{  //重载+
	for(size_t i=0;i!=days;i++)
        IncDay();
    return *this;
}
const Date &Date::operator +=(int days)
{  //重载+=
	for(size_t i=0;i!=days;i++)
        IncDay();
    return *this;
}
int Date::operator -(const Date& ymd)const
{  //重载-
   int days;
   days=DayCalc()-ymd.DayCalc();
   return days;
}
bool Date::IsLeapYear(int y) const
{
  if(y%400==0||( y%100!=0 && y%4==0 )) return true;
  else return false;
}
bool Date::IsEndofMonth()const
{
  if(month==2 && IsLeapYear(year)) return day==29;
  else return day==days[month];
}
void Date::IncDay()
{  //日期递增一天
	if(IsEndofMonth())
	{
	  if(month==12)
	  {
	   day=1;month=1;year++;
	  }else
	  {
	   day=1;month++;
	  }
	}else day++;
}
int Date::DayCalc()const
{
  int dd;
  int yy=year-1900;
  dd=yy*365;
  if(yy) dd += (yy-1)/4;
  for(size_t i=1;i!=month; i++) dd+=days[i];
  if(IsLeapYear(year)&&(month>2)) dd++;
  dd+=day;
  return dd;
}
void Date::print_ymd()const
{
 cout<<year<<"-"<<month<<"-"<<day<<endl;
}
void Date::print_mdy()const
{
  string monthName[12]={"January","February","March","April","May","June","July","August","September","October","November","December"};
  cout<<monthName[month -1] <<" "<<day<<","<<year<<endl;
}
void Date::IsBirth(const Date& ymd) const  //判断生日与否  
{
  int days;
  days=DayCalc()-ymd.DayCalc();
  if(days==0)
  {
    cout << "Happy Birthday!! "<<endl;
  }
  else if(days<0)
  {
	days=-days;
    cout<< "after "<<days<<" days is your birthday";
  }
  else 
  {
	days=365-days;
    cout <<"your birthday has passed, and you shoule wait for "<<days;
	cout<<" days for your next birthday!"<<endl;
  }
}
