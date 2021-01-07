#pragma once
#include"Card.h"
#include <array>
#include<vector>
#include <algorithm>    
#include <random>       
#include <chrono> 
#include <ctime>
class Age3Deck
{
public:
	static const size_t kDeckSize = 27;

public:
	Age3Deck();
	Age3Deck(const Age3Deck& other);
	Age3Deck(Age3Deck&& other);
	Age3Deck& operator=(const Age3Deck& other);
	Age3Deck& operator=(Age3Deck&& other);
	void PopulateDeck();
	void ShuffleInCards();
	~Age3Deck();
	friend std::ostream& operator<<(std::ostream& os, Age3Deck& deck);
	const std::array<Card, kDeckSize> &GetDeck()const;

private:
	std::array<Card, kDeckSize> deck;
};

