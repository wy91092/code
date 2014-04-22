/*************************************************************************
	> File Name: main.cpp
	> Author: crooked
	> Mail:812665244@qq.com 
	> Created Time: Tue 22 Apr 2014 11:29:27 AM CST
 ************************************************************************/
#include"address.h"
#include"addressbook.h"
#include<stdlib.h>
using namespace std;

int menu_select()
{//show main menu
  char c;
  cout << "**************************************"<<endl;
  cout<<"* 模拟电话薄 v1.0 *"<<endl;
  cout<<"* *"<<endl;
  cout<<"* 1.添加通信录 *"<<endl;
  cout<<"* 2.删除通信录 *"<<endl;
  cout<<"* 3.显示通信录 *"<<endl;
  cout<<"* 4.电话薄存盘 *"<<endl;
  cout<<"* 5.读出电话薄 *"<<endl;
  cout<<"* 6.退出 *"<<endl;
  cout << "**************************************"<<endl;
  cout<<"please input 1~6: "<<endl;
  do{//键盘输入循环
     cin.get(c);
  }while(c<'1'||c>'6');
  return c-48;
}
int main()
{
    char choice;
	AddressBook maillist;
	for(;;)  //循环，直到键盘输入结束代码
	{
	  choice=menu_select();
	  switch(choice)
	  {
	    case 1: maillist.Enter();break;
	    case 2: maillist.Erase();break;
	    case 3: maillist.List();break;
	    case 4: maillist.Save();break;
	    case 5: maillist.Load();break;
	    case 6: exit(0);
	  }
	}
   return 0;
}
