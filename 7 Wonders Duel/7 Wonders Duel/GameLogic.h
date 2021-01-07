#include<iostream>
#include <string>
#include<unordered_map>

#include"Player.h"
#include"AgeICards.h"
#include"Age2Deck.h"
#include"Age3Deck.h"
#include"GameMechanics.h"
#include "Board.h"
#include"WonderCardDeck.h"
#include"ActiveProgressTokens.h"
#include"PlaceCardsAge1.h"
#include"PlaceCardsAge2.h"
#include"PlaceCardsAge3.h"

class GameLogic {

public:
	void SettingGame();
	void RunGame();
	template <class cost>
	uint16_t CountPlayerResource(Player player1, cost costIndex);
	bool BuyingResource(Cost cost, Player& player1, Player player2);
	template <class cost, class card>
	uint16_t CountCardCost(card cardIndex, cost costIndex);
	template <class cost, class card>
	bool SetBoughtResource(card cardIndex, Player& player1, Player player2, cost costIndex);
	template<class card, class Age>
	bool BuyingCard(card c, Player& player1, Player player2, Age age);
	void MoveConflictPawn(Board& b, Player& player1, Player& player2, Card costIndex);
	template<class Symbol>
	void SetSymbol(Player& player1, Symbol symbol);
	void UseCardSymbol(Player& player1, Card card);
	bool CountSymbolInPlayersDeck(Player& player1);
	void UseSign(Player& player1, Card card);
	bool VerifyCardSign(Player& player1, Card card);
	ProgressToken FindProgressToken(std::string givenName);
	void SetSpecial(Player& player1, Card card);

	void ChoseResource(Player& player);
	void ValidResourceChosen(Player& player);
	void ChoseManufacturedGood(Player& player);
	void ValidManufacturedGoodChosen(Player& player);
	void Agriculture(Player& player);
	void Arhitecture(Player& player);
	void Economy(Player& player);
	void Law(Player& player);
	void Masonry(Player& player);
	void Mathematics(Player& player);
	void Philosophy(Player& player);
	void Theology(Player& player);
	void Strategy(Player& player);
	void Urbanism(Player& player);

	void UseProgressToken(Player& player, std::string givenName);
	void PickToken(Player& player1, ActiveProgressTokens& progressTokens);
	template< class Age>
	Card FindCard(std::string C, Age cards);

	void BuildersGuild(Player& player1, Player& player2);
	void MoneyLendersGuild(Player& player1, Player& player2);
	uint32_t CountBuildingsByColor(Card::Color c, Player player1);

	void ComparingPlayersCardColor(Player& player1, Player& player2, Card::Color color);
	void ShipownersGuild(Player& player1, Player& player2);
	void ScientistGuild(Player& player1, Player& player2);
	void TradersGuild(Player& player1, Player& player2);
	void MagistratedGuild(Player& player1, Player& player2);
	void TacticiansGuild(Player& player1, Player& player2);

	bool FindGuilCard(std::string givenName, Player player);

	void UseGuildCards(Player& player1, Player& player2);
	template<class Age>
	bool UsingCard(Player& player1, Player player2, Card card, Age age, ActiveProgressTokens& progressTokens);

	void ShowingWonderCardCost(WonderCardModel wonderCard);
	bool BuildWonderCard(Player& player1, Player player2, WonderCardDeck wonderDeck, WonderCardModel wonderCard);

	void TheAppianWay(Player& player1, Player& player2, bool& extraTurn);
	void CircusMaximus(Board& board,Player& player1, Player& player2);
	void TheColossus(Board& board, Player& player);
	void TheGreatLibrary(Player& player);
	void TheGreatLightHouse(Player& player);
	void TheMausoleum(Player& player1);
	void Piraeus(Player& player, bool& extraTurn);
	void ThePyramids(Player& player);
	void TheSphinx(Player& player, bool& extraTurn);
	void TheStatueOfZeus(Board& board, Player& player);
	void TheTempleOfArtemis(Player& player, bool& extraTurn);
	void TheHangingGardens(Player& player, bool& extraTurn);

	void UseWonderCard(Board& board,Player& player1, Player& player2, WonderCardModel wonderCard, bool& extraTurn);
	bool VerifyWonderCardCost(Board& board,Player& player1, Player &player2, WonderCardDeck wonderDeck, bool& extraTurn);

	void ChosingWonderCards();

	template <class Age,class accesible >
	void ChosingACard(accesible &placement,Player& player1, Player& player2, Age& age, Board& b, ActiveProgressTokens& progressTokens, bool& extraTurn);

	void ShowingWonderCostAndResources(Player player1);

	bool ScientificVictory(Player player);

	bool MilitaryVictory(Board board);

	template<class Age, class accesible >
	void PlayAge(accesible&p,Age& age, Player& activePlayer, Player& inactivePlayer, Board& board, ActiveProgressTokens& progressTokens, bool& extraTurn);
	void ChosingAgeCards();
private:

	GameMechanics gm;
	Player player1;
	Player player2;
	Board board;
	AgeICards age1;
	Age2Deck age2;
	Age3Deck age3;
	WonderCardDeck wonderDeck;
	ActiveProgressTokens progressTokens;
	bool extraTurn = false;
	PlaceCardsAge1 firstPlacement;
	PlaceCardsAge2 secondPlacement;
	PlaceCardsAge3 thirdPlacement;
};

template<class cost>
inline uint16_t GameLogic::CountPlayerResource(Player player1, cost c)
{

	int resourcesCountPlayer = 0;
	std::cout << "\nCost: " << c;
	std::vector<Cost> s = player1.GetResources();

	if (c.GetRawMaterial().GetRawMaterial() == RawMaterialsCLass::RawMaterials::Stone || c.GetRawMaterial().GetRawMaterial() == RawMaterialsCLass::RawMaterials::Wood || c.GetRawMaterial().GetRawMaterial() == RawMaterialsCLass::RawMaterials::Clay);
	resourcesCountPlayer = std::count_if(s.begin(), s.end(), [&c](Cost i) {return i.GetRawMaterial().GetRawMaterial() == c.GetRawMaterial().GetRawMaterial(); });

	if (c.GetManufacturedGood().GetManufacturedGood() == ManufacturedGoodsClass::ManufacturedGoods::Glass || c.GetManufacturedGood().GetManufacturedGood() == ManufacturedGoodsClass::ManufacturedGoods::Papirus)
		resourcesCountPlayer = std::count_if(s.begin(), s.end(), [&c](Cost i) {return i.GetManufacturedGood().GetManufacturedGood() == c.GetManufacturedGood().GetManufacturedGood(); });

	std::cout << "\n" << player1.GetName() << ": " << resourcesCountPlayer;

	return resourcesCountPlayer;
}

template<class cost, class card>
inline uint16_t GameLogic::CountCardCost(card cardIndex, cost c)
{
	uint16_t costCount = 0;
	std::cout << "\nCost: " << c;
	std::vector<Cost> s = cardIndex.GetCost();

	if (c.GetRawMaterial().GetRawMaterial() == RawMaterialsCLass::RawMaterials::Stone || c.GetRawMaterial().GetRawMaterial() == RawMaterialsCLass::RawMaterials::Wood || c.GetRawMaterial().GetRawMaterial() == RawMaterialsCLass::RawMaterials::Clay);
	costCount = std::count_if(s.begin(), s.end(), [&c](Cost i) {return i.GetRawMaterial().GetRawMaterial() == c.GetRawMaterial().GetRawMaterial(); });

	if (c.GetManufacturedGood().GetManufacturedGood() == ManufacturedGoodsClass::ManufacturedGoods::Glass || c.GetManufacturedGood().GetManufacturedGood() == ManufacturedGoodsClass::ManufacturedGoods::Papirus)
		costCount = std::count_if(s.begin(), s.end(), [&c](Cost i) {return i.GetManufacturedGood().GetManufacturedGood() == c.GetManufacturedGood().GetManufacturedGood(); });

	std::cout << "\nCard: " << costCount;
	return costCount;
}
template<class cost, class card>
inline bool GameLogic::SetBoughtResource(card cardIndex, Player& player1, Player player2, cost c)
{
	uint16_t costCount = CountCardCost(cardIndex, c);
	uint16_t resourcesCountPlayer = CountPlayerResource(player1, c);

	if (costCount > resourcesCountPlayer)
	{
		try {
			uint16_t differenceOfResource = costCount - resourcesCountPlayer;
			BuyingResource(c, player1, player2);
			std::vector<Cost> playerResources = player1.GetResources();
			uint16_t initialDimension = playerResources.size();
			playerResources.resize(playerResources.size() + differenceOfResource);
			std::fill(playerResources.begin() + initialDimension, playerResources.end(), c);
			player1.OverWriteResources(playerResources);
		}
		catch (const char* error)
		{
			std::cout << error << std::endl;
			return false;
		}
	}
	return true;

}

template<class card, class Age>
inline bool GameLogic::BuyingCard(card c, Player& player1, Player player2, Age age)
{
	age.PopulateDeck();
	card cardIndex;
	auto ageDub = age.GetDeck();
	auto it = std::find_if(std::begin(ageDub), end(ageDub), [&c](card& p) { return p.GetCardName() == c.GetCardName(); });
	if (it == ageDub.end())
	{
		std::cout << "\	The card " << c.GetCardName() << "wasn't found in the deck.\n";
		return false;
	}
	if (player1.GetMoney() < c.GetCost().at(0).GetCoins())
	{
		std::cout << "\nYou don't afford the card.";
		return false;
	}
	uint32_t copyMoney = player1.GetMoney();
	auto initialResources = player1.GetResources();

	player1.DecreaseMoney(c.GetCost().at(0).GetCoins());
	std::vector<Cost> posibleCost;
	posibleCost.insert(posibleCost.end(), { Cost(RawMaterialsCLass::RawMaterials::Clay),Cost(RawMaterialsCLass::RawMaterials::Wood),Cost(RawMaterialsCLass::RawMaterials::Stone),Cost(ManufacturedGoodsClass::ManufacturedGoods::Papirus),Cost(ManufacturedGoodsClass::ManufacturedGoods::Glass) });
	for (auto cost : posibleCost)
	{
		if (SetBoughtResource(c, player1, player2, cost) == false)
		{
			player1.SetMoney(copyMoney);
			player1.OverWriteResources(initialResources);
			std::cout << "\nYou don't afford the card!";
			return false;
		}
	}
	std::cout << "\nYou have all the resources required to build the card.\nCard successfully bought!\n";
	return true;
}


template<class Symbol>
inline void GameLogic::SetSymbol(Player& player1, Symbol symbol)
{
	player1.SetSymbol(symbol);
	player1.SetActiveSymbol(symbol);
}

template<class Age>
inline Card GameLogic::FindCard(std::string C, Age cards)
{
	for (auto index = 0; index < cards.GetDeck().size(); index++)
	{
		if (cards.GetDeck().at(index).GetCardName().find(C) != std::string::npos) {
			return cards.GetDeck().at(index);
		}
	}
	throw "Invalid card";
}

template<class Age>
inline bool GameLogic::UsingCard(Player& player1, Player player2, Card c, Age age, ActiveProgressTokens& progressTokens)
{
	if (VerifyCardSign(player1, c) == true)
	{
		std::cout << "You own the connected card from the previous age => The " << c.GetCardName() << " is for free.";
		player1.SetDeck(c);

		return true;
	}

	if (BuyingCard(c, player1, player2, age) == false)
	{
		return false;
	}
	player1.SetDeck(c);
	UseCardSymbol(player1, c);
	UseSign(player1, c);
	MoveConflictPawn(board, player1, player2, c);
	if (CountSymbolInPlayersDeck(player1) == true)
	{
		PickToken(player1, progressTokens);
	}
	
	switch (c.GetManufGood().GetManufacturedGood())
	{
	case ManufacturedGoodsClass::ManufacturedGoods::Glass:
	{
		player1.SetResource(Cost(ManufacturedGoodsClass::ManufacturedGoods::Glass));
		break;
	}
	case ManufacturedGoodsClass::ManufacturedGoods::Papirus:
	{
		player1.SetResource(Cost(ManufacturedGoodsClass::ManufacturedGoods::Papirus));
		break;
	}
	case ManufacturedGoodsClass::ManufacturedGoods::None:
	{break; }
	default:
		break;
	}
	switch (c.GetRawMaterial().GetRawMaterial())
	{
	case  RawMaterialsCLass::RawMaterials::None:
	{
		break;
	}
	case  RawMaterialsCLass::RawMaterials::Stone:

	{
		player1.SetResource(Cost(RawMaterialsCLass::RawMaterials::Stone));
		break;
	}
	case RawMaterialsCLass::RawMaterials::Wood:
	{
		player1.SetResource(Cost(RawMaterialsCLass::RawMaterials::Wood));
		break;
	}
	case RawMaterialsCLass::RawMaterials::Clay:
	{
		player1.SetResource(Cost(RawMaterialsCLass::RawMaterials::Clay));
		break;
	}
	default:
		break;
	}
	player1.AddMoney(c.GetCoins());
	SetSpecial(player1, c);
	return true;
}

template<class Age,class accesible>
inline void GameLogic::ChosingACard(accesible&placement,Player& player1, Player& player2, Age& age, Board& b, ActiveProgressTokens& progressTokens, bool& extraTurn)
{
	bool ok = false;
	while (ok == false) {
		std::string name;
		std::cout << "Enter the name of a card:\n";
		std::getline(std::cin.ignore(), name);
		Card c = FindCard(name, age);
		std::string chose;
		std::cout << "\nType:\n1 to buy the card\n2 to discard the card\n3 use the card to build a wonder\n4 to select another card.\n";
		std::cin >> chose;

		
			if (chose == "1")
			{
				while (true)
				{

					try
					{

						if (UsingCard(player1, player2, c, age, progressTokens) == true)
							ok = true;
						placement.DiscardCard(c);
						placement.MakeAccessibleCards();
						std::cout << "\n" << player1.GetName() << " has: " << player1.GetMoney() << " coins.\n";

						std::cout << "\n" << b;
					}
					catch (const char* error)
					{
						std::cout << error << std::endl;
						getline(std::cin, name);
					}
			break;	}
				
			}
			else if (chose == "2")
			{
				placement.DiscardCard(c);
				placement.MakeAccessibleCards();
				player1.AddMoney(2);
				std::cout << "\nPlayer has: " << player1.GetMoney() << " coins.\n";

				ok = true;
				break;
			}
			else if (chose == "3")
			{
				while (true) {
					try {
						if (VerifyWonderCardCost(board, player1, player2, wonderDeck, extraTurn) == true)
						{
							placement.DiscardCard(c);
							placement.MakeAccessibleCards();
							ok = true;
						}
					}
					catch (const char* error)
					{
						std::cout << error << std::endl;
						getline(std::cin, name);
					}
					break;
				}
			}
			else if (chose == " 4")
			{
				throw"Chose another card!";
				break;
			}
			else
				std::cout << "Invalid option.";

		
	}
}

template<class Age, class accesible>
inline void GameLogic::PlayAge(accesible&placement,Age& age, Player& activePlayer, Player& inactivePlayer, Board& board, ActiveProgressTokens& progressTokens, bool& extraTurn)
{
	std::cout << "\n";
	ShowingWonderCostAndResources(activePlayer);
	placement.AccessibleCards();

	std::cout<<"\n" << activePlayer.GetName() << "\n";
	std::cout << "\nDECK: ";
		for (auto a : activePlayer.GetPlayerDeck2())
			std::cout << a.GetCardName() << "\n";
	std::cout << "\nRESOURCES: ";
	for (auto a : activePlayer.GetResources())
		std::cout << a << " ";
	std::cout << "\nMONEY: " << activePlayer.GetMoney() << "	VICTORY POINTS: " << activePlayer.GetVictoryPoints() << "	MILITARY POINTS:" << activePlayer.GetMilitarryPoints();
	std::cout << "\nSYMBOLS: ";
	for (auto a : activePlayer.GetSymbols())
		std::cout << a << " ";
	std::cout << "\nSIGNS: ";
	for (auto a : activePlayer.GetSigns())
		std::cout << a << " ";

	std::cout << "\n\n" << inactivePlayer.GetName();
	std::cout << "\n\nDECK: ";
	for (auto a : inactivePlayer.GetPlayerDeck2())
		std::cout << a.GetCardName() << "\n";
	std::cout << "\nRESOURCES: ";
	for (auto a : inactivePlayer.GetResources())
		std::cout << a << " ";
	std::cout << "\nMONEY: " << inactivePlayer.GetMoney() << "	VICTORY POINTS: " << inactivePlayer.GetVictoryPoints() << "	MILITARY POINTS:" << inactivePlayer.GetMilitarryPoints();
	std::cout << "\nSYMBOLS: ";

	for (auto a : inactivePlayer.GetSymbols())
		std::cout << a << " ";
	std::cout << "\nSIGNS: ";
	for (auto a : inactivePlayer.GetSigns())
		std::cout << a << " ";
	std::cout << "\n\n" << activePlayer << "  ";

	while (true)
	{
		try
		{
			ChosingACard(placement,activePlayer, inactivePlayer, age, board, progressTokens, extraTurn);
			break;
		}
		catch (const char* errorMessage)
		{
			std::cout << errorMessage << std::endl;
		}
	}
}