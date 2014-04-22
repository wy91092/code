/*************************************************************************
  > File Name: server.c
  > Author: Comst
  > Mail:750145240@qq.com 
  > Created Time: Thu 03 Apr 2014 08:49:07 AM CST
 ************************************************************************/
#include "ser_cli.h"
typedef struct tag
{
	struct sockaddr_in client_addr ;
	struct tag* pNext ;
}CLIENT, *pCLIENT ;
int main(int argc, char* argv[])
{
	int server_fd ;
	struct sockaddr_in server_addr ;
	pCLIENT pClient_List = (pCLIENT)malloc(sizeof(CLIENT));
	pCLIENT pTail = pClient_List ;
	memset(pClient_List, 0, sizeof(CLIENT));
	memset(&server_addr, 0 , sizeof(struct sockaddr_in));
	server_fd = socket(AF_INET, SOCK_DGRAM, 0);
	if(server_fd == -1)
	{
		perror("socket");
		exit(-1);
	}
	server_addr.sin_family = AF_INET ;
	server_addr.sin_port = htons(atoi(argv[2]));
	server_addr.sin_addr.s_addr = inet_addr(argv[1]);
	if(-1 == bind(server_fd, (struct sockaddr* )&server_addr, sizeof(server_addr)))
	{
		perror("bind");
		close(server_fd);
		exit(-1);
	}
	fd_set fd_rd, fd_back ;
	FD_ZERO(&fd_rd);
	FD_SET(server_fd, &fd_rd);
	struct timeval tm ;
	while(1)
	{
		fd_back = fd_rd;
		tm.tv_sec = 1 ;
		tm.tv_usec = 0 ;

		select(1024, &fd_back, NULL, NULL, &tm);

		if(FD_ISSET(server_fd, &fd_back))
		{
			pCLIENT pCur= (pCLIENT)malloc(sizeof(CLIENT));
			memset(pCur, 0, sizeof(CLIENT));
			int len = sizeof(pCur ->client_addr);
			char recv_buf[1024]="";
			recvfrom(server_fd, recv_buf, sizeof(recv_buf), 0, (struct sockaddr*)&pCur->client_addr, &len );
			if(strncmp(recv_buf, "on", 2) == 0)
			{
				printf("ip: %s is online! \n", inet_ntoa(pCur -> client_addr.sin_addr));
				pTail -> pNext = pCur ;
				pTail = pCur ;
			}else if(strncmp(recv_buf, "off", 3) == 0)
			{
				pCLIENT pPre = pClient_List ;
				pCLIENT pWork = pClient_List -> pNext ;
				while(pWork)
				{
					if(pWork ->client_addr.sin_addr.s_addr == pCur ->client_addr.sin_addr.s_addr)
					{
						free(pCur);
						pCur = pWork ;	
						printf("ip: %s is offline! \n", inet_ntoa(pCur -> client_addr.sin_addr));
						pPre -> pNext = pWork -> pNext ;
						free(pCur);
						break ;
					}
					pPre = pWork ;
					pWork = pWork -> pNext ;
				}
			}else 
			{
				pCLIENT pSend = pClient_List -> pNext ;
				while(pSend)
				{
					char send_buf[1024]="";
					sprintf(send_buf, "from %s \n	%s\n",inet_ntoa(pCur -> client_addr.sin_addr), recv_buf);
					sendto(server_fd, send_buf, strlen(send_buf), 0, (struct sockaddr*)&pSend->client_addr, sizeof(pSend->client_addr));
				 	pSend = pSend -> pNext ;
				} 
			}
		}
	}

}

