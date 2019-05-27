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
	Character(std::string name, int health, int strength, int defense, Weapon lh, Weapon rh);

	/** Weapon Control */
	void addLeftHandWeapon(Weapon lh);
	void addRightHandWeapon(Weapon rh);
	void addWeapon(Weapon lh, Weapon rh);
	void unloadRightHandWeapon();
	void unloadLeftHandWeapon();
	void unloadWeapon();

	/** Game Control */
	void takeDamage(int hit);
	int attack();
	bool isCharacterAlive();

	/** Stat Tools*/
	void viewStat();
};

