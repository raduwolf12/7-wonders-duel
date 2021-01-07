#include "WonderCardDeck.h"
#include<sstream>
#include<array>
#include<algorithm>
#include <random>       
#include <chrono> 
#include <ctime>    

void WonderCardDeck::PopulateDeck()
{
	m_deck["PIRAEUS"] = WonderCardModel("PIRAEUS");
	m_deck["CIRCUS MAXIMUS"] = WonderCardModel("CIRCUS MAXIMUS");
	m_deck["THE GREAT LIGHTHOUSE"] = WonderCardModel("THE GREAT LIGHTHOUSE");
	m_deck["TEMPLE OF ARTEMIS"] = WonderCardModel("TEMPLE OF ARTEMIS");
	m_deck["THE APPIAN WAY"] = WonderCardModel("THE APPIAN WAY");
	m_deck["THE COLOSSUS"] = WonderCardModel("THE COLOSSUS");
	m_deck["THE GREAT LIBRARY"] = WonderCardModel("THE GREAT LIBRARY");
	m_deck["THE HANGING GARDENS"] = WonderCardModel("THE HANGING GARDENS");
	m_deck["THE STATUE OF ZEUS"] = WonderCardModel("THE STATUE OF ZEUS");
	m_deck["THE MAUSOLEUM"] = WonderCardModel("THE MAUSOLEUM");
	m_deck["THE PYRAMIDS"] = WonderCardModel("THE PYRAMIDS");
	m_deck["THE SPINX"] = WonderCardModel("THE SPINX");


	m_randomVector.push_back(WonderCardModel("PIRAEUS"));
	m_randomVector.push_back(WonderCardModel("CIRCUS MAXIMUS"));
	m_randomVector.push_back(WonderCardModel("THE GREAT LIGHTHOUSE"));
	m_randomVector.push_back(WonderCardModel("TEMPLE OF ARTEMIS"));
	m_randomVector.push_back(WonderCardModel("THE APPIAN WAY"));
	m_randomVector.push_back(WonderCardModel("THE COLOSSUS"));
	m_randomVector.push_back(WonderCardModel("THE GREAT LIBRARY"));
	m_randomVector.push_back(WonderCardModel("THE HANGING GARDENS"));
	m_randomVector.push_back(WonderCardModel("THE STATUE OF ZEUS"));
	m_randomVector.push_back(WonderCardModel("THE MAUSOLEUM"));
	m_randomVector.push_back(WonderCardModel("THE PYRAMIDS"));
	m_randomVector.push_back(WonderCardModel("THE SPINX"));
}

void WonderCardDeck::ShuffleInCards()
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	shuffle(m_randomVector.begin(), m_randomVector.end(), std::default_random_engine(seed));
}

void WonderCardDeck::EraseCardsFromVector(std::string str)
{
	m_randomVector.erase(std::remove_if(m_randomVector.begin(), m_randomVector.end(), [&str](WonderCardModel& wonderCard) {return wonderCard.GetCardName() == str; }), m_randomVector.end());
}

const std::vector<WonderCardModel>& WonderCardDeck::GetDeck() const
{
	return m_randomVector;
}

void WonderCardDeck::FaceingFourWonderCards()
{
	std::cout << "\n";
	for (int i = 0; i < kFacedWonders; i++)
	{
		std::cout << m_randomVector.at(i).GetCardName() << "\n";
	}
}
WonderCardDeck::WonderCardDeck(const WonderCardDeck& other)
{
	*this = other;
}
WonderCardDeck::WonderCardDeck(WonderCardDeck&& other)
{
	*this = std::move(other);
}
WonderCardDeck& WonderCardDeck::operator=(const WonderCardDeck& other)
{
	return *this;
}
WonderCardDeck& WonderCardDeck::operator=(WonderCardDeck&& other)
{
	memset(&other, 0, sizeof(other));
	return *this;
}
WonderCardDeck::~WonderCardDeck()
{
}
const WonderCardModel& WonderCardDeck::GetWCard(uint16_t i) const
{
	return m_randomVector[0];
}
WonderCardModel WonderCardDeck::PickWonderCard(std::string name)
{
	auto node = m_deck.extract(name);
	if (node)
		return std::move(node.mapped());
	else
		throw "Card not found";
}
std::ostream& operator<<(std::ostream& os, WonderCardDeck& deck)
{
	for (const auto& [CardName, Card] : deck.m_deck)
	{
		os << deck.m_deck.at(CardName).GetCardName() << " \n ";
	}
	os << std::endl;
	return os;
}