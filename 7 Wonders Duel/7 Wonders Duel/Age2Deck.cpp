#include "Age2Deck.h"

Age2Deck::Age2Deck(){}

Age2Deck::~Age2Deck() = default;

Age2Deck::Age2Deck(const Age2Deck& other)
{
	*this = other;
}

Age2Deck::Age2Deck(Age2Deck&& other)
{
	*this = std::move(other);
}

Age2Deck& Age2Deck::operator=(const Age2Deck& other)
{
	for (int index = 0; index < kNoCards; ++index)
	{
		m_deck[index] = other.m_deck[index];
	}
	return *this;
}

Age2Deck& Age2Deck::operator=(Age2Deck&& other)
{
	for (int index = 0; index < kNoCards; ++index)
	{
		m_deck[index] = other.m_deck[index];
	}
	memset(&other, 0, sizeof(other));
	return *this;
}
void Age2Deck::PopulateDeck()
{
	m_deck[0] = Card("SAWMILL              ", Card::Age::Second, Card::Color::Brown, { Cost(2) }, Signs::Sign::Null, Symbols::Symbol::Null, "2 Wood");
	m_deck[1] = Card("BRICKYARD            ", Card::Age::Second, Card::Color::Brown, { Cost(2) }, Signs::Sign::Null, Symbols::Symbol::Null, "2 Clay");
	m_deck[2] = Card("SHELFQUARRY          ", Card::Age::Second, Card::Color::Brown, { Cost(2) }, Signs::Sign::Null, Symbols::Symbol::Null, "2 Stone");

	m_deck[3] = Card("GLASS-BLOWER         ", Card::Age::Second, Card::Color::Grey, { Cost(0) }, Signs::Sign::Null, Symbols::Symbol::Null, "Glass");
	m_deck[4] = Card("DRYING ROOM          ", Card::Age::Second, Card::Color::Grey, { Cost(0) }, Signs::Sign::Null, Symbols::Symbol::Null, "Papirus");

	m_deck[5] = Card("WALLS                ", Card::Age::Second, Card::Color::Red, { Cost(RawMaterialsCLass::RawMaterials::Stone),Cost(RawMaterialsCLass::RawMaterials::Stone) }, Signs::Sign::Null, Symbols::Symbol::Null, { Points::PointsType::MilitaryVictoryPoints,Points::PointsType::MilitaryVictoryPoints });
	m_deck[6] = Card("HORSE BREEDERS       ", Card::Age::Second, Card::Color::Red, { Cost(RawMaterialsCLass::RawMaterials::Clay),Cost(RawMaterialsCLass::RawMaterials::Wood) }, Signs::Sign::Horseshoe, Symbols::Symbol::Null, { Points::PointsType::MilitaryVictoryPoints });
	m_deck[7] = Card("BARRACKS             ", Card::Age::Second, Card::Color::Red, { Cost(3) }, Signs::Sign::Sword, Symbols::Symbol::Null, { Points::PointsType::MilitaryVictoryPoints });
	m_deck[8] = Card("ARCHERY RANGE        ", Card::Age::Second, Card::Color::Red, { Cost(RawMaterialsCLass::RawMaterials::Stone),Cost(RawMaterialsCLass::RawMaterials::Wood),Cost(ManufacturedGoodsClass::ManufacturedGoods::Papirus) }, Signs::Sign::Null, Symbols::Symbol::Null, { Points::PointsType::MilitaryVictoryPoints,Points::PointsType::MilitaryVictoryPoints });
	m_deck[9] = Card("PARADE GROUND        ", Card::Age::Second, Card::Color::Red, { Cost(RawMaterialsCLass::RawMaterials::Clay),Cost(RawMaterialsCLass::RawMaterials::Clay),Cost(ManufacturedGoodsClass::ManufacturedGoods::Glass) }, Signs::Sign::Null, Symbols::Symbol::Null, { Points::PointsType::MilitaryVictoryPoints, Points::PointsType::MilitaryVictoryPoints });

	m_deck[10] = Card("FORUM                ", Card::Age::Second, Card::Color::Yellow, { Cost(3),Cost(RawMaterialsCLass::RawMaterials::Clay),Cost(RawMaterialsCLass::RawMaterials::Clay) }, Signs::Sign::Null, Symbols::Symbol::Null, "Glass/Papirus");
	m_deck[11] = Card("CARAVANSERY          ", Card::Age::Second, Card::Color::Yellow, { Cost(2),Cost(ManufacturedGoodsClass::ManufacturedGoods::Glass),Cost(ManufacturedGoodsClass::ManufacturedGoods::Papirus) }, Signs::Sign::Null, Symbols::Symbol::Null, "Wood/Clay/Stone");
	m_deck[12] = Card("CUSTOM HOUSE         ", Card::Age::Second, Card::Color::Yellow, { Cost(4) }, Signs::Sign::Null, Symbols::Symbol::Null, "Papirus/Glass");
	m_deck[13] = Card("BREWERY              ", Card::Age::Second, Card::Color::Yellow, { Cost(0) }, Signs::Sign::Null, 6);

	m_deck[14] = Card("TRIBUNAL             ", Card::Age::Second, Card::Color::Blue, { Cost(RawMaterialsCLass::RawMaterials::Wood),Cost(RawMaterialsCLass::RawMaterials::Wood),Cost(ManufacturedGoodsClass::ManufacturedGoods::Glass) }, Signs::Sign::Null, Symbols::Symbol::Null, { Points::PointsType::VictoryPoints,Points::PointsType::VictoryPoints,Points::PointsType::VictoryPoints,Points::PointsType::VictoryPoints,Points::PointsType::VictoryPoints });
	m_deck[15] = Card("STATUE               ", Card::Age::Second, Card::Color::Blue, { Cost(RawMaterialsCLass::RawMaterials::Clay),Cost(RawMaterialsCLass::RawMaterials::Clay) }, Signs::Sign::Mask, Symbols::Symbol::Null, { Points::PointsType::VictoryPoints,Points::PointsType::VictoryPoints,Points::PointsType::VictoryPoints,Points::PointsType::VictoryPoints });
	m_deck[16] = Card("TEMPLE               ", Card::Age::Second, Card::Color::Blue, { Cost(RawMaterialsCLass::RawMaterials::Wood),Cost(ManufacturedGoodsClass::ManufacturedGoods::Papirus) }, Signs::Sign::HalfMoon, Symbols::Symbol::Null, { Points::PointsType::VictoryPoints,Points::PointsType::VictoryPoints,Points::PointsType::VictoryPoints,Points::PointsType::VictoryPoints });
	m_deck[17] = Card("AQUEDUCT             ", Card::Age::Second, Card::Color::Blue, { Cost(RawMaterialsCLass::RawMaterials::Stone),Cost(RawMaterialsCLass::RawMaterials::Stone),Cost(RawMaterialsCLass::RawMaterials::Stone) }, Signs::Sign::WaterDrop, Symbols::Symbol::Bol, { Points::PointsType::VictoryPoints,Points::PointsType::VictoryPoints,Points::PointsType::VictoryPoints,Points::PointsType::VictoryPoints,Points::PointsType::VictoryPoints });
	m_deck[18] = Card("ROSTRUM              ", Card::Age::Second, Card::Color::Blue, { Cost(RawMaterialsCLass::RawMaterials::Stone),Cost(RawMaterialsCLass::RawMaterials::Wood) }, Signs::Sign::Null, Symbols::Symbol::Null, { Points::PointsType::VictoryPoints,Points::PointsType::VictoryPoints,Points::PointsType::VictoryPoints,Points::PointsType::VictoryPoints });

	m_deck[19] = Card("LIBRARY              ", Card::Age::Second, Card::Color::Green, { Cost(RawMaterialsCLass::RawMaterials::Stone),Cost(RawMaterialsCLass::RawMaterials::Wood),Cost(ManufacturedGoodsClass::ManufacturedGoods::Glass) }, Signs::Sign::Book, Symbols::Symbol::Feather, { Points::PointsType::VictoryPoints,Points::PointsType::VictoryPoints });
	m_deck[20] = Card("DISPENSARY           ", Card::Age::Second, Card::Color::Green, { Cost(RawMaterialsCLass::RawMaterials::Clay),Cost(RawMaterialsCLass::RawMaterials::Clay),Cost(RawMaterialsCLass::RawMaterials::Stone) }, Signs::Sign::Wheel, Symbols::Symbol::Bol, { Points::PointsType::VictoryPoints,Points::PointsType::VictoryPoints });
	m_deck[21] = Card("SCHOOL               ", Card::Age::Second, Card::Color::Green, { Cost(RawMaterialsCLass::RawMaterials::Wood),Cost(ManufacturedGoodsClass::ManufacturedGoods::Papirus),Cost(ManufacturedGoodsClass::ManufacturedGoods::Papirus) }, Signs::Sign::Null, Symbols::Symbol::Wheel, { Points::PointsType::VictoryPoints });
	m_deck[22] = Card("LABORATORY           ", Card::Age::Second, Card::Color::Green, { Cost(RawMaterialsCLass::RawMaterials::Wood),Cost(ManufacturedGoodsClass::ManufacturedGoods::Glass),Cost(ManufacturedGoodsClass::ManufacturedGoods::Glass) }, Signs::Sign::Book, Symbols::Symbol::Feather, { Points::PointsType::VictoryPoints });

}

const std::array<Card,Age2Deck::kNoCards> &Age2Deck::GetDeck()const
{
	return m_deck;
}

void Age2Deck::ShuffleInCards()
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	shuffle(m_deck.begin(), m_deck.end(), std::default_random_engine(seed));
}

std::ostream& operator<<(std::ostream& output, Age2Deck& age2Deck)
{
	for (auto i : age2Deck.GetDeck())
	{
		output << i << "\n" << "\n";
	}
	output << std::endl;

	return output;
}
