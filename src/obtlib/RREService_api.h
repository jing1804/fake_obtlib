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
#include "common_type.h"

typedef struct
{
	int type;
	unsigned int len;
	unsigned char pDataBuf[2048];
}TS;
typedef struct
{
	unsigned char valid;
	char ipaddr[200];
	unsigned int port;
	unsigned char saddr[2];
	unsigned char laddr[2];
}ECUINFOSTR;
#define MAX_SFF_FILE_NUM 5
#define FILEPATH_MAX_LENGTH 256
#define MAX_SFF_FILE_NUM 5
#define REMOTE_CONFIG_DID_COUNT 5
#define REMOTE_CONFIG_DID_LENGTH 32
#define REMOTE_CONFIG_FEATURE_CODE_LEN 256

#define MAX_SFF_FILE_NUM 5
#define REMOTE_CONFIG_DID_COUNT 5
#define REMOTE_CONFIG_DID_LENGTH 32
#define REMOTE_CONFIG_FEATURE_CODE_LEN 256
#define MAX_VIN_LENGTH 17
#define CLI_SEND_MSG 1
#define CLI_RECV_MSG 2
#define SER_BLOCK_MSG 3
#define SER_NODATA_MSG 4
#define SER_NORMAL_MSG 6
 
typedef union PARAMS_UNION
{
    struct {
        CHAR DIDData[3][6];                                        // �������ݣ������š�NCF�š����̣�
        CHAR sffFilePath[MAX_SFF_FILE_NUM][FILEPATH_MAX_LENGTH];   // sff�ļ�·��
        CHAR ppfFilePath[FILEPATH_MAX_LENGTH];                     // ppf�ļ�·��
        UINT16 isFunctionalAddress;  //0: Physical 1: Functional
        UINT16 toIgnoreGWACK; //0: Care GW ACK 1:Ignore GW ACK
        UINT8  logicAddress[2];  //programming logic addr
    } PARAMS_PROGRAMMING_CMD;           // ˢ�²�������
  
    struct {
        CHAR DIDData[REMOTE_CONFIG_DID_COUNT][REMOTE_CONFIG_DID_LENGTH]; // ��������
        CHAR ecsFilePath[FILEPATH_MAX_LENGTH];                     // ecs�ļ�·��
        CHAR featureCodeFilePath[REMOTE_CONFIG_FEATURE_CODE_LEN];  // FeatureCode�ļ�·��
        CHAR VINData[MAX_VIN_LENGTH];                              // VIN ID
    } PARAMS_CONFIG_CMD;                // ���ò�������

    struct {
        UINT32 ulDuration;      // ��ִ�е�ʱ��
        UINT16 usProgress;      // ��ִ�еĽ���
    } PARAMS_PROGRESS;

} PARAMS_UNION;

typedef enum
{
    OBT_LL_CLOSE = 0,
    OBT_LL_DEBUG,
    OBT_LL_INFO,
    OBT_LL_WARNING,
    OBT_LL_ERROR,
    OBT_LL_FATAL,
}OBT_LOGLEVEL;

/*typedef struct{
	int i;
}OBT_LOGLEVEL;*/
//typedef int BOOL;
typedef void(*obt_log_callback_b)(OBT_LOGLEVEL log_level, const char* msg);

#ifdef __cplusplus
extern "C"{
#endif 

extern BOOL RREServiceInit(ECUINFOSTR info, obt_log_callback_b cb);
extern void RREServiceDeinit(void);
extern BOOL SendMsgToRREService(TS *msgdat, unsigned int len);
extern BOOL RecvMsgFromRREService(TS *msgdat, unsigned int* len);

#ifdef __cplusplus
}
#endif 
class udpclient
{
public:
	static udpclient* getInstance();
	bool send(const char* msg, int ilen);
	bool recv(char* msg, int& ilen);
private:
	udpclient();
	~udpclient();
	int m_isockfd;
	struct sockaddr_in m_servaddr;
};
typedef struct {
    int error_code;
    unsigned int end_flag;
    PARAMS_UNION msg;
}OBT_DATA_BUF;

typedef struct {
    int type;
    unsigned int len;
    OBT_DATA_BUF data_buf;
}OBT_MSG;
void print_ts(TS* msg);
#endif
