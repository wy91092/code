/*************************************************************************
  > File Name: expression.cpp
  > Author: crooked
  > Mail:812665244@qq.com 
  > Created Time: Thu 24 Apr 2014 08:37:31 PM CST
 ************************************************************************/
#ifndef _EXPRESSION_H_
#define _EXPRESSION_H_
#include<iostream>
#include<stack>
#include<string>

std::string getPostfixExp(std::string &infix);
bool isOperator(char ch);
int priority(char a);
int postfixCalculate(std::string &postfix);
void getTwoNums(std::stack<int> &num_stack, int &first, int &second);
#endif
