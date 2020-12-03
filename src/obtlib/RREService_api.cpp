#include "RREService_api.h"
#define SERV_PORT 8888
#define SERV_IP "192.168.43.142"
#define MAXLINE 2056 
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
	TS msg;
	memcpy(&msg, recvmsg, MAXLINE);
	cout << "msg type: " << msg.type << endl;
	cout << "msg length: " << msg.len << endl;
	cout << "msg error code: " << *((unsigned int*)&(msg.pDataBuf[0])) << endl;
	return true;
}
BOOL SendMsgToRREService(TS *msgdat, unsigned int len)
{
	char strmsg[MAXLINE];
	memcpy(strmsg, &msgdat->type, sizeof(int));
	memcpy(&strmsg[4], &msgdat->len, sizeof(int));
	memcpy(&strmsg[8], &msgdat->pDataBuf, 2048);
	bool br = udpclient::getInstance()->send(strmsg, sizeof(TS));
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
bool udpclient::send(const char* msg, int ilen)
{
	cout << "send len: " << ilen << endl;
	return (write(m_isockfd, msg, ilen) > 0);		
}
bool udpclient::recv(char* msg, int& ilen)
{
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
