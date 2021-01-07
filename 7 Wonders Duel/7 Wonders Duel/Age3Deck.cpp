#include "Age3Deck.h"


Age3Deck::Age3Deck()
{
}

Age3Deck::Age3Deck(const Age3Deck& other)
{
	*this = other;
}

Age3Deck::Age3Deck(Age3Deck&& other)
{
	*this = std::move(other);
}

Age3Deck& Age3Deck::operator=(const Age3Deck& other)
{
	for (int i = 0; i < Age3Deck::kDeckSize; i++)
	{
		deck[i] = other.deck[i];
	}
	return *this;
}

Age3Deck& Age3Deck::operator=(Age3Deck&& other)
{
	for (int i = 0; i < Age3Deck::kDeckSize; i++)
	{
		deck[i] = other.deck[i];
	}
	memset(&other, 0, sizeof(other));
	return *this;
}
void Age3Deck::PopulateDeck()
{
	deck[0] = Card("ARSENAL             ", Card::Age::First, Card::Color::Red, { Cost(RawMaterialsCLass::RawMaterials::Clay),Cost(RawMaterialsCLass::RawMaterials::Clay),Cost(RawMaterialsCLass::RawMaterials::Clay),Cost(RawMaterialsCLass::RawMaterials::Wood),Cost(RawMaterialsCLass::RawMaterials::Wood) }, Signs::Sign::Null, Symbols::Symbol::Null, { Points::PointsType::MilitaryVictoryPoints,Points::PointsType::MilitaryVictoryPoints,Points::PointsType::MilitaryVictoryPoints });
	deck[1] = Card("COURTHOUSE          ", Card::Age::Third, Card::Color::Red, { Cost(8) }, Signs::Sign::Null, Symbols::Symbol::Null, { Points::PointsType::MilitaryVictoryPoints,Points::PointsType::MilitaryVictoryPoints,Points::PointsType::MilitaryVictoryPoints });//nu e bun
	deck[2] = Card("FORTIFICATIONS      ", Card::Age::Third, Card::Color::Red, { Cost(RawMaterialsCLass::RawMaterials::Stone),Cost(RawMaterialsCLass::RawMaterials::Stone),Cost(RawMaterialsCLass::RawMaterials::Clay),Cost(ManufacturedGoodsClass::ManufacturedGoods::Papirus) }, Signs::Sign::Null, Symbols::Symbol::Null, { Points::PointsType::MilitaryVictoryPoints,Points::PointsType::MilitaryVictoryPoints });
	deck[3] = Card("SIEGE WORKSHOP      ", Card::Age::Third, Card::Color::Red, { Cost(RawMaterialsCLass::RawMaterials::Wood),Cost(RawMaterialsCLass::RawMaterials::Wood),Cost(RawMaterialsCLass::RawMaterials::Wood),Cost(ManufacturedGoodsClass::ManufacturedGoods::Glass) }, Signs::Sign::Null, Symbols::Symbol::Null, { Points::PointsType::MilitaryVictoryPoints,Points::PointsType::MilitaryVictoryPoints });
	deck[4] = Card("CIRCUS              ", Card::Age::Third, Card::Color::Red, { Cost(RawMaterialsCLass::RawMaterials::Clay),Cost(RawMaterialsCLass::RawMaterials::Clay),Cost(RawMaterialsCLass::RawMaterials::Stone),Cost(RawMaterialsCLass::RawMaterials::Stone) }, Signs::Sign::Null, Symbols::Symbol::Null, { Points::PointsType::MilitaryVictoryPoints,Points::PointsType::MilitaryVictoryPoints, });

	deck[5] = Card("ACADEMY             ", Card::Age::Third, Card::Color::Green, { Cost(RawMaterialsCLass::RawMaterials::Stone),Cost(RawMaterialsCLass::RawMaterials::Wood),Cost(ManufacturedGoodsClass::ManufacturedGoods::Glass),Cost(ManufacturedGoodsClass::ManufacturedGoods::Glass) }, Signs::Sign::Null, Symbols::Symbol::SolarClock, { Points::PointsType::VictoryPoints,Points::PointsType::VictoryPoints,Points::PointsType::VictoryPoints });
	deck[6] = Card("STUDY               ", Card::Age::Third, Card::Color::Green, { Cost(RawMaterialsCLass::RawMaterials::Wood),Cost(RawMaterialsCLass::RawMaterials::Wood),Cost(ManufacturedGoodsClass::ManufacturedGoods::Glass),Cost(ManufacturedGoodsClass::ManufacturedGoods::Papirus) }, Signs::Sign::Null, Symbols::Symbol::SolarClock, { Points::PointsType::VictoryPoints,Points::PointsType::VictoryPoints,Points::PointsType::VictoryPoints });
	deck[7] = Card("UNIVERSITY          ", Card::Age::Third, Card::Color::Green, { Cost(RawMaterialsCLass::RawMaterials::Clay),Cost(ManufacturedGoodsClass::ManufacturedGoods::Glass),Cost(ManufacturedGoodsClass::ManufacturedGoods::Papirus) }, Signs::Sign::Null, Symbols::Symbol::Gyroscope, { Points::PointsType::VictoryPoints,Points::PointsType::VictoryPoints });
	deck[8] = Card("OBSERVATORY         ", Card::Age::Third, Card::Color::Green, { Cost(RawMaterialsCLass::RawMaterials::Stone),Cost(ManufacturedGoodsClass::ManufacturedGoods::Papirus),Cost(ManufacturedGoodsClass::ManufacturedGoods::Papirus) }, Signs::Sign::Null, Symbols::Symbol::Gyroscope, { Points::PointsType::VictoryPoints,Points::PointsType::VictoryPoints });

	deck[9] = Card("CHAMBER OF COMMERCE ", Card::Age::Third, Card::Color::Yellow, { Cost(ManufacturedGoodsClass::ManufacturedGoods::Papirus),Cost(ManufacturedGoodsClass::ManufacturedGoods::Papirus) }, Signs::Sign::Null, Symbols::Symbol::Null, { Points::PointsType::VictoryPoints,Points::PointsType::VictoryPoints,Points::PointsType::VictoryPoints });
	deck[10] = Card("PORT               ", Card::Age::Third, Card::Color::Yellow, { Cost(RawMaterialsCLass::RawMaterials::Wood),Cost(ManufacturedGoodsClass::ManufacturedGoods::Glass),Cost(ManufacturedGoodsClass::ManufacturedGoods::Papirus) }, Signs::Sign::Null, Symbols::Symbol::Null, { Points::PointsType::VictoryPoints,Points::PointsType::VictoryPoints,Points::PointsType::VictoryPoints });
	deck[11] = Card("ARMORY              ", Card::Age::Third, Card::Color::Yellow, { Cost(RawMaterialsCLass::RawMaterials::Stone),Cost(RawMaterialsCLass::RawMaterials::Stone),Cost(ManufacturedGoodsClass::ManufacturedGoods::Papirus) }, Signs::Sign::Null, Symbols::Symbol::Null, { Points::PointsType::VictoryPoints,Points::PointsType::VictoryPoints,Points::PointsType::VictoryPoints });
	deck[12] = Card("LIGHTHOUSE          ", Card::Age::Third, Card::Color::Yellow, { Cost(RawMaterialsCLass::RawMaterials::Clay),Cost(RawMaterialsCLass::RawMaterials::Clay),Cost(ManufacturedGoodsClass::ManufacturedGoods::Glass) }, Signs::Sign::Null, Symbols::Symbol::Null, { Points::PointsType::VictoryPoints,Points::PointsType::VictoryPoints,Points::PointsType::VictoryPoints });
	deck[13] = Card("ARENA               ", Card::Age::Third, Card::Color::Yellow, { Cost(RawMaterialsCLass::RawMaterials::Clay),Cost(RawMaterialsCLass::RawMaterials::Stone),Cost(RawMaterialsCLass::RawMaterials::Wood) }, Signs::Sign::Null, Symbols::Symbol::Null, { Points::PointsType::VictoryPoints,Points::PointsType::VictoryPoints,Points::PointsType::VictoryPoints });

	deck[14] = Card("PALACE              ", Card::Age::Third, Card::Color::Blue, { Cost(RawMaterialsCLass::RawMaterials::Clay),Cost(RawMaterialsCLass::RawMaterials::Stone),Cost(RawMaterialsCLass::RawMaterials::Wood),Cost(ManufacturedGoodsClass::ManufacturedGoods::Glass),Cost(ManufacturedGoodsClass::ManufacturedGoods::Glass) }, Signs::Sign::Null, Symbols::Symbol::Null, { Points::PointsType::VictoryPoints,Points::PointsType::VictoryPoints,Points::PointsType::VictoryPoints, Points::PointsType::VictoryPoints,Points::PointsType::VictoryPoints,Points::PointsType::VictoryPoints ,Points::PointsType::VictoryPoints });
	deck[15] = Card("TOWN HALL           ", Card::Age::Third, Card::Color::Blue, { Cost(RawMaterialsCLass::RawMaterials::Stone),Cost(RawMaterialsCLass::RawMaterials::Stone),Cost(RawMaterialsCLass::RawMaterials::Stone),Cost(RawMaterialsCLass::RawMaterials::Wood),Cost(RawMaterialsCLass::RawMaterials::Wood) }, Signs::Sign::Null, Symbols::Symbol::Null, { Points::PointsType::VictoryPoints,Points::PointsType::VictoryPoints,Points::PointsType::VictoryPoints, Points::PointsType::VictoryPoints,Points::PointsType::VictoryPoints,Points::PointsType::VictoryPoints ,Points::PointsType::VictoryPoints });
	deck[16] = Card("OBELISK             ", Card::Age::Third, Card::Color::Blue, { Cost(RawMaterialsCLass::RawMaterials::Stone),Cost(RawMaterialsCLass::RawMaterials::Stone),Cost(ManufacturedGoodsClass::ManufacturedGoods::Glass) }, Signs::Sign::Null, Symbols::Symbol::Null, { Points::PointsType::VictoryPoints,Points::PointsType::VictoryPoints,Points::PointsType::VictoryPoints, Points::PointsType::VictoryPoints,Points::PointsType::VictoryPoints });
	deck[17] = Card("GARDENS             ", Card::Age::Third, Card::Color::Blue, { Cost(RawMaterialsCLass::RawMaterials::Clay),Cost(RawMaterialsCLass::RawMaterials::Clay),Cost(RawMaterialsCLass::RawMaterials::Wood),Cost(RawMaterialsCLass::RawMaterials::Wood) }, Signs::Sign::Null, Symbols::Symbol::Null, { Points::PointsType::VictoryPoints,Points::PointsType::VictoryPoints,Points::PointsType::VictoryPoints, Points::PointsType::VictoryPoints,Points::PointsType::VictoryPoints,Points::PointsType::VictoryPoints });
	deck[18] = Card("PANTHEON            ", Card::Age::Third, Card::Color::Blue, { Cost(RawMaterialsCLass::RawMaterials::Clay),Cost(RawMaterialsCLass::RawMaterials::Wood),Cost(ManufacturedGoodsClass::ManufacturedGoods::Papirus),Cost(ManufacturedGoodsClass::ManufacturedGoods::Papirus) }, Signs::Sign::Null, Symbols::Symbol::Null, { Points::PointsType::VictoryPoints,Points::PointsType::VictoryPoints,Points::PointsType::VictoryPoints, Points::PointsType::VictoryPoints,Points::PointsType::VictoryPoints,Points::PointsType::VictoryPoints });
	deck[19] = Card("SENATE              ", Card::Age::Third, Card::Color::Blue, { Cost(RawMaterialsCLass::RawMaterials::Clay),Cost(RawMaterialsCLass::RawMaterials::Clay),Cost(RawMaterialsCLass::RawMaterials::Stone),Cost(ManufacturedGoodsClass::ManufacturedGoods::Papirus) }, Signs::Sign::Null, Symbols::Symbol::Null, { Points::PointsType::VictoryPoints,Points::PointsType::VictoryPoints,Points::PointsType::VictoryPoints, Points::PointsType::VictoryPoints,Points::PointsType::VictoryPoints });

	//guild cards
	deck[20] = Card("MERCHANTS GUILD ",   Card::Age::Third, Card::Color::Purple, { Cost(RawMaterialsCLass::RawMaterials::Clay), Cost(RawMaterialsCLass::RawMaterials::Wood),Cost(ManufacturedGoodsClass::ManufacturedGoods::Glass),Cost(ManufacturedGoodsClass::ManufacturedGoods::Papirus) }, Signs::Sign::Null, Symbols::Symbol::Null, "");
	deck[21] = Card("SHIPOWNERS GUILD",   Card::Age::Third, Card::Color::Purple, { Cost(RawMaterialsCLass::RawMaterials::Clay), Cost(RawMaterialsCLass::RawMaterials::Wood),Cost(ManufacturedGoodsClass::ManufacturedGoods::Glass),Cost(ManufacturedGoodsClass::ManufacturedGoods::Papirus) }, Signs::Sign::Null, Symbols::Symbol::Null, "");
	deck[22] = Card("BUILDERS GUILD  ",   Card::Age::Third, Card::Color::Purple, { Cost(RawMaterialsCLass::RawMaterials::Stone),Cost(RawMaterialsCLass::RawMaterials::Stone),Cost(RawMaterialsCLass::RawMaterials::Clay), Cost(RawMaterialsCLass::RawMaterials::Wood),Cost(ManufacturedGoodsClass::ManufacturedGoods::Glass) }, Signs::Sign::Null, Symbols::Symbol::Null, "");
	deck[23] = Card("MAGISTRATES GUILD",  Card::Age::Third, Card::Color::Purple, { Cost(RawMaterialsCLass::RawMaterials::Wood),Cost(RawMaterialsCLass::RawMaterials::Wood),Cost(RawMaterialsCLass::RawMaterials::Clay), Cost(ManufacturedGoodsClass::ManufacturedGoods::Papirus) }, Signs::Sign::Null, Symbols::Symbol::Null, "");
	deck[24] = Card("SCIENTISTS GUILD",	  Card::Age::Third, Card::Color::Purple, { Cost(RawMaterialsCLass::RawMaterials::Clay), Cost(RawMaterialsCLass::RawMaterials::Clay),Cost(RawMaterialsCLass::RawMaterials::Wood),Cost(RawMaterialsCLass::RawMaterials::Wood) }, Signs::Sign::Null, Symbols::Symbol::Null, "");
	deck[25] = Card("MONEYLENDERS GUILD", Card::Age::Third, Card::Color::Purple, { Cost(RawMaterialsCLass::RawMaterials::Stone), Cost(RawMaterialsCLass::RawMaterials::Stone),Cost(RawMaterialsCLass::RawMaterials::Wood),Cost(RawMaterialsCLass::RawMaterials::Wood) }, Signs::Sign::Null, Symbols::Symbol::Null, "");
	deck[26] = Card("TACTICIANS GUILD",   Card::Age::Third, Card::Color::Purple, { Cost(RawMaterialsCLass::RawMaterials::Stone), Cost(RawMaterialsCLass::RawMaterials::Stone),Cost(RawMaterialsCLass::RawMaterials::Clay),Cost(ManufacturedGoodsClass::ManufacturedGoods::Papirus) }, Signs::Sign::Null, Symbols::Symbol::Null, "");

}

Age3Deck::~Age3Deck() = default;

const std::array<Card, Age3Deck::kDeckSize> &Age3Deck::GetDeck()const
{
	return deck;
}

void Age3Deck::ShuffleInCards()
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	shuffle(deck.begin(), deck.end(), std::default_random_engine(seed));
}
std::ostream& operator<<(std::ostream& os, Age3Deck& deck)
{
	for (auto i : deck.deck)
	{
		os << i << "\n" << "\n";
	}
	os << std::endl;
	return os;
}