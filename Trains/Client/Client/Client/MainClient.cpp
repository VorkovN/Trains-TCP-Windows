#pragma comment(lib, "ws2_32.lib")
#include <winsock2.h>
#include <iostream>
#include <string>
#include <vector>
#include "Client.h"
#pragma warning(disable: 4996)

using namespace std;


Client client;


void ClientHandler() {
	char msg[256];
	while (true) {
		if (recv(client.Connection, msg, sizeof(msg), NULL) > 0) {
			cout << msg << endl;
			Sleep(10);
			cout << "2\n";
		}
	}
}


int main(int argc, char* argv[]) {

	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ClientHandler, NULL, NULL, NULL);

	char from[256];
	char to[256];
	char freight_type[256];
	int volume;
	while (true) {
		Sleep(100);
		cout << "Input city1" << endl;
		cin.getline(from, sizeof(from));
		cout << "Input city2" << endl;;
		cin.getline(to, sizeof(to));
		cout << "Input type of freight (liquid, wood or ore)" << endl;;
		cin.getline(freight_type, sizeof(freight_type));
		cout << "Input volume of freight (m^3)" << endl;
		cin >> volume;
		send(client.Connection, freight_type, sizeof(freight_type), NULL);
		send(client.Connection, (char*)volume, sizeof(int), NULL);
		cout << "1\n";
	}

	system("pause");
	return 0;
}
