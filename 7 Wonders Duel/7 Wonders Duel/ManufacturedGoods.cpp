#include "ManufacturedGoods.h"

ManufacturedGoodsClass::ManufacturedGoodsClass(ManufacturedGoods manufacturedGoods):
	m_manufacturedGoods(manufacturedGoods)
{
}

ManufacturedGoodsClass::ManufacturedGoodsClass()
{
}

const ManufacturedGoodsClass::ManufacturedGoods &ManufacturedGoodsClass::GetManufacturedGood()const
{
	return m_manufacturedGoods;
}

std::ostream& operator<<(std::ostream& os, const ManufacturedGoodsClass & goods)
{
	switch (goods.m_manufacturedGoods)
	{
	case ManufacturedGoodsClass::ManufacturedGoods::Glass:
		os << "Glass";
		break;
	case ManufacturedGoodsClass::ManufacturedGoods::Papirus:
		os << "Papirus";
		break;
	default:
		throw "Not a valid value";
		break;
	}
	return os;
}
