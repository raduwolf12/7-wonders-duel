#include "WonderCardModel.h"
WonderCardModel::WonderCardModel(std::string name)
{
	m_name = name;
	if (name == "PIRAEUS")
	{
		m_cost = { Cost(RawMaterialsCLass::RawMaterials::Clay),Cost(RawMaterialsCLass::RawMaterials::Stone),Cost(RawMaterialsCLass::RawMaterials::Wood),Cost(RawMaterialsCLass::RawMaterials::Wood) };
		m_effect = "papirus/glas,it s your turn again, 2 victory points ";
	}
	if (name == "CIRCUS MAXIMUS")
	{
		m_cost = { Cost(ManufacturedGoodsClass::ManufacturedGoods::Glass),Cost(RawMaterialsCLass::RawMaterials::Wood),Cost(RawMaterialsCLass::RawMaterials::Stone),Cost(RawMaterialsCLass::RawMaterials::Stone) };
		m_effect = "other player discard a gray card,1 war point,3 victory points ";
	}
	if (name == "THE GREAT LIGHTHOUSE")
	{
		m_cost = { Cost(ManufacturedGoodsClass::ManufacturedGoods::Papirus),Cost(ManufacturedGoodsClass::ManufacturedGoods::Papirus),Cost(RawMaterialsCLass::RawMaterials::Stone),Cost(RawMaterialsCLass::RawMaterials::Wood) };
		m_effect = "wood/clay/stone,4 victory points ";
	}
	if (name == "TEMPLE OF ARTEMIS")
	{
		m_cost = { Cost(ManufacturedGoodsClass::ManufacturedGoods::Papirus),Cost(ManufacturedGoodsClass::ManufacturedGoods::Glass),Cost(RawMaterialsCLass::RawMaterials::Stone),Cost(RawMaterialsCLass::RawMaterials::Wood) };
		m_effect = "12 coins,it's your turn again ";
	}
	if (name == "THE APPIAN WAY")
	{
		m_cost = { Cost(ManufacturedGoodsClass::ManufacturedGoods::Papirus),Cost(RawMaterialsCLass::RawMaterials::Clay),Cost(RawMaterialsCLass::RawMaterials::Clay),Cost(RawMaterialsCLass::RawMaterials::Stone) };
		m_effect = " +3 coin for player, -3 coin for other player,it s your turn again,3 victory points";
	}
	if (name == "THE COLOSSUS")
	{
		m_cost = { Cost(ManufacturedGoodsClass::ManufacturedGoods::Glass),Cost(RawMaterialsCLass::RawMaterials::Clay),Cost(RawMaterialsCLass::RawMaterials::Clay),Cost(RawMaterialsCLass::RawMaterials::Clay) };
		m_effect = "2 war points,3 victory points ";
	}
	if (name == "THE GREAT LIBRARY")
	{
		m_cost = { Cost(ManufacturedGoodsClass::ManufacturedGoods::Papirus),Cost(ManufacturedGoodsClass::ManufacturedGoods::Glass),Cost(RawMaterialsCLass::RawMaterials::Wood),Cost(RawMaterialsCLass::RawMaterials::Wood),Cost(RawMaterialsCLass::RawMaterials::Wood) };
		m_effect = "choose a token,4 victory points ";
	}
	if (name == "THE HANGING GARDENS")
	{
		m_cost = { Cost(ManufacturedGoodsClass::ManufacturedGoods::Papirus),Cost(ManufacturedGoodsClass::ManufacturedGoods::Glass),Cost(RawMaterialsCLass::RawMaterials::Wood),Cost(RawMaterialsCLass::RawMaterials::Wood) };
		m_effect = "6 coins,it s your turn again,3 vicotry points ";
	}
	if (name == "THE STATUE OF ZEUS")
	{
		m_cost = { Cost(ManufacturedGoodsClass::ManufacturedGoods::Papirus),Cost(ManufacturedGoodsClass::ManufacturedGoods::Papirus),Cost(RawMaterialsCLass::RawMaterials::Clay),Cost(RawMaterialsCLass::RawMaterials::Wood),Cost(RawMaterialsCLass::RawMaterials::Stone) };
		m_effect = "other player discard a red card,1 war point,3 victory points ";
	}
	if (name == "THE MAUSOLEUM")
	{
		m_cost = { Cost(ManufacturedGoodsClass::ManufacturedGoods::Papirus),Cost(ManufacturedGoodsClass::ManufacturedGoods::Glass),Cost(ManufacturedGoodsClass::ManufacturedGoods::Glass),Cost(RawMaterialsCLass::RawMaterials::Clay),Cost(RawMaterialsCLass::RawMaterials::Clay) };
		m_effect = "choose a card that was discarded an build it for free,2 victory points ";
	}
	if (name == "THE PYRAMIDS")
	{
		m_cost = { Cost(ManufacturedGoodsClass::ManufacturedGoods::Papirus),Cost(RawMaterialsCLass::RawMaterials::Stone),Cost(RawMaterialsCLass::RawMaterials::Stone),Cost(RawMaterialsCLass::RawMaterials::Stone) };
		m_effect = "9victory poins ";
	}
	if (name == "THE SPINX")
	{
		m_cost = { Cost(ManufacturedGoodsClass::ManufacturedGoods::Glass),Cost(ManufacturedGoodsClass::ManufacturedGoods::Glass),Cost(RawMaterialsCLass::RawMaterials::Clay),Cost(RawMaterialsCLass::RawMaterials::Stone) };
		m_effect = " it s your turn again,6 victory poins";
	}
}
WonderCardModel::WonderCardModel()
{
}
WonderCardModel::~WonderCardModel() = default;
const std::string &WonderCardModel::GetCardName()const
{
	return m_name;
}
const std::string &WonderCardModel::GetEffect()const
{
	return m_effect;
}
const std::vector<Cost> &WonderCardModel::GetCost()const 
{
	return m_cost;
}
std::ostream& operator<<(std::ostream & os, WonderCardModel & card)
{

	if (card.m_name == "PIRAEUS")
		os << "\n" << "PIRAEUS" << " \n ";

	if (card.m_name == "CIRCUSMAXIMUS")
		os << "\n" << "CIRCUS MAXIMUS" << " \n ";

	if (card.m_name == "THEGRATELIGHTHOUSE")
		os << "\n" << "THE GRATE LIGHTHOUSE" << " \n ";

	if (card.m_name == "THETEMPLEOFARTEMIS")
		os << "\n" << "THE TEMPLE OF ARTEMIS" << " \n ";

	if (card.m_name == "THEAPPIANWAY")
		os << "\n" << "THE APPIAN WAY" << " \n ";

	if (card.m_name == "THECOLOSSUS")
		os << "\n" << "THE COLOSSUS" << " \n ";

	if (card.m_name == "THEGRATELIBRARY")
		os << "\n" << "THE GRATE LIBRARY" << " \n ";

	if (card.m_name == "THEHANGINGGARDENS")
		os << "\n" << "THE HANGING GARDENS" << " \n ";

	if (card.m_name == "THESTATUEOFZEUS")
		os << "\n" << "THE STATUE OF ZEUS" << " \n ";

	if (card.m_name == "THEMAUSOLEUM")
		os << "\n" << "THE MAUSOLEUM" << " \n ";

	if (card.m_name == "THEPYRAMIDS")
		os << "\n" << "THE PYRAMIDS" << " \n ";

	if (card.m_name == "THESPINX")
		os << "\n" << "THE SPINX"<< " \n ";
	for (int i = 0; i < (int)card.m_cost.size(); i++)
		if (card.m_cost.at(i).GetIsGoods())
			os << card.m_cost.at(i).GetManufacturedGood() << ", ";
		else if (card.m_cost.at(i).GetIsRaw())
			os << card.m_cost.at(i).GetRawMaterial() << " ";
		else
			throw  "Not a valid value";
	os << " \n";
	os << card.m_effect << " ";
	return os;
}