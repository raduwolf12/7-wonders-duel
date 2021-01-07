#pragma once
#include "Card.h"
#include "Age3Deck.h"
class PlaceCardsAge3
{
public:
	void PlaceCards(Age3Deck &age3);
	void MakeAccessibleCards();
	void AccessibleCards();
	void DiscardCard(Card card);

public:
	static const int kNoCardsPlaced = 20;
	static const int kNoCardsFirstLine = 2;

private:
	std::array<std::pair<Card, std::string>, kNoCardsPlaced> m_placeCards;
	Age3Deck age3;
};

