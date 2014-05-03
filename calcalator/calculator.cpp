#include"calculator.h"
using namespace std;
//类中的辅助函数都比较简单，在这里就不写具体的实现了。
void Calculator::Run()
//操作结果：按算法优先发进行表达式求值计算
{
  LinkStack<double> opnd;      //操作数栈
  LinkStack<char>  optr;       //操作符栈
  optr.push('=');              //在optr栈中加入一个'='
  char ch;                     //临时字符 
  char optrTop;                //optr栈的栈顶字符
  double operand;              //操作数
  char theta;                  //操作符

  cin>>ch;                     //从输入流中获取一字符ch    
  while((optr.Top(optrTop), optrTop!='=')||ch!='=')
  {
    if(!IsOperator(ch))
   {
      cin.putback(ch);          //将字符ch放回输入流     
      cin>>operand;             //读操作数operand
      opnd.Push(operand);       //进入opnd栈
      cin>>ch;                  //读入下一字符ch
   }  
    else
   {
     switch(Precede(optrTop, ch))
     {
       case '<':                 //栈顶操作符优先级低
            optr.Push(ch);       //ch如optr栈
            cin>>ch;             //从输入流中取下一字符ch
            break;
       case '=':                 //栈顶操作符与ch优先级相等
            optr.Pop(operTop);   //脱括号
            cin>>ch;             //从输入流中读取下一字符ch
            break;
       case '>':                 //栈顶操作符优先级高 
            double left,right;   //操作数
            Get2Operands(opnd, left, right);  //取出2个操作数
            oper.Pop(theta);                 //从optr栈退出theta
            opnd.Push(Operate(left, theta, right)); //运算结果进入opnd栈
            break;
       case 'e':                 //操作符匹配错  
            cout<<"操作符匹配错"<<endl;
            exit(2);
      } 

   }
  }
   opnd.Top(operand);         //opnd栈的栈顶元素为表达式的值    
   cout<<"表达式值为："<<operand<<endl;

}
