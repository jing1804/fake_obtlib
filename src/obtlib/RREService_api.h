#ifndef RRESERVICE_API 
#define RRESERVICE_API 
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
typedef struct
{
	unsigned char valid;
	char ipaddr[200];
	unsigned int port;
	unsigned char saddr[2];
	unsigned char laddr[2];
}ECUINFOSTR;

typedef struct{
	int i;
}OBT_LOGLEVEL;
typedef void(*obt_log_callback_b)(OBT_LOGLEVEL log_level, const char* msg);

typedef struct
{
	int tyep;
	unsigned int len;
	unsigned char pDataBuf[2048];
}TS;
typedef int BOOL;
#ifdef __cplusplus
extern "C"{
#endif 

extern BOOL RREServiceInit(ECUINFOSTR info, obt_log_callback_b cb);
extern void RREServiceDeinit(void);
extern BOOL RecvMsgFromRREService(TS *msgdat, unsigned int* len);
extern BOOL SendMsgToRREService(TS *msgdat, unsigned int len);

#ifdef __cplusplus
}
#endif 
class udpclient
{
public:
	static udpclient* getInstance();
	bool send(char* msg, int ilen);
	bool recv(char* msg, int& ilen);
private:
	udpclient();
	~udpclient();
	int m_isockfd;
	struct sockaddr_in m_servaddr;
};

#endif
