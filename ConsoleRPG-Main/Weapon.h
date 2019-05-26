#pragma once
#include <String>
class Weapon
{
private:
	int damage;
	std::string name;
public:
	Weapon();
	Weapon(int damage, std::string name);

	std::string getName();
	int getDamage();
};

