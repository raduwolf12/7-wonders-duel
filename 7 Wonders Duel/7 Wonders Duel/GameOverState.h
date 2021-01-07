#pragma once
#include "State.h"
#include "Button.h"
class GameOverState :
	public State
{
	//Variables
	sf::RectangleShape background;
	sf::Font font;

	sf::Texture texture;

	sf::Music music;



	std::map<std::string, Button*> buttons;
	//Button* gamestate_btn;

	//Functions
	void initVariables();
	void initBackground();
	void initFonts();
	void initKeyBinds();
	void initButtons();
	void initWinnerTextBox(std::string winner);
	void initMusic();

public:
	GameOverState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
	GameOverState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states, std::string winner);
	virtual ~GameOverState();

	//Functions


	void updateInput(const float& dt);
	void updateButtons();
	void update(const float& dt);
	void renderButtons(sf::RenderTarget* target = nullptr);
	void render(sf::RenderTarget* target = nullptr);

};

