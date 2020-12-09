#include "RREService_api.h"
#include <iostream>
using namespace std;
//#include "handle.h"		  

int main(int argc, char** argv){
	if(argc < 2)
	{
		cout << "please input parm: 1510, 1522, 25, 26, 40" << endl;
		return 0;
	}
	ECUINFOSTR info;
	obt_log_callback_b cb = nullptr;
	TS msg;
	unsigned int iLen;
	OBT_DATA_BUF buf;
	buf.error_code = 0;
	buf.end_flag = 1000;
	memcpy(&(msg.pDataBuf[0]), &buf.error_code, sizeof(buf.error_code));
	memcpy(&(msg.pDataBuf[4]), &buf.end_flag, sizeof(buf.end_flag)); 
	switch(int(atoi(argv[1])))
	{
		case 1510:
			{
				msg.type = 15;
				msg.len = sizeof(buf.error_code) + sizeof(buf.end_flag) + 2;
				msg.pDataBuf[8] = 0x10;
				msg.pDataBuf[9] = 1;
				break;
			}
		case 1522:
			{
				msg.type = 15;
				msg.len = sizeof(buf.error_code) + sizeof(buf.end_flag) + 3;
				msg.pDataBuf[8] = 0x22;
				msg.pDataBuf[9] = 0x55;
				msg.pDataBuf[10] = 0xdd;
				break;
			}
		case 25:
			{
				msg.type = 25;
				msg.len = sizeof(buf.error_code) + sizeof(buf.end_flag) + sizeof(PARAMS_UNION);
				buf.msg.PARAMS_PROGRAMMING_CMD.isFunctionalAddress = 1;
				memcpy(&(msg.pDataBuf[8]), &buf.msg, sizeof(PARAMS_UNION));
				break;
			}
		case 26:
			{
				msg.type = 26;
				msg.len = sizeof(buf.error_code) + sizeof(buf.end_flag);
				break;
			}
		case 40:
			{
				msg.type = 40;
				msg.len = sizeof(buf.error_code) + sizeof(buf.end_flag) + sizeof(PARAMS_UNION);
				memcpy(buf.msg.PARAMS_CONFIG_CMD.DIDData[0], "new config", 10);
				memcpy(&(msg.pDataBuf[8]), &buf.msg, sizeof(PARAMS_UNION));
				break;
			}
		default:
			cout << "error parm" << endl;
			return 0;
	}
	RREServiceInit(info, cb);
	bool ru;
	do{
		ru = SendMsgToRREService(&msg, iLen);
		cout << "send ru: " << ru << endl;
	}while(!ru);
	ru = RecvMsgFromRREService(&msg, &iLen);
	cout << "recv ru: " << ru << endl;
	RREServiceDeinit();
	return 0;
}
