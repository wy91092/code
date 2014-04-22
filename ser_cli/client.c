/*************************************************************************
	> File Name: client.c
	> Author: Comst
	> Mail:750145240@qq.com 
	> Created Time: Thu 03 Apr 2014 08:48:12 AM CST
 ************************************************************************/

#include "ser_cli.h"
int main(int argc, char* argv[])
{
	struct sockaddr_in server_addr, client_addr ;
	char send_buf[1024] , recv_buf[1024] ;
	memset(&server_addr, 0, sizeof(server_addr));
	memset(&client_addr, 0, sizeof(client_addr));
	int client_fd = socket(AF_INET, SOCK_DGRAM, 0);
	if(client_fd == -1)
	{
		perror("socket");
		exit(-1);
	}
	server_addr.sin_family = AF_INET ;
	server_addr.sin_port = htons(atoi(argv[2]));
	server_addr.sin_addr.s_addr = inet_addr(argv[1]);
	sendto(client_fd, "on", 2, 0, (struct sockaddr*)&server_addr, sizeof(server_addr));
	fd_set fd_rd, fd_back ;
	struct timeval tm ;
	FD_ZERO(&fd_rd);
	FD_SET(0, &fd_rd);
	FD_SET(client_fd, &fd_rd);
	while(1)
	{
		fd_back = fd_rd ;
		tm.tv_sec = 1 ;
		tm.tv_usec = 0 ;
		select(1024, &fd_back, NULL, NULL, &tm);
		if(FD_ISSET(0, &fd_back))
		{
			memset(send_buf, 0, 1024);
			int iret = read(0, send_buf, 1024 );
			if(iret <= 0)
			{
				sendto(client_fd, "off", 3, 0, (struct sockaddr*)&server_addr, sizeof(server_addr));
				break ;
			}
			send_buf[iret] = '\0';
			sendto(client_fd, send_buf, strlen(send_buf), 0, (struct sockaddr *)&server_addr, sizeof(server_addr));
			
		}else if(FD_ISSET(client_fd, &fd_back))
		{
			memset(recv_buf, 0, 1024);
			int iret = recvfrom(client_fd, recv_buf, 1024, 0, NULL, NULL);
			recv_buf[iret] = '\0';
			write(1, recv_buf, strlen(recv_buf));
			
		}

	}
	close(client_fd);

	return 0 ;
}
