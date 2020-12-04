#include "handler.h"
using namespace std;
#define MAXLINE 2056

void print_menu(OBT_MSG stmesg, char* strout)
{
	cout << "msg type: " << stmesg.type << endl;
	cout << "msg buf len: " << stmesg.len << endl;
	cout << "msg error code: " << stmesg.data_buf.error_code << endl;
	cout << "msg end flag: " << stmesg.data_buf.end_flag << endl;
	switch(stmesg.type)
	{
		case 25:
		{
			cout << "PARAMS_UNION, is func: " << stmesg.data_buf.msg.PARAMS_PROGRAMMING_CMD.isFunctionalAddress << endl;	
			//construct send struct buf
			stmesg.type = 32;
			stmesg.len = 8;
			cout << "++++++++++++menu+++++++++++" << endl;
			cout << "1.success" << endl;
			cout << "2.error code 0x7010" << endl;
			cout << "please input:";
			char cinput[100];
			scanf("%s", cinput);
			switch(cinput[0])
			{
				case '1':
					stmesg.data_buf.error_code = 0;
					break;
				case '2':
					stmesg.data_buf.error_code = 0x7010;
					break;
			}	
			rres_serialization(stmesg, strout);
			break;
		}	
		case 26:
		{
			stmesg.type = 27;
			stmesg.len = 8 + sizeof(PARAMS_UNION);
			stmesg.data_buf.error_code = 0;
			stmesg.data_buf.end_flag = 1000;
			cout << "++++++++++++menu+++++++++++" << endl;
			cout << "1.10s, 50%" << endl;
			cout << "2.20s, 100%" << endl;
			cout << "3.error code 0x7010" << endl;
			cout << "please input:";
			char cinput[100];
			scanf("%s", cinput);
			switch(cinput[0])
			{
				case '1':
					stmesg.data_buf.msg.PARAMS_PROGRESS.ulDuration = 10;
					stmesg.data_buf.msg.PARAMS_PROGRESS.usProgress = 50;
					break;
				case '2':
					stmesg.data_buf.msg.PARAMS_PROGRESS.ulDuration = 20;
					stmesg.data_buf.msg.PARAMS_PROGRESS.usProgress = 100;
					break;
				case '3':
					stmesg.data_buf.error_code = 0x7010;
					break;
			}	
			rres_serialization(stmesg, strout);
			break;
		}	
		case 40:
		{	
			cout << "PARAMS_UNION, did data[1]: " <<(char*)&(stmesg.data_buf.msg.PARAMS_CONFIG_CMD.DIDData[0]) << endl;
			//construct send struct buf
			stmesg.type = 46;
			stmesg.len = 8;
			cout << "++++++++++++menu+++++++++++" << endl;
			cout << "1.success" << endl;
			cout << "2.error code 0x7010" << endl;
			cout << "please input:";
			char cinput[100];
			scanf("%s", cinput);
			switch(cinput[0])
			{
				case '1':
					stmesg.data_buf.error_code = 0;
					break;
				case '2':
					stmesg.data_buf.error_code = 0x7010;
					break;
			}	
			rres_serialization(stmesg, strout);
			break;
		}
	}
}

void rres_serialization(OBT_MSG stmesg, char* strout)
{
	memset(strout, 0, MAXLINE); 
	memcpy(&strout[0], &stmesg.type, sizeof(int));	
	memcpy(&strout[4], &stmesg.len, sizeof(int));	
	memcpy(&strout[8], &stmesg.data_buf.error_code, sizeof(int));	
	memcpy(&strout[12], &stmesg.data_buf.end_flag, sizeof(int));	
	memcpy(&strout[16], &stmesg.data_buf.msg, sizeof(PARAMS_UNION));	
}

void rres_deserialization(char* strmesg, OBT_MSG* stmesg)
{
	memcpy(&stmesg->type, &(strmesg[0]), sizeof(int));
	memcpy(&stmesg->len,  &(strmesg[4]), sizeof(int));
	memcpy(&stmesg->data_buf.error_code, &(strmesg[8]), sizeof(int));
	memcpy(&stmesg->data_buf.end_flag, &(strmesg[12]), sizeof(int));
	memcpy(&stmesg->data_buf.msg, &(strmesg[16]), sizeof(PARAMS_UNION));
}
