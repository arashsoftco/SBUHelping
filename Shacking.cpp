
#include "stdafx.h"

#include <iostream>
#include <windows.h>   

using namespace std;

#include <stdio.h>



		int main()
		{
			HWND consoleWindow = GetConsoleWindow();

	
			SetWindowPos(consoleWindow, 0, 49, 58, 0, 0, SWP_NOSIZE | SWP_NOZORDER);


			Sleep(2000);

			cout << "             Arashsoft EAI   ";
			while (true)
			{

for (size_t i = 58; i < 68; i++)
			{
				SetWindowPos(consoleWindow, 0, i, i, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

				Sleep(10);
			}

			for (size_t i = 68; i >58; i--)
			{
				SetWindowPos(consoleWindow, 0, i, i, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

				Sleep(10);
			}
			}
			

		system("pause");
			return 0;


	
		}
