/*************************************************************************
	> File Name: Complex.cpp
	> Author: crooked
	> Mail:812665244@qq.com 
	> Created Time: Thu 24 Apr 2014 09:35:48 AM CST
 ************************************************************************/
#include"Complex.h"
using namespace std;

Complex::Complex():_real_part(0),_imag_part(0){}

Complex::Complex(float real_part,float imag_part):_real_part(real_part),_imag_part(imag_part){}

Complex::Complex(const Complex &other)
{
  _real_part=other._real_part;
  _imag_part=other._imag_part;
}
Complex &Complex::operator=(const Complex &other)
{
   _real_part=other._real_part;
   _imag_part=other._imag_part;
   return *this;
}
Complex::~Complex()
{

}
