/**
	Shengming Yuan Pd.10
	This is a prototype of an RPG. You will fight a series of battles against opponents of your choice.

	I have attempted the following features:
	- Character/Weapon/Scene Create of your own choice.
	- Load/Unload Weapon(Inventory) on the fly.
*/

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
	::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);

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
		newGame(false);
		break;
	case 'L':
		newGame(true);
		break;
	default:
		exit(0);
		break;
	}

	getchar();
}