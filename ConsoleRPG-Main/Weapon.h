#pragma once
#include <String>
class Weapon
{
private:
	int damage, defense;
	std::string name;
public:
	Weapon();
	Weapon(std::string name,int damage, int defense);

	std::string getName();
	int getDamage();
	int getDefense();
};

