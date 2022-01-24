
#include <iostream>
#include <mutex>
#include <WinSock2.h>
#include <Windows.h>
#include <WS2tcpip.h>
#include <conio.h>

#pragma comment (lib, "ws2_32")

std::mutex Lock;

std::thread RecvThread;

bool Check = true;

char gBuffer[1024] = { 0, };
int pivot = 0;
void RecvFunc(SOCKET _SessionSocket)
{
	while (Check)
	{
		char Buffer[1024];

		int Result = recv(_SessionSocket, Buffer, sizeof(Buffer), 0);

		if (SOCKET_ERROR == Result)
		{
			return;
		}

		for (int i = 0; i < 1024; i++)
		{
			if (Buffer[i] == 0)
			{
				for (int j = 0; j < i; j++)
				{
					gBuffer[pivot] = Buffer[j];
					pivot += i;
				}
				break;
			}
		}
		if (gBuffer[pivot - 1] == '!' && gBuffer[pivot - 2] == '!')
		{
			std::cout << gBuffer << std::endl;
			pivot = 0;
			memset(gBuffer,0,1024);
		}
	}
}

int main()
{
	WSADATA wsa;

	if (0 != WSAStartup(MAKEWORD(2, 2), &wsa))
	{
		std::cout << "WSAStartup Error" << std::endl;
	}

	SOCKET SessionSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (INVALID_SOCKET == SessionSocket)
	{
		return 0;
	}

	std::cout << "IP주소를 입력해주세요" << std::endl;
	std::string Ip;
	std::string Port;
	std::cin >> Ip;

	if ("Q" == Ip
		|| "q" == Ip)
	{
		Ip = "127.0.0.1";
	}
	else if ("w" == Ip
		|| "W" == Ip)
	{
		Ip = "58.150.30.210";
	}

	SOCKADDR_IN Add = { 0, };
	Add.sin_family = AF_INET;
	Add.sin_port = htons(30001);
	if (SOCKET_ERROR == inet_pton(AF_INET, Ip.c_str(), &Add.sin_addr))
	{
		return 0;
	}
	int Len = sizeof(SOCKADDR_IN);

	if (SOCKET_ERROR == connect(SessionSocket, (const sockaddr*)&Add, Len))
	{
		return 0;
	}

	std::cout << "커넥트 성공." << std::endl;

	RecvThread = std::thread(RecvFunc, SessionSocket);

	while (true)
	{
		std::string In;

		std::cin >> In;

		if (In == "q" || In == "Q")
		{
			closesocket(SessionSocket);
			Check = false;
			RecvThread.join();
			Sleep(1);
			return 0;
		}

		char Buffer[1024] = { "" };

		Sleep(1);

		memcpy_s(Buffer, sizeof(Buffer), In.c_str(), In.size());

		int Result = send(SessionSocket, Buffer, sizeof(Buffer), 0);
	}

	_getch();
}
