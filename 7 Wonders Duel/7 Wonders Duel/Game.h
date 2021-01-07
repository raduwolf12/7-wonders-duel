#ifndef GAME_H
#define GAME_H


#include"MainMenuState.h"


class Game
{
private:
	//Varibles
	sf::RenderWindow *window;
	sf::Event sfEvent;
	std::vector<sf::VideoMode> videoMode;
	sf::ContextSettings windowSettings;
	bool fullscreen ;



	sf::Clock dtClock;
	float dt;

	std::stack<State*> states;

	
	std::map<std::string, int> supportedKeys;

	//Initialization
	void initVariables();
	void initWindow();
	void initKeys();
	void iniStates();


public:
	//Constructors/Destructors
	Game();
	virtual ~Game();

	//Reguar
	void endApplication();

	//Functions

	//Update
	void updateDt();
	void updateSFMLEvents();
	void update();

	//Render
	void render();

	//Core
	void run();
};

#endif