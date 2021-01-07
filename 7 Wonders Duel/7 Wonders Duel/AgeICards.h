#pragma once
#include"Card.h"
#include<array>

class AgeICards
{
public:
	static const size_t kDeckSize = 23;

public:
	AgeICards();
	AgeICards(const AgeICards& other);
	AgeICards(AgeICards&& other);
	AgeICards& operator=(const AgeICards& other);
	AgeICards& operator=(AgeICards&& other);
	~AgeICards();
	void PopulateDeck();
	void ShuffleInCards();
	friend std::ostream& operator<<(std::ostream& os, AgeICards& ac);
	const std::array<Card, kDeckSize> &GetDeck() const;
	void FaceingRemainingCards();
	void DiscardCard(Card c);//"Dezactiveaza" cartea
	
private:
	std::array<Card, kDeckSize> m_stackAgeICards;
};