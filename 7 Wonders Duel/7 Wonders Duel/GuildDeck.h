#pragma once
#include"Card.h"
#include<array>
#include <algorithm>    // std::shuffle
#include <array>        // std::array
#include <random>       // std::default_random_engine
#include <chrono> 
#include <ctime>        // std::time
#include <cstdlib>

class GuildDeck
{
public:
	
	void populateDeck();
	GuildDeck() = default;
	GuildDeck(const GuildDeck& other);
	GuildDeck(GuildDeck&& other);
	GuildDeck& operator=(const GuildDeck& other);
	GuildDeck& operator=(GuildDeck&& other);
	~GuildDeck();
	friend std::ostream& operator<<(std::ostream& os, GuildDeck& deck);
	const std::array<Card, 7>& GetDeck()const;
	void ShuffleDeck();
private:
	std::array<Card, 7> m_deck;
};

