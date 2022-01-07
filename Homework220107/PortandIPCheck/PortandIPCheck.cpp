#include <iostream>
#include <conio.h>
#include <string>

#include <WinSock2.h>
#include <Windows.h>
#include <WS2tcpip.h> 

#pragma comment(lib, "ws2_32")


int main()
{
	//공백들어오면 공백 지우기.
	// 0~255 넘어가면 다시.
	// 4자리 아니면 다시.
	// 포트넣으면 포트도 ㄱ채워지게.
	// 포트없으면 포트도 받기.
	// 
	// IP / PORT 입력.

	std::string IPStr = "";
	std::string PortStr = "";

	while (true)
	{
		std::cout << "IP를 입력해주세요." << std::endl;
		std::string str;
		std::cin >> str;

		//공백제거
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == ' ')
			{
				str.erase(i);
			}
		}

	
		//0~255 체크
		bool IsNumValid = true;
		// '.'이 3개들어왓는지 체크
		bool IsIPv4Valid = true;
		
		int pointCount = 0;
		int start = 0;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == '.')
			{
				std::string numStr = str.substr(start, i);
				if (stoi(numStr) > 255)
				{
					IsNumValid = false;
					break;
				}

				pointCount++;
			}
		}
		
		if (pointCount != 3)
			IsIPv4Valid = false;

		if (!IsNumValid || !IsIPv4Valid)
		{
			std::cout << "IPv4 주소체계가아닙니다." << std::endl;
			continue;
		}
		
		int pivot = str.find(':');
		if (pivot == -1) // 포트번호입력안한경우
		{
			IPStr = str;
			std::cout << "포트 번호를 입력해주세요." << std::endl;
			std::cin >> PortStr;
		}
		else			 // 포트번호 입력한경우.
		{
			IPStr = str.substr(0, pivot);
			PortStr = str.substr(pivot + 1);
		}

		break;
	}
	std::cout << "IP 번호 \"" << IPStr << "\", PORT 번호 \"" << PortStr << "\"에 접속합니다." << std::endl;

}