#include "handler.h"
using namespace std;
void print_menu(OBT_MSG stmesg, char* strout)
{
	cout << "menu:" << endl;
	cout << "1.success" << endl;
	cout << "2.failure" << endl;
	cout << "please input:";
	char cinput[100];
	scanf("%s", cinput);
	handler(stmesg, cinput[0], strout);	
}
string handler(OBT_MSG stmesg, char cinput, char* strout)
{
	return "hello world";
}
void rres_deserialization(char* strmesg, OBT_MSG stmesg)
{


}
