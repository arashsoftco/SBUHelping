//

#include "stdafx.h"

#include <iostream>
#include <windows.h>   

using namespace std;   

#include <stdio.h>


	int main()
	{
		for (;;) {

			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		
			for (int k = 1; k < 255; k++)
			{
			
				SetConsoleTextAttribute(hConsole, k);
				cout << k << " We are in AbbasPour Not SBU ... :)" << endl;
				cout <<  endl;
				Sleep(80);
			}

		}
	}

	





