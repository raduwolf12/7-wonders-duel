#include "MainMenuState.h"

void MainMenuState::initVariables()
{
}

void MainMenuState::initBackground()
{
	this->background.setSize(
		sf::Vector2f
		(
			static_cast<float>(this->window->getSize().x), 
			static_cast<float>(this->window->getSize().y)
		)
	);

	if (!this->texture.loadFromFile("Images/backgroung.png"))
	{
		throw "ERROR::MAINMANUSTATE::FAILED_TO_LOAD_BACKGROUND_TEXTURE";
	}
	this->texture.setSmooth(true);
	this->background.setTexture(&this->texture);
}

void MainMenuState::initFonts()
{
	if (!this->font.loadFromFile("Fonts/arial.ttf"))
	{
		throw "ERROR::MAINMENUSTATE::COULD NOT LOAD FONT";
	}

	

}

void MainMenuState::initKeyBinds()
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

	this->keyBinds["CLOSE"] = this->supportedKeys->at("Escape");
	this->keyBinds["MOVE_LEFT"] = this->supportedKeys->at("A");
	this->keyBinds["MOVE_RIGHT"] = this->supportedKeys->at("D");
	this->keyBinds["MOVE_UP"] = this->supportedKeys->at("W");
	this->keyBinds["MOVE_DOWN"] = this->supportedKeys->at("S");
}

void MainMenuState::initButtons()
{
	this->buttons["GAME_STATE"] = new Button(100, 200, 150, 50,
		&this->font, "New Game",
		sf::Color(70, 70, 70, 200), 
		sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));

	this->buttons["SETTINGS"] = new Button(100, 275, 150, 50,
		&this->font, "Enable bot",
		sf::Color(70, 70, 70, 200),
		sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));


	this->buttons["SETTINGS2"] = new Button(100, 350, 150, 50,
		&this->font, "Dissable bot",
		sf::Color(70, 70, 70, 200),
		sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));


	this->buttons["EXIT_STATE"] = new Button(100, 420, 150, 50,
		&this->font, "Exit",
		sf::Color(70, 70, 70, 200), 
		sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
}

void MainMenuState::initMusic()
{
	this->music.openFromFile("Music.ogg");
	music.play();
	
}

MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	:State(window, supportedKeys,states )
{
	this->initVariables();
	this->initBackground();
	this->initFonts();
	this->initKeyBinds();
	this->initButtons();
	this->initMusic();

	
	//this->background.setFillColor(sf::Color::Green);
	
}

MainMenuState::~MainMenuState()
{
	auto it =  this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
}



void MainMenuState::updateInput(const float& dt)
{
	

	
}

void MainMenuState::updateButtons()
{
	/*Updates all the buttons in the state and handles their functionality*/
	for (auto& it : this->buttons)
	{
	it.second->update(this->mousePosView);
	}

	//New game
	if (this->buttons["GAME_STATE"]->isPressed())
	{
		this->music.stop();
		this->states->push(new GameState(this->window, this->supportedKeys, this->states, botIsEnabled));

	}
	//Enable bot
	if (this->buttons["SETTINGS"]->isPressed())
	{
		botIsEnabled=true;

		this->buttons["BOTSTATE"] = new Button(1500, 420, 150, 50,
			&this->font, "BOT ENABLED",
			sf::Color(70, 70, 70, 200),
			sf::Color(70, 70, 70, 200), sf::Color(70, 70, 70, 200));

		std::cout << "bot is enabled";
	}
	if (this->buttons["SETTINGS2"]->isPressed())
	{
		botIsEnabled = false;
		this->buttons["BOTSTATE"] = new Button(1500, 420, 150, 50,
			&this->font, "BOT DISSABLED",
			sf::Color(70, 70, 70, 200),
			sf::Color(70, 70, 70, 200), sf::Color(70, 70, 70, 200));
		std::cout << "bot is dissabled";
	}

	//QUit the game
	if (this->buttons["EXIT_STATE"]->isPressed())
	{
		this->endState();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
	{
		this->gameOverState();
		if (this->GetGameOver() == true)
		{
			this->states->push(new GameOverState(this->window, this->supportedKeys, this->states));
		}
	}

	//this->gamestate_btn->update(this->mousePosView);
}

void MainMenuState::update(const float& dt)
{
	this->updateMousePosition();
	this->updateInput(dt);
	this->updateButtons();
	
}

void MainMenuState::renderButtons(sf::RenderTarget* target)
{
	
	//this->gamestate_btn->render(target);


	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}
}


void MainMenuState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	target->draw(this->background);

	this->renderButtons(target);
}
