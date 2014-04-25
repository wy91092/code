#ifndef __MYCOMPLEX_H__
#define __MYCOMPLEX_H__
#include <iostream>
using namespace std;
class MyComplex
{
	public:
		friend istream& operator >>(istream& in, MyComplex& obj);
		friend ostream& operator <<(ostream& out, const MyComplex& obj);
		friend bool operator == (const MyComplex& lobj, const MyComplex& robj);
		
	explicit	MyComplex(double real = 0 , double imag = 0):m_dreal(real), m_dimag(imag)
		{
		
		}
		MyComplex(const MyComplex& obj):m_dreal(obj.m_dreal), m_dimag(obj.m_dimag)
		{
	
		}
		MyComplex&  operator = (const MyComplex &obj)
		{
			m_dreal = obj.m_dreal ;
			m_dimag = obj.m_dimag ;
			return *this ;
		}
		MyComplex operator + (const MyComplex& robj) ;
		MyComplex operator - (const MyComplex& robj) ;
		MyComplex operator * (const MyComplex& robj) ;
	private:
		double m_dreal ;
		double m_dimag ;
};
#endif
