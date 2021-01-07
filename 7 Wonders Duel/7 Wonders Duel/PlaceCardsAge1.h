#pragma once
#include "Card.h"
#include "AgeICards.h"
class PlaceCardsAge1
{
public:
	void PlaceCards(AgeICards &age);
	void MakeAccessibleCards();
	void AccessibleCards();
	void DiscardCard(Card card);

public:
	static const int kNoCardsPlaced = 20;
	static const int kNoCardsFirstLine = 6;

private:
	std::array<std::pair<Card, std::string>, kNoCardsPlaced> m_placeCards;
	AgeICards age1;
};

