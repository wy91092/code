/*************************************************************************
	> File Name: date.h
	> Author: crooked
	> Mail:812665244@qq.com 
	> Created Time: Tue 15 Apr 2014 09:29:34 AM CST
 ************************************************************************/

#ifndef _DATE_H_
#define _DATE_H_
#include<iostream>
class Date
{
  int day, month, year;
  void IncDay();              //日期增加一天
  int DayCalc() const;        //距基准日期的天数 
  static const int days[];    //每月的天数
	public:
  Date(int y, int m, int d);
  Date(int m, int d);           //年默认为系统年份
  Date();
  int GetYear(){return year;}
  int Getmonth(){return month;}
  int Getday(){return day;}
  void SystemDate();
  void SetDate(int yy, int mm, int dd);
  void SetDate(int mm, int dd);  //年默认为系统年份
  bool IsLeapYear(int yy)const;  //是否闰年
  bool IsEndofMonth() const;     //是否月末
  void print_ymd() const;
  void print_mdy() const;
  const Date &operator + (int days) ;  //日期增加任意天
  const Date &operator += (int days);  //日期增加任意天
  int operator - (const Date& ymd) const; //两个日期之间的天数
  void IsBirth(const Date& ymd) const;  //判断生日与否  
};
#endif
