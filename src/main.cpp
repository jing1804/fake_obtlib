#include "RREService_api.h"

int main(int argc, char** argv){
	ECUINFOSTR info;
	obt_log_callback_b cb = nullptr;
	TS msg;
	unsigned int iLen;

	RREServiceInit(info, cb);
	SendMsgToRREService(&msg, iLen);
	RecvMsgFromRREService(&msg, &iLen);
	RREServiceDeinit();
	return 0;
}
