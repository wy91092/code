/*************************************************************************
	> File Name: adddressbook.cpp
	> Author: crooked
	> Mail:812665244@qq.com 
	> Created Time: Tue 22 Apr 2014 10:51:41 AM CST
 ************************************************************************/
#include"address.h"
#include"addressbook.h"
using namespace std;
int AddressBook::FindFree()
{
  int t;
  for(t=0;t<ItemNum;t++)
	  if(Item[t].isEmpty()) return t;
      return -1;
}
void AddressBook::Enter()
{
   string name, phone;
   int pointer;
   pointer=FindFree();
   if(pointer==-1) cout<<"addressbook is full";
   else
   {
     cout<<"addressbook have "<<Num<<" address items"<<endl;
	 cout<<"input name: ";
	 cin>>name;
	 cout<<"input phone number: ";
	 cin>>phone;
	 Item[pointer].Enter(name, phone);
	 Item[pointer].Set();
     Num++;
   }
}
void AddressBook::Erase()
{
   int t;
   string s;
   cout<<"addressbook have "<<Num<<" address items"<<endl;
   if(!Num) cout<<"addressbook is empty!"<<endl;
   else
   {
     cout<<"input name: ";
	 cin>>s;
	 for(t=0;t<ItemNum;t++)
	 {
	   if(!Item[t].isEmpty()&&Item[t].GetName()==s)
	   {
	     Item[t].Clear();
		 Num--;
		 cout<<"already delete "<<s<<" address item"<<endl;
		 break;
	   }
	 }
	 if(t==ItemNum)
	 {
	   cout<<"name not exist"<<endl;
	   cin.get();
	 }
   }
}
void AddressBook::List()
{
   int t,i,j;
   Address list[ItemNum],temp;
   if(!Num) cout<<"addressbook is empty!"<<endl;
   else
   {
     cout<<"addressbook have "<<Num<<" address items"<<endl;
	 for(t=0;t<ItemNum;t++) list[t]=Item[t];
	 for(i=0;i<ItemNum;i++)
	 {//排序
	   for(j=ItemNum-1;j>i;j--)
	   {
	     if(list[j-1].GetName()>list[j].GetName())
		 {
		   temp=list[j-1];
		   list[j-1]=list[j];
		   list[j]=temp;
		 }
	   }
	 }
	 cout<<setiosflags(ios::left)<<setw(31)<<"name: "<<setw(21)<<"phone num: "<<endl;
	 for(t=0; t< ItemNum;t++)
	 {
	    if(!list[t].isEmpty())
			cout<<list[t]<<endl;
	 }
   }
}
void AddressBook::Save()
{
    ofstream file;
	int i;
	char fname[41];
	cout<<"input saved filename: ";
	cin>>fname;
	file.open(fname,ios::out);
	if(!file)
	{
	   cout<<"open file failed!"<<endl;
	   cin.get();
	}
	else
	{
	  for(i=0;i<ItemNum;i++)
	  {
	    if(file&&!file.eof())
			file.write(reinterpret_cast<const char *>(&Item[i]),sizeof(Address));
	  }
	  file.close();
	}
}
void AddressBook::Load()
{
    ifstream file;
	int i;
	char fname[41];
    cout<<"input load filename: ";
	cin>>fname;
    file.open(fname, ios::in);
	if(!file)
	{
	   cout<<"open file failed!"<<endl;
	   cin.get();
	}
	else
	{
	  Num=0;
	  for(i=0;i<ItemNum;i++)
	  {
	    if(file&&!file.eof())
			file.read(reinterpret_cast<char *>(&Item[i]),sizeof(Address));
		    //cout<<Item[i]<<endl;
	    if(!Item[i].isEmpty()) Num++; 
	  }
	  file.close();
	}
}
