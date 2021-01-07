#include "Player.h"
#include<string>
Player::Player(const std::string& name) :
	m_name(name) {
}
WonderCardModel Player::PickWonderCards(std::string wonderCardName, WonderCardDeck& wonderDeck)
{
	m_wonderCards.push_back(WonderCardModel(wonderCardName));
	return (wonderDeck.PickWonderCard(wonderCardName));
}

const std::map<Card::Color, std::vector<Card>> Player::GetPlayerDeck() const
{
	return playerDeck;
}

const std::vector<Card>& Player::GetPlayerDeck2() const
{
	return playerDeck2;
}

const std::vector<WonderCardModel>& Player::GetWonderCards() const
{
	return m_wonderCards;
}
const uint16_t& Player::GetMilitarryPoints() const
{
	return m_militaryPoints;
}
const uint16_t& Player::GetVictoryPoints() const
{
	return m_victoryPoints;
}
const std::vector<ProgressToken>& Player::GetProgressTokens() const
{
	return m_progressTokens;
}
const std::vector<int>& Player::GetCoins() const
{
	return m_coins;
}
const std::vector<Cost>& Player::GetResources() const
{
	return m_resources;
}
const std::vector<WonderCardModel>& Player::GetBuildedWonders() const
{
	return m_buildedWonders;
}
const std::string& Player::GetName() const
{
	return m_name;
}
const uint16_t& Player::GetMoney() const
{
	return m_money;
}
const bool& Player::GetDirection() const
{
	return m_direction;
}
const std::vector<Symbols::Symbol>& Player::GetSymbols() const
{
	return m_symbols;
}
const std::vector<Symbols::Symbol>& Player::GetActiveSymbols() const
{
	return m_activeSymbols;
}
void Player::SetName(std::string name)
{
	m_name = name;
}
void Player::SetMilitarryPoints(uint16_t gainedMilitaryPoints)
{
	m_militaryPoints += gainedMilitaryPoints;
}
void Player::SetVictoryPoints(uint16_t gainedVictoryPoints)
{
	m_victoryPoints += gainedVictoryPoints;
}
void Player::SetResource(Cost resource)
{
	m_resources.push_back(resource);
}
void Player::SetDeck(Card resource)
{
	playerDeck2.push_back(resource);
}
void Player::SetBuildedWonders(WonderCardModel buildedWonder)
{
	m_wonderCards.erase(std::remove_if(m_wonderCards.begin(), m_wonderCards.end(), [&buildedWonder](WonderCardModel& wonderCard) {return wonderCard.GetCardName() == buildedWonder.GetCardName(); }), m_wonderCards.end());
	m_buildedWonders.push_back(buildedWonder);
}
void Player::SetDirection(bool direction)
{
	m_direction = direction;
}
void Player::SetMoney(uint16_t money)
{
	m_money = money;
}
void Player::AddMoney(uint16_t money)
{
	m_money += money;
}
void Player::DecreaseMoney(uint16_t money)
{
	m_money -= money;
}
void Player::DeactivateSymbol(Symbols::Symbol deactivatedSymbol)
{
	m_activeSymbols.erase(std::remove_if(m_activeSymbols.begin(), m_activeSymbols.end(), [&deactivatedSymbol](Symbols::Symbol& symbol) {return deactivatedSymbol == symbol; }), m_activeSymbols.end());
}
void Player::SetSign(Signs::Sign sign)
{
	m_signs.push_back(sign);
}
const std::vector<Signs::Sign>& Player::GetSigns() const
{
	return m_signs;
}
void Player::OverWriteResources(std::vector<Cost> costVector)
{
	m_resources = std::move(costVector);
}
void Player::SetProgressTokens(ProgressToken progressToken)
{
	m_progressTokens.push_back(progressToken);
}
void Player::SetSymbol(Symbols::Symbol symbol)
{
	m_symbols.push_back(symbol);
}
void Player::SetActiveSymbol(Symbols::Symbol symbol)
{
	m_activeSymbols.push_back(symbol);
}
std::ostream& operator<<(std::ostream& os, const Player& player)
{
	return os << player.m_name;
}