#include "Character.h"
#include <iostream>

//Default
Character::Character()
{
	this->name = "Unknown Char.";
	this->health = 0;
	this->strength = 0;
	this->defense = 0;
}

//Character build class
Character::Character(
	std::string name, int health, int strength, int defense,
	Weapon lh, Weapon rh
)
{
	this->name = name;
	this->health = health;
	this->strength = strength;
	this->defense = defense;
	this->leftHand = lh;
	this->rightHand = rh;
}

//Character build class without weapon
Character::Character(std::string name, int health, int strength, int defense)
{
	this->name = name;
	this->health = health;
	this->strength = strength;
	this->defense = defense;
}

//Add weapon to left hand
void Character::addLeftHandWeapon(Weapon lh)
{
	this->leftHand = lh;
}

//Add weapon to right hand
void Character::addRightHandWeapon(Weapon rh)
{
	this->rightHand = rh;
}

//Add weapon to both hand
void Character::addWeapon(Weapon lh, Weapon rh)
{
	this->leftHand = lh;
	this->rightHand = rh;
}

//Unload weapon from right hand
void Character::unloadRightHandWeapon()
{
	this->rightHand = Weapon();
}

//Unload weapon from left hand
void Character::unloadLeftHandWeapon()
{
	this->leftHand = Weapon();
}

//Unload both weapon
void Character::unloadWeapon()
{
	this->rightHand = Weapon();
	this->leftHand = Weapon();
}

//Let character take damge
void Character::takeDamage(int hit)
{
	int damage;
	int totalDefnsePt = this->defense + this->leftHand.getDefense() + this->rightHand.getDefense();
	if (hit - totalDefnsePt <= 0)
	{
		damage = 0;
	}
	else
	{
		damage = hit - totalDefnsePt;
	}

	std::cout << name << " took " << damage << " damage" << std::endl;
	health -= damage;
}

//Attack a character and give a total attack pt
int Character::attack()
{
	int weaponAddonPt = this->leftHand.getDamage() + this->rightHand.getDamage();
	int playerAttack = rand() % (strength + 1);
	if (rand() % 100 == 99) {
		playerAttack *= 2;
		std::cout << "CRITICAL HIT!" << std::endl;
	}
	else if (rand() % 100 == 0) {
		std::cout << name << " missed!" << std::endl;
		playerAttack = 0;
	}

	std::cout << name << " dealt " << playerAttack+weaponAddonPt << " damage" << std::endl;
	return playerAttack + weaponAddonPt;
}

bool Character::isCharacterAlive()
{
	if (health <= 0) 
	{
		return false;
	}
	else 
	{
		return true;
	}
}

void Character::viewStat()
{
	int totalDefnsePt = this->defense + this->leftHand.getDefense() + this->rightHand.getDefense();
	std::cout << std::endl
		<< "Name: " << name << "; Health: " << health << ";" << std::endl
		<< "Strength: " << strength << "; Defense: " << totalDefnsePt << std::endl
		<< "LF Weapon: " << leftHand.getName() << "; RH Weapon: " << rightHand.getName() << std::endl;
}
