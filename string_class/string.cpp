#include<iostream>
#include"string.h"

String::String():_str(new char[1]){
  *_str='\0';
}

String::String(const char *s){
  _str=new char[strlen(s)+1];
  strcpy(_str, s);
}

String::String(const String &s){
  _str=new char[s.size()+1];
  strcpy(_str, s.c_str());
}

String::~String(){
  delete[] _str;
  _str=NULL;
}

String &String::operator+=(const String &s){
   char *tmp=new char[size()+s.size()+1];
   strcpy(tmp,_str);
   strcat(tmp,s._str);
   delete[] _str;
   _str=NULL;

   _str=tmp;
   return *this;
}

String &String::operator+=(const char *s){
   *this+=String(s);
   return *this;
}

String &String::operator=(const String &s){
  if(s!=*this){
    delete[] _str;
    _str=NULL;
    _str=new char[s.size()+1];
    strcpy(_str, s.c_str());
  }
  return *this;
}

String &String::operator=(const char *str){
 
    delete[] _str;
    _str=NULL;
    _str=new char[strlen(str)+1];
    strcpy(_str, str);
    return *this;
}

std::size_t String::size() const{
   return strlen(_str);
}

const char* String::c_str() const{
     return _str;
}

void String::debug(){
   std::cout<<_str<<std::endl;
}
