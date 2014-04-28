/*************************************************************************
	> File Name: client_json.cpp
	> Author: Comst
	> Mail:750145240@qq.com 
	> Created Time: Mon 21 Apr 2014 11:27:29 PM CST
 ************************************************************************/

#include<iostream>
#include <fstream>
#include <sys/socket.h>
#include <sys/time.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
using namespace std;
int main(int argc, char* argv[])
{
	int fd_client ;
	ifstream fin(argv[1]);
	string ip, port ;
	fin >> ip >> port ;
	fin.close();
	cout << ip <<" " << port << endl ;
	fd_client = socket(AF_INET, SOCK_DGRAM, 0);
	struct sockaddr_in server_addr ;
	server_addr.sin_family = AF_INET ;
	server_addr.sin_port = htons(atoi(port.c_str()));
	server_addr.sin_addr.s_addr = inet_addr(ip.c_str());
   int iret =	sendto(fd_client, "hello", 5, 0, (struct sockaddr*)&server_addr, sizeof(server_addr));
	cout << iret << endl ;
	char *buf = new char[1024*1024] ;
	memset(buf, 0, 1024*1024);
	 iret = recvfrom(fd_client, buf, 1024*1024, 0, NULL, NULL);
	cout << iret << endl ;
	cout << buf << endl ;
	return 0 ;
}

