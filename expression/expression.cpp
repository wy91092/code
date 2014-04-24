/*************************************************************************
	> File Name: expression.cpp
	> Author: crooked
	> Mail:812665244@qq.com 
	> Created Time: Thu 24 Apr 2014 08:37:31 PM CST
 ************************************************************************/
#include"expression.h"
using namespace std;

string getPostfixExp(string &infix)  //获取后缀表达式
{/*
  转换原则：
  1.当读到一个操作数时，立即将它放到输出中。操作符则不立即输出，放入栈中，遇到左圆括号也推入栈中。
  2.如果遇到一个右括号，那么就将栈顶元素弹出，将符号写出直到遇到一个对应的左括号，但是这个左括号只被弹出，并不输出。
  3.在读到操作符时，如果此时栈顶操作符优先级大于或等于此操作符，弹出栈顶操作符直到发现优先级更低的元素位置，除了处理“）”的时候，否则绝不从栈中移走“（”。操作符中，+-优先级最低，（）优先级最高。
  4.如果读到输入的末尾，将栈元素弹出直到该栈变成空栈，将符号写到输出中。
	*/
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
			 num_stack.push(postfix[i]-'0');   //读入操作数
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
