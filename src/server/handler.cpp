#include "handler.h"
#include <iostream>
using namespace std;

string handler(char* msg, int ilen)
{
	cout << msg << endl;
	return "hello world";
}
