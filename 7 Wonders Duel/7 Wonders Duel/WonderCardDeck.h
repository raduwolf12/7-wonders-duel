#pragma once
#include "WonderCardModel.h"
#include "Cost.h"
#include<unordered_map>
#include <array>

class WonderCardDeck
{
public:
	WonderCardDeck() {}
	void PopulateDeck();
	WonderCardDeck(const WonderCardDeck& other);
	WonderCardDeck(WonderCardDeck&& other);
	WonderCardDeck& operator=(const WonderCardDeck& other);
	WonderCardDeck& operator=(WonderCardDeck&& other);
	~WonderCardDeck();

public:
	static const size_t kFacedWonders = 4;

public:

	const WonderCardModel& GetWCard(uint16_t i)const;
	const std::unordered_map<std::string, WonderCardModel>& GetMap()const;
	friend std::ostream& operator<<(std::ostream& os, WonderCardDeck& deck);
	WonderCardModel PickWonderCard(const std::string name);
	void ShuffleInCards();
	void EraseCardsFromVector(std::string str);
	const std::vector<WonderCardModel>& GetDeck()const;
	void FaceingFourWonderCards();


private:

	std::unordered_map<std::string, WonderCardModel> m_deck;
	std::vector<WonderCardModel> m_randomVector;
};