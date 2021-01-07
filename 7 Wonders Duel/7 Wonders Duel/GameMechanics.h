#pragma once
#include"Points.h"
#include"Player.h"
#include"AgeICards.h"
#include"Age2Deck.h"
#include"Age3Deck.h"
#include"ActiveProgressTokens.h"

class GameMechanics
{
public:
	enum class Turn
	{
		First,
		Second,
		Third,
	};
	GameMechanics();
	int PlayTurn(Turn turn);

public:
	
	template<class Age, class card>
	bool BuyingCard(card c, Player& player1, Player player2, Age age);
	template <class cost, class card>
	bool funct(card cardIndex, Player& player1, Player player2, cost c);
	bool SetPlayerBoughtResource(Cost c, Player& player1, Player player2, int costCount, int resourcesCountPlayer);
	bool BuyingResource(Cost cost, Player& player1, Player player2);
	int CountBuildingsByColor(Card::Color c, Player player1);
	int CountRawMaterialsWood(Player player1);
	int CountRawMaterialsClay(Player player1);
	int CountRawMaterialsStone(Player player1);
	int CountMaterialsGoodsGlass(Player player1);
	int CountMaterialsGoodsPapirus(Player player1);
public:
	template <class Age>
	Card FindCard(std::string C, Age cards);
	template<class Age>
	bool UsingCard(Player& player1, Player player2, Card c, Age age, ActiveProgressTokens& progressTokens);
	void UseSign(Player& player1, Card c);
	bool CountSymbolInPlayersDeck(Player& player1);
	void SetSpecial(Player& player1, Card c);
	bool VerifyCardSign(Player& player1, Card c);
	void UseCardSymbol(Player& player1, Card c);
	void PickToken(Player& player1, ActiveProgressTokens& progressTokens, std::string progressTokenName);
	ProgressToken FindProgressToken(std::string C,ActiveProgressTokens progressTokens);
	void UseProgressToken(Player& player, std::string s);



public:
	void ChoseResource(Player& player)
	{
		std::cout << "Chose between Stone, Wood and Clay.\n";
		std::string resource;
		//std::cin >> resource;
		if (resource == "Stone")
			player.SetResource(Cost(RawMaterialsCLass::RawMaterials::Stone));
		else if (resource == "Clay")
			player.SetResource(Cost(RawMaterialsCLass::RawMaterials::Clay));
		else if (resource == "Wood")
			player.SetResource(Cost(RawMaterialsCLass::RawMaterials::Wood));
		else
			throw"Invalid option.";
	}
	void ValidResourceChosen(Player& player)
	{
		bool ok = false;
		while (ok == false)
		{
			try {
				ChoseResource(player);
				ok = true;
				break;
			}
			catch (const char* error)
			{
				std::cout << error;
			}
		}
	}
	void ChoseManufacturedGood(Player& player)
	{
		std::cout << "Chose between Glass and Papirus";
		std::string good;
		//std::cin >> good;
		if (good == "Glass")
			player.SetResource(Cost(ManufacturedGoodsClass::ManufacturedGoods::Glass));
		else if (good == "Papirus")
			player.SetResource(Cost(ManufacturedGoodsClass::ManufacturedGoods::Papirus));
		else
			throw"Invalid option.";

	}
	void ValidManufacturedGoodChosen(Player& player)
	{
		bool ok = false;
		while (ok == false)
		{
			try {
				ChoseManufacturedGood(player);
				ok = true;
				break;
			}
			catch (const char* error)
			{
				std::cout << error;
			}
		}
	}
	void Agriculture(Player& player) // good
	{
		player.AddMoney(6);
		player.SetVictoryPoints(4);
		std::cout << "\n!!!!!!!!!!\n";
		std::cout << player.GetMoney();
		std::cout << "\nVP:" << player.GetVictoryPoints();

	}
	void Arhitecture(Player& player)// !!!
	{
		ValidResourceChosen(player);
		ValidResourceChosen(player);
		std::cout << "\n!!!!!!!!!!\n";
		for (auto resource : player.GetResources())
			std::cout << resource;
	}
	void Economy(Player& player)// !!!
	{
		player.AddMoney(7);
		std::cout << "\n!!!!!!!!!!\n";
		std::cout << player.GetMoney();
	}
	void Law(Player& player) //godd
	{
		player.SetVictoryPoints(3);
		std::cout << "\n!!!!!!!!!!\n";
		std::cout << player.GetVictoryPoints();
	}
	void Masonry(Player& player) //good
	{
		ValidResourceChosen(player);
		ValidResourceChosen(player);
		std::cout << "\n!!!!!!!!!!\n";
		for (auto resource : player.GetResources())
			std::cout << resource;
	}
	void Mathematics(Player& player)
	{
		player.AddMoney(player.GetProgressTokens().size());
		std::cout << "\n!!!!!!!!!!\n";
		std::cout << player.GetMoney();
	}
	void Philosophy(Player& player)
	{
		player.SetVictoryPoints(7);
		std::cout << "\n!!!!!!!!!!\n";
		std::cout << player.GetVictoryPoints();
	}
	void Theology(Player& player)
	{
		ValidManufacturedGoodChosen(player);
		ValidManufacturedGoodChosen(player);
		std::cout << "\n!!!!!!!!!!\n";
		for (auto resource : player.GetResources())
			std::cout << resource;
	}
	void Strategy(Player& player)
	{
		player.SetMilitarryPoints(3);
		std::cout << "\n!!!!!!!!!!\n";
		std::cout << player.GetMilitarryPoints();

	}
	void Urbanism(Player& player)
	{
		player.AddMoney(6);
		std::cout << "\n!!!!!!!!!!\n";
		std::cout << player.GetMoney();
	}
private:
	Turn turn;

};



template<class Age>
inline Card GameMechanics::FindCard(std::string C, Age cards)
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
inline bool GameMechanics::UsingCard(Player& player1, Player player2, Card c, Age age, ActiveProgressTokens& progressTokens)
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
	//MoveConflictPawn(board, player1, player2, c);
	/*if (CountSymbolInPlayersDeck(player1) == true)
	{
		PickToken(player1, progressTokens);
	}*/

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
	SetSpecial(player1, c);
	return true;
}

template<class Age, class card>
inline bool GameMechanics::BuyingCard(card c, Player& player1, Player player2, Age age)
{
	age.PopulateDeck();
	card cardIndex;
	for (auto it : age.GetDeck())
	{

		if (it.GetCardName() == c.GetCardName())
		{
			cardIndex = it;
		}
	}
	int copyMoney = player1.GetMoney();

	if (cardIndex.GetCardName() != c.GetCardName())
	{
		player1.SetMoney(copyMoney);

		throw"The card wasn't found in the deck!";
		return false;
	}
	if (player1.GetMoney() < c.GetCost().at(0).GetCoins())
	{
		player1.SetMoney(copyMoney);

		throw (player1.GetName() + " doesn't afford the card!");
		return false;

	}
	player1.DecreaseMoney(c.GetCost().at(0).GetCoins());
	Player fool(player1);

	Cost clayCost(RawMaterialsCLass::RawMaterials::Clay);
	if (funct(c, fool, player2, clayCost) == false)
	{
		player1.SetMoney(copyMoney);

		throw (player1.GetName() + " doesn't afford the card!");
		return false;

	}
	Cost woodCost(RawMaterialsCLass::RawMaterials::Wood);
	if (funct(c, fool, player2, woodCost) == false)
	{
		player1.SetMoney(copyMoney);

		throw (player1.GetName() + " doesn't afford the card!");
		return false;

	}
	Cost stoneCost(RawMaterialsCLass::RawMaterials::Stone);

	if (funct(c, fool, player2, stoneCost) == false)
	{
		player1.SetMoney(copyMoney);

 		throw (player1.GetName() + " doesn't afford the card!");
		return false;

	}
	Cost papirusCost(ManufacturedGoodsClass::ManufacturedGoods::Papirus);
	if (funct(c, fool, player2, papirusCost) == false)
	{
		throw (player1.GetName() + " doesn't afford the card!");
	}
	Cost glassCost(ManufacturedGoodsClass::ManufacturedGoods::Glass);

	if (funct(c, fool, player2, glassCost) == false)
	{
		player1.SetMoney(copyMoney);

		throw (player1.GetName() + " doesn't afford the card!");
		return false;
	}


	player1.SetMoney(fool.GetMoney());
	std::cout << "\nThe player has all resources required to buy the card.\nSuccessfully purchased card!\n";

	return true;
}

template<class cost, class card>
inline bool GameMechanics::funct(card cardIndex, Player& player1, Player player2, cost c)
{

	int costCount = 0;
	std::cout << "\nCost: " << c;

	for (auto it : cardIndex.GetCost())
	{
		if (c.GetManufacturedGood().GetManufacturedGood() == ManufacturedGoodsClass::ManufacturedGoods::Glass || c.GetManufacturedGood().GetManufacturedGood() == ManufacturedGoodsClass::ManufacturedGoods::Papirus)
		{
			if (it.GetManufacturedGood().GetManufacturedGood() == c.GetManufacturedGood().GetManufacturedGood())
			{
				costCount++;
			}
		}
		if (c.GetRawMaterial().GetRawMaterial() == RawMaterialsCLass::RawMaterials::Stone || c.GetRawMaterial().GetRawMaterial() == RawMaterialsCLass::RawMaterials::Wood || c.GetRawMaterial().GetRawMaterial() == RawMaterialsCLass::RawMaterials::Clay)
		{
			if (it.GetRawMaterial().GetRawMaterial() == c.GetRawMaterial().GetRawMaterial())
			{
				costCount++;
			}
		}
	}
	std::cout << "\nCard: " << costCount;
	int resourcesCountPlayer = 0;
	for (auto itPla : player1.GetResources())
	{
		if (c.GetManufacturedGood().GetManufacturedGood() == ManufacturedGoodsClass::ManufacturedGoods::Glass || c.GetManufacturedGood().GetManufacturedGood() == ManufacturedGoodsClass::ManufacturedGoods::Papirus)
		{
			if (itPla.GetManufacturedGood().GetManufacturedGood() == c.GetManufacturedGood().GetManufacturedGood())
			{
				resourcesCountPlayer++;
			}
		}
		if (c.GetRawMaterial().GetRawMaterial() == RawMaterialsCLass::RawMaterials::Stone || c.GetRawMaterial().GetRawMaterial() == RawMaterialsCLass::RawMaterials::Wood || c.GetRawMaterial().GetRawMaterial() == RawMaterialsCLass::RawMaterials::Clay)
		{
			if (itPla.GetRawMaterial().GetRawMaterial() == c.GetRawMaterial().GetRawMaterial())
			{
				resourcesCountPlayer++;
			}
		}
	}
	std::cout << "\n" << player1.GetName() << ": " << resourcesCountPlayer;
	int chose=0;
	//std::cout << "\n\nDo you want to buy the resource?\nType:\n0 for YES\n1 for no\n";
	//std::cin >> chose;
	if (chose == 0)
	{
		SetPlayerBoughtResource(c, player1, player2, costCount, resourcesCountPlayer);
		return true;

	}
	return false;
}


