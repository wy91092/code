/*************************************************************************
	> File Name: server_json.cpp
	> Author: Comst
	> Mail:750145240@qq.com 
	> Created Time: Mon 21 Apr 2014 10:01:07 PM CST
 ************************************************************************/

#include<iostream>
#include <fstream>
#include <sys/socket.h>
#include <sys/time.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include "json/json.h"
#include <arpa/inet.h>
#include <netinet/in.h>
using namespace std ;
string json_string();
int main(int argc, char* argv[])
{
	int fd_server;
	ifstream fin(argv[1]);
	string ip , port ;
	fin >> ip >> port ;

	fin.close();
	fd_server = socket(AF_INET, SOCK_DGRAM, 0);
	struct sockaddr_in server_addr ;
	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET ;
	server_addr.sin_port = htons(atoi(port.c_str()));
	server_addr.sin_addr.s_addr = inet_addr(ip.c_str());
	int flag = bind(fd_server, (struct sockaddr *)&server_addr, sizeof(server_addr));
	if(flag == -1)
	{
		perror("bind");
		exit(-1);
	}
	char buf[128]="";
	struct sockaddr_in client_addr ;
	socklen_t len = sizeof(client_addr);
	recvfrom(fd_server, buf, 128, 0, (struct sockaddr*)&client_addr, &len);
	cout <<buf << endl ;
	string jsonstr = json_string();
	sendto(fd_server, jsonstr.c_str(), jsonstr.size(), 0, (struct sockaddr*)&client_addr, sizeof(client_addr));
	close(fd_server);
	return 0 ;
} 
string json_string( )
{
	srand(time(NULL));
	int size ;
	while(1)
	{
		size = rand() % 100 ;
		if(size > 0)
		{
			break ;
		}
	}
	Json::Value root ;
	Json::Value arr ;
	while(size)
	{
		Json::Value elem ;
		char title[128] = "";
		char summary[128]="";
		sprintf(title , "tile_%d", size);
		sprintf(summary, "summary_%d", size);
		elem["title"] = title ;
		elem["summary"] = summary ;
		arr.append(elem);
		size -- ;
	}
	root["files"]=arr ;
	Json::FastWriter writer ;
	Json::StyledWriter stlwriter ;
	return stlwriter.write(root);

}
