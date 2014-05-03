#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_

#include<iostream>
#include<stack>

class Calculator
{ 
private:
   //辅助函数
    static bool Isoperator(char ch);    //判断字符ch是否为操作符   
    static char Precede(char theta1, char theta2);  //判断相继出现的操作符th                                                      eta1和theta2的优先级
    static double Operator(double left, char theta, double right);
                               //执行运算left theta right
    static void Get2Operands(LinkStack<double>&opnd, double &left, double &right);   //从栈opnd中退出两个操作数
public:
   //接口方法声明：
    Calculator(){};         //无参数的构造函数
    ~Calculator(){};        //析构函数
    static void Run();      //执行表达式求值计算
};
#endif
