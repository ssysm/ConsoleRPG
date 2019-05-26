#pragma once

#include <String>
#include "Weapon.h"

class Character
{
private:
	int health, strength, defense;
	std::string name;
	Weapon leftHand, rightHand;

public:
	Character();
	Character(std::string name, int health, int strength, int defense);
};

