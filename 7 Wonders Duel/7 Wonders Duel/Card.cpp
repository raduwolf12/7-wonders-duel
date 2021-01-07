#include "Card.h"

Card::Card() {}

Card::Card(std::string cardName, Age age, Color color, std::vector<Cost> cost, Signs::Sign sign, int value) : m_cardName(cardName), m_age(age), m_color(color), m_cost(cost), m_sign(sign), m_coins(value)
{

}

Card::Card(std::string cardName, Age age, Color color, std::vector<Cost> cost, Signs::Sign sign, RawMaterialsCLass value) : m_cardName(cardName), m_age(age), m_color(color), m_cost(cost), m_sign(sign), m_rawMaterials(value)
{
	m_isRaw = true;
}

Card::Card(std::string cardName, Age age, Color color, std::vector<Cost> cost, Signs::Sign sign, ManufacturedGoodsClass value) : m_cardName(cardName), m_age(age), m_color(color), m_cost(cost), m_sign(sign), m_manufacturedGoods(value)
{
	m_isGoods = true;
}

Card::Card(std::string cardName, Age age, Color color, std::vector<Cost> cost, Signs::Sign sign, Symbols::Symbol symbol, std::vector < Points> value) : m_cardName(cardName), m_age(age), m_color(color), m_cost(cost), m_sign(sign), m_symbol(symbol), m_points(value)
{
	m_isPoint = true;
	m_isSymbol = true;
}

Card::Card(std::string cardName, Age age, Color color, std::vector<Cost> cost, Signs::Sign sign, Symbols::Symbol symbol) :m_cardName(cardName), m_age(age), m_color(color), m_cost(cost), m_sign(sign), m_symbol(symbol)
{
	m_isPoint = false;
	m_isSymbol = true;
}

Card::Card(std::string cardName, Age age, Color color, std::vector<Cost> cost, Signs::Sign sign, Symbols::Symbol symbol, std::string value) : m_cardName(cardName), m_age(age), m_color(color), m_cost(cost), m_sign(sign), m_special(value), m_symbol(symbol) {}

Card::Card(const Card& other)
{
	*this = other;
}

Card::Card(Card&& other)
{
	*this = std::move(other);
}

Card& Card::operator=(const Card& other)
{
	m_cardName = other.m_cardName;
	m_color = other.m_color;
	m_age = other.m_age;
	m_cost = other.m_cost;
	m_coins = other.m_coins;
	m_points = other.m_points;
	m_sign = other.m_sign;
	m_special = other.m_special;
	m_rawMaterials = other.m_rawMaterials;
	m_manufacturedGoods = other.m_manufacturedGoods;
	m_symbol = other.m_symbol;
	m_isRaw = other.m_isRaw;
	m_isGoods = other.m_isGoods;
	m_isPoint = other.m_isPoint;
	return *this;
}

Card& Card::operator=(Card&& other)
{
	m_cardName = other.m_cardName;
	m_color = other.m_color;
	m_age = other.m_age;
	m_cost = other.m_cost;
	m_coins = other.m_coins;
	m_points = other.m_points;
	m_sign = other.m_sign;
	m_special = other.m_special;
	m_rawMaterials = other.m_rawMaterials;
	m_manufacturedGoods = other.m_manufacturedGoods;
	m_symbol = other.m_symbol;
	m_isRaw = other.m_isRaw;
	m_isGoods = other.m_isGoods;
	m_isPoint = other.m_isPoint;
	memset(&other, 0, sizeof(other));
	return *this;
}

Card& Card::operator&=(const Card& other)
{
	m_cardName = other.m_cardName;
	m_color = other.m_color;
	m_age = other.m_age;
	m_cost = other.m_cost;
	m_coins = other.m_coins;
	m_points = other.m_points;
	m_sign = other.m_sign;
	m_special = other.m_special;
	m_rawMaterials = other.m_rawMaterials;
	m_manufacturedGoods = other.m_manufacturedGoods;
	m_symbol = other.m_symbol;
	m_isRaw = other.m_isRaw;
	m_isGoods = other.m_isGoods;
	m_isPoint = other.m_isPoint;
	std::cout << "Object was copied";
	return *this;
}

Card::~Card() {}

const Card::Age& Card::GetAge()const
{
	return m_age;
}
const Card::Color& Card::GetColor() const
{
	return m_color;
}

const std::string& Card::GetCardName() const
{
	return m_cardName;
}

const std::vector<Cost>& Card::GetCost() const
{
	return m_cost;
}

const std::vector<Points>& Card::GetPoints() const
{
	return m_points;
}

const RawMaterialsCLass& Card::GetRawMaterial() const
{
	return m_rawMaterials;
}

const ManufacturedGoodsClass& Card::GetManufGood() const
{
	return m_manufacturedGoods;
}

const std::string& Card::GetSpecial() const
{
	return m_special;
}

const Symbols::Symbol& Card::GetSymbol() const
{
	return m_symbol;
}

const Signs::Sign& Card::GetSign() const
{
	return m_sign;
}

const int& Card::GetCoins() const
{
	return m_coins;
}

void Card::SetName()
{
	m_cardName.clear();
}

std::ostream& operator<<(std::ostream& out, Card& card)
{
	out << card.m_cardName;
	switch (card.m_age)
	{
	case Card::Age::First:
		out << "First ";
		break;
	case Card::Age::Second:
		out << "Second ";
		break;
	case Card::Age::Third:
		out << "Third ";
		break;
	case Card::Age::Guild:
		out << "Guild ";
		break;
	default:
		throw "Not a valid value ";
		break;
	}
	switch (card.m_color)
	{
	case Card::Color::Grey:
		out << "Grey ";
		break;
	case Card::Color::Brown:
		out << "Brown ";
		break;
	case Card::Color::Blue:
		out << "Blue ";
		break;
	case Card::Color::Green:
		out << "Green ";
		break;
	case Card::Color::Yellow:
		out << "Yellow ";
		break;
	case Card::Color::Red:
		out << "Red ";
		break;
	case Card::Color::Purple:
		out << "Purple ";
		break;
	default:
		throw "Not a valid value ";
		break;
	}
	for (int index = 0; index < card.m_cost.size(); index++)
	{
		out << card.m_cost.at(index) << " ";
	}
	switch (card.m_sign)
	{
	case Signs::Sign::Barrel:out << "Barrel ";
		break;
	case Signs::Sign::Book:out << "Book ";
		break;
	case Signs::Sign::Column:out << "Column ";
		break;
	case Signs::Sign::HalfMoon:out << "HalfMoon ";
		break;
	case Signs::Sign::Harp:out << "Harp ";
		break;
	case Signs::Sign::Helmet:out << "Helmet ";
		break;
	case Signs::Sign::Horseshoe:out << "Horseshoe ";
		break;
	case Signs::Sign::Lamp:out << "Lamp ";
		break;
	case Signs::Sign::Mask:out << "Mask ";
		break;
	case Signs::Sign::Sun:out << "Sun ";
		break;
	case Signs::Sign::Sword:out << "Sword ";
		break;
	case Signs::Sign::Target:out << "Target ";
		break;
	case Signs::Sign::Temple:out << "Temple ";
		break;
	case Signs::Sign::Tower:out << "Tower ";
		break;
	case Signs::Sign::Vessel:out << "Vessel ";
		break;
	case Signs::Sign::WaterDrop:out << "WaterDrop ";
		break;
	case Signs::Sign::Wheel:out << "Wheel ";
		break;
	case Signs::Sign::Null: out << "Null ";
		break;
	default:
		throw "Not a valid value ";
		break;
	}

	if (card.m_isSymbol)
	{
		switch (card.m_symbol)
		{
		case Symbols::Symbol::Bol:
			out << "Bowl ";
			break;
		case Symbols::Symbol::Feather:
			out << "Feather ";
			break;
		case Symbols::Symbol::Gyroscope:
			out << "Gyroscope ";
			break;
		case Symbols::Symbol::Pendulum:
			out << "Pendulum ";
			break;
		case  Symbols::Symbol::SolarClock:
			out << "SolarClock ";
			break;
		case Symbols::Symbol::Wheel:
			out << "Wheel ";
			break;
		case Symbols::Symbol::Null:
			out << "Null ";
			break;
		default:
			throw "Not a valid value ";
			break;
		}
	}
	if (card.m_isRaw)
		out << card.m_rawMaterials;
	if (card.m_isGoods)
		out << card.m_manufacturedGoods;
	if (card.m_isPoint)
		for (int index = 0; index < card.m_points.size(); index++)
			out << card.m_points.at(index) << " ";
	if (card.m_coins != -1)
		out << card.m_coins << " ";

	return out;

}
