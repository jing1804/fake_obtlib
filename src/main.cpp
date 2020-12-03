#include "RREService_api.h"
#include <iostream>
using namespace std;
//#include "handle.h"		  

int main(int argc, char** argv){
	if(argc < 2)
	{
		cout << "please input parm" << endl;
		return 0;
	}
	ECUINFOSTR info;
	obt_log_callback_b cb = nullptr;
	TS msg;
	unsigned int iLen;
	switch(int(atoi(argv[1])))
	{
		case 25:
			{
				msg.type = 25;
				OBT_DATA_BUF buf;
				buf.error_code = 0;
				buf.end_flag = 1000;
				buf.msg.PARAMS_PROGRAMMING_CMD.isFunctionalAddress = 1;
				msg.len = sizeof(buf.error_code) + sizeof(buf.end_flag) + sizeof(PARAMS_UNION);
				memcpy(&(msg.pDataBuf[0]), &buf.error_code, sizeof(buf.error_code));
				memcpy(&(msg.pDataBuf[4]), &buf.end_flag, sizeof(buf.end_flag)); 
				memcpy(&(msg.pDataBuf[8]), &buf.msg, sizeof(PARAMS_UNION));
				break;
			}
		case 26:
			break;
		case 40:
			break;
		default:
			cout << "error parm" << endl;
			return 0;
	}
	cout << "send msg type: " << msg.type << endl;	
	cout << "send msg len: " << msg.len << endl;	
	RREServiceInit(info, cb);
	SendMsgToRREService(&msg, iLen);
	RecvMsgFromRREService(&msg, &iLen);
	RREServiceDeinit();
	return 0;
}
