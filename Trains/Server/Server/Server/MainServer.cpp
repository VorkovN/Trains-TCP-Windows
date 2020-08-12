#pragma comment(lib, "ws2_32.lib")
#include <winsock2.h>
#include <iostream>
#include <set>
#include "Server.h"
#include "Controller.h"
#include "Station.h"
#pragma warning(disable: 4996)

using namespace std;

Server server;
Controller controller;

void ClientHandler(SOCKET current_socket) {

	char from[256];
	char to[256];
	char freight_type[256];
	int volume;
	while (true) {
		if (recv(current_socket, from, sizeof(from), NULL) > 0
			&& recv(current_socket, to, sizeof(to), NULL) > 0
			&& recv(current_socket, freight_type, sizeof(freight_type), NULL) > 0
			&& recv(current_socket, (char*)&volume, sizeof(int), NULL) > 0) {

			controller.chooseTrain(from, to, freight_type, volume);
		}
	}
}

int main(int argc, char* argv[]) {




	while (true) {
		SOCKET newConnection = accept(server.sListen, (SOCKADDR*)&server.addr, &server.sizeofaddr);

		if (newConnection == 0) {
			cout << "Error #2\n";
		}
		else {
			cout << "Client Connected!\n";
			char msg[64] = "Hello. You can order transportation your freight";
			send(newConnection, msg, sizeof(msg), NULL);

			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ClientHandler, (LPVOID)(newConnection), NULL, NULL);
			cout << "3\n";
		}

	}


	system("pause");
	return 0;
}