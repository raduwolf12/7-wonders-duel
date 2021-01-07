#pragma once
#include<cstdint>
#include <vector>
#include<string>
#include"Cost.h"
#include"Points.h"
#include"Symbols.h"
#include"Signs.h"
class  Card
{
public:
	enum class Age
	{
		First,
		Second,
		Third,
		Guild

	};
	enum class Color
	{
		Brown,
		Grey,
		Blue,
		Green,
		Yellow,
		Red,
		Purple
	};



public:

	Card();
	Card(std::string cardName, Age age, Color color, std::vector<Cost> cost, Signs::Sign sign, int value);
	Card(std::string cardName, Age age, Color color, std::vector<Cost> cost, Signs::Sign sign, RawMaterialsCLass value);
	Card(std::string cardName, Age age, Color color, std::vector<Cost> cost, Signs::Sign sign, ManufacturedGoodsClass value);
	Card(std::string cardName, Age age, Color color, std::vector<Cost> cost, Signs::Sign sign, Symbols::Symbol symbol, std::vector < Points> value);
	Card(std::string cardName, Age age, Color color, std::vector<Cost> cost, Signs::Sign sign, Symbols::Symbol symbol);
	Card(std::string cardName, Age age, Color color, std::vector<Cost> cost, Signs::Sign sign, Symbols::Symbol symbol, std::string value);
	Card(const Card& other);
	Card(Card&& other);
	Card& operator=(const Card& other);
	Card& operator=(Card&& other);
	Card& operator &= (const Card& other);

	~Card();
	friend std::ostream& operator<<(std::ostream& out, Card& card);
	const Age& GetAge() const;
	const Color& GetColor() const;

public: //getters
	const std::string& GetCardName()const;
	const std::vector<Cost>& GetCost() const;
	const std::vector < Points>& GetPoints()const;
	const RawMaterialsCLass& GetRawMaterial()const;
	const ManufacturedGoodsClass& GetManufGood()const;
	const std::string& GetSpecial()const;
	const Symbols::Symbol& GetSymbol()const;
	const Signs::Sign& GetSign()const;
	const int& GetCoins()const;

public:

	void SetName();

private:

	static int card_id;
	Color m_color;
	Age m_age;
	std::vector<Cost> m_cost;
	int m_coins = -1;
	std::vector < Points> m_points;
	Signs::Sign m_sign;
	std::string m_special;
	RawMaterialsCLass m_rawMaterials;
	ManufacturedGoodsClass m_manufacturedGoods;
	std::string m_cardName;
	Symbols::Symbol m_symbol;
	bool m_isRaw = false;
	bool m_isGoods = false;
	bool m_isPoint = false;
	bool m_isSymbol = false;
};

