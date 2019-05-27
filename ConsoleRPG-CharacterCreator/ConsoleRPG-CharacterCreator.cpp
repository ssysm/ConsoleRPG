// ConsoleRPG-CharacterCreator.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <fstream>

using namespace std;

//Function Proto
void CreateCharacter();
void CreateWeapon();

int main()
{
	char select;
	do
	{
		cout << string(100, '\n');
		cout << "Welcome to ConsoleRPG Character/Weapon Maker!" << endl;
		cout << "Please Choose a Letter.: [W]eapon/[C]haracter/[Q]uit: ";
		cin >> select;
		if (select != 'W' && select != 'C' && select != 'Q') {
			cout << "Please Try Again." << endl;
		}
	} while (select != 'W' && select != 'C' && select != 'Q');

	switch (select)
	{
	case 'W':
		CreateWeapon();
		break;
	case 'C':
		CreateCharacter();
		break;
	case 'Q':
		exit(0);
	default:
		break;
	}
}

void CreateCharacter()
{
	cout << string(100, '\n');
	ofstream characterConfig;
	int health, strength, defense;
	string name;

	cout << "Enter A Name: ";
	cin >> name;
	cout << "Enter Health Level: ";
	cin >> health;
	cout << "Enter Max Strength: ";
	cin >> strength;
	cout << "Enter Defense Point: ";
	cin >> defense;

	characterConfig.open(name + "-C.cfg");
	characterConfig << name << ' '
		<< health <<  ' '
		<< strength << ' '
		<< defense;
	characterConfig.close();

	cout << "Your Character File has been saved to " << name + "-C.cfg" << endl
		<< "Press any key to go back to home screen..." << endl << endl;
	getchar();
	main();
}

void CreateWeapon() 
{
	cout << string(100, '\n');
	ofstream weaponConfig;
	int damageLF, defenseLF;
	int damageRT, defenseRT;
	string nameLF,nameRT;

	cout << "Enter A Name for LF Hand: ";
	cin >> nameLF;
	cout << "Enter damage point LF Hand: ";
	cin >> damageLF;
	cout << "Enter defense point LF Hand: ";
	cin >> defenseLF;

	cout << endl;

	cout << "Enter A Name for RT Hand: ";
	cin >> nameRT;
	cout << "Enter damage point RT Hand: ";
	cin >> damageRT;
	cout << "Enter defense point RT Hand: ";
	cin >> defenseRT;

	weaponConfig.open(nameLF  + '+' + nameRT + "-W.wfg");
	weaponConfig << nameLF << ' '
		<< damageLF << ' '
		<< defenseLF << endl
		<< nameRT << ' '
		<< damageRT << ' '
		<< defenseRT;
	weaponConfig.close();
	cout << "Your Weapon File has been saved to " << nameLF + '+' + nameRT + "-W.wfg" << endl
		<< "Press any key to go back to home screen..." << endl << endl;
	getchar();
	main();
}