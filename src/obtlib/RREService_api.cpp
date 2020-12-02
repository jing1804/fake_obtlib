#include "RREService_api.h"
#define SERV_PORT 8888
#define SERV_IP "192.168.43.130"
#define MAXLINE 80
#include <iostream>
using namespace std;
BOOL RREServiceInit(ECUINFOSTR info, obt_log_callback_b cb)
{
	udpclient::getInstance();
	return true;
}
void RREServiceDeinit(void)
{

}
BOOL RecvMsgFromRREService(TS *msgdat, unsigned int* len)
{
	char recvmsg[MAXLINE];
	int ilen = 0;
	cout << "begin recv" << endl;
	udpclient::getInstance()->recv(recvmsg, ilen);
	cout << "recv " << ilen << " :" << recvmsg << endl;
	return true;
}
BOOL SendMsgToRREService(TS *msgdat, unsigned int len)
{
	bool br = udpclient::getInstance()->send("abc", 4);
	cout << "send result: " << br << endl;
	return true;
}
udpclient* udpclient::getInstance()
{
	static udpclient* udpclie = nullptr;
	if(udpclie == nullptr)
	{
		udpclie = new udpclient;
	}
	return udpclie;
}
bool udpclient::send(char* msg, int ilen)
{
	return (write(m_isockfd, msg, ilen) > 0);		
}
bool udpclient::recv(char* msg, int& ilen)
{
	int n;
	ilen = read(m_isockfd, msg, MAXLINE);
	return (ilen != -1);
}
udpclient::udpclient()
{
	bzero(&m_servaddr, sizeof(m_servaddr));
	m_servaddr.sin_family = AF_INET;
	m_servaddr.sin_port = htons(SERV_PORT);
	inet_pton(AF_INET, SERV_IP, &m_servaddr.sin_addr);
	m_isockfd = socket(AF_INET, SOCK_DGRAM, 0); 
	int iresult = connect(m_isockfd, (struct sockaddr*)&m_servaddr, sizeof(m_servaddr));
	cout << "connect result: " << iresult << endl;
}
udpclient::~udpclient()
{

}
