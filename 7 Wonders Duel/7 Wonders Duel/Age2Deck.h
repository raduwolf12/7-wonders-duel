#pragma once
#include "Card.h"
#include <array>
#include <algorithm>    
#include <random>       
#include <chrono> 
#include <ctime>  
#include"Symbols.h"

class Age2Deck
{
public:
	static const int kNoCards = 23;

public:
	Age2Deck();
	Age2Deck(const Age2Deck& other);
	Age2Deck(Age2Deck&& other);
	Age2Deck& operator = (const Age2Deck& other);
	Age2Deck& operator = (Age2Deck&& other);
	~Age2Deck();

public:
	void PopulateDeck();
	void ShuffleInCards();
	friend std::ostream& operator<<(std::ostream& output, Age2Deck& age2Deck);
	const std::array<Card, kNoCards> &GetDeck() const;

private:
	std::array <Card, kNoCards> m_deck;
};

