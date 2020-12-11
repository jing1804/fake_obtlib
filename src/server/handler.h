#ifndef RRESERVER_HANDLER
#define RRESERVER_HANDLER
#include <iostream>
#include <string.h>
#include "RREService_api.h"
void print_menu(OBT_MSG* stmesg, short* stype, char* strout);
//std::string handler(OBT_MSG* stmesg, char cinput, char* strout);
void rres_deserialization(char* strmesg, OBT_MSG* stmesg, short* stype);
void rres_serialization(OBT_MSG* stmesg, short* stype, char* strout);

void print_msg(OBT_MSG* stmesg, short* stype);
#endif
