#include "udpserver.h"
#define MAXLINE 80
#define SERV_PORT 8888
udpserver::udpserver()
{
	m_isockfd = socket(AF_INET, SOCK_DGRAM, 0);
	struct sockaddr_in servaddr;
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(SERV_PORT);
	if(bind(m_isockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) ==  -1)
	{
		perror("bind error");
		exit(1);	
	}
}
udpserver::~udpserver()
{

}

void udpserver::run()
{
	int n;
	socklen_t len;
	char mesg[MAXLINE];
	cout << "begin recv" << endl;	
	for(;;)
	{
		len = sizeof(m_clieaddr);
		n = recvfrom(m_isockfd, mesg, MAXLINE, 0, (struct sockaddr *)&m_clieaddr, &len);
		cout << "recv: " << mesg << endl;
		string stroutmsg = handler(mesg, n);	
		sendto(m_isockfd, stroutmsg.c_str(), stroutmsg.length(), 0, (struct sockaddr *)&m_clieaddr, len);
	}


}
