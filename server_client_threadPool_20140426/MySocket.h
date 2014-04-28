#ifndef __MYSOCKET_H__
#define __MYSOCKET_H__
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdexcept>
#include <stdlib.h>
class MySocket
{
	private:
		int m_server_fd ;
		socklen_t  m_len;
		struct sockaddr_in m_server_addr, m_client_addr;	
		MySocket(const MySocket& obj);
		MySocket& operator = (const MySocket& obj);
	public:
		MySocket(const std::string ip, const std::string port)
		{
			if( (m_server_fd = socket(AF_INET, SOCK_DGRAM, 0)) == -1 )
			{
				throw std::runtime_error("socket");
			}
			m_server_addr.sin_family = AF_INET ;
			m_server_addr.sin_port = htons(atoi(port.c_str()));
			m_server_addr.sin_addr.s_addr = inet_addr(ip.c_str());
			if(-1 == (bind(m_server_fd, (struct sockaddr*)&m_server_addr, sizeof(m_server_addr)  )))
			{
				throw std::runtime_error("bind");
			}
			m_len = sizeof(m_client_addr);
			std::cout << __LINE__ << " " << ip << " " << port << std::endl ;
		}
		const struct sockaddr_in get_client() const
		{
			return m_client_addr ;
		}
		int send_message(char* buf, int len)
		{
			return sendto(m_server_fd, buf, len, 0, (struct sockaddr*)&m_client_addr, sizeof(m_client_addr) );
		}
		int recv_message(char* buf, int len)
		{
			std::cout << "recv .." << std::endl ;
			int iret =  recvfrom(m_server_fd, buf, len, 0, (struct sockaddr *)&m_client_addr, &m_len);
			return iret ;
		}
		~MySocket()
		{
			close(m_server_fd);
		}
		
};	
#endif
