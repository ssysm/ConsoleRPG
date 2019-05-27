#pragma once
#include <vector>
#include "Character.h"
#include "Weapon.h"
class Scene
{
private:
	std::vector<Character> enmies;
	std::string name;

public:
	Scene();
	Scene(std::vector<Character>& enmies);

	/** Scene Control */
	std::vector<Character>* getEnmies();
	void addEnmies(Character enimy);
	void attackAllEnmies(int damage);
	void attackOneEnmies(int index,int damage);

	/** Enmies Control */
	int giveDamage(int index);
	int giveDamage();

	/** Stat Control */
	void viewAllStat();
	void viewOneStat(int index);
	int getEnmiesTotal();
	bool isEnmiesAlive();
};

