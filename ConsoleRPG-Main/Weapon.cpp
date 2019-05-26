#include "Weapon.h"

Weapon::Weapon()
{
}

Weapon::Weapon(int damage, std::string name)
{
	this->damage = damage;
	this->name = name;
}

std::string Weapon::getName()
{
	return this->name;
}

int Weapon::getDamage()
{
	return this->damage;
}
