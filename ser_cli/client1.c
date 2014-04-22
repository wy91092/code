/*************************************************************************
	> File Name: client1.c
	> Author: Comst
	> Mail:750145240@qq.com 
	> Created Time: Thu 03 Apr 2014 03:32:57 PM CST
 ************************************************************************/

#include "ser_cli.h"
//main send
//thread recv
void* thd_handle(void* arg)
{
	struct sockaddr_in server_addr = *(struct sockaddr_in *)arg ;
	char recv_buf[1024] ;
	int fd_recv = socket(AF_INET, SOCK_DGRAM, 0);
	sendto(fd_recv, "on", 2, 0, (struct sockaddr*)&server_addr, sizeof(server_addr));
	fd_set fd_rd, fd_back ;
	FD_ZERO(&fd_rd);
	FD_SET(fd_recv, &fd_rd);
	struct timeval tm ;
	while(1)
	{
		fd_back = fd_rd ;
		tm.tv_sec = 0 ;
		tm.tv_usec= 10 ;
		select(fd_recv + 1, &fd_back, NULL, NULL, &tm );
		if(FD_ISSET(fd_recv, &fd_back))
		{
			memset(recv_buf, 0, 1024);
			int iret = recvfrom(fd_recv, recv_buf, 1024, 0, NULL, NULL);
			recv_buf[iret] = '\0';
			write(1, recv_buf, strlen(recv_buf));
		}
	}
}
int main(int argc, char* argv[])
{
	pthread_t thd ;
	int fd_send ;
	char send_buf[1024];
	struct sockaddr_in server_addr ;
	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET ;
	server_addr.sin_port = htons(atoi(argv[2]));
	server_addr.sin_addr.s_addr = inet_addr(argv[1]);
	pthread_create(&thd, NULL, thd_handle, (void*)&server_addr );
	fd_send = socket(AF_INET, SOCK_DGRAM, 0 );
	if(fd_send == -1)
	{
		perror("socket");
		exit(-1);
	}
	fd_set fd_rd, fd_back ;
	FD_ZERO(&fd_rd);
	FD_SET(0, &fd_rd);
	struct timeval tm ;
	while(1)
	{
		fd_back = fd_rd ;
		tm.tv_sec = 0 ;
		tm.tv_usec= 10 ;
		select( 1, &fd_back, NULL, NULL, &tm );
		if(FD_ISSET(0, &fd_back))
		{
			memset(send_buf, 0, 1024);
			int iret = read(0, send_buf, 1024) ;
			if(iret <= 0)
			{
			sendto(fd_send, "off", 3, 0, (struct sockaddr*)&server_addr, sizeof(server_addr));
			break ;
			}
			send_buf[iret] = '\0';
			sendto(fd_send, send_buf, strlen(send_buf), 0, (struct sockaddr*)&server_addr, sizeof(server_addr));

		}
	}
	pthread_cancel(thd);
	close(fd_send);
	return 0 ;
}
