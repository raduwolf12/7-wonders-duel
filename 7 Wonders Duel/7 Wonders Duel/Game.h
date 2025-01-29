#ifndef GAME_H
#define GAME_H


#include"MainMenuState.h"
#include <map>
#include <memory>
#include <stack>
#include <vector>
//#include "SettingsWindow.h"

class Game
{
private:
	// Variables
	sf::RenderWindow* window;                ///< Pointer to the main window
	sf::Event sfEvent;                       ///< Event variable for SFML events
	std::vector<sf::VideoMode> videoMode;    ///< Supported video modes
	sf::ContextSettings windowSettings;      ///< Window settings
	bool fullscreen;                         ///< Fullscreen mode flag

	sf::Clock dtClock;                       ///< Clock for delta time calculation
	float dt;                                ///< Delta time

	std::stack<State*> states;               ///< Stack of game states
	SettingsPanel settingsPanel;			 //// Add SettingsPanel instance


	std::map<std::string, int> supportedKeys; ///< Supported keys mapping

	//std::unique_ptr<SettingsWindow> settingsWindow;


	//Initialization
	void initVariables();
	void initWindow();
	void initKeys();
	void iniStates();


public:

	//Constructors/Destructors
	Game();
	virtual ~Game();

	// Regular
	void endApplication();

	//Functions

	// Update functions
	void updateDt();
	void updateSFMLEvents();
	void update();

	// Render functions
	void render();

	//Core
	void run();
	void saveWindowSettings(); // Declare the save method

};

#endif