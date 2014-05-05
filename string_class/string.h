#ifndef STRING_H_
#define STRING_H_

#include<string.h>
#include<cstddef>

class String
{
public:
   String();
   String(const char *);
   String(const String &);
   ~String();
   String &operator=(const String &);
   String &operator=(const char *);
   String &operator+=(const String &);
   String &operator+=(const char *);
   std::size_t size() const;
   const char * c_str() const;
   void debug();

   friend String operator+(const String&, const String &);
   friend String operator+(const String&, const char *);
   friend String operator+(const char *, const String &);

   friend bool operator==(const String &, const String &);
   friend bool operator!=(const String &, const String &);

   friend bool operator<(const String &, const String &);
   friend bool operator>(const String &, const String &);
   friend bool operator<=(const String &, const String &);
   friend bool operator>=(const String &, const String &);
 
   friend std::ostream &operator<<(std::ostream &os, const String &s);
   friend std::istream &operator>>(std::istream &is, String &s);
   
private:
   char *_str;
};

inline String operator+(const String &lhs, const String &rhs)
{
  String tmp;
  tmp._str=new char[lhs.size() +rhs.size()+1];
  strcpy(tmp._str, lhs._str);
  strcat(tmp._str, rhs._str);
  return tmp;
}

inline String operator+(const String &lhs, const char *s){
   return lhs+String(s);
}

inline String operator+(const char *s, const String &rhs){
   return String(s)+rhs;
}

inline bool operator==(const String &lhs, const String &rhs){
   return strcmp(lhs._str, rhs._str)==0;
}

inline bool operator!=(const String &lhs, const String &rhs){
   return !(lhs==rhs);
}

inline bool operator<(const String &lhs, const String &rhs){
  return strcmp(lhs._str, rhs._str)<0;
}

inline bool operator>(const String &lhs, const String &rhs){
  return strcmp(lhs._str, rhs._str)>0;
}

inline bool operator<=(const String &lhs, const String &rhs){
  return !(lhs>rhs);
}

inline bool operator>=(const String &lhs, const String &rhs){
  return !(lhs<rhs);
}

inline std::ostream &operator<<(std::ostream &os,const String &s){
   os<< s._str;
   return os;
}

inline std::istream &operator>>(std::istream &is, String &s){
    char buf[1024];
    is>>buf;
    if(is){
      s=buf;
    }
    return is;
}
#endif
