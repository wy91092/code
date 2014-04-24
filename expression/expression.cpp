/*************************************************************************
	> File Name: expression.cpp
	> Author: crooked
	> Mail:812665244@qq.com 
	> Created Time: Thu 24 Apr 2014 08:37:31 PM CST
 ************************************************************************/
#include"expression.h"
using namespace std;

string getPostfixExp(string &infix)  //获取后缀表达式
{
  stack<char> operator_stack;
  string postfix;
  for(int i=0;i<infix.size();i++)
  {
	char p=infix[i];
    if(isOperator(p))
	{
	  while(!operator_stack.empty()&&isOperator(operator_stack.top())&&priority(operator_stack.top())>=priority(p))
	  {
	    postfix.push_back(operator_stack.top());
		postfix.push_back(' ');
		operator_stack.pop();
	  }
	  operator_stack.push(p);
	}
	else if(p=='(')
	{
	  operator_stack.push(p);
	}
	else if(p==')')
	{
	  while(operator_stack.top()!='(')
	  {
	    postfix.push_back(operator_stack.top());
	    postfix.push_back(' ');
		operator_stack.pop();
	  }
	}
	else 
	{
	  postfix.push_back(p);
	  postfix.push_back(' ');
	}
  }
  while(!operator_stack.empty())
  {
     postfix.push_back(operator_stack.top());
     postfix.push_back(' ');
	 operator_stack.pop();
  }
  postfix[postfix.size()-1]=' '; //将最后一位置为空格
  return postfix;
}

bool isOperator(char ch)
{
  switch(ch)
  {
	  case '+':
	  case '-':
	  case '*':
	  case '/':
		  return true;
	  default:
		  return false;
  }
}

int priority(char a)   //运算符优先级
{
   int temp;
   if(a=='*'||a=='/')
	   temp=2;
   else if(a=='+'||a=='-')
	   temp=1;
   return temp;
}

int postfixCalculate(string &postfix)   //后缀表达所求值
{
   int first, second;
   stack<int> num_stack;
   for(int i=0;i<postfix.size();i++)
   {
     switch(postfix[i])
	 {
		 case '*':
			 getTwoNums(num_stack,first,second);
	         num_stack.push(first*second);
			 break;
		 case '/':
			 getTwoNums(num_stack,first,second);
	         num_stack.push(first/second);
			 break;
		 case '+':
			 getTwoNums(num_stack,first,second);
	         num_stack.push(first+second);
			 break;
		 case '-':
			 getTwoNums(num_stack,first,second);
	         num_stack.push(first-second);
			 break;
		 case ' ':
			 break;
		 default:
			 num_stack.push(postfix[i]-'0');
             break;
	 }
   }
   int result=num_stack.top();
   num_stack.pop();
   return result;
}

void getTwoNums(stack<int> &num_stack, int &first, int &second) //获取需要计算的2个数
{
   second=num_stack.top();
   num_stack.pop();

   first=num_stack.top();
   num_stack.pop();
}
