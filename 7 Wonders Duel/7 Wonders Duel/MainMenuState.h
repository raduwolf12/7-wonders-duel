#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include "GameState.h"
#include "GameOverState.h"
#include"Button.h"
//#include "SettingsWindow.h"
#include "SettingsPanel.h"

class MainMenuState :
	public State
{
private:
	//Variables
	sf::RectangleShape background;
	sf::Font font;

	sf::Texture texture;

	sf::Music music;

	bool botIsEnabled = false;


	std::map<std::string, Button*> buttons;
	//Button* gamestate_btn;

	//std::unique_ptr<SettingsWindow> settingsWindow;
	SettingsPanel settingsPanel;



	//Functions
	void initVariables();
	void initBackground();
	void initFonts();
	void initKeyBinds();
	void initButtons();
	void initMusic();
	void applySettingsChanges();

public:
	MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
	virtual ~MainMenuState();

	//Functions


	void updateInput(const float& dt);
	void updateButtons();
	void update(const float& dt);
	void renderButtons(sf::RenderTarget* target = nullptr);
	void render(sf::RenderTarget* target = nullptr);

};


#endif 
