#ifndef RRESERVICE_API 
#define RRESERVICE_API 
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


#endif
