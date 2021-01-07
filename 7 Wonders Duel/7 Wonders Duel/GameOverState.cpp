#include "GameOverState.h"
#include"MainMenuState.h"
void GameOverState::initVariables()
{
}

void GameOverState::initBackground()
{
	this->background.setSize(
		sf::Vector2f
		(
			static_cast<float>(this->window->getSize().x),
			static_cast<float>(this->window->getSize().y)
		)
	);

	if (!this->texture.loadFromFile("Images/gameover.png"))
	{
		throw "ERROR::MAINMANUSTATE::FAILED_TO_LOAD_BACKGROUND_TEXTURE";
	}
	this->texture.setSmooth(true);
	this->background.setTexture(&this->texture);
}

void GameOverState::initFonts()
{
	if (!this->font.loadFromFile("Fonts/arial.ttf"))
	{
		throw "ERROR::GameOverState::COULD NOT LOAD FONT";
	}



}

void GameOverState::initKeyBinds()
{
	std::ifstream ifs("Config/gamestate_keybinds.ini");

	if (ifs.is_open())
	{
		std::string key = "";
		std::string key2 = "";

		while (ifs >> key >> key2)
		{
			this->keyBinds[key] = this->supportedKeys->at(key2);
		}
	}
	ifs.close();

	
}
void GameOverState::initWinnerTextBox(std::string winner)
{
	this->buttons["WINNER"] = new Button(800, 150, 150, 50,
		&this->font, winner,
		sf::Color(0, 0, 0, 200),
		sf::Color(0, 0, 0, 200), sf::Color(0, 0, 0, 200));
}

void GameOverState::initButtons()
{
	this->buttons["EXIT_STATE"] = new Button(1200, 350, 150, 50,
		&this->font, "Exit",
		sf::Color(70, 70, 70, 200),
		sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
}

void GameOverState::initMusic()
{
	this->music.openFromFile("Music.ogg");
	music.play();

}

GameOverState::GameOverState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	:State(window, supportedKeys, states)
{
	this->initVariables();
	this->initBackground();
	this->initFonts();
	this->initKeyBinds();
	this->initButtons();
	this->initMusic();


	//this->background.setFillColor(sf::Color::Green);

}

GameOverState::GameOverState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states, std::string winner)
	:State(window, supportedKeys, states)
{
	this->initVariables();
	this->initBackground();
	this->initFonts();
	this->initKeyBinds();
	this->initButtons();
	this->initMusic();
	this->initWinnerTextBox(winner);

}

GameOverState::~GameOverState()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
}



void GameOverState::updateInput(const float& dt)
{



}

void GameOverState::updateButtons()
{
	/*Updates all the buttons in the state and handles their functionality*/
	for (auto& it : this->buttons)
	{
		it.second->update(this->mousePosView);
	}

	//QUit the game
	if (this->buttons["EXIT_STATE"]->isPressed())
	{
		this->states->pop();
		this->states->pop();
		this->states->top()->endState();
	}
	
}

void GameOverState::update(const float& dt)
{
	this->updateMousePosition();
	this->updateInput(dt);
	this->updateButtons();

}

void GameOverState::renderButtons(sf::RenderTarget* target)
{
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}
}


void GameOverState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	target->draw(this->background);

	this->renderButtons(target);
}
