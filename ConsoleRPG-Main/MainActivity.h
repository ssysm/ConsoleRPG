#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <ctime>
#include "Character.h"
#include "Scene.h"
#include "Weapon.h"

Scene loadScene(std::string filename);
std::vector<Weapon> loadWeapon(std::string filename);
Character initCharacter();
Character loadCharacter(std::string filename);
Scene initScene();

void mainGame(Scene& playground, Character& player);
char getGameChoice();
void newGame(bool loadScene);
void progressSaver(Scene playground, Character player);
void continueGame();