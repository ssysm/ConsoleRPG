#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include "Character.h"
#include "Scene.h"
#include "Weapon.h"

Scene loadScene();
std::vector<Weapon> loadWeapon(std::string filename);
Character initCharacter();
Character loadCharacter(std::string filename);

char getGameChoice();
void newGame(bool loadScene);