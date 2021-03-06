#include "udpserver.h"
#define MAXLINE 2058
#define SERV_PORT 8888
udpserver::udpserver()
{
	m_isockfd = socket(AF_INET, SOCK_DGRAM, 0);
	struct sockaddr_in servaddr;
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(SERV_PORT);
	if(bind(m_isockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1)
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
	socklen_t len;
	char strmesg[MAXLINE];
	char strout[MAXLINE];
	
	for(;;)
	{
		cout << "========begin recv=========" << endl;	
		len = sizeof(m_clieaddr);
		memset(strout, 0, MAXLINE);
		recvfrom(m_isockfd, strmesg, MAXLINE, 0, (struct sockaddr *)&m_clieaddr, &len);
		OBT_MSG stmesg;
		short stype;
		rres_deserialization(strmesg, &stmesg, &stype);
		print_menu(&stmesg, &stype, strout);
		sendto(m_isockfd, strout, MAXLINE, 0, (struct sockaddr *)&m_clieaddr, len);
	}
}
