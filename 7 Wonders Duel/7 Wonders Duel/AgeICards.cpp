#include "AgeICards.h"
#include"Cost.h"
#include <algorithm>    
#include <random>       
#include <chrono> 
#include <ctime>    
#include"Symbols.h"
AgeICards::AgeICards()
{
}

AgeICards::AgeICards(const AgeICards& other)
{
	*this = other;
}

AgeICards::AgeICards(AgeICards&& other)
{
	*this = std::move(other);
}

AgeICards& AgeICards::operator=(const AgeICards& other)
{
	for (int i = 0; i < kDeckSize; i++)
	{
		m_stackAgeICards[i] = other.m_stackAgeICards[i];
	}
	return *this;
}

AgeICards& AgeICards::operator=(AgeICards&& other)
{
	for (int i = 0; i < kDeckSize; i++)
	{
		m_stackAgeICards[i] = other.m_stackAgeICards[i];
	}
	memset(&other, 0, sizeof(other));
	return *this;
}

AgeICards::~AgeICards() {}

void AgeICards::PopulateDeck()
{
	m_stackAgeICards[0] = Card("LUMBER YARD     ", Card::Age::First, Card::Color::Brown, {0}, Signs::Sign::Null, RawMaterialsCLass::RawMaterials::Wood);
	m_stackAgeICards[1] = Card("LOGGING CAMP    ", Card::Age::First, Card::Color::Brown, {1}, Signs::Sign::Null, RawMaterialsCLass::RawMaterials::Wood);
	m_stackAgeICards[2] = Card("CLAY PIT        ", Card::Age::First, Card::Color::Brown, {1}, Signs::Sign::Null, RawMaterialsCLass::RawMaterials::Clay);
	m_stackAgeICards[3] = Card("CLAY POOL       ", Card::Age::First, Card::Color::Brown, {0}, Signs::Sign::Null, RawMaterialsCLass::RawMaterials::Clay);
	m_stackAgeICards[4] = Card("QUARRY          ", Card::Age::First, Card::Color::Brown, {0}, Signs::Sign::Null, RawMaterialsCLass::RawMaterials::Stone);
	m_stackAgeICards[5] = Card("STONE PIT       ", Card::Age::First, Card::Color::Brown, { 1 }, Signs::Sign::Null, RawMaterialsCLass::RawMaterials::Stone);
	m_stackAgeICards[6] = Card("GLASS WORKS     ", Card::Age::First, Card::Color::Grey, { 1 }, Signs::Sign::Null, ManufacturedGoodsClass::ManufacturedGoods::Glass);
	m_stackAgeICards[7] = Card("PRESS           ", Card::Age::First, Card::Color::Grey, { 1 }, Signs::Sign::Null, ManufacturedGoodsClass::ManufacturedGoods::Glass);
	m_stackAgeICards[8] = Card("GUARD TOWER     ", Card::Age::First, Card::Color::Red, {0}, Signs::Sign::Null, Symbols::Symbol::Null, { Points::PointsType::MilitaryVictoryPoints });
	m_stackAgeICards[9] = Card("WORKSHOP        ", Card::Age::First, Card::Color::Green, { Cost(ManufacturedGoodsClass::ManufacturedGoods::Papirus) }, Signs::Sign::Null, Symbols::Symbol::Pendulum, { Points::PointsType::VictoryPoints });
	m_stackAgeICards[10] = Card("STONE RESERVE   ", Card::Age::First, Card::Color::Yellow, { 3 }, Signs::Sign::Null, 3);
	m_stackAgeICards[11] = Card("CLAY RESERVE    ", Card::Age::First, Card::Color::Yellow, { 3 }, Signs::Sign::Null, 3);
	m_stackAgeICards[12] = Card("WOOD RESERVE    ", Card::Age::First, Card::Color::Yellow, { 3 }, Signs::Sign::Null, 3);
	m_stackAgeICards[13] = Card("STABLE          ", Card::Age::First, Card::Color::Red, {0, Cost(RawMaterialsCLass::RawMaterials::Wood) }, Signs::Sign::Horseshoe, Symbols::Symbol::Null, { Points::PointsType::MilitaryVictoryPoints });
	m_stackAgeICards[14] = Card("GARISON         ", Card::Age::First, Card::Color::Red, { 0,Cost(RawMaterialsCLass::RawMaterials::Clay) }, Signs::Sign::Sword, Symbols::Symbol::Null, { Points::PointsType::MilitaryVictoryPoints });
	m_stackAgeICards[15] = Card("PALISADE        ", Card::Age::First, Card::Color::Red, { 2 }, Signs::Sign::Tower, Symbols::Symbol::Null, { Points::PointsType::MilitaryVictoryPoints });
	m_stackAgeICards[16] = Card("SCRIPTORIUM     ", Card::Age::First, Card::Color::Green, { 2 }, Signs::Sign::Book, Symbols::Symbol::Feather);
	m_stackAgeICards[17] = Card("PHARMACIST      ", Card::Age::First, Card::Color::Red, { 2 }, Signs::Sign::Tower, Symbols::Symbol::Bol);
	m_stackAgeICards[18] = Card("THEATER         ", Card::Age::First, Card::Color::Blue, {0}, Signs::Sign::Mask, Symbols::Symbol::Null, { Points::PointsType::VictoryPoints,Points::PointsType::VictoryPoints,Points::PointsType::VictoryPoints });
	m_stackAgeICards[19] = Card("ALTAR           ", Card::Age::First, Card::Color::Blue, {0}, Signs::Sign::HalfMoon, Symbols::Symbol::Null, { Points::PointsType::VictoryPoints,Points::PointsType::VictoryPoints,Points::PointsType::VictoryPoints });
	m_stackAgeICards[20] = Card("BATHS           ", Card::Age::First, Card::Color::Blue, {0, Cost(RawMaterialsCLass::RawMaterials::Stone) }, Signs::Sign::WaterDrop, Symbols::Symbol::Null, { Points::PointsType::VictoryPoints,Points::PointsType::VictoryPoints,Points::PointsType::VictoryPoints });
	m_stackAgeICards[21] = Card("TAVERN          ", Card::Age::First, Card::Color::Yellow, {0}, Signs::Sign::Vessel, 6);

	m_stackAgeICards[22] = Card("APOTHECARY      ", Card::Age::First, Card::Color::Green, { {0}, Cost(ManufacturedGoodsClass::ManufacturedGoods::Glass) }, Signs::Sign::Null, Symbols::Symbol::Wheel, { Points::PointsType::VictoryPoints });
}

void AgeICards::ShuffleInCards()
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	shuffle(m_stackAgeICards.begin(), m_stackAgeICards.end(), std::default_random_engine(seed));
}

const std::array<Card, AgeICards::kDeckSize> &AgeICards::GetDeck() const
{
	return m_stackAgeICards;
}

std::ostream& operator<<(std::ostream& os, AgeICards& ac)
{
	for (int i = 0; i < AgeICards::kDeckSize; i++)
	{
		os << ac.m_stackAgeICards.at(i) << "\n" << "\n";
	}
	os << std::endl;
	return os;
}
