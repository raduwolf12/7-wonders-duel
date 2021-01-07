#include "Cost.h"

Cost::Cost() {}

Cost::Cost(RawMaterialsCLass raw, ManufacturedGoodsClass goods) :m_raw(raw), m_goods(goods)
{
	m_isGoods = true;
	m_isRaw = true;
}

Cost::Cost(RawMaterialsCLass raw) :m_raw(raw)
{
	m_isRaw = true;
}

Cost::Cost(ManufacturedGoodsClass goods) : m_goods(goods)
{
	m_isGoods = true;
}

Cost::Cost(int coins) : m_coins(coins)
{
	m_isCoins = true;
}

Cost::Cost(RawMaterialsCLass raw, ManufacturedGoodsClass goods, int coins) : m_raw(raw), m_goods(goods), m_coins(coins)
{
	m_isCoins = true;
	m_isRaw = true;
	m_isGoods = true;
}

const RawMaterialsCLass& Cost::GetRawMaterial()const
{
	return m_raw;
}

const ManufacturedGoodsClass& Cost::GetManufacturedGood()const
{
	return m_goods;
}

const bool& Cost::GetIsRaw()const
{
	return m_isRaw;
}

const bool& Cost::GetIsGoods()const
{
	return m_isGoods;
}

const int& Cost::GetCoins()const
{
	return m_coins;
}

void Cost::setRawMaterials(RawMaterialsCLass raw)
{
	m_raw = raw;
	m_isRaw = true;
}

void Cost::setManufacturedGoods(ManufacturedGoodsClass goods)
{
	m_goods = goods;
	m_isGoods = true;
}

Cost::~Cost() = default;

std::ostream& operator<<(std::ostream & os, Cost & cost)
{
	if (cost.m_isCoins)
		return os << cost.m_coins;
	if (cost.m_isRaw && cost.m_isGoods)
		return os << cost.m_goods << " " << cost.m_raw;
	else
		if (cost.m_isRaw == true)
			return os << cost.m_raw;
		else
			return os << cost.m_goods;
}