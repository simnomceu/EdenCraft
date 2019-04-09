#include "network/protocol.hpp"
#include "network/common.hpp"
#include "core/application.hpp"
#include "utility/log.hpp"
/*
void StartSniffing(SOCKET Sock); //This will sniff here and there

void ProcessPacket(char*, int); //This will decide how to digest
void PrintIpHeader(char*);
void PrintIcmpPacket(char*, int);
void PrintIgmpPacket(char*, int);
void PrintUdpPacket(char*, int);
void PrintTcpPacket(char*, int);
void PrintData(char*, int);

FILE *logfile;
int i, j;
struct sockaddr_in source, dest; */

int main()
{
	try {
		ece::Application app;

		ece::Socket sniffer;
	/*	struct in_addr addr = {};
		int in;*/

		sniffer.open();
		auto hostname = ece::getHostname();
		ece::INFO << "Host name: " << hostname << ece::flush;

		//Retrive the available IPs of the local host
		[[maybe_unused]] auto host = ece::Host::getByName(hostname);
		ece::INFO << "Available Network Interfaces : " << ece::flush;
		auto interfaces = host.getAddresses();
		auto i = 0;
		for (auto & interface : interfaces)
		{
			ece::INFO << "Interface Number : " << i << " Address : " << inet_ntoa(interface.address) << ece::flush;
			++i;
		}

		auto in = 0;
		ece::INFO << "Enter the interface number you would like to sniff : " << ece::flush;
		std::cin >> in;

		sniffer.bind(interfaces[in]);
/*
		//Enable this socket with the power to sniff : SIO_RCVALL is the key Receive ALL ;)

		j = 1;
		std::cerr << "\nSetting socket to sniff...";
		if (WSAIoctl(sniffer, SIO_RCVALL, &j, sizeof(j), 0, 0, (LPDWORD)&in, 0, 0) == SOCKET_ERROR)
		{
			std::cerr << "WSAIoctl() failed.\n";
			return 1;
		}
		std::cerr << "Socket set.";

		//Begin
		std::cerr << "\nStarted Sniffing\n" << "Packet Capture Statistics...\n";
		StartSniffing(sniffer); //Happy Sniffing
		*/

		sniffer.close();
	}
	catch (const std::runtime_error & e) {
		ece::ERROR << e.what() << ece::flush;
	}
	catch (const std::exception & e) {
		ece::ERROR << e.what() << ece::flush;
	}
	return 0;
}
/*
void StartSniffing(SOCKET sniffer)
{
	std::array<char, 65536> Buffer; //Its Big!
	int mangobyte;

	do
	{
		mangobyte = recvfrom(sniffer, Buffer.data(), 65536, 0, 0, 0); //Eat as much as u can

		if (mangobyte > 0)
		{
			ProcessPacket(Buffer.data(), mangobyte);
		}
		else
		{
			std::cerr << "recvfrom() failed.\n";
		}
	} while (mangobyte > 0);
}

void ProcessPacket(char* Buffer, int Size)
{
	static int tcp = 0, udp = 0, icmp = 0, others = 0, igmp = 0, total = 0;

	auto iphdr = reinterpret_cast<ece::IPv4Header *>(Buffer);
	++total;

	// TODO: maybe a method can map the protocol to avoid the following big & ugly switch
	switch (iphdr->protocol) //Check the Protocol and do accordingly...
	{
	case 0: break;// HOPOPT Protocol
	case 1: //ICMP Protocol
		++icmp;
		PrintIcmpPacket(Buffer, Size);
		break;
	case 2: //IGMP Protocol
		++igmp;
		PrintIgmpPacket(Buffer, Size);
		break;
	case 3: break; // GGP Protocol
	case 4: break; //IP-in-IP Protocol
	case 5: break; // ST Protocol
	case 6: //TCP Protocol
		++tcp;
		PrintTcpPacket(Buffer, Size);
		break;
	case 7: break; // CBT Protocol
	case 8: break; // EGP Protocol
	case 9: break; // IGP Protocol
	case 10: break; // BBN-RCC-MON Protocol
	case 11: break; // NVP-II Protocol
	case 12: break; // PUP Protocol
	case 13: break; // ARGUS Protocol
	case 14: break; // EMCON Protocol
	case 15: break; // XNET Protocol
	case 16: break; // CHAOS Protocol
	case 17: //UDP Protocol
		++udp;
		PrintUdpPacket(Buffer, Size);
		break;
	case 18: break; // MUX Protocol
	case 19: break; // DCN-MEAS Protocol
	case 20: break; // HMP Protocol
	case 21: break; // PRM Protocol
	case 22: break; // XNS-IDP Protocol
	case 23: break; // TRUNK-1 Protocol
	case 24: break; // TRUNK-2 Protocol
	case 25: break; // LEAF-1 Protocol
	case 26: break; // LEAF-2 Protocol
	case 27: break; // RDP Protocol
	case 28: break; // IRTP Protocol
	case 29: break; // ISO-TP4 Protocol
	case 30: break; // NETBLT Protocol
	case 31: break; // MFE-NSP Protocol
	case 32: break; // MERIT-INP Protocol
	case 33: break; // DCCP Protocol
	case 34: break; // 3PC Protocol
	case 35: break; // IDRP Protocol
	case 36: break; // XTP Protocol
	case 37: break; // DDP Protocol
	case 38: break; // IDPR-CMTP Protocol
	case 39: break; // TP++ Protocol
	case 40: break; // IL Protocol
	case 41: break; // IPv6 Protocol
	case 42: break; // SDRP Protocol
	case 43: break; // IPv6-Route Protocol
	case 44: break; // IPv6-Frag Protocol
	case 45: break; // IDRP Protocol
	case 46: break; // RSVP Protocol
	case 47: break; // GREs Protocol
	case 48: break; // DRS Protocol
	case 49: break; // BNA Protocol
	case 50: break; // ESP Protocol
	case 51: break; // AH Protocol
	case 52: break; // I-NLSP Protocol
	case 53: break; // SWIPE Protocol
	case 54: break; // NARP Protocol
	case 55: break; // MOBILE Protocol
	case 56: break; // TLSP Protocol
	case 57: break; // SKIP Protocol
	case 58: break; // IPv6-ICMP Protocol
	case 59: break; // IPv6-NoNxt Protocol
	case 60: break; // IPv6-Opts Protocol
	case 61: break; // Protocol
	case 62: break; // CFTP Protocol
	case 63: break; // Protocol
	case 64: break; // SAT-EXPAK Protocol
	case 65: break; // KRYPTOLAN Protocol
	case 66: break; // RVD Protocol
	case 67: break; // IPPC Protocol
	case 68: break; // Protocol
	case 69: break; // SAT-MON Protocol
	case 70: break; // VISA Protocol
	case 71: break; // IPCU Protocol
	case 72: break; // CPNX Protocol
	case 73: break; // CPHB Protocol
	case 74: break; // WSN Protocol
	case 75: break; // PVP Protocol
	case 76: break; // BR-SAT-MON Protocol
	case 77: break; // SUN-ND Protocol
	case 78: break; // WB-MON Protocol
	case 79: break; // WB-EXPAK Protocol
	case 80: break; // ISO-IP Protocol
	case 81: break; // VMTP Protocol
	case 82: break; // SECURE-VMTP Protocol
	case 83: break; // VINES Protocol
	case 84: break; // TTP / IPTM Protocol
	case 85: break; // NSFNET-IGP Protocol
	case 86: break; // DGP Protocol
	case 87: break; // TCF Protocol
	case 88: break; // EIGRP Protocol
	case 89: break; // OSPF PRotocol
	case 90: break; // Sprite-RPC Protocol
	case 91: break; // LARP Protocol
	case 92: break; // MTP Protocol
	case 93: break; // AX.25 Protocol
	case 94: break; // OS Protocol
	case 95: break; // MICP Protocol
	case 96: break; // SCC-SP Protocol
	case 97: break; // ETHERIP Protocol
	case 98: break; // ENCAP Protocol
	case 99: break; // Protocol
	case 100: break; // GMTP Protocol
	case 101: break; // IFMP Protocol
	case 102: break; // PNNI Protocol
	case 103: break; // PIM Protocol
	case 104: break; // ARIS Protocol
	case 105: break; // SCPS Protocol
	case 106: break; // QNX Protocol
	case 107: break; // A/N Protocol
	case 108: break; // IPComp Protocol
	case 109: break; // SNP Protocol
	case 110: break; // Compaq-Peer Protocol
	case 111: break; // IPX-in-IP Protocol
	case 112: break; // VRRP Protocol
	case 113: break; // PGM Protocol
	case 114: break; // Protocol
	case 115: break; // L2TP Protocol
	case 116: break; // DDX Protocol
	case 117: break; // IATP Protocol
	case 118: break; // STP Protocol
	case 119: break; // SRP Protocol
	case 120: break; // UTI Protocol
	case 121: break; // SMP Protocol
	case 122: break; // SM Protocol
	case 123: break; // PTP Protocol
	case 124: break; // IS-IS over IPv4 Protocol
	case 125: break; // FIRE Protocol
	case 126: break; // CRTP Protocol
	case 127: break; // CRUDP Protocol
	case 128: break; // SSCOPMCE Protocol
	case 129: break; // IPLT Protocol
	case 130: break; // SPS Protocol
	case 131: break; // PIPE Protocol
	case 132: break; // SCTP Protocol
	case 133: break; // FC Protocol
	case 134: break; // RSVP-E2E-IGNORE Protocol
	case 135: break; // Mobility Header Protocol
	case 136: break; // UDPLite Protocol
	case 137: break; // MPLS-in-IP Protocol
	case 138: break; // manet Protocol
	case 139: break; // HIP Protocol
	case 140: break; // Shim6 Protocol
	case 141: break; // WESP Protocol
	case 142: break; // ROHC Protocol
	default: //Some Other Protocol like ARP etc.
		++others;
		break;
	}
	std::cerr << "TCP : " << tcp << " UDP : " << udp << " ICMP : " << icmp << " IGMP : " << igmp << " Others : " << others << " Total : " << total << "\r";
}

void PrintIpHeader(char* Buffer)
{
	auto iphdr = (ece::IPv4Header *)Buffer;

	std::cerr << iphdr->to_string();
}

void PrintTcpPacket(char* Buffer, int Size)
{
	unsigned short iphdrlen;

	auto iphdr = (ece::IPv4Header *)Buffer;
	iphdrlen = iphdr->internetHeaderLength * 4;

	auto tcpheader = (ece::network::protocol::TCPHeader*)(Buffer + iphdrlen);

	std::cerr << "\n\n***********************TCP Packet*************************\n";

	PrintIpHeader(Buffer);

	std::cerr << tcpheader->to_string();
	std::cerr << "\n DATA Dump\n";
	std::cerr << "IP Header\n";
	PrintData(Buffer, iphdrlen);

	std::cerr << "TCP Header\n";
	PrintData(Buffer + iphdrlen, tcpheader->dataOffset * 4);

	std::cerr << "Data Payload\n";
	PrintData(Buffer + iphdrlen + tcpheader->dataOffset * 4
		, (Size - tcpheader->dataOffset * 4 - iphdr->internetHeaderLength * 4));

	std::cerr << "\n###########################################################";
}

void PrintUdpPacket(char *Buffer, int Size)
{
	unsigned short iphdrlen;

	auto iphdr = reinterpret_cast<ece::IPv4Header *>(Buffer);
	iphdrlen = iphdr->internetHeaderLength * 4;

	auto udpheader = reinterpret_cast<ece::UDPHeader *>(Buffer + iphdrlen);

	std::cerr << "\n\n***********************UDP Packet*************************\n";

	PrintIpHeader(Buffer);

	std::cerr << udpheader->to_string();

	PrintData(Buffer, iphdrlen);

	std::cerr << "UDP Header\n";

	PrintData(Buffer + iphdrlen, sizeof(ece::UDPHeader));

	std::cerr << "Data Payload\n";

	PrintData(Buffer + iphdrlen + sizeof(ece::UDPHeader), (Size - sizeof(ece::UDPHeader) - iphdr->internetHeaderLength * 4));

	std::cerr << "\n###########################################################";
}

void PrintIcmpPacket(char* Buffer, int Size)
{
	unsigned short iphdrlen;

	auto iphdr = (ece::IPv4Header *)Buffer;
	iphdrlen = iphdr->internetHeaderLength * 4;

	auto icmpheader = reinterpret_cast<ece::ICMPHeader *>(Buffer + iphdrlen);

	printf("\n\n***********************ICMP Packet*************************\n");
	PrintIpHeader(Buffer);

	std::cerr << icmpheader->to_string();
	std::cerr << "\nIP Header\n";
	PrintData(Buffer, iphdrlen);

	std::cerr << "UDP Header\n";
	PrintData(Buffer + iphdrlen, sizeof(ece::ICMPHeader));

	std::cerr << "Data Payload\n";
	PrintData(Buffer + iphdrlen + sizeof(ece::ICMPHeader), (Size - sizeof(ece::ICMPHeader) - iphdr->internetHeaderLength * 4));

	std::cerr << "\n###########################################################";
}

void PrintIgmpPacket(char* Buffer, int Size)
{
	unsigned short iphdrlen;

	auto iphdr = (ece::IPv4Header *)Buffer;
	iphdrlen = iphdr->internetHeaderLength * 4;

	auto igmpheader = reinterpret_cast<ece::IGMPv1Header *>(Buffer + iphdrlen);

	printf("\n\n***********************IGMP Packet*************************\n");
	PrintIpHeader(Buffer);

	std::cerr << "\nIGMP Header\n";
	std::cerr << " |-Type : " << (unsigned int)(igmpheader->type);

	std::cerr << "\nIP Header\n";
	PrintData(Buffer, iphdrlen);

	std::cerr << "UDP Header\n";
	PrintData(Buffer + iphdrlen, sizeof(ece::ICMPHeader));

	std::cerr << "Data Payload\n";
	PrintData(Buffer + iphdrlen + sizeof(ece::ICMPHeader), (Size - sizeof(ece::ICMPHeader) - iphdr->internetHeaderLength * 4));

	std::cerr << "\n###########################################################";
}


// Print the hex values of the data
void PrintData(char* data, int Size)
{
	char a;
	unsigned char c;
	int k;

	std::string line(17, ' ');

	//loop over each character and print
	for (i = 0; i < Size; i++)
	{
		c = (unsigned char)data[i];

		//Print the hex value for every character , with a space. Important to make unsigned
		printf(" %.2x", c);

		//Add the character to data line. Important to make unsigned
		a = (c >= 32) ? c : '.';

		line[i % 16] = a;

		//if last character of a line , then print the line - 16 characters in 1 line
		if ((i != 0 && (i + 1) % 16 == 0) || i == Size - 1)
		{
			line[i % 16 + 1] = '\0';

			//print a big gap of 10 characters between hex and characters
			std::cerr << "          ";

			//Print additional spaces for last lines which might be less than 16 characters in length
			for (k = line.size(); k < 16; k++)
			{
				std::cerr << "   ";
			}

			std::cerr << line << "\n";
		}
	}

	std::cerr << "\n";
}
*/
