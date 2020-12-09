#include "handler.h"
using namespace std;
#define MAXLINE 2056
OBT_MSG g_stmesg;

void print_msg(OBT_MSG* stmesg, short* stype)
{
	switch(*stype)
	{
		case CLI_SEND_MSG:
		{
			cout << "client send msg" << endl;			
			break;
		}
		case CLI_RECV_MSG:
		{
			cout << "client recv msg" << endl;			
			break;
		}
		case SER_BLOCK_MSG:
		{
			cout << "server return block msg" << endl;			
			return;
		}
		case SER_NODATA_MSG:
		{
			cout << "server return no data msg" << endl;			
			return;
		}
		case SER_NORMAL_MSG:
		{
			cout << "server return normal msg" << endl;			
			break;
		}
	}	
	cout << "msg type: " << stmesg->type << endl;
	cout << "msg buf len: " << stmesg->len << endl;
	cout << "msg error code: " << stmesg->data_buf.error_code << endl;
	cout << "msg end flag: " << stmesg->data_buf.end_flag << endl;
	switch(stmesg->type)
	{
		case 15:
			{
				unsigned char* parr = &(stmesg->data_buf.msg.PARAMS_ARRAY.arr[0]);
				cout << hex << "diagnose type: 0x" << (unsigned int)(parr[0]) << endl;
				if(parr[0] == 0x10)
				{
					cout << dec << "session: " << (unsigned int)(parr[1]) << endl;	
				}
				else if(parr[0] == 0x22)
				{
					cout << hex << "did address: 0x" << (unsigned int)(parr[1]) << (unsigned int)(parr[2]) << endl;
				}
				break;
			}
		case 16:
			{
				unsigned char* parr = &(stmesg->data_buf.msg.PARAMS_ARRAY.arr[0]);
				cout << hex << "diagnose result: 0x" << (unsigned int)(parr[0]) << endl;
				if(parr[0] == 0x50)
        	    {
        	        cout << dec << "session: " << (unsigned int)(parr[1]) << endl;
        	    }       
        	    else if(parr[0] == 0x62)
        	    {
        	        cout << hex << "did address: 0x" << (unsigned int)(parr[1]) << (unsigned int)(parr[2]) << (unsigned int)(parr[3]) << (unsigned int)(parr[4]) << (unsigned int)(parr[5])  << endl;
        	    }
        	    else if(parr[0] == 0x7f && parr[1] == 0x10)
        	    {
        	        cout << hex << "diagnose 0x10 error, tag: 0x" << (unsigned int)(parr[2]) << endl;
        	    }
        	    else if(parr[0] == 0x7f && parr[1] == 0x22)
        	    {
        	        cout << hex << "diagnose 0x22 error, tag: 0x" << (unsigned int)(parr[2]) << endl;
        	    }
            	break;	
			}
		case 25:
		{
			cout << "PARAMS_UNION, is func: " << stmesg->data_buf.msg.PARAMS_PROGRAMMING_CMD.isFunctionalAddress << endl;	
			break;
		} 
		case 27:
		{
			cout << "union duration: " << stmesg->data_buf.msg.PARAMS_PROGRESS.ulDuration << endl;    
            cout << "union progess: " <<  stmesg->data_buf.msg.PARAMS_PROGRESS.usProgress << endl;
			break;
		} 
		case 40:
		{
			cout << "PARAMS_UNION, did data[1]: " <<(char*)&(stmesg->data_buf.msg.PARAMS_CONFIG_CMD.DIDData[0]) << endl;
			break;
		} 
	}
	cout.unsetf(ios::hex);
}
void print_menu(OBT_MSG* stmesg, short* stype, char* strout)
{
	if(*stype == CLI_SEND_MSG)
	{
		print_msg(stmesg, stype);
		cout << "++++++++++++menu+++++++++++" << endl;
		cout << "1.block 10s" << endl;
		cout << "2.return false" << endl;
		short sReturn;
		cout << "3.return true" << endl;
		cout << "please input:";
		char cinput[100];
		scanf("%s", cinput);
		switch(cinput[0])
		{
			case '1':
				sReturn = SER_BLOCK_MSG;	
				break;
			case '2':
				sReturn = SER_NODATA_MSG;
				break;
			default:
				sReturn = SER_NORMAL_MSG;
		}	
		rres_serialization(stmesg, &sReturn, strout);
		memcpy(&g_stmesg, stmesg, sizeof(OBT_MSG));
	}
	else if(*stype == CLI_RECV_MSG)
	{
		cout << "++++++++++++menu+++++++++++" << endl;
		cout << "1.block 10s" << endl;
		cout << "2.return false" << endl;
		short sReturn;
		OBT_MSG stretu; 
        stretu.data_buf.end_flag = 1000;
        stretu.data_buf.error_code = 0;
		stretu.len = 8;
		char cinput[100];
		switch(g_stmesg.type)
		{
			case 15:
				stretu.type = 16;
				cout << "3.diagnose success" << endl;
				cout << "4.diagnose failure" << endl;
				cout << "5.error code 0x7010" << endl;
				cout << "please input:";
				scanf("%s", cinput);
				switch(cinput[0])
				{
					case '1':
					{
						sReturn = SER_BLOCK_MSG;
						break;
					}
					case '2':
					{
						sReturn = SER_NODATA_MSG;
						break;
					}
					case '3':
					{
						sReturn = SER_NORMAL_MSG;
						unsigned char* pin = g_stmesg.data_buf.msg.PARAMS_ARRAY.arr;
						unsigned char* pretu = stretu.data_buf.msg.PARAMS_ARRAY.arr;
						if(pin[0] == 0x10)
						{
							pretu[0] = 0x50;
							pretu[1] = pin[1];	
							stretu.len = 10;
						}
						else if(pin[0] == 0x22)
						{
							cout << "0x22 successful" << endl;
							pretu[0] = 0x62;
							pretu[1] = pin[1];
							pretu[2] = pin[2];
							pretu[3] = 0xff;
							pretu[4] = 0xff;
							pretu[5] = 0xff;
							stretu.len = 14;
						}
						break;
					}
					case '4':
					{
						sReturn = SER_NORMAL_MSG;
						unsigned char* pin = g_stmesg.data_buf.msg.PARAMS_ARRAY.arr;
						unsigned char* pretu = stretu.data_buf.msg.PARAMS_ARRAY.arr;
						stretu.len = 11;
						if(pin[0] == 0x10)
						{
							pretu[0] = 0x7f;
							pretu[1] = 0x10;
							pretu[2] = 0x7f;
							stretu.len = 11;
						}
						else if(pin[0] == 0x22)
						{
							cout << "0x22 failure" << endl;
							pretu[0] = 0x7f;
							pretu[1] = 0x22;
							pretu[2] = 0x7f;
							stretu.len = 11;
						}
						break;
					}
					case '5':
					{
						sReturn = SER_NORMAL_MSG;	
						stretu.data_buf.error_code = 0x7010;
						break;
					}
				}
				break;
			case 25:
				stretu.type = 32;
				cout << "3.success" << endl;
				cout << "4.error code 0x7010" << endl;
				cout << "please input:";
				scanf("%s", cinput);
				switch(cinput[0])
				{
					case '1':
						sReturn = SER_BLOCK_MSG;	
						break;
					case '2':
						sReturn = SER_NODATA_MSG;
						break;
					case '3':
						sReturn = SER_NORMAL_MSG;	
						stretu.data_buf.error_code = 0;
						break;
					case '4':
						sReturn = SER_NORMAL_MSG;	
						stretu.data_buf.error_code = 0x7010;
						break;
				}
				break;
			case 26:
				stretu.type = 27;
				stretu.len = 8 + sizeof(PARAMS_UNION);
				stretu.data_buf.error_code = 0;
				cout << "3.10s, 50%" << endl;
                cout << "4.20s, 100%" << endl;
                cout << "5.error code 0x7010" << endl;
                cout << "please input:";
                scanf("%s", cinput);
                switch(cinput[0])
                {
                    case '1':
						sReturn = SER_BLOCK_MSG;
						break;
                    case '2':
						sReturn = SER_NODATA_MSG;
						break;
					case '3':
						stretu.data_buf.msg.PARAMS_PROGRESS.ulDuration = 10;
                        stretu.data_buf.msg.PARAMS_PROGRESS.usProgress = 50;
                        break;
                    case '4':
                        stretu.data_buf.msg.PARAMS_PROGRESS.ulDuration = 20;
                        stretu.data_buf.msg.PARAMS_PROGRESS.usProgress = 100;
                        break;
                    case '5':
                        stretu.data_buf.error_code = 0x7010;
                        break;
				}
				break;
			case 40:
				stretu.type = 46;
				cout << "3.success" << endl;
				cout << "4.error code 0x7010" << endl;
				cout << "please input:";
				scanf("%s", cinput);
				switch(cinput[0])
				{
					case '1':
						sReturn = SER_BLOCK_MSG;	
						break;
					case '2':
						sReturn = SER_NODATA_MSG;
						break;
					case '3':
						sReturn = SER_NORMAL_MSG;	
						stretu.data_buf.error_code = 0;
						break;
					case '4':
						sReturn = SER_NORMAL_MSG;	
						stretu.data_buf.error_code = 0x7010;
						break;
				}
				break;
		}
		rres_serialization(&stretu, &sReturn, strout);
	}
}
/*
void print_menu(OBT_MSG stmesg, short stype, char* strout)
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
*/
void rres_serialization(OBT_MSG* stmesg, short* stype, char* strout)
{
	memset(strout, 0, MAXLINE); 
	memcpy(&strout[0], stype, sizeof(short));
	memcpy(&strout[2], &stmesg->type, sizeof(int));	
	memcpy(&strout[6], &stmesg->len, sizeof(int));	
	memcpy(&strout[10], &stmesg->data_buf.error_code, sizeof(int));	
	memcpy(&strout[14], &stmesg->data_buf.end_flag, sizeof(int));	
	memcpy(&strout[18], &stmesg->data_buf.msg, sizeof(PARAMS_UNION));	
}

void rres_deserialization(char* strmesg, OBT_MSG* stmesg, short* stype)
{
	memcpy(stype, &(strmesg[0]), sizeof(short));
	memcpy(&stmesg->type, &(strmesg[2]), sizeof(int));
	memcpy(&stmesg->len,  &(strmesg[6]), sizeof(int));
	memcpy(&stmesg->data_buf.error_code, &(strmesg[10]), sizeof(int));
	memcpy(&stmesg->data_buf.end_flag, &(strmesg[14]), sizeof(int));
	memcpy(&stmesg->data_buf.msg, &(strmesg[18]), sizeof(PARAMS_UNION));
}
