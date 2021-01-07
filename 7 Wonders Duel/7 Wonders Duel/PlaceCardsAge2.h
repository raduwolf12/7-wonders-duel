#pragma once
#include "Card.h"
#include "Age2Deck.h"
#include "array"

class PlaceCardsAge2
{
public:
	void PlaceCards(Age2Deck &age);
	void MakeAccessibleCards();
	void AccessibleCards();
	void DiscardCard(Card card);

public:
	static const int kNoCardsPlaced = 20;
	static const int kNoCardsFirstLine = 2;

private:
	std::array<std::pair<Card, std::string>, kNoCardsPlaced> m_placeCards;
	Age2Deck age2;
};

