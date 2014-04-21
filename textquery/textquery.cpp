/*************************************************************************
	> File Name: textquery.cpp
	> Author: crooked
	> Mail:812665244@qq.com 
	> Created Time: Fri 18 Apr 2014 09:27:56 AM CST
 ************************************************************************/

#include"textquery.h"
using namespace std;
static std::ifstream &open_file(std::ifstream &is,const std::string &filename)
{
  is.close();
  is.clear();
  is.open(filename.c_str());
  return is;
}
void TextQuery::read_file(const std::string &filename)
{
   std::ifstream infile;
   if(!open_file(infile,filename))
   {
    throw std::runtime_error("open file failed!");
   }
   std::string line;
   while(std::getline(infile, line))
   {
     lines_of_text.push_back(line);
   }
   infile.close();
   infile.clear();
}
/*void TextQuery::store_file(ifstream &is)
{
    string line;
	while(getline(is, line))
           lines_of_text.push_back(line);
}*/
void TextQuery::build_map()
{
  std::istringstream sstream;
  string word;
  for(line_no ix=0;ix!=lines_of_text.size();++ix)
  {
	  sstream.str(lines_of_text[ix]);
    while(sstream >> word)
	{
	   word_map[word].insert(ix);
	}
	sstream.clear();
  }
}
set<TextQuery::line_no> TextQuery::run_query(const std::string &word) const
{ 
	std::map<std::string,std::set<TextQuery::line_no> >::const_iterator iter=word_map.find(word);
  if(iter!=word_map.end())
  {
   return iter->second;
  }
  else   return set<TextQuery::line_no>();
}
string TextQuery::text_line(TextQuery::line_no pos) const
{
   if(pos<0||pos>lines_of_text.size())
	    throw out_of_range("range eror");
   return lines_of_text[pos];
}
void TextQuery::query_word(const std::string &word)
{
   std::set<TextQuery::line_no> line_set=run_query(word);
   std::cout<<word<<" occurs "<<line_set.size()<<" times"<<std::endl;
   std::set<TextQuery::line_no>::iterator iter=line_set.begin();
   for(;iter!=line_set.end();++iter)
   {
	   std::cout<<"line: "<<*iter<<" "<<text_line(*iter)<<std::endl;
   }


}
