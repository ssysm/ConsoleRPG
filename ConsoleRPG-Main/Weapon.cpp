#include "Weapon.h"

Weapon::Weapon()
{
	this->damage = 0;
	this->name = "None";
	this->defense = 0;
}

Weapon::Weapon(std::string name,int damage, int defense)
{
	this->damage = damage;
	this->name = name;
	this->defense = defense;
}

std::string Weapon::getName()
{
	return this->name;
}

int Weapon::getDamage()
{
	return this->damage;
}

int Weapon::getDefense()
{
	return this->defense;
}
