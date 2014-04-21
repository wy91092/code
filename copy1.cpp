/*************************************************************************
	> File Name: copy1.cpp
	> Author: crooked
	> Mail:812665244@qq.com 
	> Created Time: Fri 18 Apr 2014 10:40:26 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class Student
{
   int _id;
   string _name;
   int _score;
	public:
   Student():_id(0),_name("love"),_score(59){}
   Student(int id,string name,int score):_id(id),_name(name),_score(score){}
   Student(const Student &s):_id(s._id),_name(s._name),_score(s._score){}
   void print()
   {
     cout<<_id<<" "<<_name<<" "<<_score<<endl;
   }
};
int main()
{
    Student s;
	s.print();
    Student s1(501,"heqing",77);
	s1.print();
	Student s2(s1);
	s2.print();
}
