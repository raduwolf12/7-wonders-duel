#include "GameState.h"
#include"Game.h"
using namespace std::chrono_literals;

void GameState::initTokens()
{
	//victory tokens
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::ifstream tokenName("Utils/TokenNames.txt");
	std::ifstream tokenPositionFile("Utils/TokenPosition.txt");

	if (tokenName.is_open()) {
		std::string line;
		while (getline(tokenName, line)) {

			this->progressTokensName.push_back(line.c_str());

		}
		tokenName.close();
	}
	std::shuffle(this->progressTokensName.begin(), this->progressTokensName.end(), std::default_random_engine(seed));

	for (int i = 0; i < progressTokensName.size(); i++)
	{

		int x, y;
		tokenPositionFile >> x >> y;
		if (i < 6)
		{
			progressTokens.push_back(new CardRender(x, y, &this->textures[this->progressTokensName[i]], sf::Color(0, 0, 0, 0),
				sf::Color(10, 10, 10, 200), sf::Color(0, 0, 0, 0), this->progressTokensName[i]));
		}
		else
		{
			progressTokens.push_back(new CardRender(0, 0, &this->textures[this->progressTokensName[i]], sf::Color(0, 0, 0, 0),
				sf::Color(10, 10, 10, 200), sf::Color(0, 0, 0, 0), this->progressTokensName[i]));
		}

	}
	//war tokens

	std::ifstream warTokenName("Utils/WarTokenNames.txt");
	std::ifstream warTokenPositionFile("Utils/WarTokenPosition.txt");

	if (warTokenName.is_open()) {
		std::string line;
		while (getline(warTokenName, line)) {

			this->warTokensNames.push_back(line.c_str());

		}
		warTokenName.close();
	}
	for (int i = 0; i < warTokensNames.size(); i++)
	{

		int x, y;
		warTokenPositionFile >> x >> y;
		
		{
			warTokens.push_back(new CardRender(x, y, &this->textures[this->warTokensNames[i]], sf::Color(0, 0, 0, 0),
				sf::Color(10, 10, 10, 200), sf::Color(0, 0, 0, 0), this->warTokensNames[i]));
		}
		

	}

}

void GameState::initKeyBinds()
{
	/*std::ifstream ifs("Config/gamestate_keybinds.ini");

	if (ifs.is_open())
	{
		std::string key = "";
		std::string key2 = "";

		while (ifs >> key >> key2)
		{
			this->keyBinds[key] =this->supportedKeys->at(key2);
		}
	}
	ifs.close();*/

	this->keyBinds["CLOSE"] = this->supportedKeys->at("Escape");
	this->keyBinds["MOVE_LEFT"] = this->supportedKeys->at("A");
	this->keyBinds["MOVE_RIGHT"] = this->supportedKeys->at("D");
	this->keyBinds["MOVE_UP"] = this->supportedKeys->at("W");
	this->keyBinds["MOVE_DOWN"] =this->supportedKeys->at("S");
}

void GameState::initTextures()
{
	//Card texture
	std::string preset;
	switch (this->curentTurn)
	{
	case GameMechanics::Turn::First:
		preset = "Utils/Age1DeckPresets.txt";
		break;
	case GameMechanics::Turn::Second:
		preset = "Utils/Age2DeckPresets.txt";
		break;
	case GameMechanics::Turn::Third:
		preset = "Utils/Age3DeckPresets.txt";
		break;

	default:
		break;
	}

	sf::Texture temp;
	sf::Texture temps;
	std::ifstream file(preset);
	if (file.is_open()) {
		std::cout << "#####_CARDS_#####\n";
		std::string line;
		std::string previusName;
		int i = 0;
		while (getline(file, line)) {
			if (i == 0)
			{
				temp.loadFromFile(line.c_str());
				this->textures["ZBACK"] = temp;
				
			}
			else
					if (i % 2 == 0)
					{
						temps.loadFromFile(line.c_str());
						this->textures[previusName] = temps;
					}
					else {
						previusName = line.c_str();
						std::cout << previusName << "\n";
					}
			
			i++;
				
			
		}
		file.close();
	}
	
	
	//WondersTexture
	std::ifstream wonderPresets("Utils/WonderCardsPresets.txt");
	if (wonderPresets.is_open()) {
		std::cout << "#####_WONDERS_#####\n";
		std::string line;
		std::string previusName;
		int i = 1;
		while (getline(wonderPresets, line)) {
			
				if (i % 2 == 0)
				{
					temps.loadFromFile(line.c_str());
					this->textures[previusName] = temps;
				}
				else {
					previusName = line.c_str();
					std::cout << previusName << "\n";
				}

			i++;


		}
		wonderPresets.close();
	}


	std::ifstream wonderPresetsSmall("Utils/WonderCardsPresetsSmall.txt");
	if (wonderPresetsSmall.is_open()) {
		std::cout << "#####_WONDERS_SMALL_#####\n";
		std::string line;
		std::string previusName;
		int i = 1;
		while (getline(wonderPresetsSmall, line)) {

			if (i % 2 == 0)
			{
				temps.loadFromFile(line.c_str());
				this->textures[previusName] = temps;
			}
			else {
				previusName = line.c_str();
				std::cout << previusName << "\n";
			}

			i++;


		}
		wonderPresetsSmall.close();
	}
	
	
	sf::Texture tempsS;
	tempsS.loadFromFile("Images/OtherResources/WARBOARD.png");
	this->textures["ZWARBOARD"] = tempsS;


	tempsS.loadFromFile("Images/OtherResources/POWN.png");
	this->textures["ZPOWN"] = tempsS;


	std::ifstream tokensPresets("Utils/TokenPresets.txt");
	if (tokensPresets.is_open()) {
		std::cout << "#####_TOKENS_#####\n";
		std::string line;
		std::string previusName;
		int i = 1;
		while (getline(tokensPresets, line)) {

			if (i % 2 == 0)
			{
				temps.loadFromFile(line.c_str());
				this->textures[previusName] = temps;
			}
			else {
				previusName = line.c_str();
				std::cout << previusName << "\n";
			}

			i++;


		}
		wonderPresets.close();
	}

	std::ifstream warTokensPresets("Utils/WarTokenPresets.txt");
	if (warTokensPresets.is_open()) {
		std::cout << "#####_WAR_TOKENS_#####\n";
		std::string line;
		std::string previusName;
		int i = 1;
		while (getline(warTokensPresets, line)) {

			if (i % 2 == 0)
			{
				temps.loadFromFile(line.c_str());
				this->textures[previusName] = temps;
			}
			else {
				previusName = line.c_str();
				std::cout << previusName << "\n";
			}

			i++;


		}
		warTokensPresets.close();
	}
	
	tempsS.loadFromFile("Images/OtherResources/resourceTable.png");
	this->textures["RESOURCEBOARD"] = tempsS;

	std::ifstream numberPresets("Utils/NumbersInit.txt");
	if (numberPresets.is_open()) {
		std::cout << "#####_NUMBERS_#####\n";
		std::string line;
		std::string previusName;
		int i = 1;
		while (getline(numberPresets, line)) {

			if (i % 2 == 0)
			{
				temps.loadFromFile(line.c_str());
				this->textures[previusName] = temps;
			}
			else {
				previusName = line.c_str();
				std::cout << previusName << "\n";
			}

			i++;


		}
		numberPresets.close();
	}

}

void GameState::initCards()
{
	std::string position;
	std::string name;
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

	

	switch (this->curentTurn)
	{

	case GameMechanics::Turn::First:
		 fliped = { 0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,1,1,0,0 };
		 position = "Utils/Age1CardsPosition.txt";
		 name = "Utils/Age1CardsNames.txt";
		break;
	case GameMechanics::Turn::Second:
		 fliped = { 0,0,1,1,1,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0 };
		 position = "Utils/Age2DeckPosition.txt";
		 name = "Utils/Age2DeckNames.txt";
		break;
	case GameMechanics::Turn::Third:
		 fliped = { 0,0,1,1,1,0,0,0,0,1,1,0,0,0,0,1,1,1,0,0 };
		 position = "Utils/Age3DeckPosition.txt";
		 name = "Utils/Age3DeckNames.txt";
		break;

	default:
		break;
	}

	std::ifstream positionFile(position);
	decltype(this->textures)::iterator it = textures.begin();
	
	
	
	std::ifstream nameFile(name);

	if (nameFile.is_open()) {
		std::string line;
		while (getline(nameFile, line)) {
			if (this->curentTurn == GameMechanics::Turn::First)
				this->cardNames.push_back(line.c_str());
			if(this->curentTurn == GameMechanics::Turn::Second)
				this->cardNameAge2.push_back(line.c_str());
			if (this->curentTurn == GameMechanics::Turn::Third)
				this->cardNameAge3.push_back(line.c_str());
		}
		nameFile.close();

		if (this->curentTurn == GameMechanics::Turn::Second)
			std::swap(cardNames, cardNameAge2);
		if (this->curentTurn == GameMechanics::Turn::Third)
			std::swap(cardNames, cardNameAge3);
	}
	
	std::shuffle(this->cardNames.begin(), this->cardNames.end(), std::default_random_engine(seed));


	for(int i = 0; i < 20; i++)
	{
		
		int x, y;
		positionFile >> x >> y;
		char caracte = i + 48;
		std::string sir(1, caracte); 
		std::string denum = it->first;
		if (fliped.at(i) == 1)
		{
			//this->cardsMap[this->names[i]] = new CardRender(x, y, &this->textures["ZBACK"]);	//OLD render for cards
			cards.push_back(new CardRender(x, y, &this->textures["ZBACK"], sf::Color(0, 0, 0, 0),
				sf::Color(10, 10, 10, 200), sf::Color(0, 0, 0, 0), this->cardNames[i]));
			/*cards.at(i)->shape.setSize(sf::Vector2f
			(
				static_cast<float>(cards.at(i)->shape.getSize().x / 2),
				static_cast<float>(cards.at(i)->shape.getSize().y / 2)
			));*/
			
		}
		else
		{
			//this->cardsMap[this->names[i]] = new CardRender(x, y, &this->textures[this->names[i]]);	//OLD render for cards
			cards.push_back(new CardRender(x, y, &this->textures[this->cardNames[i]], sf::Color(0, 0, 0, 0),
				sf::Color(10, 10, 10, 200), sf::Color(0, 0, 0, 0), this->cardNames[i]));
			/*cards.at(i)->shape.setSize(sf::Vector2f
			(
				static_cast<float>(cards.at(i)->shape.getSize().x / 2),
				static_cast<float>(cards.at(i)->shape.getSize().y / 2)
			));*/
			
		}
		it++;
	}




	if (this->curentTurn != GameMechanics::Turn::First)
	{
		for (int i = 0; i < allCards.size(); i++)
		{
			allCards.at(i)->shape.setSize(sf::Vector2f
			(
				static_cast<float>(allCards.at(i)->shape.getSize().x / 2),
				static_cast<float>(allCards.at(i)->shape.getSize().y / 2)
			));
		}
	}

	
	if (this->curentTurn == GameMechanics::Turn::First)
	{
		this->warBoard = new CardRender(700, 10, &this->textures["ZWARBOARD"]);
		this->warPown = new CardRender(990, 85, &this->textures["ZPOWN"]);
		this->scoreTable = new  CardRender(0, 0, &this->textures["RESOURCEBOARD"]);
		std::string poz = "Utils/NumbersPosition.txt";
		std::ifstream numPoz(poz);
		for (int i = 0; i < 20; i++)
		{
			int x, y;
			numPoz >> x >> y;
			if (i == 14 || i == 15)
				this->numbers.push_back(new CardRender(x, y, &this->textures["7"]));
			else
				this->numbers.push_back(new CardRender(x, y, &this->textures["0"]));
			
		}
		//this->numbers.push_back(new CardRender(12, 55, &this->textures["0"]));
		
	}
}

void GameState::initWonders()
{
	std::vector<bool> fliped;
	std::string position = "Utils/WonderCardsPosition.txt";
	std::string name = "Utils/WonderCardsNames.txt";;
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

	std::ifstream wonderPositionFile(position);
	std::ifstream wonderNameFile(name);

	if (wonderNameFile.is_open()) {
		std::string line;
		while (getline(wonderNameFile, line)) {

			this->wonderName.push_back(line.c_str());

		}
		wonderNameFile.close();
	}

	

	std::shuffle(this->wonderName.begin(), this->wonderName.end(), std::default_random_engine(seed));


	for (int i = 0; i < 9; i++)
	{

		int x, y;
		wonderPositionFile >> x >> y;

		wonders.push_back(new CardRender(x, y, &this->textures[this->wonderName[i]], sf::Color(0, 0, 0, 0),
			sf::Color(10, 10, 10, 200), sf::Color(0, 0, 0, 0),this->wonderName[i]));

	}

}

void GameState::initWondersSmall()
{
	 

	//Wonders Small
	std::string nameSmall = "Utils/WonderCardsNames.txt";;
	std::ifstream wonderNameSmallFile(nameSmall);
	std::ifstream wonderPositionFile("Utils/WonderCardsPositionSmall.txt");

	if (wonderNameSmallFile.is_open()) {
		std::string line;
		while (getline(wonderNameSmallFile, line)) {

			this->wonderNameSmall.push_back(line.c_str());

		}
		wonderNameSmallFile.close();
	}

	for (int i = 0; i < wondersClear.size(); i++)
	{
		int x, y;
		wonderPositionFile >> x >> y;
		std::string num = wondersClear.at(i)->getName();
		num = num + " SMALL";

		wondersSmall.push_back(new CardRender(x, y, &this->textures[num], sf::Color(0, 0, 0, 0),
			sf::Color(10, 10, 10, 200), sf::Color(0, 0, 0, 0), num));

	}


}

void GameState::initPlayers()
{
	this->player1 = Player("User");
	player1.SetMoney(7);
	this->player1.SetMilitarryPoints(0);
	this->player1.SetVictoryPoints(0);
	this->player2 = Player("AI");
	player2.SetMoney(7);
	this->player2.SetMilitarryPoints(0);
	this->player2.SetVictoryPoints(0);

	this->wonderDeck.PopulateDeck();
	this->deck.PopulateDeck();
	this->deck2.PopulateDeck();
	this->deck3.PopulateDeck();

	this->bot.dataSource = player2;
}

void GameState::initProgressTokens()
{
	activeProgressTokens.PopulateProgressTokens();
}

GameState::GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states,bool botIsEnabled )
	:State(window, supportedKeys, states)
{
	this->initKeyBinds();
	this->m_processingTime =45ms;
	this->initTextures();
	this->initWonders();
	this->initCards();
	this->initTokens();
	this->initPlayers();
	this->initProgressTokens();
	//this->card.createSprite(&text);
	this->botIsEnabled = botIsEnabled;


	this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	this->texture.loadFromFile("Images/background_game.png");
	this->texture.setSmooth(true);
	this->background.setTexture(&this->texture);
}

GameState::~GameState()
{

	for (decltype(this->cardsMap)::iterator it = cardsMap.begin(); it != cardsMap.end(); it++)
	{
		delete	it->second;
	}

		delete this->warBoard;
		delete this->warPown;

	for (decltype(this->progressTokens)::iterator it = progressTokens.begin(); it != progressTokens.end(); it++)
	{
		delete	*it;
	}
	
}



void GameState::updateCards()
{
	//wonders selection 
	if (wonderInitialization == true)
	{
		wonderPickPos = { 1,1,1,1 };
		wonderInitialization = false;
		playerPickOrder = { 0,1,1,0 };
	}
	if (selectedWonders != 1)
	{
		for (int i = 0; i < 4; i++)
		{

			wonders.at(i)->update(this->mousePosView);
			if (wonders.at(i)->isPressed())
			{
				wondersClear.push_back(wonders.at(i));
				if (playerPickOrder.at(pressed4) == 0)
				{
					player1.PickWonderCards(wonders.at(i)->getName(), this->wonderDeck);
				}
				else
				{
					player2.PickWonderCards(wonders.at(i)->getName(), this->wonderDeck);

				}
				if (wonderPickPos.at(i) == 1)
				{
					wonderPickPos.at(i) = 0;
					wonders.at(i)->setPosition(0, 0);
					pressed4++;


				}

				if (pressed4 >= 4)
				{
					this->selectedFirst4Wonders = 1;


				}
				if (pressed4 == 4 && selectedFirst4Wonders == 1)
				{

					wonderPickPos = { 1,1,1,1 };
					playerPickOrder = { 1,0,0,1 };
				}



			}
		}
		if (pressed4 == 4 && selectedFirst4Wonders == 1)
		{
			for (int i = 4, j = 0; i < wonders.size() - 1; i++, j++)
			{
				if (wonders.at(i)->isPressed())
				{

					if (playerPickOrder.at(j) == 0)
					{
						player1.PickWonderCards(wonders.at(i)->getName(), this->wonderDeck);
					}
					else
					{
						player2.PickWonderCards(wonders.at(i)->getName(), this->wonderDeck);

					}

					if (wonderPickPos.at(i - 4) == 1)
					{
						wonderPickPos.at(i - 4) = 0;
						wonders.at(i)->setPosition(0, 0);

						pressed8++;

					}
					wondersClear.push_back(wonders.at(i));

				}
				wonders.at(i)->update(this->mousePosView);
				if (pressed8 == 4)
				{
					this->selectedWonders = 1;
					initWondersSmall();

				}
			}
		}
	}



	//card selection  
	if (allCardsPressed == 20)
	{
		this->curentTurn = GameMechanics::Turn::Second;
		
		allCards=cards;
		cards.clear();
		if (cardInitialization == false)
		{
			this->initTextures();
			this->initCards();
			
		}
		allCardsPressed++;
		cardInitialization = true;
	}

	if (allCardsPressed == 41)
	{
		this->curentTurn = GameMechanics::Turn::Third;
		
		for (int i = 0; i < cards.size(); i++)
			allCards.push_back(cards.at(i));
		//allCards = cards;
		cards.clear();
		if (cardInitialization == false)
		{
			this->initTextures();
			this->initCards();
		}
		allCardsPressed++;
		cardInitialization = true;
	}

	if (allCardsPressed == 62)
	{
		if (player1.GetVictoryPoints() > player2.GetVictoryPoints())
		{
			this->GameOver(player1.GetName()+" has won!");
		}
		else
			if(player1.GetVictoryPoints() < player2.GetVictoryPoints())
			{
				this->GameOver(player2.GetName() + " has won!");
			}
			else
			{
				this->GameOver("Too bad, it's a draw!");
			}
		
	}
	

	if (cardInitialization == true)
	{
		switch (this->curentTurn)
		{

		case GameMechanics::Turn::First:

			st = { 0,0,0,0,0,0,1,2,3,4,5,7,8,9,10,12,13,14,16,17 };
			dr = { 0,0,0,0,0,0,2,3,4,5,6,8,9,10,11,13,14,15,17,18 };
			taken = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
			cardInitialization = false;
			
			break;
		case GameMechanics::Turn::Second:
			st = { 0,0,0,1,2,0,3,4,5,0,6,7,8,9,0,10,11,12,13,14 };
			dr = { 0,0,1,2,0,3,4,5,0,6,7,8,9,0,10,11,12,13,14,0 };
			taken = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
			cardInitialization = false;
			break;
		case GameMechanics::Turn::Third:
			st = { 0,0,0,1,2,0,3,4,5,6,8,0,10,0,11,12,13,14,16,17 };
			dr = { 0,0,1,2,0,3,4,5,0,7,9,10,0,11,0,13,14,15,17,18 };
			taken = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
			cardInitialization = false;
			break;

		default:
			break;
		}
	}
	std::string tokenName;
	if (duplicateSymbol == true)
	{
		for (int i = 0; i < progressTokens.size(); i++)
		{

			progressTokens.at(i)->update(this->mousePosView);
			if (progressTokens.at(i)->isPressed())
			{
				progressTokens.at(i)->setPosition(0, 0);
				tokenName = progressTokens.at(i)->getName();
				m_mechanics.PickToken(player1, this->activeProgressTokens, tokenName);
				duplicateSymbol = false;
			}
		}
	}
	if (selectedWonders == 1)
	{
	for (int i = 0; i < cards.size(); i++)
	{
		if (duplicateSymbol == false)
		{	
			if(botIsEnabled!=false)
			{
				if (bot.isActive == false)
				{
					if (st.at(i) == 0 && dr.at(i) == 0)
					{

						if (cards.at(i)->isPressed())
						{
							if (!cards.at(i)->isPressedR())
							{
								
								curentCardIndex = i;
								switch (this->curentTurn)
								{
								case GameMechanics::Turn::First:
									if (m_mechanics.UsingCard(player1, player2, m_mechanics.FindCard(cards.at(i)->getName(), deck), deck, this->activeProgressTokens) == true)
									{
										
										taken.at(i) = 0;
										int val = this->player1.GetMoney();
										std::string s = std::to_string(val);

										if (player1.GetName() == "User")
										{
											this->numbers.at(14) = (new CardRender(this->numbers.at(14)->getX(), this->numbers.at(14)->getY(), &this->textures[s]));
									
										}
										else
											this->numbers.at(15) = (new CardRender(this->numbers.at(15)->getX(), this->numbers.at(15)->getY(), &this->textures[s]));


										for (int j = 0; j < cards.size(); j++)
										{
											if (st.at(j) == i + 1)
												st.at(j) = 0;
											if (dr.at(j) == i + 1)
												dr.at(j) = 0;
											if (st.at(j) == 0 && dr.at(j) == 0)
											{
												fliped.at(j) = false;
												if (fliped.at(j) == false)
												{
													cards.at(j) = new CardRender(cards.at(j)->getX(), cards.at(j)->getY(), &this->textures[this->cardNames[j]], sf::Color(0, 0, 0, 0),
														sf::Color(10, 10, 10, 200), sf::Color(0, 0, 0, 0), this->cardNames[j]);
												}
											}

										}
										Card::Color curentCardColor = m_mechanics.FindCard(cards.at(i)->getName(), deck).GetColor();
										int curentCardIndex = 20 * m_mechanics.CountBuildingsByColor(curentCardColor, player1);
								
										switch (curentCardColor)
										{
										case Card::Color::Red:
										{
											player1.SetMilitarryPoints(m_mechanics.FindCard(cards.at(i)->getName(), deck).GetPoints().size());
											int val = this->player1.GetMilitarryPoints();
											std::string s = std::to_string(val);
											if (player1.GetName() == "User")
											{
												this->numbers.at(10) = (new CardRender(this->numbers.at(10)->getX(), this->numbers.at(10)->getY(), &this->textures[s]));
												cards.at(i)->setPosition(0, 730 + curentCardIndex);
											}

											if (player1.GetName() == "AI")
											{
												this->numbers.at(11) = (new CardRender(this->numbers.at(11)->getX(), this->numbers.at(11)->getY(), &this->textures[s]));
												cards.at(i)->setPosition(1810, 730 + curentCardIndex);
											}




											int aux = this->player1.GetMilitarryPoints() - this->player2.GetMilitarryPoints();
											if (aux == 9 || aux == -9)
											{
												this->GameOver(player1.GetName());
											}
											switch (aux)
											{

											case -9:
												warPown->setPosition(762, warPown->getY());
												std::cout << "Win p1";
												this->GameOver(player1.GetName());
												break;
											case -8:
											{
												if (token5P1 == true)
												{
													player2.DecreaseMoney(5);
													token5P1 = false;
													int val = this->player2.GetMoney();
													std::string s = std::to_string(val);
													this->numbers.at(15) = (new CardRender(this->numbers.at(15)->getX(), this->numbers.at(15)->getY(), &this->textures[s]));
												}
												warPown->setPosition(782, warPown->getY());
												warTokens.at(0)->setPosition(0, 0);
												break;
											}
											case -7:
											{
												if (token5P1 == true)
												{
													player2.DecreaseMoney(5);
													token5P1 = false;
													int val = this->player2.GetMoney();
													std::string s = std::to_string(val);
													this->numbers.at(15) = (new CardRender(this->numbers.at(15)->getX(), this->numbers.at(15)->getY(), &this->textures[s]));
												}
												warPown->setPosition(808, warPown->getY());
												warTokens.at(0)->setPosition(0, 0);
												break;
											}
											case -6:
											{
												if (token5P1 == true)
												{
													player2.DecreaseMoney(5);
													token5P1 = false;
													int val = this->player2.GetMoney();
													std::string s = std::to_string(val);
													this->numbers.at(15) = (new CardRender(this->numbers.at(15)->getX(), this->numbers.at(15)->getY(), &this->textures[s]));

												}
												warPown->setPosition(834, warPown->getY());
												warTokens.at(0)->setPosition(0, 0);
												break;
											}
											case -5:
											{
												if (token2P1 == true)
												{
													player2.DecreaseMoney(2);
													token2P1 = false;
													int val = this->player2.GetMoney();
													std::string s = std::to_string(val);
													this->numbers.at(15) = (new CardRender(this->numbers.at(15)->getX(), this->numbers.at(15)->getY(), &this->textures[s]));

												}
												warPown->setPosition(860, warPown->getY());
												warTokens.at(1)->setPosition(0, 0);
												break;
											}
											case -4:
											{
												if (token2P1 == true)
												{
													player2.DecreaseMoney(2);
													token2P1 = false;
													int val = this->player2.GetMoney();
													std::string s = std::to_string(val);
													this->numbers.at(15) = (new CardRender(this->numbers.at(15)->getX(), this->numbers.at(15)->getY(), &this->textures[s]));
												}
												warPown->setPosition(886, warPown->getY());
												warTokens.at(1)->setPosition(0, 0);
												break;
											}
											case -3:
											{
												if (token2P1 == true)
												{
													player2.DecreaseMoney(2);
													token2P1 = false;
													int val = this->player2.GetMoney();
													std::string s = std::to_string(val);
													this->numbers.at(15) = (new CardRender(this->numbers.at(15)->getX(), this->numbers.at(15)->getY(), &this->textures[s]));
												}
												warPown->setPosition(912, warPown->getY());
												warTokens.at(1)->setPosition(0, 0);
												break;
											}
											case -2:
												warPown->setPosition(938, warPown->getY());
												break;

											case -1:
												warPown->setPosition(964, warPown->getY());
												break;
											case 0:
												warPown->setPosition(990, 85);
												break;
											case 1:
												warPown->setPosition(1016, warPown->getY());
												break;
											case 2:
												warPown->setPosition(1042, warPown->getY());
												break;
											case 3:
											{
												if (token2P2 == true)
												{
													player2.DecreaseMoney(2);
													token2P2 = false;
													int val = this->player1.GetMoney();
													std::string s = std::to_string(val);
													this->numbers.at(14) = (new CardRender(this->numbers.at(14)->getX(), this->numbers.at(14)->getY(), &this->textures[s]));

												}
												warPown->setPosition(1068, warPown->getY());
												warTokens.at(2)->setPosition(0, 0);
												break;
											}
											case 4:
											{
												if (token2P2 == true)
												{
													player2.DecreaseMoney(2);
													token2P2 = false;
													int val = this->player1.GetMoney();
													std::string s = std::to_string(val);
													this->numbers.at(14) = (new CardRender(this->numbers.at(14)->getX(), this->numbers.at(14)->getY(), &this->textures[s]));

												}
												warPown->setPosition(1094, warPown->getY());
												warTokens.at(2)->setPosition(0, 0);
												break;
											}
											case 5:
											{
												if (token2P2 == true)
												{
													player2.DecreaseMoney(2);
													token2P2 = false;
													int val = this->player1.GetMoney();
													std::string s = std::to_string(val);
													this->numbers.at(14) = (new CardRender(this->numbers.at(14)->getX(), this->numbers.at(14)->getY(), &this->textures[s]));

												}
												warPown->setPosition(1120, warPown->getY());
												warTokens.at(2)->setPosition(0, 0);
												break;
											}
											case 6:
											{
												if (token5P2 == true)
												{
													player2.DecreaseMoney(5);
													token5P2 = false;
													int val = this->player1.GetMoney();
													std::string s = std::to_string(val);
													this->numbers.at(14) = (new CardRender(this->numbers.at(14)->getX(), this->numbers.at(14)->getY(), &this->textures[s]));

												}

												warPown->setPosition(1146, warPown->getY());
												warTokens.at(3)->setPosition(0, 0);
												break;
											}
											case 7:
											{
												if (token5P2 == true)
												{
													player2.DecreaseMoney(5);
													token5P2 = false;
													int val = this->player1.GetMoney();
													std::string s = std::to_string(val);
													this->numbers.at(14) = (new CardRender(this->numbers.at(14)->getX(), this->numbers.at(14)->getY(), &this->textures[s]));

												}
												warPown->setPosition(1172, warPown->getY());
												warTokens.at(3)->setPosition(0, 0);
												break;
											}
											case 8:
											{
												if (token5P2 == true)
												{
													player2.DecreaseMoney(5);
													token5P2 = false;
													int val = this->player1.GetMoney();
													std::string s = std::to_string(val);
													this->numbers.at(14) = (new CardRender(this->numbers.at(14)->getX(), this->numbers.at(14)->getY(), &this->textures[s]));

												}
												warPown->setPosition(1198, warPown->getY());
												warTokens.at(3)->setPosition(0, 0);
												break;
											}
											case 9:
											{	warPown->setPosition(1224, warPown->getY());
											std::cout << "Win p2";
											this->GameOver(player2.GetName());
											break;
											}
											default:
												break;
											}

											break;
										}
										case Card::Color::Blue:
										{
											player1.SetVictoryPoints(m_mechanics.FindCard(cards.at(i)->getName(), deck).GetPoints().size());
											int val = this->player1.GetVictoryPoints();
											std::string s = std::to_string(val);

											if (player1.GetName() == "User")
											{
												this->numbers.at(12) = (new CardRender(this->numbers.at(12)->getX(), this->numbers.at(12)->getY(), &this->textures[s]));
												cards.at(i)->setPosition(122, 730 + curentCardIndex);
											}

											if (player1.GetName() == "AI")
											{
												this->numbers.at(13) = (new CardRender(this->numbers.at(13)->getX(), this->numbers.at(13)->getY(), &this->textures[s]));
												cards.at(i)->setPosition(1688, 730 + curentCardIndex);
											}
											break;
										}
										case Card::Color::Brown:
										{
											//player1.SetVictoryPoints(m_mechanics.FindCard(cards.at(i)->getName(), deck).GetPoints().size());




											if (player1.GetName() == "User")
											{
												switch (m_mechanics.FindCard(cards.at(i)->getName(), deck).GetRawMaterial().GetRawMaterial())
												{
												case::RawMaterialsCLass::RawMaterials::Wood:
												{
													int val = m_mechanics.CountRawMaterialsWood(player1);
													std::string s = std::to_string(val);
													this->numbers.at(2) = (new CardRender(this->numbers.at(2)->getX(), this->numbers.at(2)->getY(), &this->textures[s]));
													break;
												}
												case::RawMaterialsCLass::RawMaterials::Clay:
												{
													int val = m_mechanics.CountRawMaterialsClay(player1);
													std::string s = std::to_string(val);
													this->numbers.at(0) = (new CardRender(this->numbers.at(0)->getX(), this->numbers.at(0)->getY(), &this->textures[s]));
													break;
												}
												case::RawMaterialsCLass::RawMaterials::Stone:
												{
													int val = m_mechanics.CountRawMaterialsStone(player1);
													std::string s = std::to_string(val);
													this->numbers.at(4) = (new CardRender(this->numbers.at(4)->getX(), this->numbers.at(4)->getY(), &this->textures[s]));
													break;
												}
												default:
													break;
												}
												cards.at(i)->setPosition(244, 730 + curentCardIndex);
											}

											if (player1.GetName() == "AI")
											{
												switch (m_mechanics.FindCard(cards.at(i)->getName(), deck).GetRawMaterial().GetRawMaterial())
												{
												case::RawMaterialsCLass::RawMaterials::Wood:
												{
													int val = m_mechanics.CountRawMaterialsWood(player1);
													std::string s = std::to_string(val);
													this->numbers.at(3) = (new CardRender(this->numbers.at(3)->getX(), this->numbers.at(3)->getY(), &this->textures[s]));
													break;
												}
												case::RawMaterialsCLass::RawMaterials::Clay:
												{
													int val = m_mechanics.CountRawMaterialsClay(player1);
													std::string s = std::to_string(val);
													this->numbers.at(1) = (new CardRender(this->numbers.at(1)->getX(), this->numbers.at(1)->getY(), &this->textures[s]));
													break;
												}
												case::RawMaterialsCLass::RawMaterials::Stone:
												{
													int val = m_mechanics.CountRawMaterialsStone(player1);
													std::string s = std::to_string(val);
													this->numbers.at(5) = (new CardRender(this->numbers.at(5)->getX(), this->numbers.at(5)->getY(), &this->textures[s]));
													break;
												}
												default:
													break;
												}
												cards.at(i)->setPosition(1566, 730 + curentCardIndex);
											}
											break;
										}
										case Card::Color::Green:
										{
											//player1.SetSymbol(m_mechanics.FindCard(cards.at(i)->getName(), deck).GetSymbol());


											if (m_mechanics.CountSymbolInPlayersDeck(player1) == true)
											{
												duplicateSymbol = true;
												m_mechanics.PickToken(player1, this->activeProgressTokens, tokenName);
											}

											player1.SetVictoryPoints(m_mechanics.FindCard(cards.at(i)->getName(), deck).GetPoints().size());
											int val = this->player1.GetVictoryPoints();
											std::string s = std::to_string(val);

											if (player1.GetName() == "User")
											{
												this->numbers.at(12) = (new CardRender(this->numbers.at(12)->getX(), this->numbers.at(12)->getY(), &this->textures[s]));
												cards.at(i)->setPosition(366, 730 + curentCardIndex);
											}

											if (player1.GetName() == "AI")
											{
												this->numbers.at(13) = (new CardRender(this->numbers.at(13)->getX(), this->numbers.at(13)->getY(), &this->textures[s]));
												cards.at(i)->setPosition(1444, 730 + curentCardIndex);
											}
											break; 
										}
										case Card::Color::Grey:
										{
											if (player1.GetName() == "User")
											{
												switch (m_mechanics.FindCard(cards.at(i)->getName(), deck).GetManufGood().GetManufacturedGood())
												{
												case::ManufacturedGoodsClass::ManufacturedGoods::Glass:
												{
													int val = m_mechanics.CountMaterialsGoodsGlass(player1);
													std::string s = std::to_string(val);
													this->numbers.at(6) = (new CardRender(this->numbers.at(6)->getX(), this->numbers.at(6)->getY(), &this->textures[s]));
													break;
												}
												case::ManufacturedGoodsClass::ManufacturedGoods::Papirus:
												{
													int val = m_mechanics.CountMaterialsGoodsPapirus(player1);
													std::string s = std::to_string(val);
													this->numbers.at(8) = (new CardRender(this->numbers.at(8)->getX(), this->numbers.at(8)->getY(), &this->textures[s]));
													break;
												}
												default:
													break;
												}
												cards.at(i)->setPosition(488, 730 + curentCardIndex);
											}

											if (player1.GetName() == "AI")
											{
												switch (m_mechanics.FindCard(cards.at(i)->getName(), deck).GetManufGood().GetManufacturedGood())
												{
												case::ManufacturedGoodsClass::ManufacturedGoods::Glass:
												{
													int val = m_mechanics.CountMaterialsGoodsGlass(player1);
													std::string s = std::to_string(val);
													this->numbers.at(7) = (new CardRender(this->numbers.at(7)->getX(), this->numbers.at(7)->getY(), &this->textures[s]));
													break;
												}
												case::ManufacturedGoodsClass::ManufacturedGoods::Papirus:
												{
													int val = m_mechanics.CountMaterialsGoodsPapirus(player1);
													std::string s = std::to_string(val);
													this->numbers.at(9) = (new CardRender(this->numbers.at(9)->getX(), this->numbers.at(9)->getY(), &this->textures[s]));
													break;
												}
												default:
													break;
												}
												cards.at(i)->setPosition(1322, 730 + curentCardIndex);
											}
											break;
										}
										case Card::Color::Purple:
										{
											if (player1.GetName() == "User")
											{
												cards.at(i)->setPosition(610, 730 + curentCardIndex);
											}

											if (player1.GetName() == "AI")
											{
												cards.at(i)->setPosition(1200, 730 + curentCardIndex);
											}
											break;
										}
										case Card::Color::Yellow:
										{
											if (player1.GetName() == "User")
											{
												cards.at(i)->setPosition(732, 730 + curentCardIndex);
											}

											if (player1.GetName() == "AI")
											{
												cards.at(i)->setPosition(1000, 730 + curentCardIndex);
											}
											break;
										}
										default:
											break;
										}
										allCardsPressed++;
										bot.isActive = true;
										std::swap(player1, player2);
									}
									else
										break;

									break;

								case GameMechanics::Turn::Second:

									if (m_mechanics.UsingCard(player1, player2, m_mechanics.FindCard(cards.at(i)->getName(), deck2), deck2, this->activeProgressTokens) == true)
									{
										taken.at(i) = 0;
										int val = this->player1.GetMoney();
										std::string s = std::to_string(val);

										int wood =  m_mechanics.CountRawMaterialsWood(player1);
										std::string swood = std::to_string(wood);
										int stone = m_mechanics.CountRawMaterialsStone(player1);
										std::string sstone = std::to_string(stone);
										int clay = m_mechanics.CountRawMaterialsClay(player1);
										std::string sclay = std::to_string(clay);

										if (player1.GetName() == "User")
										{
											this->numbers.at(0) = (new CardRender(this->numbers.at(0)->getX(), this->numbers.at(0)->getY(), &this->textures[sclay]));
											this->numbers.at(2) = (new CardRender(this->numbers.at(2)->getX(), this->numbers.at(2)->getY(), &this->textures[swood]));
											this->numbers.at(4) = (new CardRender(this->numbers.at(4)->getX(), this->numbers.at(4)->getY(), &this->textures[sstone]));
											this->numbers.at(14) = (new CardRender(this->numbers.at(14)->getX(), this->numbers.at(14)->getY(), &this->textures[s]));

										}
										else
										{

											this->numbers.at(1) = (new CardRender(this->numbers.at(1)->getX(), this->numbers.at(1)->getY(), &this->textures[sclay]));
											this->numbers.at(3) = (new CardRender(this->numbers.at(3)->getX(), this->numbers.at(3)->getY(), &this->textures[swood]));
											this->numbers.at(5) = (new CardRender(this->numbers.at(5)->getX(), this->numbers.at(5)->getY(), &this->textures[sstone]));
											this->numbers.at(15) = (new CardRender(this->numbers.at(15)->getX(), this->numbers.at(15)->getY(), &this->textures[s]));
										}
										for (int j = 0; j < cards.size(); j++)
										{
											if (st.at(j) == i + 1)
												st.at(j) = 0;
											if (dr.at(j) == i + 1)
												dr.at(j) = 0;
											if (st.at(j) == 0 && dr.at(j) == 0)
											{
												fliped.at(j) = false;
												if (fliped.at(j) == false)
												{
													cards.at(j) = new CardRender(cards.at(j)->getX(), cards.at(j)->getY(), &this->textures[this->cardNames[j]], sf::Color(0, 0, 0, 0),
														sf::Color(10, 10, 10, 200), sf::Color(0, 0, 0, 0), this->cardNames[j]);
												}
											}

										}

										Card::Color curentCardColor = m_mechanics.FindCard(cards.at(i)->getName(), deck2).GetColor();
										int curentCardIndex = 20 * m_mechanics.CountBuildingsByColor(curentCardColor, player1);

										switch (curentCardColor)
										{
										case Card::Color::Red:
										{

											player1.SetMilitarryPoints(m_mechanics.FindCard(cards.at(i)->getName(), deck2).GetPoints().size());
											int val = this->player1.GetMilitarryPoints();
											std::string s = std::to_string(val);
											if (player1.GetName() == "User")
											{
												this->numbers.at(10) = (new CardRender(this->numbers.at(10)->getX(), this->numbers.at(10)->getY(), &this->textures[s]));
												cards.at(i)->setPosition(0, 730 + curentCardIndex);
											}

											if (player1.GetName() == "AI")
											{
												this->numbers.at(11) = (new CardRender(this->numbers.at(11)->getX(), this->numbers.at(11)->getY(), &this->textures[s]));
												cards.at(i)->setPosition(1810, 730 + curentCardIndex);
											}




											int aux = this->player1.GetMilitarryPoints() - this->player2.GetMilitarryPoints();
											if (aux == 9 || aux == -9)
											{
												this->GameOver(player1.GetName());
											}
											switch (aux)
											{

											case -9:
												warPown->setPosition(762, warPown->getY());
												std::cout << "Win p1";
												this->GameOver(player1.GetName());
												break;
											case -8:
											{
												if (token5P1 == true)
												{
													player2.DecreaseMoney(5);
													token5P1 = false;
													int val = this->player2.GetMoney();
													std::string s = std::to_string(val);
													this->numbers.at(15) = (new CardRender(this->numbers.at(15)->getX(), this->numbers.at(15)->getY(), &this->textures[s]));
												}
												warPown->setPosition(782, warPown->getY());
												warTokens.at(0)->setPosition(0, 0);
												break;
											}
											case -7:
											{
												if (token5P1 == true)
												{
													player2.DecreaseMoney(5);
													token5P1 = false;
													int val = this->player2.GetMoney();
													std::string s = std::to_string(val);
													this->numbers.at(15) = (new CardRender(this->numbers.at(15)->getX(), this->numbers.at(15)->getY(), &this->textures[s]));
												}
												warPown->setPosition(808, warPown->getY());
												warTokens.at(0)->setPosition(0, 0);
												break;
											}
											case -6:
											{
												if (token5P1 == true)
												{
													player2.DecreaseMoney(5);
													token5P1 = false;
													int val = this->player2.GetMoney();
													std::string s = std::to_string(val);
													this->numbers.at(15) = (new CardRender(this->numbers.at(15)->getX(), this->numbers.at(15)->getY(), &this->textures[s]));

												}
												warPown->setPosition(834, warPown->getY());
												warTokens.at(0)->setPosition(0, 0);
												break;
											}
											case -5:
											{
												if (token2P1 == true)
												{
													player2.DecreaseMoney(2);
													token2P1 = false;
													int val = this->player2.GetMoney();
													std::string s = std::to_string(val);
													this->numbers.at(15) = (new CardRender(this->numbers.at(15)->getX(), this->numbers.at(15)->getY(), &this->textures[s]));

												}
												warPown->setPosition(860, warPown->getY());
												warTokens.at(1)->setPosition(0, 0);
												break;
											}
											case -4:
											{
												if (token2P1 == true)
												{
													player2.DecreaseMoney(2);
													token2P1 = false;
													int val = this->player2.GetMoney();
													std::string s = std::to_string(val);
													this->numbers.at(15) = (new CardRender(this->numbers.at(15)->getX(), this->numbers.at(15)->getY(), &this->textures[s]));
												}
												warPown->setPosition(886, warPown->getY());
												warTokens.at(1)->setPosition(0, 0);
												break;
											}
											case -3:
											{
												if (token2P1 == true)
												{
													player2.DecreaseMoney(2);
													token2P1 = false;
													int val = this->player2.GetMoney();
													std::string s = std::to_string(val);
													this->numbers.at(15) = (new CardRender(this->numbers.at(15)->getX(), this->numbers.at(15)->getY(), &this->textures[s]));
												}
												warPown->setPosition(912, warPown->getY());
												warTokens.at(1)->setPosition(0, 0);
												break;
											}
											case -2:
												warPown->setPosition(938, warPown->getY());
												break;

											case -1:
												warPown->setPosition(964, warPown->getY());
												break;
											case 0:
												warPown->setPosition(990, 85);
												break;
											case 1:
												warPown->setPosition(1016, warPown->getY());
												break;
											case 2:
												warPown->setPosition(1042, warPown->getY());
												break;
											case 3:
											{
												if (token2P2 == true)
												{
													player2.DecreaseMoney(2);
													token2P2 = false;
													int val = this->player1.GetMoney();
													std::string s = std::to_string(val);
													this->numbers.at(14) = (new CardRender(this->numbers.at(14)->getX(), this->numbers.at(14)->getY(), &this->textures[s]));

												}
												warPown->setPosition(1068, warPown->getY());
												warTokens.at(2)->setPosition(0, 0);
												break;
											}
											case 4:
											{
												if (token2P2 == true)
												{
													player2.DecreaseMoney(2);
													token2P2 = false;
													int val = this->player1.GetMoney();
													std::string s = std::to_string(val);
													this->numbers.at(14) = (new CardRender(this->numbers.at(14)->getX(), this->numbers.at(14)->getY(), &this->textures[s]));

												}
												warPown->setPosition(1094, warPown->getY());
												warTokens.at(2)->setPosition(0, 0);
												break;
											}
											case 5:
											{
												if (token2P2 == true)
												{
													player2.DecreaseMoney(2);
													token2P2 = false;
													int val = this->player1.GetMoney();
													std::string s = std::to_string(val);
													this->numbers.at(14) = (new CardRender(this->numbers.at(14)->getX(), this->numbers.at(14)->getY(), &this->textures[s]));

												}
												warPown->setPosition(1120, warPown->getY());
												warTokens.at(2)->setPosition(0, 0);
												break;
											}
											case 6:
											{
												if (token5P2 == true)
												{
													player2.DecreaseMoney(5);
													token5P2 = false;
													int val = this->player1.GetMoney();
													std::string s = std::to_string(val);
													this->numbers.at(14) = (new CardRender(this->numbers.at(14)->getX(), this->numbers.at(14)->getY(), &this->textures[s]));

												}

												warPown->setPosition(1146, warPown->getY());
												warTokens.at(3)->setPosition(0, 0);
												break;
											}
											case 7:
											{
												if (token5P2 == true)
												{
													player2.DecreaseMoney(5);
													token5P2 = false;
													int val = this->player1.GetMoney();
													std::string s = std::to_string(val);
													this->numbers.at(14) = (new CardRender(this->numbers.at(14)->getX(), this->numbers.at(14)->getY(), &this->textures[s]));

												}
												warPown->setPosition(1172, warPown->getY());
												warTokens.at(3)->setPosition(0, 0);
												break;
											}
											case 8:
											{
												if (token5P2 == true)
												{
													player2.DecreaseMoney(5);
													token5P2 = false;
													int val = this->player1.GetMoney();
													std::string s = std::to_string(val);
													this->numbers.at(14) = (new CardRender(this->numbers.at(14)->getX(), this->numbers.at(14)->getY(), &this->textures[s]));

												}
												warPown->setPosition(1198, warPown->getY());
												warTokens.at(3)->setPosition(0, 0);
												break;
											}
											case 9:
											{	warPown->setPosition(1224, warPown->getY());
											std::cout << "Win p2";
											this->GameOver(player2.GetName());
											break;
											}
											default:
												break;
											}

											break;
										}
										case Card::Color::Blue:
										{
											player1.SetVictoryPoints(m_mechanics.FindCard(cards.at(i)->getName(), deck2).GetPoints().size());
											int val = this->player1.GetVictoryPoints();
											std::string s = std::to_string(val);

											if (player1.GetName() == "User")
											{
												this->numbers.at(12) = (new CardRender(this->numbers.at(12)->getX(), this->numbers.at(12)->getY(), &this->textures[s]));
												cards.at(i)->setPosition(122, 730 + curentCardIndex);
											}

											if (player1.GetName() == "AI")
											{
												this->numbers.at(13) = (new CardRender(this->numbers.at(13)->getX(), this->numbers.at(13)->getY(), &this->textures[s]));
												cards.at(i)->setPosition(1688, 730 + curentCardIndex);
											}
											break;
										}
										case Card::Color::Brown:

											if (player1.GetName() == "User")
											{
												switch (m_mechanics.FindCard(cards.at(i)->getName(), deck2).GetRawMaterial().GetRawMaterial())
												{
												case::RawMaterialsCLass::RawMaterials::Wood:
												{
													int val = m_mechanics.CountRawMaterialsWood(player1);
													std::string s = std::to_string(val);
													this->numbers.at(2) = (new CardRender(this->numbers.at(2)->getX(), this->numbers.at(2)->getY(), &this->textures[s]));
													break;
												}
												case::RawMaterialsCLass::RawMaterials::Clay:
												{
													int val = m_mechanics.CountRawMaterialsClay(player1);
													std::string s = std::to_string(val);
													this->numbers.at(0) = (new CardRender(this->numbers.at(0)->getX(), this->numbers.at(0)->getY(), &this->textures[s]));
													break;
												}
												case::RawMaterialsCLass::RawMaterials::Stone:
												{
													int val = m_mechanics.CountRawMaterialsStone(player1);
													std::string s = std::to_string(val);
													this->numbers.at(4) = (new CardRender(this->numbers.at(4)->getX(), this->numbers.at(4)->getY(), &this->textures[s]));
													break;
												}
												default:
													break;
												}
												cards.at(i)->setPosition(244, 730 + curentCardIndex);
											}

											if (player1.GetName() == "AI")
											{
												switch (m_mechanics.FindCard(cards.at(i)->getName(), deck2).GetRawMaterial().GetRawMaterial())
												{
												case::RawMaterialsCLass::RawMaterials::Wood:
												{
													int val = m_mechanics.CountRawMaterialsWood(player1);
													std::string s = std::to_string(val);
													this->numbers.at(3) = (new CardRender(this->numbers.at(3)->getX(), this->numbers.at(3)->getY(), &this->textures[s]));
													break;
												}
												case::RawMaterialsCLass::RawMaterials::Clay:
												{
													int val = m_mechanics.CountRawMaterialsClay(player1);
													std::string s = std::to_string(val);
													this->numbers.at(1) = (new CardRender(this->numbers.at(1)->getX(), this->numbers.at(1)->getY(), &this->textures[s]));
													break;
												}
												case::RawMaterialsCLass::RawMaterials::Stone:
												{
													int val = m_mechanics.CountRawMaterialsStone(player1);
													std::string s = std::to_string(val);
													this->numbers.at(5) = (new CardRender(this->numbers.at(5)->getX(), this->numbers.at(5)->getY(), &this->textures[s]));
													break;
												}
												default:
													break;
												}
												cards.at(i)->setPosition(1566, 730 + curentCardIndex);
											}
											break;
										case Card::Color::Green:
										{
											//player1.SetSymbol(m_mechanics.FindCard(cards.at(i)->getName(), deck).GetSymbol());


											if (m_mechanics.CountSymbolInPlayersDeck(player1) == true)
											{
												duplicateSymbol = true;
												m_mechanics.PickToken(player1, this->activeProgressTokens, tokenName);
											}

											player1.SetVictoryPoints(m_mechanics.FindCard(cards.at(i)->getName(), deck2).GetPoints().size());
											int val = this->player1.GetVictoryPoints();
											std::string s = std::to_string(val);

											if (player1.GetName() == "User")
											{
												this->numbers.at(12) = (new CardRender(this->numbers.at(12)->getX(), this->numbers.at(12)->getY(), &this->textures[s]));
												cards.at(i)->setPosition(366, 730 + curentCardIndex);
											}

											if (player1.GetName() == "AI")
											{
												this->numbers.at(13) = (new CardRender(this->numbers.at(13)->getX(), this->numbers.at(13)->getY(), &this->textures[s]));
												cards.at(i)->setPosition(1444, 730 + curentCardIndex);
											}
											break; }
										case Card::Color::Grey:
										{
											if (player1.GetName() == "User")
											{
												switch (m_mechanics.FindCard(cards.at(i)->getName(), deck2).GetManufGood().GetManufacturedGood())
												{
												case::ManufacturedGoodsClass::ManufacturedGoods::Glass:
												{
													int val = m_mechanics.CountMaterialsGoodsGlass(player1);
													std::string s = std::to_string(val);
													this->numbers.at(6) = (new CardRender(this->numbers.at(6)->getX(), this->numbers.at(6)->getY(), &this->textures[s]));
													break;
												}
												case::ManufacturedGoodsClass::ManufacturedGoods::Papirus:
												{
													int val = m_mechanics.CountMaterialsGoodsPapirus(player1);
													std::string s = std::to_string(val);
													this->numbers.at(8) = (new CardRender(this->numbers.at(8)->getX(), this->numbers.at(8)->getY(), &this->textures[s]));
													break;
												}
												default:
													break;
												}
												cards.at(i)->setPosition(488, 730 + curentCardIndex);
											}

											if (player1.GetName() == "AI")
											{
												switch (m_mechanics.FindCard(cards.at(i)->getName(), deck2).GetManufGood().GetManufacturedGood())
												{
												case::ManufacturedGoodsClass::ManufacturedGoods::Glass:
												{
													int val = m_mechanics.CountMaterialsGoodsGlass(player1);
													std::string s = std::to_string(val);
													this->numbers.at(7) = (new CardRender(this->numbers.at(7)->getX(), this->numbers.at(7)->getY(), &this->textures[s]));
													break;
												}
												case::ManufacturedGoodsClass::ManufacturedGoods::Papirus:
												{
													int val = m_mechanics.CountMaterialsGoodsPapirus(player1);
													std::string s = std::to_string(val);
													this->numbers.at(9) = (new CardRender(this->numbers.at(9)->getX(), this->numbers.at(9)->getY(), &this->textures[s]));
													break;
												}
												default:
													break;
												}
												cards.at(i)->setPosition(1322, 730 + curentCardIndex);
											}
											break;
										}
										case Card::Color::Purple:
											if (player1.GetName() == "User")
											{
												cards.at(i)->setPosition(610, 730 + curentCardIndex);
											}

											if (player1.GetName() == "AI")
											{
												cards.at(i)->setPosition(1200, 730 + curentCardIndex);
											}
											break;
										case Card::Color::Yellow:
											if (player1.GetName() == "User")
											{
												cards.at(i)->setPosition(732, 730 + curentCardIndex);
											}

											if (player1.GetName() == "AI")
											{
												cards.at(i)->setPosition(1000, 730 + curentCardIndex);
											}
											break;
										default:
											break;
										}
										allCardsPressed++;
										bot.isActive = true;
										std::swap(player1, player2);
									}
									else
										break;

									break;
								case GameMechanics::Turn::Third:

									if (m_mechanics.UsingCard(player1, player2, m_mechanics.FindCard(cards.at(i)->getName(), deck3), deck3, this->activeProgressTokens) == true)
									{
										taken.at(i) = 0;

										int val = this->player1.GetMoney();
										std::string s = std::to_string(val);

										if (player1.GetName() == "User")
										{
											this->numbers.at(14) = (new CardRender(this->numbers.at(14)->getX(), this->numbers.at(14)->getY(), &this->textures[s]));

										}
										else
											this->numbers.at(15) = (new CardRender(this->numbers.at(15)->getX(), this->numbers.at(15)->getY(), &this->textures[s]));

										for (int j = 0; j < cards.size(); j++)
										{
											if (st.at(j) == i + 1)
												st.at(j) = 0;
											if (dr.at(j) == i + 1)
												dr.at(j) = 0;
											if (st.at(j) == 0 && dr.at(j) == 0)
											{
												fliped.at(j) = false;
												if (fliped.at(j) == false)
												{
													cards.at(j) = new CardRender(cards.at(j)->getX(), cards.at(j)->getY(), &this->textures[this->cardNames[j]], sf::Color(0, 0, 0, 0),
														sf::Color(10, 10, 10, 200), sf::Color(0, 0, 0, 0), this->cardNames[j]);
												}
											}

										}

										Card::Color curentCardColor = m_mechanics.FindCard(cards.at(i)->getName(), deck3).GetColor();
										int curentCardIndex = 20 * m_mechanics.CountBuildingsByColor(curentCardColor, player1);

										switch (curentCardColor)
										{
										case Card::Color::Red:
										{


											player1.SetMilitarryPoints(m_mechanics.FindCard(cards.at(i)->getName(), deck3).GetPoints().size());
											int val = this->player1.GetMilitarryPoints();
											std::string s = std::to_string(val);
											if (player1.GetName() == "User")
											{
												this->numbers.at(10) = (new CardRender(this->numbers.at(10)->getX(), this->numbers.at(10)->getY(), &this->textures[s]));
												cards.at(i)->setPosition(0, 730 + curentCardIndex);
											}

											if (player1.GetName() == "AI")
											{
												this->numbers.at(11) = (new CardRender(this->numbers.at(11)->getX(), this->numbers.at(11)->getY(), &this->textures[s]));
												cards.at(i)->setPosition(1810, 730 + curentCardIndex);
											}




											int aux = this->player1.GetMilitarryPoints() - this->player2.GetMilitarryPoints();
											if (aux == 9 || aux == -9)
											{
												this->GameOver(player1.GetName());
											}
											switch (aux)
											{

											case -9:
												warPown->setPosition(762, warPown->getY());
												std::cout << "Win p1";
												this->GameOver(player1.GetName());
												break;
											case -8:
											{
												if (token5P1 == true)
												{
													player2.DecreaseMoney(5);
													token5P1 = false;
													int val = this->player2.GetMoney();
													std::string s = std::to_string(val);
													this->numbers.at(15) = (new CardRender(this->numbers.at(15)->getX(), this->numbers.at(15)->getY(), &this->textures[s]));
												}
												warPown->setPosition(782, warPown->getY());
												warTokens.at(0)->setPosition(0, 0);
												break;
											}
											case -7:
											{
												if (token5P1 == true)
												{
													player2.DecreaseMoney(5);
													token5P1 = false;
													int val = this->player2.GetMoney();
													std::string s = std::to_string(val);
													this->numbers.at(15) = (new CardRender(this->numbers.at(15)->getX(), this->numbers.at(15)->getY(), &this->textures[s]));
												}
												warPown->setPosition(808, warPown->getY());
												warTokens.at(0)->setPosition(0, 0);
												break;
											}
											case -6:
											{
												if (token5P1 == true)
												{
													player2.DecreaseMoney(5);
													token5P1 = false;
													int val = this->player2.GetMoney();
													std::string s = std::to_string(val);
													this->numbers.at(15) = (new CardRender(this->numbers.at(15)->getX(), this->numbers.at(15)->getY(), &this->textures[s]));

												}
												warPown->setPosition(834, warPown->getY());
												warTokens.at(0)->setPosition(0, 0);
												break;
											}
											case -5:
											{
												if (token2P1 == true)
												{
													player2.DecreaseMoney(2);
													token2P1 = false;
													int val = this->player2.GetMoney();
													std::string s = std::to_string(val);
													this->numbers.at(15) = (new CardRender(this->numbers.at(15)->getX(), this->numbers.at(15)->getY(), &this->textures[s]));

												}
												warPown->setPosition(860, warPown->getY());
												warTokens.at(1)->setPosition(0, 0);
												break;
											}
											case -4:
											{
												if (token2P1 == true)
												{
													player2.DecreaseMoney(2);
													token2P1 = false;
													int val = this->player2.GetMoney();
													std::string s = std::to_string(val);
													this->numbers.at(15) = (new CardRender(this->numbers.at(15)->getX(), this->numbers.at(15)->getY(), &this->textures[s]));
												}
												warPown->setPosition(886, warPown->getY());
												warTokens.at(1)->setPosition(0, 0);
												break;
											}
											case -3:
											{
												if (token2P1 == true)
												{
													player2.DecreaseMoney(2);
													token2P1 = false;
													int val = this->player2.GetMoney();
													std::string s = std::to_string(val);
													this->numbers.at(15) = (new CardRender(this->numbers.at(15)->getX(), this->numbers.at(15)->getY(), &this->textures[s]));
												}
												warPown->setPosition(912, warPown->getY());
												warTokens.at(1)->setPosition(0, 0);
												break;
											}
											case -2:
												warPown->setPosition(938, warPown->getY());
												break;

											case -1:
												warPown->setPosition(964, warPown->getY());
												break;
											case 0:
												warPown->setPosition(990, 85);
												break;
											case 1:
												warPown->setPosition(1016, warPown->getY());
												break;
											case 2:
												warPown->setPosition(1042, warPown->getY());
												break;
											case 3:
											{
												if (token2P2 == true)
												{
													player2.DecreaseMoney(2);
													token2P2 = false;
													int val = this->player1.GetMoney();
													std::string s = std::to_string(val);
													this->numbers.at(14) = (new CardRender(this->numbers.at(14)->getX(), this->numbers.at(14)->getY(), &this->textures[s]));

												}
												warPown->setPosition(1068, warPown->getY());
												warTokens.at(2)->setPosition(0, 0);
												break;
											}
											case 4:
											{
												if (token2P2 == true)
												{
													player2.DecreaseMoney(2);
													token2P2 = false;
													int val = this->player1.GetMoney();
													std::string s = std::to_string(val);
													this->numbers.at(14) = (new CardRender(this->numbers.at(14)->getX(), this->numbers.at(14)->getY(), &this->textures[s]));

												}
												warPown->setPosition(1094, warPown->getY());
												warTokens.at(2)->setPosition(0, 0);
												break;
											}
											case 5:
											{
												if (token2P2 == true)
												{
													player2.DecreaseMoney(2);
													token2P2 = false;
													int val = this->player1.GetMoney();
													std::string s = std::to_string(val);
													this->numbers.at(14) = (new CardRender(this->numbers.at(14)->getX(), this->numbers.at(14)->getY(), &this->textures[s]));

												}
												warPown->setPosition(1120, warPown->getY());
												warTokens.at(2)->setPosition(0, 0);
												break;
											}
											case 6:
											{
												if (token5P2 == true)
												{
													player2.DecreaseMoney(5);
													token5P2 = false;
													int val = this->player1.GetMoney();
													std::string s = std::to_string(val);
													this->numbers.at(14) = (new CardRender(this->numbers.at(14)->getX(), this->numbers.at(14)->getY(), &this->textures[s]));

												}

												warPown->setPosition(1146, warPown->getY());
												warTokens.at(3)->setPosition(0, 0);
												break;
											}
											case 7:
											{
												if (token5P2 == true)
												{
													player2.DecreaseMoney(5);
													token5P2 = false;
													int val = this->player1.GetMoney();
													std::string s = std::to_string(val);
													this->numbers.at(14) = (new CardRender(this->numbers.at(14)->getX(), this->numbers.at(14)->getY(), &this->textures[s]));

												}
												warPown->setPosition(1172, warPown->getY());
												warTokens.at(3)->setPosition(0, 0);
												break;
											}
											case 8:
											{
												if (token5P2 == true)
												{
													player2.DecreaseMoney(5);
													token5P2 = false;
													int val = this->player1.GetMoney();
													std::string s = std::to_string(val);
													this->numbers.at(14) = (new CardRender(this->numbers.at(14)->getX(), this->numbers.at(14)->getY(), &this->textures[s]));

												}
												warPown->setPosition(1198, warPown->getY());
												warTokens.at(3)->setPosition(0, 0);
												break;
											}
											case 9:
											{	warPown->setPosition(1224, warPown->getY());
											std::cout << "Win p2";
											this->GameOver(player2.GetName());
											break;
											}
											default:
												break;
											}

											break;
											break;
										}
										case Card::Color::Blue:
										{
											player1.SetVictoryPoints(m_mechanics.FindCard(cards.at(i)->getName(), deck3).GetPoints().size());
											int val = this->player1.GetVictoryPoints();
											std::string s = std::to_string(val);

											if (player1.GetName() == "User")
											{
												this->numbers.at(12) = (new CardRender(this->numbers.at(12)->getX(), this->numbers.at(12)->getY(), &this->textures[s]));
												cards.at(i)->setPosition(122, 730 + curentCardIndex);
											}

											if (player1.GetName() == "AI")
											{
												this->numbers.at(13) = (new CardRender(this->numbers.at(13)->getX(), this->numbers.at(13)->getY(), &this->textures[s]));
												cards.at(i)->setPosition(1688, 730 + curentCardIndex);
											}
											break;
										}
										case Card::Color::Brown:
										{
											if (player1.GetName() == "User")
											{
												switch (m_mechanics.FindCard(cards.at(i)->getName(), deck3).GetRawMaterial().GetRawMaterial())
												{
												case::RawMaterialsCLass::RawMaterials::Wood:
												{
													int val = m_mechanics.CountRawMaterialsWood(player1);
													std::string s = std::to_string(val);
													this->numbers.at(2) = (new CardRender(this->numbers.at(2)->getX(), this->numbers.at(2)->getY(), &this->textures[s]));
													break;
												}
												case::RawMaterialsCLass::RawMaterials::Clay:
												{
													int val = m_mechanics.CountRawMaterialsClay(player1);
													std::string s = std::to_string(val);
													this->numbers.at(0) = (new CardRender(this->numbers.at(0)->getX(), this->numbers.at(0)->getY(), &this->textures[s]));
													break;
												}
												case::RawMaterialsCLass::RawMaterials::Stone:
												{
													int val = m_mechanics.CountRawMaterialsStone(player1);
													std::string s = std::to_string(val);
													this->numbers.at(4) = (new CardRender(this->numbers.at(4)->getX(), this->numbers.at(4)->getY(), &this->textures[s]));
													break;
												}
												default:
													break;
												}
												cards.at(i)->setPosition(244, 730 + curentCardIndex);
											}

											if (player1.GetName() == "AI")
											{
												switch (m_mechanics.FindCard(cards.at(i)->getName(), deck3).GetRawMaterial().GetRawMaterial())
												{
												case::RawMaterialsCLass::RawMaterials::Wood:
												{
													int val = m_mechanics.CountRawMaterialsWood(player1);
													std::string s = std::to_string(val);
													this->numbers.at(3) = (new CardRender(this->numbers.at(3)->getX(), this->numbers.at(3)->getY(), &this->textures[s]));
													break;
												}
												case::RawMaterialsCLass::RawMaterials::Clay:
												{
													int val = m_mechanics.CountRawMaterialsClay(player1);
													std::string s = std::to_string(val);
													this->numbers.at(1) = (new CardRender(this->numbers.at(1)->getX(), this->numbers.at(1)->getY(), &this->textures[s]));
													break;
												}
												case::RawMaterialsCLass::RawMaterials::Stone:
												{
													int val = m_mechanics.CountRawMaterialsStone(player1);
													std::string s = std::to_string(val);
													this->numbers.at(5) = (new CardRender(this->numbers.at(5)->getX(), this->numbers.at(5)->getY(), &this->textures[s]));
													break;
												}
												default:
													break;
												}
												cards.at(i)->setPosition(1566, 730 + curentCardIndex);
											}
											break;
										}
										case Card::Color::Green:
										{
									


											if (m_mechanics.CountSymbolInPlayersDeck(player1) == true)
											{
												duplicateSymbol = true;
												m_mechanics.PickToken(player1, this->activeProgressTokens, tokenName);
											}

											player1.SetVictoryPoints(m_mechanics.FindCard(cards.at(i)->getName(), deck3).GetPoints().size());
											int val = this->player1.GetVictoryPoints();
											std::string s = std::to_string(val);

											if (player1.GetName() == "User")
											{
												this->numbers.at(12) = (new CardRender(this->numbers.at(12)->getX(), this->numbers.at(12)->getY(), &this->textures[s]));
												cards.at(i)->setPosition(366, 730 + curentCardIndex);
											}

											if (player1.GetName() == "AI")
											{
												this->numbers.at(13) = (new CardRender(this->numbers.at(13)->getX(), this->numbers.at(13)->getY(), &this->textures[s]));
												cards.at(i)->setPosition(1444, 730 + curentCardIndex);
											}
											break;
										}
										case Card::Color::Grey:
										{
											if (player1.GetName() == "User")
											{
												switch (m_mechanics.FindCard(cards.at(i)->getName(), deck3).GetManufGood().GetManufacturedGood())
												{
												case::ManufacturedGoodsClass::ManufacturedGoods::Glass:
												{
													int val = m_mechanics.CountMaterialsGoodsGlass(player1);
													std::string s = std::to_string(val);
													this->numbers.at(6) = (new CardRender(this->numbers.at(6)->getX(), this->numbers.at(6)->getY(), &this->textures[s]));
													break;
												}
												case::ManufacturedGoodsClass::ManufacturedGoods::Papirus:
												{
													int val = m_mechanics.CountMaterialsGoodsPapirus(player1);
													std::string s = std::to_string(val);
													this->numbers.at(8) = (new CardRender(this->numbers.at(8)->getX(), this->numbers.at(8)->getY(), &this->textures[s]));
													break;
												}
												default:
													break;
												}
												cards.at(i)->setPosition(488, 730 + curentCardIndex);
											}

											if (player1.GetName() == "AI")
											{
												switch (m_mechanics.FindCard(cards.at(i)->getName(), deck3).GetManufGood().GetManufacturedGood())
												{
												case::ManufacturedGoodsClass::ManufacturedGoods::Glass:
												{
													int val = m_mechanics.CountMaterialsGoodsGlass(player1);
													std::string s = std::to_string(val);
													this->numbers.at(7) = (new CardRender(this->numbers.at(7)->getX(), this->numbers.at(7)->getY(), &this->textures[s]));
													break;
												}
												case::ManufacturedGoodsClass::ManufacturedGoods::Papirus:
												{
													int val = m_mechanics.CountMaterialsGoodsPapirus(player1);
													std::string s = std::to_string(val);
													this->numbers.at(9) = (new CardRender(this->numbers.at(9)->getX(), this->numbers.at(9)->getY(), &this->textures[s]));
													break;
												}
												default:
													break;
												}
												cards.at(i)->setPosition(1322, 730 + curentCardIndex);
											}
											break;
										}
										case Card::Color::Purple:
											if (player1.GetName() == "User")
											{
												cards.at(i)->setPosition(610, 730 + curentCardIndex);
											}

											if (player1.GetName() == "AI")
											{
												cards.at(i)->setPosition(1200, 730 + curentCardIndex);
											}
											break;
										case Card::Color::Yellow:
											if (player1.GetName() == "User")
											{
												cards.at(i)->setPosition(732, 730 + curentCardIndex);
											}

											if (player1.GetName() == "AI")
											{
												cards.at(i)->setPosition(1000, 730 + curentCardIndex);
											}
											break;
										default:
											break;
										}
										allCardsPressed++;
										bot.isActive = true;
										std::swap(player1, player2);
									}
									else
										break;

									break;

								default:
									break;
								}


							}
							else
							{

							taken.at(i) = 0;
								cards.at(i)->setPosition(1700, 0);
								for (int j = 0; j < cards.size(); j++)
								{
									if (st.at(j) == i + 1)
										st.at(j) = 0;
									if (dr.at(j) == i + 1)
										dr.at(j) = 0;
									if (st.at(j) == 0 && dr.at(j) == 0)
									{
										fliped.at(j) = false;
										if (fliped.at(j) == false)
										{
											cards.at(j) = new CardRender(cards.at(j)->getX(), cards.at(j)->getY(), &this->textures[this->cardNames[j]], sf::Color(0, 0, 0, 0),
												sf::Color(10, 10, 10, 200), sf::Color(0, 0, 0, 0), this->cardNames[j]);
										}
									}

								}
								allCardsPressed++;
								player1.AddMoney(2);
								int val = this->player1.GetMoney();
								std::string s = std::to_string(val);

								if (player1.GetName() == "User")
								{
									this->numbers.at(14) = (new CardRender(this->numbers.at(14)->getX(), this->numbers.at(14)->getY(), &this->textures[s]));

								}
								else
									this->numbers.at(15) = (new CardRender(this->numbers.at(15)->getX(), this->numbers.at(15)->getY(), &this->textures[s]));
								bot.isActive = true;
								std::swap(player1, player2);
							}
						}
					cards.at(i)->update(this->mousePosView);



				}
			}
				else
				{
					std::this_thread::sleep_for(m_processingTime);
					int i = bot.PickCard(cards, dr, st, deck, taken, fliped, m_mechanics, curentCardIndex);

					

					switch (this->curentTurn)
					{
					case GameMechanics::Turn::First:
						if (m_mechanics.UsingCard(player1, player2, m_mechanics.FindCard(cards.at(i)->getName(), deck), deck, this->activeProgressTokens) == true)
						{
							curentCardIndex = i;
							taken.at(i) = 0;
							int val = this->player1.GetMoney();
							std::string s = std::to_string(val);

							
								this->numbers.at(15) = (new CardRender(this->numbers.at(15)->getX(), this->numbers.at(15)->getY(), &this->textures[s]));


							for (int j = 0; j < cards.size(); j++)
							{
								if (st.at(j) == i + 1)
									st.at(j) = 0;
								if (dr.at(j) == i + 1)
									dr.at(j) = 0;
								if (st.at(j) == 0 && dr.at(j) == 0)
								{
									fliped.at(j) = false;
									if (fliped.at(j) == false)
									{
										cards.at(j) = new CardRender(cards.at(j)->getX(), cards.at(j)->getY(), &this->textures[this->cardNames[j]], sf::Color(0, 0, 0, 0),
											sf::Color(10, 10, 10, 200), sf::Color(0, 0, 0, 0), this->cardNames[j]);
									}
								}

							}
							Card::Color curentCardColor = m_mechanics.FindCard(cards.at(i)->getName(), deck).GetColor();
							int curentCardIndex = 20 * m_mechanics.CountBuildingsByColor(curentCardColor, player1);

							switch (curentCardColor)
							{
							case Card::Color::Red:
							{
								player1.SetMilitarryPoints(m_mechanics.FindCard(cards.at(i)->getName(), deck).GetPoints().size());
								int val = this->player1.GetMilitarryPoints();
								std::string s = std::to_string(val);
								
								if (player1.GetName() == "AI")
								{
									this->numbers.at(11) = (new CardRender(this->numbers.at(11)->getX(), this->numbers.at(11)->getY(), &this->textures[s]));
									cards.at(i)->setPosition(1810, 730 + curentCardIndex);
								}




								int aux = this->player1.GetMilitarryPoints() - this->player2.GetMilitarryPoints();
								if (aux == 9 || aux == -9)
								{
									this->GameOver(player1.GetName());
								}
								switch (aux)
								{

								case -9:
									warPown->setPosition(762, warPown->getY());
									std::cout << "Win p1";
									this->GameOver(player1.GetName());
									break;
								case -8:
								{
									if (token5P1 == true)
									{
										player2.DecreaseMoney(5);
										token5P1 = false;
										int val = this->player2.GetMoney();
										std::string s = std::to_string(val);
										this->numbers.at(15) = (new CardRender(this->numbers.at(15)->getX(), this->numbers.at(15)->getY(), &this->textures[s]));
									}
									warPown->setPosition(782, warPown->getY());
									warTokens.at(0)->setPosition(0, 0);
									break;
								}
								case -7:
								{
									if (token5P1 == true)
									{
										player2.DecreaseMoney(5);
										token5P1 = false;
										int val = this->player2.GetMoney();
										std::string s = std::to_string(val);
										this->numbers.at(15) = (new CardRender(this->numbers.at(15)->getX(), this->numbers.at(15)->getY(), &this->textures[s]));
									}
									warPown->setPosition(808, warPown->getY());
									warTokens.at(0)->setPosition(0, 0);
									break;
								}
								case -6:
								{
									if (token5P1 == true)
									{
										player2.DecreaseMoney(5);
										token5P1 = false;
										int val = this->player2.GetMoney();
										std::string s = std::to_string(val);
										this->numbers.at(15) = (new CardRender(this->numbers.at(15)->getX(), this->numbers.at(15)->getY(), &this->textures[s]));

									}
									warPown->setPosition(834, warPown->getY());
									warTokens.at(0)->setPosition(0, 0);
									break;
								}
								case -5:
								{
									if (token2P1 == true)
									{
										player2.DecreaseMoney(2);
										token2P1 = false;
										int val = this->player2.GetMoney();
										std::string s = std::to_string(val);
										this->numbers.at(15) = (new CardRender(this->numbers.at(15)->getX(), this->numbers.at(15)->getY(), &this->textures[s]));

									}
									warPown->setPosition(860, warPown->getY());
									warTokens.at(1)->setPosition(0, 0);
									break;
								}
								case -4:
								{
									if (token2P1 == true)
									{
										player2.DecreaseMoney(2);
										token2P1 = false;
										int val = this->player2.GetMoney();
										std::string s = std::to_string(val);
										this->numbers.at(15) = (new CardRender(this->numbers.at(15)->getX(), this->numbers.at(15)->getY(), &this->textures[s]));
									}
									warPown->setPosition(886, warPown->getY());
									warTokens.at(1)->setPosition(0, 0);
									break;
								}
								case -3:
								{
									if (token2P1 == true)
									{
										player2.DecreaseMoney(2);
										token2P1 = false;
										int val = this->player2.GetMoney();
										std::string s = std::to_string(val);
										this->numbers.at(15) = (new CardRender(this->numbers.at(15)->getX(), this->numbers.at(15)->getY(), &this->textures[s]));
									}
									warPown->setPosition(912, warPown->getY());
									warTokens.at(1)->setPosition(0, 0);
									break;
								}
								case -2:
									warPown->setPosition(938, warPown->getY());
									break;

								case -1:
									warPown->setPosition(964, warPown->getY());
									break;
								case 0:
									warPown->setPosition(990, 85);
									break;
								case 1:
									warPown->setPosition(1016, warPown->getY());
									break;
								case 2:
									warPown->setPosition(1042, warPown->getY());
									break;
								case 3:
								{
									if (token2P2 == true)
									{
										player2.DecreaseMoney(2);
										token2P2 = false;
										int val = this->player1.GetMoney();
										std::string s = std::to_string(val);
										this->numbers.at(14) = (new CardRender(this->numbers.at(14)->getX(), this->numbers.at(14)->getY(), &this->textures[s]));

									}
									warPown->setPosition(1068, warPown->getY());
									warTokens.at(2)->setPosition(0, 0);
									break;
								}
								case 4:
								{
									if (token2P2 == true)
									{
										player2.DecreaseMoney(2);
										token2P2 = false;
										int val = this->player1.GetMoney();
										std::string s = std::to_string(val);
										this->numbers.at(14) = (new CardRender(this->numbers.at(14)->getX(), this->numbers.at(14)->getY(), &this->textures[s]));

									}
									warPown->setPosition(1094, warPown->getY());
									warTokens.at(2)->setPosition(0, 0);
									break;
								}
								case 5:
								{
									if (token2P2 == true)
									{
										player2.DecreaseMoney(2);
										token2P2 = false;
										int val = this->player1.GetMoney();
										std::string s = std::to_string(val);
										this->numbers.at(14) = (new CardRender(this->numbers.at(14)->getX(), this->numbers.at(14)->getY(), &this->textures[s]));

									}
									warPown->setPosition(1120, warPown->getY());
									warTokens.at(2)->setPosition(0, 0);
									break;
								}
								case 6:
								{
									if (token5P2 == true)
									{
										player2.DecreaseMoney(5);
										token5P2 = false;
										int val = this->player1.GetMoney();
										std::string s = std::to_string(val);
										this->numbers.at(14) = (new CardRender(this->numbers.at(14)->getX(), this->numbers.at(14)->getY(), &this->textures[s]));

									}

									warPown->setPosition(1146, warPown->getY());
									warTokens.at(3)->setPosition(0, 0);
									break;
								}
								case 7:
								{
									if (token5P2 == true)
									{
										player2.DecreaseMoney(5);
										token5P2 = false;
										int val = this->player1.GetMoney();
										std::string s = std::to_string(val);
										this->numbers.at(14) = (new CardRender(this->numbers.at(14)->getX(), this->numbers.at(14)->getY(), &this->textures[s]));

									}
									warPown->setPosition(1172, warPown->getY());
									warTokens.at(3)->setPosition(0, 0);
									break;
								}
								case 8:
								{
									if (token5P2 == true)
									{
										player2.DecreaseMoney(5);
										token5P2 = false;
										int val = this->player1.GetMoney();
										std::string s = std::to_string(val);
										this->numbers.at(14) = (new CardRender(this->numbers.at(14)->getX(), this->numbers.at(14)->getY(), &this->textures[s]));

									}
									warPown->setPosition(1198, warPown->getY());
									warTokens.at(3)->setPosition(0, 0);
									break;
								}
								case 9:
								{	warPown->setPosition(1224, warPown->getY());
								std::cout << "Win p2";
								this->GameOver(player2.GetName());
								break;
								}
								default:
									break;
								}

								break;
							}
							case Card::Color::Blue:
							{
								player1.SetVictoryPoints(m_mechanics.FindCard(cards.at(i)->getName(), deck).GetPoints().size());
								int val = this->player1.GetVictoryPoints();
								std::string s = std::to_string(val);

								

								if (player1.GetName() == "AI")
								{
									this->numbers.at(13) = (new CardRender(this->numbers.at(13)->getX(), this->numbers.at(13)->getY(), &this->textures[s]));
									cards.at(i)->setPosition(1688, 730 + curentCardIndex);
								}
								break;
							}
							case Card::Color::Brown:
							{
								
								if (player1.GetName() == "AI")
								{
									switch (m_mechanics.FindCard(cards.at(i)->getName(), deck).GetRawMaterial().GetRawMaterial())
									{
									case::RawMaterialsCLass::RawMaterials::Wood:
									{
										int val = m_mechanics.CountRawMaterialsWood(player1);
										std::string s = std::to_string(val);
										this->numbers.at(3) = (new CardRender(this->numbers.at(3)->getX(), this->numbers.at(3)->getY(), &this->textures[s]));
										break;
									}
									case::RawMaterialsCLass::RawMaterials::Clay:
									{
										int val = m_mechanics.CountRawMaterialsClay(player1);
										std::string s = std::to_string(val);
										this->numbers.at(1) = (new CardRender(this->numbers.at(1)->getX(), this->numbers.at(1)->getY(), &this->textures[s]));
										break;
									}
									case::RawMaterialsCLass::RawMaterials::Stone:
									{
										int val = m_mechanics.CountRawMaterialsStone(player1);
										std::string s = std::to_string(val);
										this->numbers.at(5) = (new CardRender(this->numbers.at(5)->getX(), this->numbers.at(5)->getY(), &this->textures[s]));
										break;
									}
									default:
										break;
									}
									cards.at(i)->setPosition(1566, 730 + curentCardIndex);
								}
								break;
							}
							case Card::Color::Green:
							{


								if (m_mechanics.CountSymbolInPlayersDeck(player1) == true)
								{
									duplicateSymbol = true;
									m_mechanics.PickToken(player1, this->activeProgressTokens, tokenName);
								}

								player1.SetVictoryPoints(m_mechanics.FindCard(cards.at(i)->getName(), deck).GetPoints().size());
								int val = this->player1.GetVictoryPoints();
								std::string s = std::to_string(val);

								
								if (player1.GetName() == "AI")
								{
									this->numbers.at(13) = (new CardRender(this->numbers.at(13)->getX(), this->numbers.at(13)->getY(), &this->textures[s]));
									cards.at(i)->setPosition(1444, 730 + curentCardIndex);
								}
								break;
							}
							case Card::Color::Grey:
							{
								
								if (player1.GetName() == "AI")
								{
									switch (m_mechanics.FindCard(cards.at(i)->getName(), deck).GetManufGood().GetManufacturedGood())
									{
									case::ManufacturedGoodsClass::ManufacturedGoods::Glass:
									{
										int val = m_mechanics.CountMaterialsGoodsGlass(player1);
										std::string s = std::to_string(val);
										this->numbers.at(7) = (new CardRender(this->numbers.at(7)->getX(), this->numbers.at(7)->getY(), &this->textures[s]));
										break;
									}
									case::ManufacturedGoodsClass::ManufacturedGoods::Papirus:
									{
										int val = m_mechanics.CountMaterialsGoodsPapirus(player1);
										std::string s = std::to_string(val);
										this->numbers.at(9) = (new CardRender(this->numbers.at(9)->getX(), this->numbers.at(9)->getY(), &this->textures[s]));
										break;
									}
									default:
										break;
									}
									cards.at(i)->setPosition(1322, 730 + curentCardIndex);
								}
								break;
							}
							case Card::Color::Purple:
							{
								

								if (player1.GetName() == "AI")
								{
									cards.at(i)->setPosition(1200, 730 + curentCardIndex);
								}
								break;
							}
							case Card::Color::Yellow:
							{
								

								if (player1.GetName() == "AI")
								{
									cards.at(i)->setPosition(1000, 730 + curentCardIndex);
								}
								break;
							}
							default:
								break;
							}
							allCardsPressed++;
							//bot.isActive = true;
							bot.dataSource = player2;
							std::swap(player1, player2);
						}
						else
							break;

						break;

					}



				 }
			}
			else
			{
			if (st.at(i) == 0 && dr.at(i) == 0)
			{

				if (cards.at(i)->isPressed())
				{
					if (!cards.at(i)->isPressedR())
					{

						switch (this->curentTurn)
						{
						case GameMechanics::Turn::First:
							if (m_mechanics.UsingCard(player1, player2, m_mechanics.FindCard(cards.at(i)->getName(), deck), deck, this->activeProgressTokens) == true)
							{
								
								int val = this->player1.GetMoney();
								std::string s = std::to_string(val);

								if (player1.GetName() == "User")
								{
									this->numbers.at(14) = (new CardRender(this->numbers.at(14)->getX(), this->numbers.at(14)->getY(), &this->textures[s]));

								}
								else
									this->numbers.at(15) = (new CardRender(this->numbers.at(15)->getX(), this->numbers.at(15)->getY(), &this->textures[s]));


								for (int j = 0; j < cards.size(); j++)
								{
									if (st.at(j) == i + 1)
										st.at(j) = 0;
									if (dr.at(j) == i + 1)
										dr.at(j) = 0;
									if (st.at(j) == 0 && dr.at(j) == 0)
									{
										fliped.at(j) = false;
										if (fliped.at(j) == false)
										{
											cards.at(j) = new CardRender(cards.at(j)->getX(), cards.at(j)->getY(), &this->textures[this->cardNames[j]], sf::Color(0, 0, 0, 0),
												sf::Color(10, 10, 10, 200), sf::Color(0, 0, 0, 0), this->cardNames[j]);
										}
									}

								}
								Card::Color curentCardColor = m_mechanics.FindCard(cards.at(i)->getName(), deck).GetColor();
								int curentCardIndex = 20 * m_mechanics.CountBuildingsByColor(curentCardColor, player1);

								switch (curentCardColor)
								{
								case Card::Color::Red:
								{
									player1.SetMilitarryPoints(m_mechanics.FindCard(cards.at(i)->getName(), deck).GetPoints().size());
									int val = this->player1.GetMilitarryPoints();
									std::string s = std::to_string(val);
									if (player1.GetName() == "User")
									{
										this->numbers.at(10) = (new CardRender(this->numbers.at(10)->getX(), this->numbers.at(10)->getY(), &this->textures[s]));
										cards.at(i)->setPosition(0, 730 + curentCardIndex);
									}

									if (player1.GetName() == "AI")
									{
										this->numbers.at(11) = (new CardRender(this->numbers.at(11)->getX(), this->numbers.at(11)->getY(), &this->textures[s]));
										cards.at(i)->setPosition(1810, 730 + curentCardIndex);
									}




									int aux = this->player1.GetMilitarryPoints() - this->player2.GetMilitarryPoints();
									if (aux == 9 || aux == -9)
									{
										this->GameOver(player1.GetName());
									}
									switch (aux)
									{

									case -9:
										warPown->setPosition(762, warPown->getY());
										std::cout << "Win p1";
										this->GameOver(player1.GetName());
										break;
									case -8:
									{
										if (token5P1 == true)
										{
											player2.DecreaseMoney(5);
											token5P1 = false;
											int val = this->player2.GetMoney();
											std::string s = std::to_string(val);
											this->numbers.at(15) = (new CardRender(this->numbers.at(15)->getX(), this->numbers.at(15)->getY(), &this->textures[s]));
										}
										warPown->setPosition(782, warPown->getY());
										warTokens.at(0)->setPosition(0, 0);
										break;
									}
									case -7:
									{
										if (token5P1 == true)
										{
											player2.DecreaseMoney(5);
											token5P1 = false;
											int val = this->player2.GetMoney();
											std::string s = std::to_string(val);
											this->numbers.at(15) = (new CardRender(this->numbers.at(15)->getX(), this->numbers.at(15)->getY(), &this->textures[s]));
										}
										warPown->setPosition(808, warPown->getY());
										warTokens.at(0)->setPosition(0, 0);
										break;
									}
									case -6:
									{
										if (token5P1 == true)
										{
											player2.DecreaseMoney(5);
											token5P1 = false;
											int val = this->player2.GetMoney();
											std::string s = std::to_string(val);
											this->numbers.at(15) = (new CardRender(this->numbers.at(15)->getX(), this->numbers.at(15)->getY(), &this->textures[s]));

										}
										warPown->setPosition(834, warPown->getY());
										warTokens.at(0)->setPosition(0, 0);
										break;
									}
									case -5:
									{
										if (token2P1 == true)
										{
											player2.DecreaseMoney(2);
											token2P1 = false;
											int val = this->player2.GetMoney();
											std::string s = std::to_string(val);
											this->numbers.at(15) = (new CardRender(this->numbers.at(15)->getX(), this->numbers.at(15)->getY(), &this->textures[s]));

										}
										warPown->setPosition(860, warPown->getY());
										warTokens.at(1)->setPosition(0, 0);
										break;
									}
									case -4:
									{
										if (token2P1 == true)
										{
											player2.DecreaseMoney(2);
											token2P1 = false;
											int val = this->player2.GetMoney();
											std::string s = std::to_string(val);
											this->numbers.at(15) = (new CardRender(this->numbers.at(15)->getX(), this->numbers.at(15)->getY(), &this->textures[s]));
										}
										warPown->setPosition(886, warPown->getY());
										warTokens.at(1)->setPosition(0, 0);
										break;
									}
									case -3:
									{
										if (token2P1 == true)
										{
											player2.DecreaseMoney(2);
											token2P1 = false;
											int val = this->player2.GetMoney();
											std::string s = std::to_string(val);
											this->numbers.at(15) = (new CardRender(this->numbers.at(15)->getX(), this->numbers.at(15)->getY(), &this->textures[s]));
										}
										warPown->setPosition(912, warPown->getY());
										warTokens.at(1)->setPosition(0, 0);
										break;
									}
									case -2:
										warPown->setPosition(938, warPown->getY());
										break;

									case -1:
										warPown->setPosition(964, warPown->getY());
										break;
									case 0:
										warPown->setPosition(990, 85);
										break;
									case 1:
										warPown->setPosition(1016, warPown->getY());
										break;
									case 2:
										warPown->setPosition(1042, warPown->getY());
										break;
									case 3:
									{
										if (token2P2 == true)
										{
											player2.DecreaseMoney(2);
											token2P2 = false;
											int val = this->player1.GetMoney();
											std::string s = std::to_string(val);
											this->numbers.at(14) = (new CardRender(this->numbers.at(14)->getX(), this->numbers.at(14)->getY(), &this->textures[s]));

										}
										warPown->setPosition(1068, warPown->getY());
										warTokens.at(2)->setPosition(0, 0);
										break;
									}
									case 4:
									{
										if (token2P2 == true)
										{
											player2.DecreaseMoney(2);
											token2P2 = false;
											int val = this->player1.GetMoney();
											std::string s = std::to_string(val);
											this->numbers.at(14) = (new CardRender(this->numbers.at(14)->getX(), this->numbers.at(14)->getY(), &this->textures[s]));

										}
										warPown->setPosition(1094, warPown->getY());
										warTokens.at(2)->setPosition(0, 0);
										break;
									}
									case 5:
									{
										if (token2P2 == true)
										{
											player2.DecreaseMoney(2);
											token2P2 = false;
											int val = this->player1.GetMoney();
											std::string s = std::to_string(val);
											this->numbers.at(14) = (new CardRender(this->numbers.at(14)->getX(), this->numbers.at(14)->getY(), &this->textures[s]));

										}
										warPown->setPosition(1120, warPown->getY());
										warTokens.at(2)->setPosition(0, 0);
										break;
									}
									case 6:
									{
										if (token5P2 == true)
										{
											player2.DecreaseMoney(5);
											token5P2 = false;
											int val = this->player1.GetMoney();
											std::string s = std::to_string(val);
											this->numbers.at(14) = (new CardRender(this->numbers.at(14)->getX(), this->numbers.at(14)->getY(), &this->textures[s]));

										}

										warPown->setPosition(1146, warPown->getY());
										warTokens.at(3)->setPosition(0, 0);
										break;
									}
									case 7:
									{
										if (token5P2 == true)
										{
											player2.DecreaseMoney(5);
											token5P2 = false;
											int val = this->player1.GetMoney();
											std::string s = std::to_string(val);
											this->numbers.at(14) = (new CardRender(this->numbers.at(14)->getX(), this->numbers.at(14)->getY(), &this->textures[s]));

										}
										warPown->setPosition(1172, warPown->getY());
										warTokens.at(3)->setPosition(0, 0);
										break;
									}
									case 8:
									{
										if (token5P2 == true)
										{
											player2.DecreaseMoney(5);
											token5P2 = false;
											int val = this->player1.GetMoney();
											std::string s = std::to_string(val);
											this->numbers.at(14) = (new CardRender(this->numbers.at(14)->getX(), this->numbers.at(14)->getY(), &this->textures[s]));

										}
										warPown->setPosition(1198, warPown->getY());
										warTokens.at(3)->setPosition(0, 0);
										break;
									}
									case 9:
									{	warPown->setPosition(1224, warPown->getY());
									std::cout << "Win p2";
									this->GameOver(player2.GetName());
									break;
									}
									default:
										break;
									}

									break;
								}
								case Card::Color::Blue:
								{
									player1.SetVictoryPoints(m_mechanics.FindCard(cards.at(i)->getName(), deck).GetPoints().size());
									int val = this->player1.GetVictoryPoints();
									std::string s = std::to_string(val);

									if (player1.GetName() == "User")
									{
										this->numbers.at(12) = (new CardRender(this->numbers.at(12)->getX(), this->numbers.at(12)->getY(), &this->textures[s]));
										cards.at(i)->setPosition(122, 730 + curentCardIndex);
									}

									if (player1.GetName() == "AI")
									{
										this->numbers.at(13) = (new CardRender(this->numbers.at(13)->getX(), this->numbers.at(13)->getY(), &this->textures[s]));
										cards.at(i)->setPosition(1688, 730 + curentCardIndex);
									}
									break;
								}
								case Card::Color::Brown:
								{
									
									if (player1.GetName() == "User")
									{
										switch (m_mechanics.FindCard(cards.at(i)->getName(), deck).GetRawMaterial().GetRawMaterial())
										{
										case::RawMaterialsCLass::RawMaterials::Wood:
										{
											int val = m_mechanics.CountRawMaterialsWood(player1);
											std::string s = std::to_string(val);
											this->numbers.at(2) = (new CardRender(this->numbers.at(2)->getX(), this->numbers.at(2)->getY(), &this->textures[s]));
											break;
										}
										case::RawMaterialsCLass::RawMaterials::Clay:
										{
											int val = m_mechanics.CountRawMaterialsClay(player1);
											std::string s = std::to_string(val);
											this->numbers.at(0) = (new CardRender(this->numbers.at(0)->getX(), this->numbers.at(0)->getY(), &this->textures[s]));
											break;
										}
										case::RawMaterialsCLass::RawMaterials::Stone:
										{
											int val = m_mechanics.CountRawMaterialsStone(player1);
											std::string s = std::to_string(val);
											this->numbers.at(4) = (new CardRender(this->numbers.at(4)->getX(), this->numbers.at(4)->getY(), &this->textures[s]));
											break;
										}
										default:
											break;
										}
										cards.at(i)->setPosition(244, 730 + curentCardIndex);
									}

									if (player1.GetName() == "AI")
									{
										switch (m_mechanics.FindCard(cards.at(i)->getName(), deck).GetRawMaterial().GetRawMaterial())
										{
										case::RawMaterialsCLass::RawMaterials::Wood:
										{
											int val = m_mechanics.CountRawMaterialsWood(player1);
											std::string s = std::to_string(val);
											this->numbers.at(3) = (new CardRender(this->numbers.at(3)->getX(), this->numbers.at(3)->getY(), &this->textures[s]));
											break;
										}
										case::RawMaterialsCLass::RawMaterials::Clay:
										{
											int val = m_mechanics.CountRawMaterialsClay(player1);
											std::string s = std::to_string(val);
											this->numbers.at(1) = (new CardRender(this->numbers.at(1)->getX(), this->numbers.at(1)->getY(), &this->textures[s]));
											break;
										}
										case::RawMaterialsCLass::RawMaterials::Stone:
										{
											int val = m_mechanics.CountRawMaterialsStone(player1);
											std::string s = std::to_string(val);
											this->numbers.at(5) = (new CardRender(this->numbers.at(5)->getX(), this->numbers.at(5)->getY(), &this->textures[s]));
											break;
										}
										default:
											break;
										}
										cards.at(i)->setPosition(1566, 730 + curentCardIndex);
									}
									break;
								}
								case Card::Color::Green:
								{
									
									if (m_mechanics.CountSymbolInPlayersDeck(player1) == true)
									{
										duplicateSymbol = true;
										m_mechanics.PickToken(player1, this->activeProgressTokens, tokenName);
									}

									player1.SetVictoryPoints(m_mechanics.FindCard(cards.at(i)->getName(), deck).GetPoints().size());
									int val = this->player1.GetVictoryPoints();
									std::string s = std::to_string(val);

									if (player1.GetName() == "User")
									{
										this->numbers.at(12) = (new CardRender(this->numbers.at(12)->getX(), this->numbers.at(12)->getY(), &this->textures[s]));
										cards.at(i)->setPosition(366, 730 + curentCardIndex);
									}

									if (player1.GetName() == "AI")
									{
										this->numbers.at(13) = (new CardRender(this->numbers.at(13)->getX(), this->numbers.at(13)->getY(), &this->textures[s]));
										cards.at(i)->setPosition(1444, 730 + curentCardIndex);
									}
									break;
								}
								case Card::Color::Grey:
								{
									if (player1.GetName() == "User")
									{
										ManufacturedGoodsClass::ManufacturedGoods good = m_mechanics.FindCard(cards.at(i)->getName(), deck).GetManufGood().GetManufacturedGood();
										switch (good)
										{
										case::ManufacturedGoodsClass::ManufacturedGoods::Glass:
										{
											int val = m_mechanics.CountMaterialsGoodsGlass(player1);
											std::string s = std::to_string(val);
											this->numbers.at(6) = (new CardRender(this->numbers.at(6)->getX(), this->numbers.at(6)->getY(), &this->textures[s]));
											break;
										}
										case::ManufacturedGoodsClass::ManufacturedGoods::Papirus:
										{
											int val = m_mechanics.CountMaterialsGoodsPapirus(player1);
											std::string s = std::to_string(val);
											this->numbers.at(8) = (new CardRender(this->numbers.at(8)->getX(), this->numbers.at(8)->getY(), &this->textures[s]));
											break;
										}
										default:
											break;
										}
										cards.at(i)->setPosition(488, 730 + curentCardIndex);
									}

									if (player1.GetName() == "AI")
									{
										switch (m_mechanics.FindCard(cards.at(i)->getName(), deck).GetManufGood().GetManufacturedGood())
										{
										case::ManufacturedGoodsClass::ManufacturedGoods::Glass:
										{
											int val = m_mechanics.CountMaterialsGoodsGlass(player1);
											std::string s = std::to_string(val);
											this->numbers.at(7) = (new CardRender(this->numbers.at(7)->getX(), this->numbers.at(7)->getY(), &this->textures[s]));
											break;
										}
										case::ManufacturedGoodsClass::ManufacturedGoods::Papirus:
										{
											int val = m_mechanics.CountMaterialsGoodsPapirus(player1);
											std::string s = std::to_string(val);
											this->numbers.at(9) = (new CardRender(this->numbers.at(9)->getX(), this->numbers.at(9)->getY(), &this->textures[s]));
											break;
										}
										default:
											break;
										}
										cards.at(i)->setPosition(1322, 730 + curentCardIndex);
									}
									break;
								}
								case Card::Color::Purple:
								{
									if (player1.GetName() == "User")
									{
										cards.at(i)->setPosition(610, 730 + curentCardIndex);
									}

									if (player1.GetName() == "AI")
									{
										cards.at(i)->setPosition(1200, 730 + curentCardIndex);
									}
									break;
								}
								case Card::Color::Yellow:
								{
									if (player1.GetName() == "User")
									{
										cards.at(i)->setPosition(732, 730 + curentCardIndex);
									}

									if (player1.GetName() == "AI")
									{
										cards.at(i)->setPosition(1000, 730 + curentCardIndex);
									}
									break;
								}
								default:
									break;
								}
								allCardsPressed++;
								
								std::swap(player1, player2);
							}
							else
								break;

							break;

						case GameMechanics::Turn::Second:

							if (m_mechanics.UsingCard(player1, player2, m_mechanics.FindCard(cards.at(i)->getName(), deck2), deck2, this->activeProgressTokens) == true)
							{
								int val = this->player1.GetMoney();
								std::string s = std::to_string(val);

								int wood = m_mechanics.CountRawMaterialsWood(player1);
								std::string swood = std::to_string(wood);
								int stone = m_mechanics.CountRawMaterialsStone(player1);
								std::string sstone = std::to_string(stone);
								int clay = m_mechanics.CountRawMaterialsClay(player1);
								std::string sclay = std::to_string(clay);
								
								int glass = m_mechanics.CountMaterialsGoodsGlass(player1);
								std::string sglass = std::to_string(glass);
								int papirus = m_mechanics.CountMaterialsGoodsPapirus(player1);
								std::string spapirus = std::to_string(papirus);

								if (player1.GetName() == "User")
								{
									this->numbers.at(0) = (new CardRender(this->numbers.at(0)->getX(), this->numbers.at(0)->getY(), &this->textures[sclay]));
									this->numbers.at(2) = (new CardRender(this->numbers.at(2)->getX(), this->numbers.at(2)->getY(), &this->textures[swood]));
									this->numbers.at(4) = (new CardRender(this->numbers.at(4)->getX(), this->numbers.at(4)->getY(), &this->textures[sstone]));
									this->numbers.at(6) = (new CardRender(this->numbers.at(6)->getX(), this->numbers.at(6)->getY(), &this->textures[sstone]));
									this->numbers.at(8) = (new CardRender(this->numbers.at(8)->getX(), this->numbers.at(8)->getY(), &this->textures[sstone]));

									this->numbers.at(14) = (new CardRender(this->numbers.at(14)->getX(), this->numbers.at(14)->getY(), &this->textures[s]));

								}
								else
								{

									this->numbers.at(1) = (new CardRender(this->numbers.at(1)->getX(), this->numbers.at(1)->getY(), &this->textures[sclay]));
									this->numbers.at(3) = (new CardRender(this->numbers.at(3)->getX(), this->numbers.at(3)->getY(), &this->textures[swood]));
									this->numbers.at(5) = (new CardRender(this->numbers.at(5)->getX(), this->numbers.at(5)->getY(), &this->textures[sstone]));
									this->numbers.at(15) = (new CardRender(this->numbers.at(15)->getX(), this->numbers.at(15)->getY(), &this->textures[s]));
								}
								for (int j = 0; j < cards.size(); j++)
								{
									if (st.at(j) == i + 1)
										st.at(j) = 0;
									if (dr.at(j) == i + 1)
										dr.at(j) = 0;
									if (st.at(j) == 0 && dr.at(j) == 0)
									{
										fliped.at(j) = false;
										if (fliped.at(j) == false)
										{
											cards.at(j) = new CardRender(cards.at(j)->getX(), cards.at(j)->getY(), &this->textures[this->cardNames[j]], sf::Color(0, 0, 0, 0),
												sf::Color(10, 10, 10, 200), sf::Color(0, 0, 0, 0), this->cardNames[j]);
										}
									}

								}

								Card::Color curentCardColor = m_mechanics.FindCard(cards.at(i)->getName(), deck2).GetColor();
								int curentCardIndex = 20 * m_mechanics.CountBuildingsByColor(curentCardColor, player1);

								switch (curentCardColor)
								{
								case Card::Color::Red:
								{

									player1.SetMilitarryPoints(m_mechanics.FindCard(cards.at(i)->getName(), deck2).GetPoints().size());
									int val = this->player1.GetMilitarryPoints();
									std::string s = std::to_string(val);
									if (player1.GetName() == "User")
									{
										this->numbers.at(10) = (new CardRender(this->numbers.at(10)->getX(), this->numbers.at(10)->getY(), &this->textures[s]));
										cards.at(i)->setPosition(0, 730 + curentCardIndex);
									}

									if (player1.GetName() == "AI")
									{
										this->numbers.at(11) = (new CardRender(this->numbers.at(11)->getX(), this->numbers.at(11)->getY(), &this->textures[s]));
										cards.at(i)->setPosition(1810, 730 + curentCardIndex);
									}




									int aux = this->player1.GetMilitarryPoints() - this->player2.GetMilitarryPoints();
									if (aux == 9 || aux == -9)
									{
										this->GameOver(player1.GetName());
									}
									switch (aux)
									{

									case -9:
										warPown->setPosition(762, warPown->getY());
										std::cout << "Win p1";
										this->GameOver(player1.GetName());
										break;
									case -8:
									{
										if (token5P1 == true)
										{
											player2.DecreaseMoney(5);
											token5P1 = false;
											int val = this->player2.GetMoney();
											std::string s = std::to_string(val);
											this->numbers.at(15) = (new CardRender(this->numbers.at(15)->getX(), this->numbers.at(15)->getY(), &this->textures[s]));
										}
										warPown->setPosition(782, warPown->getY());
										warTokens.at(0)->setPosition(0, 0);
										break;
									}
									case -7:
									{
										if (token5P1 == true)
										{
											player2.DecreaseMoney(5);
											token5P1 = false;
											int val = this->player2.GetMoney();
											std::string s = std::to_string(val);
											this->numbers.at(15) = (new CardRender(this->numbers.at(15)->getX(), this->numbers.at(15)->getY(), &this->textures[s]));
										}
										warPown->setPosition(808, warPown->getY());
										warTokens.at(0)->setPosition(0, 0);
										break;
									}
									case -6:
									{
										if (token5P1 == true)
										{
											player2.DecreaseMoney(5);
											token5P1 = false;
											int val = this->player2.GetMoney();
											std::string s = std::to_string(val);
											this->numbers.at(15) = (new CardRender(this->numbers.at(15)->getX(), this->numbers.at(15)->getY(), &this->textures[s]));

										}
										warPown->setPosition(834, warPown->getY());
										warTokens.at(0)->setPosition(0, 0);
										break;
									}
									case -5:
									{
										if (token2P1 == true)
										{
											player2.DecreaseMoney(2);
											token2P1 = false;
											int val = this->player2.GetMoney();
											std::string s = std::to_string(val);
											this->numbers.at(15) = (new CardRender(this->numbers.at(15)->getX(), this->numbers.at(15)->getY(), &this->textures[s]));

										}
										warPown->setPosition(860, warPown->getY());
										warTokens.at(1)->setPosition(0, 0);
										break;
									}
									case -4:
									{
										if (token2P1 == true)
										{
											player2.DecreaseMoney(2);
											token2P1 = false;
											int val = this->player2.GetMoney();
											std::string s = std::to_string(val);
											this->numbers.at(15) = (new CardRender(this->numbers.at(15)->getX(), this->numbers.at(15)->getY(), &this->textures[s]));
										}
										warPown->setPosition(886, warPown->getY());
										warTokens.at(1)->setPosition(0, 0);
										break;
									}
									case -3:
									{
										if (token2P1 == true)
										{
											player2.DecreaseMoney(2);
											token2P1 = false;
											int val = this->player2.GetMoney();
											std::string s = std::to_string(val);
											this->numbers.at(15) = (new CardRender(this->numbers.at(15)->getX(), this->numbers.at(15)->getY(), &this->textures[s]));
										}
										warPown->setPosition(912, warPown->getY());
										warTokens.at(1)->setPosition(0, 0);
										break;
									}
									case -2:
										warPown->setPosition(938, warPown->getY());
										break;

									case -1:
										warPown->setPosition(964, warPown->getY());
										break;
									case 0:
										warPown->setPosition(990, 85);
										break;
									case 1:
										warPown->setPosition(1016, warPown->getY());
										break;
									case 2:
										warPown->setPosition(1042, warPown->getY());
										break;
									case 3:
									{
										if (token2P2 == true)
										{
											player2.DecreaseMoney(2);
											token2P2 = false;
											int val = this->player1.GetMoney();
											std::string s = std::to_string(val);
											this->numbers.at(14) = (new CardRender(this->numbers.at(14)->getX(), this->numbers.at(14)->getY(), &this->textures[s]));

										}
										warPown->setPosition(1068, warPown->getY());
										warTokens.at(2)->setPosition(0, 0);
										break;
									}
									case 4:
									{
										if (token2P2 == true)
										{
											player2.DecreaseMoney(2);
											token2P2 = false;
											int val = this->player1.GetMoney();
											std::string s = std::to_string(val);
											this->numbers.at(14) = (new CardRender(this->numbers.at(14)->getX(), this->numbers.at(14)->getY(), &this->textures[s]));

										}
										warPown->setPosition(1094, warPown->getY());
										warTokens.at(2)->setPosition(0, 0);
										break;
									}
									case 5:
									{
										if (token2P2 == true)
										{
											player2.DecreaseMoney(2);
											token2P2 = false;
											int val = this->player1.GetMoney();
											std::string s = std::to_string(val);
											this->numbers.at(14) = (new CardRender(this->numbers.at(14)->getX(), this->numbers.at(14)->getY(), &this->textures[s]));

										}
										warPown->setPosition(1120, warPown->getY());
										warTokens.at(2)->setPosition(0, 0);
										break;
									}
									case 6:
									{
										if (token5P2 == true)
										{
											player2.DecreaseMoney(5);
											token5P2 = false;
											int val = this->player1.GetMoney();
											std::string s = std::to_string(val);
											this->numbers.at(14) = (new CardRender(this->numbers.at(14)->getX(), this->numbers.at(14)->getY(), &this->textures[s]));

										}

										warPown->setPosition(1146, warPown->getY());
										warTokens.at(3)->setPosition(0, 0);
										break;
									}
									case 7:
									{
										if (token5P2 == true)
										{
											player2.DecreaseMoney(5);
											token5P2 = false;
											int val = this->player1.GetMoney();
											std::string s = std::to_string(val);
											this->numbers.at(14) = (new CardRender(this->numbers.at(14)->getX(), this->numbers.at(14)->getY(), &this->textures[s]));

										}
										warPown->setPosition(1172, warPown->getY());
										warTokens.at(3)->setPosition(0, 0);
										break;
									}
									case 8:
									{
										if (token5P2 == true)
										{
											player2.DecreaseMoney(5);
											token5P2 = false;
											int val = this->player1.GetMoney();
											std::string s = std::to_string(val);
											this->numbers.at(14) = (new CardRender(this->numbers.at(14)->getX(), this->numbers.at(14)->getY(), &this->textures[s]));

										}
										warPown->setPosition(1198, warPown->getY());
										warTokens.at(3)->setPosition(0, 0);
										break;
									}
									case 9:
									{	warPown->setPosition(1224, warPown->getY());
									std::cout << "Win p2";
									this->GameOver(player2.GetName());
									break;
									}
									default:
										break;
									}

									break;
								}
								case Card::Color::Blue:
								{
									player1.SetVictoryPoints(m_mechanics.FindCard(cards.at(i)->getName(), deck2).GetPoints().size());
									int val = this->player1.GetVictoryPoints();
									std::string s = std::to_string(val);

									if (player1.GetName() == "User")
									{
										this->numbers.at(12) = (new CardRender(this->numbers.at(12)->getX(), this->numbers.at(12)->getY(), &this->textures[s]));
										cards.at(i)->setPosition(122, 730 + curentCardIndex);
									}

									if (player1.GetName() == "AI")
									{
										this->numbers.at(13) = (new CardRender(this->numbers.at(13)->getX(), this->numbers.at(13)->getY(), &this->textures[s]));
										cards.at(i)->setPosition(1688, 730 + curentCardIndex);
									}
									break;
								}
								case Card::Color::Brown:

								{
									if (player1.GetName() == "User")
									{
										switch (m_mechanics.FindCard(cards.at(i)->getName(), deck2).GetRawMaterial().GetRawMaterial())
										{
										case::RawMaterialsCLass::RawMaterials::Wood:
										{
											int val = m_mechanics.CountRawMaterialsWood(player1);
											std::string s = std::to_string(val);
											this->numbers.at(2) = (new CardRender(this->numbers.at(2)->getX(), this->numbers.at(2)->getY(), &this->textures[s]));
											break;
										}
										case::RawMaterialsCLass::RawMaterials::Clay:
										{
											int val = m_mechanics.CountRawMaterialsClay(player1);
											std::string s = std::to_string(val);
											this->numbers.at(0) = (new CardRender(this->numbers.at(0)->getX(), this->numbers.at(0)->getY(), &this->textures[s]));
											break;
										}
										case::RawMaterialsCLass::RawMaterials::Stone:
										{
										int val = m_mechanics.CountRawMaterialsStone(player1);
										std::string s = std::to_string(val);
										this->numbers.at(4) = (new CardRender(this->numbers.at(4)->getX(), this->numbers.at(4)->getY(), &this->textures[s]));
										break;
										}
										default:
											break;
										}
										cards.at(i)->setPosition(244, 730 + curentCardIndex);
									}

									if (player1.GetName() == "AI")
									{
										switch (m_mechanics.FindCard(cards.at(i)->getName(), deck2).GetRawMaterial().GetRawMaterial())
										{
										case::RawMaterialsCLass::RawMaterials::Wood:
										{
											int val = m_mechanics.CountRawMaterialsWood(player1);
											std::string s = std::to_string(val);
											this->numbers.at(3) = (new CardRender(this->numbers.at(3)->getX(), this->numbers.at(3)->getY(), &this->textures[s]));
											break;
										}
										case::RawMaterialsCLass::RawMaterials::Clay:
										{
											int val = m_mechanics.CountRawMaterialsClay(player1);
											std::string s = std::to_string(val);
											this->numbers.at(1) = (new CardRender(this->numbers.at(1)->getX(), this->numbers.at(1)->getY(), &this->textures[s]));
											break;
										}
										case::RawMaterialsCLass::RawMaterials::Stone:
										{
											int val = m_mechanics.CountRawMaterialsStone(player1);
											std::string s = std::to_string(val);
											this->numbers.at(5) = (new CardRender(this->numbers.at(5)->getX(), this->numbers.at(5)->getY(), &this->textures[s]));
											break;
										}
										default:
											break;
										}
										cards.at(i)->setPosition(1566, 730 + curentCardIndex);
									}
									break;
								}
								case Card::Color::Green:
								{

									if (m_mechanics.CountSymbolInPlayersDeck(player1) == true)
									{
										duplicateSymbol = true;
										m_mechanics.PickToken(player1, this->activeProgressTokens, tokenName);
									}

									player1.SetVictoryPoints(m_mechanics.FindCard(cards.at(i)->getName(), deck2).GetPoints().size());
									int val = this->player1.GetVictoryPoints();
									std::string s = std::to_string(val);

									if (player1.GetName() == "User")
									{
										this->numbers.at(12) = (new CardRender(this->numbers.at(12)->getX(), this->numbers.at(12)->getY(), &this->textures[s]));
										cards.at(i)->setPosition(366, 730 + curentCardIndex);
									}

									if (player1.GetName() == "AI")
									{
										this->numbers.at(13) = (new CardRender(this->numbers.at(13)->getX(), this->numbers.at(13)->getY(), &this->textures[s]));
										cards.at(i)->setPosition(1444, 730 + curentCardIndex);
									}
									break; }
								case Card::Color::Grey:
								{
									if (player1.GetName() == "User")
									{
										ManufacturedGoodsClass::ManufacturedGoods good = m_mechanics.FindCard(cards.at(i)->getName(), deck2).GetManufGood().GetManufacturedGood();
										std::string sS = m_mechanics.FindCard(cards.at(i)->getName(), deck2).GetSpecial();
										if (sS._Equal("Glass"))
										{
											int val = m_mechanics.CountMaterialsGoodsGlass(player1);
											std::string s = std::to_string(val);
											this->numbers.at(6) = (new CardRender(this->numbers.at(6)->getX(), this->numbers.at(6)->getY(), &this->textures[s]));
										}
										if (sS._Equal("Papirus"))
										{
											int val = m_mechanics.CountMaterialsGoodsPapirus(player1);
											std::string s = std::to_string(val);
											this->numbers.at(8) = (new CardRender(this->numbers.at(8)->getX(), this->numbers.at(8)->getY(), &this->textures[s]));
										}
										
										
										
										switch (good)
										{
										case::ManufacturedGoodsClass::ManufacturedGoods::Glass:
										{
											int val = m_mechanics.CountMaterialsGoodsGlass(player1);
											std::string s = std::to_string(val);
											this->numbers.at(6) = (new CardRender(this->numbers.at(6)->getX(), this->numbers.at(6)->getY(), &this->textures[s]));
											break;
										}
										case::ManufacturedGoodsClass::ManufacturedGoods::Papirus:
										{
											int val = m_mechanics.CountMaterialsGoodsPapirus(player1);
											std::string s = std::to_string(val);
											this->numbers.at(8) = (new CardRender(this->numbers.at(8)->getX(), this->numbers.at(8)->getY(), &this->textures[s]));
											break;
										}
										default:
											break;
										}
										cards.at(i)->setPosition(488, 730 + curentCardIndex);
									}

									if (player1.GetName() == "AI")
									{
										ManufacturedGoodsClass::ManufacturedGoods good = m_mechanics.FindCard(cards.at(i)->getName(), deck2).GetManufGood().GetManufacturedGood();
										std::string sS = m_mechanics.FindCard(cards.at(i)->getName(), deck2).GetSpecial();
										if (sS._Equal("Glass"))
										{
											int val = m_mechanics.CountMaterialsGoodsGlass(player1);
											std::string s = std::to_string(val);
											this->numbers.at(7) = (new CardRender(this->numbers.at(7)->getX(), this->numbers.at(7)->getY(), &this->textures[s]));
										}
										if (sS._Equal("Papirus"))
										{
											int val = m_mechanics.CountMaterialsGoodsPapirus(player1);
											std::string s = std::to_string(val);
											this->numbers.at(9) = (new CardRender(this->numbers.at(9)->getX(), this->numbers.at(9)->getY(), &this->textures[s]));
										}
										
										
										switch (good)
										{
										case::ManufacturedGoodsClass::ManufacturedGoods::Glass:
										{
											int val = m_mechanics.CountMaterialsGoodsGlass(player1);
											std::string s = std::to_string(val);
											this->numbers.at(7) = (new CardRender(this->numbers.at(7)->getX(), this->numbers.at(7)->getY(), &this->textures[s]));
											break;
										}
										case::ManufacturedGoodsClass::ManufacturedGoods::Papirus:
										{
											int val = m_mechanics.CountMaterialsGoodsPapirus(player1);
											std::string s = std::to_string(val);
											this->numbers.at(9) = (new CardRender(this->numbers.at(9)->getX(), this->numbers.at(9)->getY(), &this->textures[s]));
											break;
										}
										default:
											break;
										}
										cards.at(i)->setPosition(1322, 730 + curentCardIndex);
									}
									break;
								}
								case Card::Color::Purple:
									if (player1.GetName() == "User")
									{
										cards.at(i)->setPosition(610, 730 + curentCardIndex);
									}

									if (player1.GetName() == "AI")
									{
										cards.at(i)->setPosition(1200, 730 + curentCardIndex);
									}
									break;
								case Card::Color::Yellow:
								{
									int val = this->player1.GetMoney();
									std::string s = std::to_string(val);
									if (player1.GetName() == "User")
									{
										cards.at(i)->setPosition(732, 730 + curentCardIndex);
										this->numbers.at(14) = (new CardRender(this->numbers.at(14)->getX(), this->numbers.at(14)->getY(), &this->textures[s]));

									}

									if (player1.GetName() == "AI")
									{
										cards.at(i)->setPosition(1000, 730 + curentCardIndex);
										this->numbers.at(15) = (new CardRender(this->numbers.at(15)->getX(), this->numbers.at(15)->getY(), &this->textures[s]));

									}
									break;
								}
								default:
									break;
								}
								allCardsPressed++;
								std::swap(player1, player2);
							}
							else
								break;

							break;
						case GameMechanics::Turn::Third:

							if (m_mechanics.UsingCard(player1, player2, m_mechanics.FindCard(cards.at(i)->getName(), deck3), deck3, this->activeProgressTokens) == true)
							{
								int val = this->player1.GetMoney();
								std::string s = std::to_string(val);

								if (player1.GetName() == "User")
								{
									this->numbers.at(14) = (new CardRender(this->numbers.at(14)->getX(), this->numbers.at(14)->getY(), &this->textures[s]));

								}
								else
									this->numbers.at(15) = (new CardRender(this->numbers.at(15)->getX(), this->numbers.at(15)->getY(), &this->textures[s]));

								for (int j = 0; j < cards.size(); j++)
								{
									if (st.at(j) == i + 1)
										st.at(j) = 0;
									if (dr.at(j) == i + 1)
										dr.at(j) = 0;
									if (st.at(j) == 0 && dr.at(j) == 0)
									{
										fliped.at(j) = false;
										if (fliped.at(j) == false)
										{
											cards.at(j) = new CardRender(cards.at(j)->getX(), cards.at(j)->getY(), &this->textures[this->cardNames[j]], sf::Color(0, 0, 0, 0),
												sf::Color(10, 10, 10, 200), sf::Color(0, 0, 0, 0), this->cardNames[j]);
										}
									}

								}

								Card::Color curentCardColor = m_mechanics.FindCard(cards.at(i)->getName(), deck3).GetColor();
								int curentCardIndex = 20 * m_mechanics.CountBuildingsByColor(curentCardColor, player1);

								switch (curentCardColor)
								{
								case Card::Color::Red:
								{


									player1.SetMilitarryPoints(m_mechanics.FindCard(cards.at(i)->getName(), deck3).GetPoints().size());
									int val = this->player1.GetMilitarryPoints();
									std::string s = std::to_string(val);
									if (player1.GetName() == "User")
									{
										this->numbers.at(10) = (new CardRender(this->numbers.at(10)->getX(), this->numbers.at(10)->getY(), &this->textures[s]));
										cards.at(i)->setPosition(0, 730 + curentCardIndex);
									}

									if (player1.GetName() == "AI")
									{
										this->numbers.at(11) = (new CardRender(this->numbers.at(11)->getX(), this->numbers.at(11)->getY(), &this->textures[s]));
										cards.at(i)->setPosition(1810, 730 + curentCardIndex);
									}




									int aux = this->player1.GetMilitarryPoints() - this->player2.GetMilitarryPoints();
									if (aux == 9 || aux == -9)
									{
										this->GameOver(player1.GetName());
									}
									switch (aux)
									{

									case -9:
										warPown->setPosition(762, warPown->getY());
										std::cout << "Win p1";
										this->GameOver(player1.GetName());
										break;
									case -8:
									{
										if (token5P1 == true)
										{
											player2.DecreaseMoney(5);
											token5P1 = false;
											int val = this->player2.GetMoney();
											std::string s = std::to_string(val);
											this->numbers.at(15) = (new CardRender(this->numbers.at(15)->getX(), this->numbers.at(15)->getY(), &this->textures[s]));
										}
										warPown->setPosition(782, warPown->getY());
										warTokens.at(0)->setPosition(0, 0);
										break;
									}
									case -7:
									{
										if (token5P1 == true)
										{
											player2.DecreaseMoney(5);
											token5P1 = false;
											int val = this->player2.GetMoney();
											std::string s = std::to_string(val);
											this->numbers.at(15) = (new CardRender(this->numbers.at(15)->getX(), this->numbers.at(15)->getY(), &this->textures[s]));
										}
										warPown->setPosition(808, warPown->getY());
										warTokens.at(0)->setPosition(0, 0);
										break;
									}
									case -6:
									{
										if (token5P1 == true)
										{
											player2.DecreaseMoney(5);
											token5P1 = false;
											int val = this->player2.GetMoney();
											std::string s = std::to_string(val);
											this->numbers.at(15) = (new CardRender(this->numbers.at(15)->getX(), this->numbers.at(15)->getY(), &this->textures[s]));

										}
										warPown->setPosition(834, warPown->getY());
										warTokens.at(0)->setPosition(0, 0);
										break;
									}
									case -5:
									{
										if (token2P1 == true)
										{
											player2.DecreaseMoney(2);
											token2P1 = false;
											int val = this->player2.GetMoney();
											std::string s = std::to_string(val);
											this->numbers.at(15) = (new CardRender(this->numbers.at(15)->getX(), this->numbers.at(15)->getY(), &this->textures[s]));

										}
										warPown->setPosition(860, warPown->getY());
										warTokens.at(1)->setPosition(0, 0);
										break;
									}
									case -4:
									{
										if (token2P1 == true)
										{
											player2.DecreaseMoney(2);
											token2P1 = false;
											int val = this->player2.GetMoney();
											std::string s = std::to_string(val);
											this->numbers.at(15) = (new CardRender(this->numbers.at(15)->getX(), this->numbers.at(15)->getY(), &this->textures[s]));
										}
										warPown->setPosition(886, warPown->getY());
										warTokens.at(1)->setPosition(0, 0);
										break;
									}
									case -3:
									{
										if (token2P1 == true)
										{
											player2.DecreaseMoney(2);
											token2P1 = false;
											int val = this->player2.GetMoney();
											std::string s = std::to_string(val);
											this->numbers.at(15) = (new CardRender(this->numbers.at(15)->getX(), this->numbers.at(15)->getY(), &this->textures[s]));
										}
										warPown->setPosition(912, warPown->getY());
										warTokens.at(1)->setPosition(0, 0);
										break;
									}
									case -2:
										warPown->setPosition(938, warPown->getY());
										break;

									case -1:
										warPown->setPosition(964, warPown->getY());
										break;
									case 0:
										warPown->setPosition(990, 85);
										break;
									case 1:
										warPown->setPosition(1016, warPown->getY());
										break;
									case 2:
										warPown->setPosition(1042, warPown->getY());
										break;
									case 3:
									{
										if (token2P2 == true)
										{
											player2.DecreaseMoney(2);
											token2P2 = false;
											int val = this->player1.GetMoney();
											std::string s = std::to_string(val);
											this->numbers.at(14) = (new CardRender(this->numbers.at(14)->getX(), this->numbers.at(14)->getY(), &this->textures[s]));

										}
										warPown->setPosition(1068, warPown->getY());
										warTokens.at(2)->setPosition(0, 0);
										break;
									}
									case 4:
									{
										if (token2P2 == true)
										{
											player2.DecreaseMoney(2);
											token2P2 = false;
											int val = this->player1.GetMoney();
											std::string s = std::to_string(val);
											this->numbers.at(14) = (new CardRender(this->numbers.at(14)->getX(), this->numbers.at(14)->getY(), &this->textures[s]));

										}
										warPown->setPosition(1094, warPown->getY());
										warTokens.at(2)->setPosition(0, 0);
										break;
									}
									case 5:
									{
										if (token2P2 == true)
										{
											player2.DecreaseMoney(2);
											token2P2 = false;
											int val = this->player1.GetMoney();
											std::string s = std::to_string(val);
											this->numbers.at(14) = (new CardRender(this->numbers.at(14)->getX(), this->numbers.at(14)->getY(), &this->textures[s]));

										}
										warPown->setPosition(1120, warPown->getY());
										warTokens.at(2)->setPosition(0, 0);
										break;
									}
									case 6:
									{
										if (token5P2 == true)
										{
											player2.DecreaseMoney(5);
											token5P2 = false;
											int val = this->player1.GetMoney();
											std::string s = std::to_string(val);
											this->numbers.at(14) = (new CardRender(this->numbers.at(14)->getX(), this->numbers.at(14)->getY(), &this->textures[s]));

										}

										warPown->setPosition(1146, warPown->getY());
										warTokens.at(3)->setPosition(0, 0);
										break;
									}
									case 7:
									{
										if (token5P2 == true)
										{
											player2.DecreaseMoney(5);
											token5P2 = false;
											int val = this->player1.GetMoney();
											std::string s = std::to_string(val);
											this->numbers.at(14) = (new CardRender(this->numbers.at(14)->getX(), this->numbers.at(14)->getY(), &this->textures[s]));

										}
										warPown->setPosition(1172, warPown->getY());
										warTokens.at(3)->setPosition(0, 0);
										break;
									}
									case 8:
									{
										if (token5P2 == true)
										{
											player2.DecreaseMoney(5);
											token5P2 = false;
											int val = this->player1.GetMoney();
											std::string s = std::to_string(val);
											this->numbers.at(14) = (new CardRender(this->numbers.at(14)->getX(), this->numbers.at(14)->getY(), &this->textures[s]));

										}
										warPown->setPosition(1198, warPown->getY());
										warTokens.at(3)->setPosition(0, 0);
										break;
									}
									case 9:
									{	warPown->setPosition(1224, warPown->getY());
									std::cout << "Win p2";
									this->GameOver(player2.GetName());
									break;
									}
									default:
										break;
									}

									break;
									break;
								}
								case Card::Color::Blue:
								{
									player1.SetVictoryPoints(m_mechanics.FindCard(cards.at(i)->getName(), deck3).GetPoints().size());
									int val = this->player1.GetVictoryPoints();
									std::string s = std::to_string(val);

									if (player1.GetName() == "User")
									{
										this->numbers.at(12) = (new CardRender(this->numbers.at(12)->getX(), this->numbers.at(12)->getY(), &this->textures[s]));
										cards.at(i)->setPosition(122, 730 + curentCardIndex);
									}

									if (player1.GetName() == "AI")
									{
										this->numbers.at(13) = (new CardRender(this->numbers.at(13)->getX(), this->numbers.at(13)->getY(), &this->textures[s]));
										cards.at(i)->setPosition(1688, 730 + curentCardIndex);
									}
									break;
								}
								case Card::Color::Brown:
								{
									if (player1.GetName() == "User")
									{
										switch (m_mechanics.FindCard(cards.at(i)->getName(), deck3).GetRawMaterial().GetRawMaterial())
										{
										case::RawMaterialsCLass::RawMaterials::Wood:
										{
											int val = m_mechanics.CountRawMaterialsWood(player1);
											std::string s = std::to_string(val);
											this->numbers.at(2) = (new CardRender(this->numbers.at(2)->getX(), this->numbers.at(2)->getY(), &this->textures[s]));
											break;
										}
										case::RawMaterialsCLass::RawMaterials::Clay:
										{
											int val = m_mechanics.CountRawMaterialsClay(player1);
											std::string s = std::to_string(val);
											this->numbers.at(0) = (new CardRender(this->numbers.at(0)->getX(), this->numbers.at(0)->getY(), &this->textures[s]));
											break;
										}
										case::RawMaterialsCLass::RawMaterials::Stone:
										{
											int val = m_mechanics.CountRawMaterialsStone(player1);
											std::string s = std::to_string(val);
											this->numbers.at(4) = (new CardRender(this->numbers.at(4)->getX(), this->numbers.at(4)->getY(), &this->textures[s]));
											break;
										}
										default:
											break;
										}
										cards.at(i)->setPosition(244, 730 + curentCardIndex);
									}

									if (player1.GetName() == "AI")
									{
										switch (m_mechanics.FindCard(cards.at(i)->getName(), deck3).GetRawMaterial().GetRawMaterial())
										{
										case::RawMaterialsCLass::RawMaterials::Wood:
										{
											int val = m_mechanics.CountRawMaterialsWood(player1);
											std::string s = std::to_string(val);
											this->numbers.at(3) = (new CardRender(this->numbers.at(3)->getX(), this->numbers.at(3)->getY(), &this->textures[s]));
											break;
										}
										case::RawMaterialsCLass::RawMaterials::Clay:
										{
											int val = m_mechanics.CountRawMaterialsClay(player1);
											std::string s = std::to_string(val);
											this->numbers.at(1) = (new CardRender(this->numbers.at(1)->getX(), this->numbers.at(1)->getY(), &this->textures[s]));
											break;
										}
										case::RawMaterialsCLass::RawMaterials::Stone:
										{
											int val = m_mechanics.CountRawMaterialsStone(player1);
											std::string s = std::to_string(val);
											this->numbers.at(5) = (new CardRender(this->numbers.at(5)->getX(), this->numbers.at(5)->getY(), &this->textures[s]));
											break;
										}
										default:
											break;
										}
										cards.at(i)->setPosition(1566, 730 + curentCardIndex);
									}
									break;
								}
								case Card::Color::Green:
								{



									if (m_mechanics.CountSymbolInPlayersDeck(player1) == true)
									{
										duplicateSymbol = true;
										m_mechanics.PickToken(player1, this->activeProgressTokens, tokenName);
									}

									player1.SetVictoryPoints(m_mechanics.FindCard(cards.at(i)->getName(), deck3).GetPoints().size());
									int val = this->player1.GetVictoryPoints();
									std::string s = std::to_string(val);

									if (player1.GetName() == "User")
									{
										this->numbers.at(12) = (new CardRender(this->numbers.at(12)->getX(), this->numbers.at(12)->getY(), &this->textures[s]));
										cards.at(i)->setPosition(366, 730 + curentCardIndex);
									}

									if (player1.GetName() == "AI")
									{
										this->numbers.at(13) = (new CardRender(this->numbers.at(13)->getX(), this->numbers.at(13)->getY(), &this->textures[s]));
										cards.at(i)->setPosition(1444, 730 + curentCardIndex);
									}
									break;
								}
								case Card::Color::Grey:
								{
									if (player1.GetName() == "User")
									{
										switch (m_mechanics.FindCard(cards.at(i)->getName(), deck3).GetManufGood().GetManufacturedGood())
										{
										case::ManufacturedGoodsClass::ManufacturedGoods::Glass:
										{
											int val = m_mechanics.CountMaterialsGoodsGlass(player1);
											std::string s = std::to_string(val);
											this->numbers.at(6) = (new CardRender(this->numbers.at(6)->getX(), this->numbers.at(6)->getY(), &this->textures[s]));
											break;
										}
										case::ManufacturedGoodsClass::ManufacturedGoods::Papirus:
										{
											int val = m_mechanics.CountMaterialsGoodsPapirus(player1);
											std::string s = std::to_string(val);
											this->numbers.at(8) = (new CardRender(this->numbers.at(8)->getX(), this->numbers.at(8)->getY(), &this->textures[s]));
											break;
										}
										default:
											break;
										}
										cards.at(i)->setPosition(488, 730 + curentCardIndex);
									}

									if (player1.GetName() == "AI")
									{
										switch (m_mechanics.FindCard(cards.at(i)->getName(), deck3).GetManufGood().GetManufacturedGood())
										{
										case::ManufacturedGoodsClass::ManufacturedGoods::Glass:
										{
											int val = m_mechanics.CountMaterialsGoodsGlass(player1);
											std::string s = std::to_string(val);
											this->numbers.at(7) = (new CardRender(this->numbers.at(7)->getX(), this->numbers.at(7)->getY(), &this->textures[s]));
											break;
										}
										case::ManufacturedGoodsClass::ManufacturedGoods::Papirus:
										{
											int val = m_mechanics.CountMaterialsGoodsPapirus(player1);
											std::string s = std::to_string(val);
											this->numbers.at(9) = (new CardRender(this->numbers.at(9)->getX(), this->numbers.at(9)->getY(), &this->textures[s]));
											break;
										}
										default:
											break;
										}
										cards.at(i)->setPosition(1322, 730 + curentCardIndex);
									}
									break;
								}
								case Card::Color::Purple:
									if (player1.GetName() == "User")
									{
										cards.at(i)->setPosition(610, 730 + curentCardIndex);
									}

									if (player1.GetName() == "AI")
									{
										cards.at(i)->setPosition(1200, 730 + curentCardIndex);
									}
									break;
								case Card::Color::Yellow:
									if (player1.GetName() == "User")
									{
										cards.at(i)->setPosition(732, 730 + curentCardIndex);
									}

									if (player1.GetName() == "AI")
									{
										cards.at(i)->setPosition(1000, 730 + curentCardIndex);
									}
									break;
								default:
									break;
								}
								allCardsPressed++;
								std::swap(player1, player2);
							}
							else
								break;

							break;

						default:
							break;
						}


					}
					else
					{
						cards.at(i)->setPosition(1700, 0);
						for (int j = 0; j < cards.size(); j++)
						{
							if (st.at(j) == i + 1)
								st.at(j) = 0;
							if (dr.at(j) == i + 1)
								dr.at(j) = 0;
							if (st.at(j) == 0 && dr.at(j) == 0)
							{
								fliped.at(j) = false;
								if (fliped.at(j) == false)
								{
									cards.at(j) = new CardRender(cards.at(j)->getX(), cards.at(j)->getY(), &this->textures[this->cardNames[j]], sf::Color(0, 0, 0, 0),
										sf::Color(10, 10, 10, 200), sf::Color(0, 0, 0, 0), this->cardNames[j]);
								}
							}

						}
						allCardsPressed++;
						player1.AddMoney(2);
						int val = this->player1.GetMoney();
						std::string s = std::to_string(val);

						if (player1.GetName() == "User")
						{
							this->numbers.at(14) = (new CardRender(this->numbers.at(14)->getX(), this->numbers.at(14)->getY(), &this->textures[s]));

						}
						else
							this->numbers.at(15) = (new CardRender(this->numbers.at(15)->getX(), this->numbers.at(15)->getY(), &this->textures[s]));
						std::swap(player1, player2);
					}
				}
				cards.at(i)->update(this->mousePosView);
			}
			}
		}
	}

	}
	
}

void GameState::updateInput(const float& dt)
{
	

	//Update player input
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("CLOSE"))))
		this->endState();
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::P))
		this->gameOverState();
}

void GameState::update(const float& dt)
{
	this->updateMousePosition();
	this->updateInput(dt);
	this->updateCards();

}


void GameState::render(sf::RenderTarget* target )
{
	if (!target)
		target = this->window;
	target->draw(this->background);
	
	if (selectedWonders != 1)
	{
		

		if (selectedFirst4Wonders != 1)
		{
			for (int i = 0; i < 4; i++)
			{

				wonders.at(i)->render(target);

			}
		}
		else
		{
			for (int i = 4; i < wonders.size()-1; i++)
			{

				wonders.at(i)->render(target);

			}

		}


	}

	
	if(selectedWonders!=0)
	{ 

	for (int i = cards.size() - 1; i >= 0; i--)
	{
		
		cards.at(i)->render(target);

	}
	for (int i = allCards.size() - 1; i >= 0; i--)
	{
	
		allCards.at(i)->render(target);

	}
	
	
	this->warBoard->render(target);
	this->warPown->render(target);
	for (int i = 0; i < 5; i++)
	{

		progressTokens.at(i)->render(target);
		

	}
	for (int i = 0; i < warTokens.size(); i++)
	{

		warTokens.at(i)->render(target);


	}

	//Token render 
	if (sf::Keyboard::isKeyPressed((sf::Keyboard::Key::X)))
	{
		this->progressTokens.at(6)->render(target);
		this->progressTokens.at(7)->setPosition(0,60);
		this->progressTokens.at(7)->render(target);
		this->progressTokens.at(8)->setPosition(0,120);
		this->progressTokens.at(8)->render(target);
		this->progressTokens.at(9)->setPosition(0,180);
		this->progressTokens.at(9)->render(target);
		this->progressTokens.at(5)->setPosition(0,270);
		this->progressTokens.at(5)->render(target);
		
	}
	

	for (int i =  0; i< wondersClear.size(); i++)
	{
		
		wondersSmall.at(i)->render(target);

	}
	
	this->scoreTable->render(target);
	for (int i = 0; i < numbers.size();i++)
	{ 
		this->numbers.at(i)->render(target);
	}
	
	}
}

void GameState::GameOver()
{
	this->states->push(new GameOverState(this->window, this->supportedKeys, this->states));
}

void GameState::GameOver(std::string winner)
{
	this->states->push(new GameOverState(this->window, this->supportedKeys, this->states, winner));
}
