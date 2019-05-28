#include "MainActivity.h"

//Load a Scene from a file and return scene
Scene loadScene(std::string filename)
{
	std::vector<Character> enmies;
	int health,strength, defense;
	std::string name;
	std::ifstream sceneFile(filename);
	if (sceneFile.is_open())
	{
		while (sceneFile >> name >> health >> defense >> strength)
		{
			enmies.push_back(Character(name, health, strength, defense));
		}
	}
	return Scene(enmies);
}

//Load a Character from a file and return Character
Character loadCharacter(std::string filename)
{
	Character savedChar;
	int health, strength, defense;
	std::string name;
	std::ifstream characterFile(filename);
	if (characterFile.is_open())
	{
		characterFile >> name >> health >> strength >> defense;
		savedChar = Character(name, health, strength, defense);
	}
	return savedChar;
}

//Load a Weapon from a file and return Weapon vector
std::vector<Weapon> loadWeapon(std::string filename) 
{
	std::vector<Weapon> weapons;
	int damage, defense;
	std::string name;
	std::ifstream weaponFile(filename);
	if (weaponFile.is_open())
	{
		while (weaponFile >> name >> damage >> defense)
		{
			weapons.push_back(Weapon(name, damage, defense));
		}
	}
	return weapons;
}

//Init Player Character
Character initCharacter() {

	Character player;

	char loadCharOption;
	std::cout << std::string(100, '\n')
		<< "Do you want to load up your character build? [(N)/Y]: ";
	std::cin >> loadCharOption;
	if (loadCharOption == 'Y')
	{
		std::string filename;
		std::cout << "What is your file name? [*-C.cfg]: ";
		std::cin >> filename;
		player = loadCharacter(filename);
	}
	else
	{
		player = Character("Player", 200, 100, 5);
	}

	std::cout << "Do you want to load up your weapon for your player? [(N)/Y]: ";
	std::cin >> loadCharOption;
	if (loadCharOption == 'Y')
	{
		std::string filename;
		std::cout << "What is your file name? [*+*-W.wfg]: ";
		std::cin >> filename;
		std::vector<Weapon> temp = loadWeapon(filename);
		player.addWeapon(temp.at(0), temp.at(1));
	}

	return player;
}

//Init Playground(Scene)
Scene initScene()
{
	std::string filename;
	std::cout << "Please enter the Sence File [*.sfg]: ";
	std::cin >> filename;
	return loadScene(filename);
}

//Get Game choice from player each round(helper)
char getGameChoice() {
	char gameChoice;
	do
	{
		std::cout << "You Have Following Choices: " << std::endl
			<< "[A]ttack a single Enmies" << std::endl
			<< "[S]mash all enmies." << std::endl
			<< "[L]oad weapon." << std::endl
			<< "[U]nload weapon." << std::endl
			<< "[R]un away. [A/S/L/U/R]: ";
		std::cin >> gameChoice;
		if (gameChoice != 'A' && gameChoice != 'S' && gameChoice != 'L' && gameChoice != 'U' && gameChoice != 'R')
		{
			std::cout << "Please Try Again" << std::endl;
		}
	} while (gameChoice != 'A' && gameChoice != 'S' && gameChoice != 'L' && gameChoice != 'U' && gameChoice != 'R');
	return gameChoice;
}

//Determine if is a new game or not
void newGame(bool loadSceneFile) 
{
	Scene playground;
	Character player;
	player = initCharacter();
	//Start Game
	if (loadSceneFile) 
	{
		playground = initScene();
	}
	mainGame(playground, player);
}

//Save Progesss as game goes
void progressSaver(Scene playground, Character player)
{
	std::ofstream progressFile;
	progressFile.open("progress.pfg");
	progressFile << player.getName() << ' ' << player.getHealth() << ' ' << player.getDefense() << ' ' << player.getStrength() << std::endl;
	for (Character& c : *playground.getEnmies()) 
	{
		progressFile << c.getName() << ' ' << c.getHealth() << ' ' << c.getDefense() << ' ' << c.getStrength() << std::endl;
	}
	progressFile.close();
}

void continueGame()
{

}
