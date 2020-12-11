#include "RREService_api.h"
#define SERV_PORT 8888
#define SERV_IP "127.0.0.1"
#define MAXLINE 2058
#include <iostream>
using namespace std;
enum ObtLibTcpStatus
{
	OBT_LIB_TCP_INIT = 0, 
	OBT_LIB_TCP_IDLE = 1,
	OBT_LIB_TCP_RECONNECTING = 2,
	OBT_LIB_TCP_CONNECTED = 3,
	OBT_LIB_TCP_CLOSE = 4,
};

enum obtLibRouteStatus
{
	OBT_LIB_ROUTE_INACTIVE = 0,
	OBT_LIB_ROUTE_ACTIVE = 1,
};
uint8_t tcpStatus = OBT_LIB_TCP_IDLE;
BOOL RREServiceInit(ECUINFOSTR info, obt_log_callback_b cb)
{
	udpclient::getInstance();
	return true;
}
void RREServiceDeinit(void)
{

}
void RREServiceTcpConnect(void)
{
	tcpStatus = OBT_LIB_TCP_CONNECTED;
}
void RREServiceTcpClose(void)
{
	tcpStatus = OBT_LIB_TCP_IDLE;
}
uint8_t RREServiceTcpGetTcpStatus(void)
{
	return tcpStatus;
}
uint8_t RREServiceTcpGetDoipRaStatus(void)
{
	return OBT_LIB_ROUTE_ACTIVE;
}
BOOL SendMsgToRREService(TS *msgdat, unsigned int len)
{
	short msgT = CLI_SEND_MSG;
	char strmsg[MAXLINE];
	memcpy(&(strmsg[0]), &msgT, sizeof(short));
	memcpy(&(strmsg[2]), &msgdat->type, sizeof(int));
	memcpy(&(strmsg[6]), &msgdat->len, sizeof(int));
	memcpy(&(strmsg[10]), &msgdat->pDataBuf, 2048);
	cout << "=========send msg==========" << endl;
	print_ts(msgdat);
	bool br = udpclient::getInstance()->send(strmsg, MAXLINE);
	if(br)
	{
		int ilen = 0;
		udpclient::getInstance()->recv(strmsg, ilen); 
		msgT = *((short*)&(strmsg[0]));
		if(msgT == SER_BLOCK_MSG)
		{
			sleep(10);
			return true;	
		}
		else if(msgT == SER_NODATA_MSG)
		{
			return false;
		}
	}
	return true;
}
BOOL RecvMsgFromRREService(TS *msgdat, unsigned int* len)
{
	//short msgT = CLI_RECV_MSG;
	short msgT = CLI_RECV_MSG;
	char recvmsg[MAXLINE];
	memcpy(&(recvmsg[0]), &msgT, sizeof(short));
	udpclient::getInstance()->send(recvmsg, MAXLINE);
	int ilen = 0;
	cout << "========begin recv=========" << endl;
	udpclient::getInstance()->recv(recvmsg, ilen);
	memcpy(&msgT, &(recvmsg[0]), sizeof(short));
	if(msgT == SER_BLOCK_MSG)
	{
		sleep(10);
	}
	else if(msgT == SER_NODATA_MSG)
	{
		return false;
	}
	else if(msgT == SER_NORMAL_MSG)
	{
		memcpy(&msgdat->type, &(recvmsg[2]), sizeof(int));
		memcpy(&msgdat->len, &(recvmsg[6]), sizeof(int));
		memcpy(msgdat->pDataBuf, &(recvmsg[10]), 2048);
		print_ts(msgdat);
	}
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
	return (write(m_isockfd, msg, ilen) > 0);		
}
bool udpclient::recv(char* msg, int& ilen)
{
	ilen = read(m_isockfd, msg, MAXLINE);
	cout << "udp read ilen: " << ilen << endl;
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

void print_ts(TS* msg)
{
	cout.unsetf(ios::hex);
	cout << "msg type: " << msg->type << endl;
	cout << "msg len: " << msg->len << endl;
	cout << hex << "msg error code: 0x" <<*((int*)&msg->pDataBuf[0]) << endl;
	cout << dec << "msg end flag: " << *((int*)&msg->pDataBuf[4]) << endl;
	if(*((int*)&msg->pDataBuf[0]) != 0)
	{
		cout << "error code != 0, stop print" << endl;
		return;
	}
	PARAMS_UNION* punion = (PARAMS_UNION*)&msg->pDataBuf[8];
	
	switch(msg->type)
	{
		case 15:
			cout << hex << "diagnose type: 0x" << (unsigned int)(msg->pDataBuf[8]) << endl;
			if(msg->pDataBuf[8] == 0x10)
			{
				cout << dec << "session: " << (unsigned int)(msg->pDataBuf[9]) << endl;
			}
			else if(msg->pDataBuf[8] == 0x22)
			{
				cout << hex << "did address: 0x" << (unsigned int)(msg->pDataBuf[9]) << (unsigned int)(msg->pDataBuf[10]) << endl;
			}
			break;
		case 16:
			cout << hex << "diagnose result: 0x" << (unsigned int)(msg->pDataBuf[8]) << endl;
			if(msg->pDataBuf[8] == 0x50)
			{
				cout << dec << "session: " << (unsigned int)(msg->pDataBuf[9]) << endl;
			}
			else if(msg->pDataBuf[8] == 0x62)
			{
				cout << hex << "did address: 0x" << (unsigned int)(msg->pDataBuf[9]) << (unsigned int)(msg->pDataBuf[10]) << (unsigned int)(msg->pDataBuf[11]) << (unsigned int)(msg->pDataBuf[12]) << (unsigned int)(msg->pDataBuf[13])  << endl;
			}
			else if(msg->pDataBuf[8] == 0x7f && msg->pDataBuf[9] == 0x10)
			{
				cout << hex << "diagnose 0x10 error, tag: 0x" << (unsigned int)(msg->pDataBuf[10]) << endl;
			}
			else if(msg->pDataBuf[8] == 0x7f && msg->pDataBuf[9] == 0x22)
			{
				cout << hex << "diagnose 0x22 error, tag: 0x" << (unsigned int)(msg->pDataBuf[10]) << endl;
			}
			break;	
		case 25:
			cout << "msg is functional address: " << punion->PARAMS_PROGRAMMING_CMD.isFunctionalAddress << endl;
			break;
		case 27:
			cout << "union duration: " << punion->PARAMS_PROGRESS.ulDuration << endl;		
			cout << "union progess: " << punion->PARAMS_PROGRESS.usProgress << endl;
			break;
		case 40:
			cout << "msg did data[0]: " << punion->PARAMS_CONFIG_CMD.DIDData[0] << endl;
			break;
	}
	cout.unsetf(ios::hex);
}
