/*************************************************************************
	> File Name: testjason.cpp
	> Author: Comst
	> Mail:750145240@qq.com 
	> Created Time: Mon 21 Apr 2014 09:46:56 PM CST
 ************************************************************************/

#include<iostream>
#include "json/json.h"
#include <string>
int main(int argc, char* argv[])
{
	std::string test = "{\"name\":\"hello\",\"sex\":\"男\"}";
	Json::Reader reader ;
	Json::Value root ;
	if(!reader.parse(test, root))
	{
		std::cout <<"parse fail ! \n"<< std::endl ;
		return -1 ;
	}
	std::cout << "name: " << root["name"].asString() << std::endl ;
	std::cout << "sex: " <<root["sex"].asString() << std::endl ;
	return 0 ;
	
}
