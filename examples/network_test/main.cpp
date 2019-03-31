#include "stdio.h"
#include "network/protocol.hpp"

#pragma comment(lib,"ws2_32.lib") //For winsock

#define SIO_RCVALL _WSAIOW(IOC_VENDOR,1) //this removes the need of mstcpip.h

void StartSniffing(SOCKET Sock); //This will sniff here and there

void ProcessPacket(char*, int); //This will decide how to digest
void PrintIpHeader(char*);
void PrintIcmpPacket(char*, int);
void PrintUdpPacket(char*, int);
void PrintTcpPacket(char*, int);
void ConvertToHex(char*, unsigned int);
void PrintData(char*, int);

FILE *logfile;
int tcp = 0, udp = 0, icmp = 0, others = 0, igmp = 0, total = 0, i, j;
struct sockaddr_in source, dest;
char hex[2];

//Its free!
ece::IPv4Header *iphdr;
ece::TCPHeader *tcpheader;
ece::UDPHeader *udpheader;
ece::ICMPHeader *icmpheader;

int main()
{
	SOCKET sniffer;
	struct in_addr addr = {};
	int in;

	char hostname[100];
	struct hostent *local;
	WSADATA wsa;

	fopen_s(&logfile, "log.txt", "w+");
	if (logfile == NULL)
	{
		printf("Unable to create file.");
	}

	//Initialise Winsock
	printf("\nInitialising Winsock...");
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf("WSAStartup() failed.\n");
		return 1;
	}
	printf("Initialised");

	//Create a RAW Socket
	printf("\nCreating RAW Socket...");
	sniffer = socket(AF_INET, SOCK_RAW, IPPROTO_IP);
	if (sniffer == INVALID_SOCKET)
	{
		printf("Failed to create raw socket.\n");
		return 1;
	}
	printf("Created.");

	//Retrive the local hostname
	if (gethostname(hostname, sizeof(hostname)) == SOCKET_ERROR)
	{
		printf("Error : %d", WSAGetLastError());
		return 1;
	}
	printf("\nHost name : %s \n", hostname);

	//Retrive the available IPs of the local host
	local = gethostbyname(hostname);
	printf("\nAvailable Network Interfaces : \n");
	if (local == NULL)
	{
		printf("Error : %d.\n", WSAGetLastError());
		return 1;
	}

	for (i = 0; local->h_addr_list[i] != 0; ++i)
	{
		memcpy(&addr, local->h_addr_list[i], sizeof(struct in_addr));
		printf("Interface Number : %d Address : %s\n", i, inet_ntoa(addr));
	}

	printf("Enter the interface number you would like to sniff : ");
	scanf_s("%d", &in);

	memset(&dest, 0, sizeof(dest));
	memcpy(&dest.sin_addr.s_addr, local->h_addr_list[in], sizeof(dest.sin_addr.s_addr));
	dest.sin_family = AF_INET;
	dest.sin_port = 0;

	printf("\nBinding socket to local system and port 0 ...");
	if (bind(sniffer, (struct sockaddr *)&dest, sizeof(dest)) == SOCKET_ERROR)
	{
		printf("bind(%s) failed.\n", inet_ntoa(addr));
		return 1;
	}
	printf("Binding successful");

	//Enable this socket with the power to sniff : SIO_RCVALL is the key Receive ALL ;)

	j = 1;
	printf("\nSetting socket to sniff...");
	if (WSAIoctl(sniffer, SIO_RCVALL, &j, sizeof(j), 0, 0, (LPDWORD)&in, 0, 0) == SOCKET_ERROR)
	{
		printf("WSAIoctl() failed.\n");
		return 1;
	}
	printf("Socket set.");

	//Begin
	printf("\nStarted Sniffing\n");
	printf("Packet Capture Statistics...\n");
	StartSniffing(sniffer); //Happy Sniffing

							//End
	closesocket(sniffer);
	WSACleanup();

	return 0;
}

void StartSniffing(SOCKET sniffer)
{
	char *Buffer = (char *)malloc(65536); //Its Big!
	int mangobyte;

	if (Buffer == NULL)
	{
		printf("malloc() failed.\n");
		return;
	}

	do
	{
		mangobyte = recvfrom(sniffer, Buffer, 65536, 0, 0, 0); //Eat as much as u can

		if (mangobyte > 0)
		{
			ProcessPacket(Buffer, mangobyte);
		}
		else
		{
			printf("recvfrom() failed.\n");
		}
	} while (mangobyte > 0);

	free(Buffer);
}

void ProcessPacket(char* Buffer, int Size)
{
	iphdr = (ece::IPv4Header *)Buffer;
	++total;

	switch (iphdr->protocol) //Check the Protocol and do accordingly...
	{
	case 1: //ICMP Protocol
		++icmp;
		PrintIcmpPacket(Buffer, Size);
		break;

	case 2: //IGMP Protocol
		++igmp;
		break;

	case 6: //TCP Protocol
		++tcp;
		PrintTcpPacket(Buffer, Size);
		break;

	case 17: //UDP Protocol
		++udp;
		PrintUdpPacket(Buffer, Size);
		break;

	default: //Some Other Protocol like ARP etc.
		++others;
		break;
	}
	printf("TCP : %d UDP : %d ICMP : %d IGMP : %d Others : %d Total : %d\r", tcp, udp, icmp, igmp, others, total);
}

void PrintIpHeader(char* Buffer)
{
	unsigned short iphdrlen;

	iphdr = (ece::IPv4Header *)Buffer;
	iphdrlen = iphdr->internetHeaderLength * 4;

	memset(&source, 0, sizeof(source));
	source.sin_addr.s_addr = iphdr->source;

	memset(&dest, 0, sizeof(dest));
	dest.sin_addr.s_addr = iphdr->destination;

	printf("\n");
	printf("IP Header\n");
	printf(" |-IP Version : %d\n", (unsigned int)iphdr->version);
	printf(" |-IP Header Length : %d DWORDS or %d Bytes\n", (unsigned int)iphdr->internetHeaderLength, ((unsigned int)(iphdr->internetHeaderLength)) * 4);
	printf(" |-Type Of Service : %d\n", (unsigned int)iphdr->dscp);
	printf(" |-IP Total Length : %d Bytes(Size of Packet)\n", ntohs(iphdr->totalLength));
	printf(" |-Identification : %d\n", ntohs(iphdr->identification));
	printf(" |-Reserved ZERO Field : %d\n", (unsigned int)iphdr->reservedFlag);
	printf(" |-Dont Fragment Field : %d\n", (unsigned int)iphdr->dfFlag);
	printf(" |-More Fragment Field : %d\n", (unsigned int)iphdr->mfFlag);
	printf(" |-TTL : %d\n", (unsigned int)iphdr->ttl);
	printf(" |-Protocol : %d\n", (unsigned int)iphdr->protocol);
	printf(" |-Checksum : %d\n", ntohs(iphdr->checksum));
	printf(" |-Source IP : %s\n", inet_ntoa(source.sin_addr));
	printf(" |-Destination IP : %s\n", inet_ntoa(dest.sin_addr));
}

void PrintTcpPacket(char* Buffer, int Size)
{
	unsigned short iphdrlen;

	iphdr = (ece::IPv4Header *)Buffer;
	iphdrlen = iphdr->internetHeaderLength * 4;

	tcpheader = (ece::network::protocol::TCPHeader*)(Buffer + iphdrlen);

	printf("\n\n***********************TCP Packet*************************\n");

	PrintIpHeader(Buffer);

	printf("\n");
	printf("TCP Header\n");
	printf(" |-Source Port : %u\n", ntohs(tcpheader->source));
	printf(" |-Destination Port : %u\n", ntohs(tcpheader->destination));
	printf(" |-Sequence Number : %u\n", ntohl(tcpheader->sequence));
	printf(" |-Acknowledge Number : %u\n", ntohl(tcpheader->acknowledgment));
	printf(" |-Header Length : %d DWORDS or %d BYTES\n"
		, (unsigned int)tcpheader->dataOffset, (unsigned int)tcpheader->dataOffset * 4);
	printf(" |-ECN-nonce Flag: %d\n", (unsigned int)tcpheader->ecnFlag);
	printf(" |-CWR Flag : %d\n", (unsigned int)tcpheader->cwrFlag);
	printf(" |-ECN Flag : %d\n", (unsigned int)tcpheader->ecnFlag);
	printf(" |-Urgent Flag : %d\n", (unsigned int)tcpheader->urgFlag);
	printf(" |-Acknowledgement Flag : %d\n", (unsigned int)tcpheader->ackFlag);
	printf(" |-Push Flag : %d\n", (unsigned int)tcpheader->pshFlag);
	printf(" |-Reset Flag : %d\n", (unsigned int)tcpheader->rstFlag);
	printf(" |-Synchronise Flag : %d\n", (unsigned int)tcpheader->synFlag);
	printf(" |-Finish Flag : %d\n", (unsigned int)tcpheader->finFlag);
	printf(" |-Window : %d\n", ntohs(tcpheader->windowSize));
	printf(" |-Checksum : %d\n", ntohs(tcpheader->checksum));
	printf(" |-Urgent Pointer : %d\n", tcpheader->urgentPointer);
	printf("\n");
	printf(" DATA Dump ");
	printf("\n");

	printf("IP Header\n");
	PrintData(Buffer, iphdrlen);

	printf("TCP Header\n");
	PrintData(Buffer + iphdrlen, tcpheader->dataOffset * 4);

	printf("Data Payload\n");
	PrintData(Buffer + iphdrlen + tcpheader->dataOffset * 4
		, (Size - tcpheader->dataOffset * 4 - iphdr->internetHeaderLength * 4));

	printf("\n###########################################################");
}

void PrintUdpPacket(char *Buffer, int Size)
{
	unsigned short iphdrlen;

	iphdr = (ece::IPv4Header *)Buffer;
	iphdrlen = iphdr->internetHeaderLength * 4;

	udpheader = reinterpret_cast<ece::UDPHeader *>(Buffer + iphdrlen);

	printf("\n\n***********************UDP Packet*************************\n");

	PrintIpHeader(Buffer);

	printf("\nUDP Header\n");
	printf(" |-Source Port : %d\n", ntohs(udpheader->source));
	printf(" |-Destination Port : %d\n", ntohs(udpheader->destination));
	printf(" |-UDP Length : %d\n", ntohs(udpheader->length));
	printf(" |-UDP Checksum : %d\n", ntohs(udpheader->checksum));

	printf("\n");
	printf("IP Header\n");

	PrintData(Buffer, iphdrlen);

	printf("UDP Header\n");

	PrintData(Buffer + iphdrlen, sizeof(ece::UDPHeader));

	printf("Data Payload\n");

	PrintData(Buffer + iphdrlen + sizeof(ece::UDPHeader), (Size - sizeof(ece::UDPHeader) - iphdr->internetHeaderLength * 4));

	printf("\n###########################################################");
}

void PrintIcmpPacket(char* Buffer, int Size)
{
	unsigned short iphdrlen;

	iphdr = (ece::IPv4Header *)Buffer;
	iphdrlen = iphdr->internetHeaderLength * 4;

	icmpheader = reinterpret_cast<ece::ICMPHeader *>(Buffer + iphdrlen);

	printf("\n\n***********************ICMP Packet*************************\n");
	PrintIpHeader(Buffer);

	printf("\n");

	printf("ICMP Header\n");
	printf(" |-Type : %d", (unsigned int)(icmpheader->type));

	if ((unsigned int)(icmpheader->type) == 11)
	{
		printf(" (TTL Expired)\n");
	}
	else if ((unsigned int)(icmpheader->type) == 0)
	{
		printf(" (ICMP Echo Reply)\n");
	}

	printf(" |-Code : %d\n", (unsigned int)(icmpheader->code));
	printf(" |-Checksum : %d\n", ntohs(icmpheader->checksum));
	printf(" |-Identifier : %d\n", ntohs(*reinterpret_cast<std::uint16_t *>(&icmpheader->data)));
	printf(" |-Sequence : %d\n", ntohs(*reinterpret_cast<std::uint16_t *>(&icmpheader->data + sizeof(std::uint16_t))));
	printf("\n");

	printf("IP Header\n");
	PrintData(Buffer, iphdrlen);

	printf("UDP Header\n");
	PrintData(Buffer + iphdrlen, sizeof(ece::ICMPHeader));

	printf("Data Payload\n");
	PrintData(Buffer + iphdrlen + sizeof(ece::ICMPHeader), (Size - sizeof(ece::ICMPHeader) - iphdr->internetHeaderLength * 4));

	printf("\n###########################################################");
}

/*
Print the hex values of the data
*/
void PrintData(char* data, int Size)
{
	char a, line[17], c;
	int k;

	//loop over each character and print
	for (i = 0; i < Size; i++)
	{
		c = data[i];

		//Print the hex value for every character , with a space. Important to make unsigned
		printf(" %.2x", (unsigned char)c);

		//Add the character to data line. Important to make unsigned
		a = (c >= 32 && c <= 128) ? (unsigned char)c : '.';

		line[i % 16] = a;

		//if last character of a line , then print the line - 16 characters in 1 line
		if ((i != 0 && (i + 1) % 16 == 0) || i == Size - 1)
		{
			line[i % 16 + 1] = '\0';

			//print a big gap of 10 characters between hex and characters
			printf("          ");

			//Print additional spaces for last lines which might be less than 16 characters in length
			for (k = strlen(line); k < 16; k++)
			{
				printf("   ");
			}

			printf("%s \n", line);
		}
	}

	printf("\n");
}