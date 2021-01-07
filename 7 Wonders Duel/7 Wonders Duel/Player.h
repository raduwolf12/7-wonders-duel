#pragma once
#include<cstdint>
#include<iostream>
#include <vector>
#include<string>
#include<map>
#include"Card.h"
#include"WonderCardDeck.h"
#include"ProgressToken.h"
class Player
{
public:
	Player() {}
	Player(const std::string& name);
	WonderCardModel PickWonderCards(std::string wonderCardName, WonderCardDeck& m_wonderCards);
	friend std::ostream& operator << (std::ostream& os, const Player& player);

public: //getters
	const std::map<Card::Color, std::vector<Card>> GetPlayerDeck()const;
	const std::vector<Card>& GetPlayerDeck2()const;
	const	std::vector<WonderCardModel>& GetWonderCards()const;
	const uint16_t& GetMilitarryPoints()const;
	const uint16_t& GetVictoryPoints() const;
	const std::vector<ProgressToken>& GetProgressTokens()const;
	const std::vector<int>& GetCoins()const;
	const std::vector<Cost>& GetResources()const;
	const std::vector<WonderCardModel>& GetBuildedWonders() const;
	const std::string& GetName()const;
	const uint16_t& GetMoney()const;
	const bool& GetDirection()const;
	const std::vector<Symbols::Symbol>& GetSymbols() const;
	const std::vector<Symbols::Symbol>& GetActiveSymbols() const;
	const std::vector<Signs::Sign>& GetSigns()const;

public://Setters
	void SetName(std::string name);
	void SetMilitarryPoints(uint16_t p);
	void SetVictoryPoints(uint16_t p);
	void SetResource(Cost ca);
	void SetDeck(Card c);
	void SetBuildedWonders(WonderCardModel c);
	void SetDirection(bool direction);
	void SetMoney(uint16_t i);
	void SetSymbol(Symbols::Symbol symbol);
	void SetActiveSymbol(Symbols::Symbol symbol);
	void SetSign(Signs::Sign sign);
	void SetProgressTokens(ProgressToken p);

public://Functions
	void AddMoney(uint16_t i);
	void DecreaseMoney(uint16_t i);
	void DeactivateSymbol(Symbols::Symbol s);
	void OverWriteResources(std::vector<Cost> costVector);

private:
	std::string m_name;
	std::map<Card::Color, std::vector<Card>> playerDeck;
	std::vector<Card> playerDeck2;
	std::vector<WonderCardModel> m_wonderCards;
	std::vector<WonderCardModel> m_buildedWonders;
	uint16_t m_militaryPoints = 0;
	uint16_t m_victoryPoints = 0;
	std::vector<ProgressToken> m_progressTokens;
	std::vector<Symbols::Symbol> m_activeSymbols;
	bool m_direction;
	std::vector<int>m_coins;
	std::vector<Symbols::Symbol> m_symbols;
	std::vector<Signs::Sign> m_signs;
	uint16_t m_money;
	std::vector<Cost> m_resources;
};


