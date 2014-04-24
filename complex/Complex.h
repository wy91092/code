/*************************************************************************
  > File Name: Complex.h
  > Author: crooked
  > Mail:812665244@qq.com 
  > Created Time: Thu 24 Apr 2014 09:20:18 AM CST
 ************************************************************************/
#ifndef _COMPLEX_H_
#define _COMPLEX_H_
#include<iostream>
class Complex
{
	private:
		float _real_part;
		float _imag_part;
	public:
		Complex();
		Complex(float real_part,float imag_part);
		Complex(const Complex &);
		Complex &operator=(const Complex&);
		~Complex();
		friend bool operator==(const Complex &,const Complex &);
		friend Complex operator+(const Complex&,const Complex &);
		friend Complex operator-(const Complex&, const Complex &);
		friend Complex operator*(const Complex&,const Complex &);
		friend std::ostream &operator<<(std::ostream &os,const Complex &);
		friend std::istream &operator>>(std::istream &is, Complex &);

};
inline bool operator==(const Complex &lhs,const Complex &rhs)
{
	if(lhs._real_part==rhs._real_part&&lhs._imag_part==rhs._imag_part) return true;
	else return false;
}

inline Complex operator+(const Complex &lhs,const Complex &rhs)
{
	Complex tmp;
	tmp._real_part=lhs._real_part+rhs._real_part;
	tmp._imag_part=lhs._imag_part+rhs._imag_part;
	return tmp;
}
inline Complex operator-(const Complex &lhs,const Complex &rhs)
{
	Complex tmp;
	tmp._real_part=lhs._real_part-rhs._real_part;
	tmp._imag_part=lhs._imag_part-rhs._imag_part;
	return tmp;
}
inline Complex operator*(const Complex &lhs,const Complex &rhs)
{
	Complex tmp;
	tmp._real_part=lhs._real_part*rhs._real_part;
	tmp._imag_part=lhs._imag_part*rhs._imag_part;
	return tmp;
}
inline std::ostream &operator<<(std::ostream &os, const Complex &s)
{ 
	os<<s._real_part<<"+"<<"("<<s._imag_part<<"i"<<")";
	return os;
}
inline std::istream &operator>>(std::istream &is, Complex &s)
{
	float r,i;
	is>>r;
	is>>i;
	if(is)
	{
		s._real_part=r;
		s._imag_part=i;
	}
	return is;
}


#endif
