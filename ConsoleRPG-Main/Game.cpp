#include "Game.h";
//Main Game Logic
void mainGame(Scene& playground, Character& player)
{
	char gameChoice;
	std::string filename;
	std::vector<Weapon> temp;
	do
	{
		std::cout << "Enmies:" << std::endl;
		playground.viewAllStat();
		std::cout << "You: " << std::endl;
		player.viewStat();
		std::cout << std::endl;
		gameChoice = getGameChoice();
		std::cout << std::string(100, '\n') << std::endl;
		switch (gameChoice)
		{
		case 'A':
			int enmiesIndex;
			do
			{
				std::cout << "Please enter enimey No. [1-" << playground.getEnmiesTotal() << "]: ";
				std::cin >> enmiesIndex;
				enmiesIndex -= 1;
				if (enmiesIndex < 1 && enmiesIndex > playground.getEnmiesTotal())
				{
					std::cout << "Please Try Again" << std::endl;
				}
			} while (enmiesIndex < 0 && enmiesIndex > playground.getEnmiesTotal());
			playground.attackOneEnmies(enmiesIndex, player.attack());
			player.takeDamage(playground.giveDamage(enmiesIndex));
			break;
		case 'S':
			playground.attackAllEnmies(player.attack() / playground.getEnmiesTotal());
			player.takeDamage(playground.giveDamage() / playground.getEnmiesTotal());
			break;
		case 'L':
			std::cout << "What is your weapon file name? [*+*-W.wfg]: ";
			std::cin >> filename;
			temp = loadWeapon(filename);
			player.addWeapon(temp.at(0), temp.at(1));
			break;
		case 'U':
			player.unloadWeapon();
			std::cout << "Unloaded weapon." << std::endl;
			break;
		default:
			progressSaver(playground, player);
			exit(0);
			break;
		}
	} while (playground.isEnmiesAlive() && player.isCharacterAlive());
}