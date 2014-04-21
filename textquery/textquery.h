/*************************************************************************
	> File Name: textquery.h
	> Author: crooked
	> Mail:812665244@qq.com 
	> Created Time: Fri 18 Apr 2014 09:09:50 AM CST
 ************************************************************************/

#ifndef _TEXTQUERY_
#define _TEXTQUERY
#include<vector>
#include<string>
#include<set>
#include<map>
#include<iostream>
#include<fstream>
#include<sstream>
#include<stdexcept>
class TextQuery
{
   public:
	   typedef std::vector<std::string>::size_type line_no;
	   void read_file(const std::string &filename);
	   std::set<line_no> run_query(const std::string &) const;
	   std::string text_line(line_no) const;
       void query_word(const std::string &word); 
	   void build_map();   //associated each word with a set of line
   private:
	  // void store_file(std::ifstream &);  //store input file
	   std::vector<std::string> lines_of_text;
	   std::map<std::string, std::set<line_no> > word_map;
};

#endif
