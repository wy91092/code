/*************************************************************************
	> File Name: testmain.c
	> Author: Comst
	> Mail:750145240@qq.com 
	> Created Time: Sun 23 Mar 2014 02:56:42 PM CST
 ************************************************************************/

#include "stack_app.h"
int main(int argc, char* argv[])
{
	int index ;
	for(index = 1; index < argc; index ++)
	{
		ispair(argv[index]);
	}
	return 0 ;
}
