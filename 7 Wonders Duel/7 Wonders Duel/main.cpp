#include"Game.h"
#include <iostream>
#include"..\Logging\Logging.h"
#include"GameLogic.h"
int main()
{
	std::ofstream logFile("log.log", std::ios::app);

	Logging logger(logFile, Logging::Level::Info);
	logger.Log("Application started!", Logging::Level::Info);

	std::string gameType;
	std::cout << "Choose what game you want to start \n Press 0 for basic! \n Press 1 for advanced!";
	std::cin >> gameType;
	while (true) {
		if (gameType == "0")
		{

			GameLogic g;
			g.RunGame();
			break;

		}
		else if (gameType == "1")
		{
			Game game;
			game.run();
			break;
		}
		else
		{
			std::cout << "Invalid option!\nTry again.";
			gameType.clear();
				std::cin >> gameType;

		}
	}
	return 0;

}