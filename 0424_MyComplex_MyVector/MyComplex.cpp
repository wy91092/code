/*************************************************************************
	> File Name: MyComplex.cpp
	> Author: Comst
	> Mail:750145240@qq.com 
	> Created Time: Thu 24 Apr 2014 09:38:51 AM CST
 ************************************************************************/
#include "MyComplex.h"
using namespace std ;
istream& operator >>(istream& in, MyComplex& obj)
{
	double dreal, dimag ;
	in >> dreal >> dimag ;
	if(in)
	{
		obj.m_dreal = dreal ;
		obj.m_dimag = dimag ;
	}
	else 
	{
		obj = MyComplex() ;
	}
	return in ;
}
ostream& operator << (ostream& out, const MyComplex& obj)
{
	out << obj.m_dreal << "+" <<obj.m_dimag <<"i" ;
	return out ;
}
MyComplex MyComplex::operator +(const MyComplex& obj)
{
	double dreal, dimag ;
	dreal = m_dreal + obj.m_dreal ;
	dimag = m_dimag + obj.m_dimag ;
	return MyComplex(dreal, dimag);
}
MyComplex MyComplex::operator -(const MyComplex& obj)
{
	double dreal, dimag ;
	dreal = m_dreal - obj.m_dreal ;
	dimag = m_dimag - obj.m_dimag ;
	return MyComplex(dreal, dimag);

}
MyComplex MyComplex::operator *(const MyComplex& obj)
{
	double dreal, dimag ;
	dreal = m_dreal * obj.m_dreal - m_dimag * obj.m_dimag ;
	dimag = m_dreal * m_dimag + m_dimag * obj.m_dreal ;
	return MyComplex(dreal, dimag);

}
bool operator == (const MyComplex& lobj, const MyComplex& robj)
{
	return (lobj.m_dreal == robj.m_dreal && lobj.m_dimag == robj.m_dimag);
}








