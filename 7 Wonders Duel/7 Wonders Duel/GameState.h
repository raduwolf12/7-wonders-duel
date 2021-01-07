#ifndef GAMESTATE_H
#define GAMESTATE_H

#include"Card.h"
#include"CardRender.h"
#include "State.h"
#include"GameMechanics.h"
#include<unordered_map>
#include <algorithm>    
#include <random>       
#include <chrono> 
#include <ctime>  
#include<thread>
#include"ActiveProgressTokens.h"
#include"BotUtils.h"

class GameState :
	public State
{
private:
	Player player1;
	Player player2;
	BotUtils bot;

	bool botIsEnabled;

	

	ActiveProgressTokens activeProgressTokens;

	//To be removed
	GameMechanics m_mechanics;
	WonderCardDeck wonderDeck;

	AgeICards deck;
	Age2Deck deck2;
	Age3Deck deck3;
	std::array<Card, 23> curentDeck;
	//End removed
	CardRender* scoreTable;
	
	CardRender* warBoard;
	CardRender* warPown;
	std::vector<std::string> warTokensNames;
	std::vector<CardRender*> warTokens;

	bool selectedWonders = 0;
	bool selectedFirst4Wonders = 0;
	bool cardInitialization = true;
	bool wonderInitialization = true;
	bool token2P1=true;
	bool token5P1=true;
	bool token2P2=true;
	bool token5P2=true;
	bool duplicateSymbol = false;

	int pressed4 = 0;
	int pressed8 = 0;
	int allCardsPressed = 0;

	std::vector<std::string> cardNames;
	std::vector<std::string> cardNameAge2;
	std::vector<std::string> cardNameAge3;

	std::vector<CardRender*> numbers;

	std::vector<CardRender*> cards;
	std::vector<CardRender*> allCards;

	std::vector<std::string> wonderName;
	std::vector<CardRender*> wonders;

	std::vector<std::string> wonderNameSmall;
	std::vector<CardRender*> wondersSmall;

	std::unordered_map<std::string, CardRender*> cardsMap;

	std::vector<CardRender*> wondersClear;

	std::vector<std::string> progressTokensName;
	std::vector<CardRender*> progressTokens;

	GameMechanics::Turn curentTurn = GameMechanics::Turn::First;

	std::vector<int> st;
	std::vector<int> dr;
	std::vector<int> taken;
	std::vector<bool> fliped;
	std::vector<int> wonderPickPos;
	std::vector<int> playerPickOrder;

	sf::RectangleShape background;
	sf::Texture texture;

	//Threads
	std::chrono::milliseconds m_processingTime;

	//Functions
	void initTokens();
	void initKeyBinds();
	void initTextures();
	void initCards();
	void initWonders();
	void initWondersSmall();
	void initPlayers();
	void initProgressTokens();
public:
	int curentCardIndex;
	GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states, bool botIsEnabled=false);
	virtual ~GameState();

	//Functions
	
	void updateCards();
	void updateInput(const float& dt);
	void update(const float& dt);
	void render(sf::RenderTarget* target = nullptr);
	void GameOver();
	void GameOver(std::string winner);
};

#endif 