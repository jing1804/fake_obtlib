#ifndef UDPSERVER_H 
#define UDPSERVER_H
#include "handler.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
class udpserver{
public:
	udpserver();
	~udpserver();
	void run();
private:
	int m_isockfd;
	struct sockaddr_in m_clieaddr;
};

#endif
