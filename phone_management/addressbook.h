/*************************************************************************
	> File Name: adddressbook.h
	> Author: crooked
	> Mail:812665244@qq.com 
	> Created Time: Tue 22 Apr 2014 10:47:05 AM CST
 ************************************************************************/
#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H
#include"address.h"
const int ItemNum=100;
class AddressBook
{
   Address Item[ItemNum];
   int Num;
   int FindFree();
	public:
   AddressBook(){Num=0;}
   void Enter();
   void Erase();
   void Load();
   void Save();
   void List();
   friend std::ostream &operator<<(std::ostream &output, const Address &addr);
};

inline std::ostream &operator<<(std::ostream &output, const Address &addr)
{
  output<< setiosflags(std::ios::left)<<std::setw(31)<<addr.GetName()<<std::setw(21)<<addr.GetPhone();
  return output;
}
#endif
