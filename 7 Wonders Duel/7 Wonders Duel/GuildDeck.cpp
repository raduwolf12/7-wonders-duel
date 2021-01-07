#include "GuildDeck.h"



void GuildDeck::populateDeck()
{
	m_deck[0] = Card(" MERCHANTS GUILD", Card::Age::Guild, Card::Color::Purple, { Cost(RawMaterialsCLass::RawMaterials::Clay), Cost(RawMaterialsCLass::RawMaterials::Wood),Cost(ManufacturedGoodsClass::ManufacturedGoods::Glass),Cost(ManufacturedGoodsClass::ManufacturedGoods::Papirus) }, Signs::Sign::Null, Symbols::Symbol::Null, "");
	m_deck[1] = Card("SHIPOWNERS GUILD", Card::Age::Guild, Card::Color::Purple, { Cost(RawMaterialsCLass::RawMaterials::Clay), Cost(RawMaterialsCLass::RawMaterials::Wood),Cost(ManufacturedGoodsClass::ManufacturedGoods::Glass),Cost(ManufacturedGoodsClass::ManufacturedGoods::Papirus) }, Signs::Sign::Null, Symbols::Symbol::Null, "");
	m_deck[2] = Card("  BUILDERS GUILD", Card::Age::Guild, Card::Color::Purple, { Cost(RawMaterialsCLass::RawMaterials::Stone),Cost(RawMaterialsCLass::RawMaterials::Stone),Cost(RawMaterialsCLass::RawMaterials::Clay), Cost(RawMaterialsCLass::RawMaterials::Wood),Cost(ManufacturedGoodsClass::ManufacturedGoods::Glass) }, Signs::Sign::Null, Symbols::Symbol::Null, "");
	m_deck[3] = Card("MAGISTRATES GUILD", Card::Age::Guild, Card::Color::Purple, { Cost(RawMaterialsCLass::RawMaterials::Wood),Cost(RawMaterialsCLass::RawMaterials::Wood),Cost(RawMaterialsCLass::RawMaterials::Clay), Cost(ManufacturedGoodsClass::ManufacturedGoods::Papirus) }, Signs::Sign::Null, Symbols::Symbol::Null, "");
	m_deck[4] = Card("SCIENTISTS GUILD", Card::Age::Guild, Card::Color::Purple, { Cost(RawMaterialsCLass::RawMaterials::Clay), Cost(RawMaterialsCLass::RawMaterials::Clay),Cost(RawMaterialsCLass::RawMaterials::Wood),Cost(RawMaterialsCLass::RawMaterials::Wood) }, Signs::Sign::Null, Symbols::Symbol::Null, "");
	m_deck[5] = Card("MONEYLENDERS GUILD", Card::Age::Guild, Card::Color::Purple, { Cost(RawMaterialsCLass::RawMaterials::Stone), Cost(RawMaterialsCLass::RawMaterials::Stone),Cost(RawMaterialsCLass::RawMaterials::Wood),Cost(RawMaterialsCLass::RawMaterials::Wood) }, Signs::Sign::Null, Symbols::Symbol::Null, "");
	m_deck[6] = Card("TACTICIANS GUILD", Card::Age::Guild, Card::Color::Purple, { Cost(RawMaterialsCLass::RawMaterials::Stone), Cost(RawMaterialsCLass::RawMaterials::Stone),Cost(RawMaterialsCLass::RawMaterials::Clay),Cost(ManufacturedGoodsClass::ManufacturedGoods::Papirus) }, Signs::Sign::Null, Symbols::Symbol::Null, "");
}

GuildDeck::GuildDeck(const GuildDeck& other)
{
	*this = other;
}

GuildDeck::GuildDeck(GuildDeck&& other)
{
	*this = std::move(other);
}

GuildDeck& GuildDeck::operator=(const GuildDeck& other)
{
	 m_deck= other.m_deck;
	std::cout << "Object was copied";
	return *this;
}

GuildDeck& GuildDeck::operator=(GuildDeck&& other)
{
	m_deck = other.m_deck;
	//reset other object
	memset(&other, 0, sizeof(other));
	return *this;
}

GuildDeck::~GuildDeck()
{
}

const std::array<Card, 7>& GuildDeck::GetDeck() const
{
	return m_deck;
}

void GuildDeck::ShuffleDeck()
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	shuffle(m_deck.begin(), m_deck.end(), std::default_random_engine(seed));
	std::cout << "shuffled elements: \n";
}

std::ostream& operator<<(std::ostream& os, GuildDeck& deck)
{
	for (int i = 0; i < 7; i++)
	{
		os << deck.m_deck.at(i) << "\n" << "\n";
	}
	os << std::endl;
	return os;
}
