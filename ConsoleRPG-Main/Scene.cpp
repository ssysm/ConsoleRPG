#include "Scene.h"

Scene::Scene()
{
	this->enmies.push_back(Character("E1", 400, 10, 2));
	this->enmies.push_back(Character("E2", 400, 10, 2));
	this->enmies.push_back(Character("E3", 400, 10, 2));
	this->enmies.push_back(Character("E4", 400, 10, 2));
	this->enmies.push_back(Character("E5", 400, 10, 2));

}

Scene::Scene(std::vector<Character>& enmies)
{
	this->enmies = enmies;
}

std::vector<Character>* Scene::getEnmies()
{
	return &this->enmies;
}

void Scene::addEnmies(Character enimy)
{
	this->enmies.push_back(enimy);
}

void Scene::attackAllEnmies(int damage)
{
	for (Character &c : this->enmies) {
		c.takeDamage(damage);
	}
}

void Scene::attackOneEnmies(int index, int damage)
{
	this->enmies.at(index).takeDamage(damage);
}

void Scene::viewAllStat()
{
	for (Character &c : this->enmies) 
	{
		c.viewStat();
	}
}

void Scene::viewOneStat(int index)
{
	this->enmies.at(index).viewStat();
}

int Scene::getEnmiesTotal()
{
	return this->enmies.size();
}

bool Scene::isEnmiesAlive()
{
	for (Character& c : this->enmies) {
		if (!c.isCharacterAlive()) {
			return false;
		}
	}
	return true;
}
