/*************************************************************************
  > File Name: testMyComplex.cpp
  > Author: Comst
  > Mail:750145240@qq.com 
  > Created Time: Thu 24 Apr 2014 09:52:20 AM CST
 ************************************************************************/

#include "MyComplex.h"
int main(int argc, char* argv[])
{
	MyComplex complex_obj1 ;
	std::cout << complex_obj1 << std::endl ;
	MyComplex complex_obj2(3,4);
	std::cout << complex_obj2 << std::endl ;
	MyComplex complex_obj3 , complex_obj4 ;
	std::cin >> complex_obj3 >> complex_obj4 ;
	std::cout << complex_obj2 + complex_obj3 << std::endl ;
	std::cout << complex_obj2 - complex_obj3 << std::endl ;
	std::cout << complex_obj2 * complex_obj4 << std::endl ;
	std::cout << (complex_obj2 == complex_obj3) << std::endl ;
	MyComplex  complex_obj5(complex_obj2) ;
	std::cout << complex_obj5 << std::endl ;
	MyComplex  complex_obj6 ;
	complex_obj6 = complex_obj2 ;
	std::cout << complex_obj6 << std::endl ;

	return 0 ;
}
