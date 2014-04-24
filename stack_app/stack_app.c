/*************************************************************************
  > File Name: stack_app.c
  > Author: Comst
  > Mail:750145240@qq.com 
  > Created Time: Fri 21 Mar 2014 07:48:08 PM CST
 ************************************************************************/
#define _DEBUG
#include "stack_app.h"
void print_to_log(FILE* log_fp, char* message)
{
#ifdef  _DEBUG
	{
		printf("%s\n", message);
	}
#endif
		fprintf(log_fp,"%s\n", message);
}
void ispair(char* file_name)
{
	int lsbrace = 0,rsbrace = 0, lmbrace = 0, rmbrace = 0, lbbrace = 0, rbbrace = 0 ;
	int ch ,top = -1, flag = 1;
	int delt_s ,delt_m, delt_b;
	char stack[100], message[128] ;
	FILE* file_in_fp, *file_log_fp;
	memset(stack, 0, 100);
	file_in_fp = fopen(file_name, "r");
	file_log_fp = fopen(LOG_FILE, "a");
	if(!file_in_fp || !file_log_fp)
	{
		printf("fopen \n");
		exit (-1);
	}
	while((ch = fgetc(file_in_fp)) != EOF)
	{
		switch(ch)
		{
			case '(':
				lsbrace ++ ;
				if(flag)
				{
					stack[++top] = ch ;
				}
				break ;
			case ')':
				rsbrace ++ ;
				if(flag)
				{
					if( stack[top] == '(' )
					{
						top -- ;
					}else if(top == -1 || stack[top] != '(') 
					{
						flag = 0 ;
					}
				}
				break ;
			case '[':
				lmbrace ++ ;
				if(flag)
				{
					stack[++top] = ch ;
				}
				break ;
			case ']':
				rmbrace ++ ;
				if(flag)
				{
					if( stack[top] == '[' )
					{
						top -- ;
					}else if(top == -1 || stack[top] != '[')
					{
						flag = 0 ;
					}
				}
				break ;
			case '{':
				lbbrace ++ ;
				if(flag) 
				{
					stack[++top] = ch ;
				}
				break ;
			case '}':
				rbbrace ++ ;
				if(flag)
				{
					if( stack[top] == '{')
					{
						top -- ;
					}else if(top == -1 || stack[top] != '{')
					{
						flag = 0 ;
					}
				}
				break ;
		}
	}
	
	#ifdef  _DEBUG
	{
	printf("%d\t%d\t%d\n",lsbrace, lmbrace, lbbrace);
	printf("%d\t%d\t%d\n",rsbrace, rmbrace, rbbrace);
	printf("top : %d \n", top);
	}
	#endif
	memset(message, 0, 128);
	if(flag == 1 && top == -1)
	{
		sprintf(message,"file-> %s : pair", file_name);
		print_to_log(file_log_fp, message);
	}else
	{
		delt_s = lsbrace - rsbrace ;
		delt_m = lmbrace - rmbrace ;
		delt_b = lbbrace - rbbrace ;
		sprintf(message, "file-> %s : small_brace:%d, middle_brace:%d, big_brace:%d", file_name, delt_s, delt_m, delt_b);
		print_to_log(file_log_fp, message);
	}

	fclose(file_in_fp);
	fclose(file_log_fp);
}

