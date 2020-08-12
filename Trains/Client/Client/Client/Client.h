#pragma once
#pragma comment(lib, "ws2_32.lib")
#include <winsock2.h>
#include <iostream>
#include <string>
#pragma warning(disable: 4996)

using namespace std;

class Client {
public:
	Client();

public:
	SOCKET Connection;
	WSAData wsaData;
	WORD DLLVersion;
	SOCKADDR_IN addr;
	int sizeofaddr;
};

