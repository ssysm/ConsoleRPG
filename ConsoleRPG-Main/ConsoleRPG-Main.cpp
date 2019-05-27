// ConsoleRPG-Main.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include <Windows.h>

#pragma comment(lib, "user32")

#include "Character.h";
#include "Weapon.h";
#include "Scene.h";
#include "MainActivity.h";

using namespace std;

int main()
{
	srand(time(nullptr));
	//::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
	
	Character player("John", 200, 100, 15);
	Scene playfield;
	
	char gamemode;
	do
	{
		cout << string(100, '\n');
		cout << "Welcome to ConsoleRPG."
			<< "You have following choice: " << endl
			<< "[N]ew Game with default profile" << endl
			<< "[C]ontinue a game " << endl
			<< "[L]oad a Game Scene file" << endl
			<< "[Q]uit" << endl
			<< "Your Choice [(Q)/N/C/L]:  ";
		cin >> gamemode;
		if (gamemode != 'N' && gamemode != 'C' && gamemode != 'L' && gamemode != 'Q') 
		{
			cout << "Please Try Again" << endl;
		}
	} while (gamemode != 'N' && gamemode != 'C' && gamemode != 'L' && gamemode != 'Q');
	
	switch (gamemode)
	{
	case 'N':
		newGame();
		break;
	default:
		exit(0);
		break;
	}

	getchar();
}