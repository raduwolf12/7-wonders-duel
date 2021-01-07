#pragma once
#include "RawMaterials.h"
#include "ManufacturedGoods.h"
class Cost
{
public:

	Cost();
	Cost(RawMaterialsCLass raw, ManufacturedGoodsClass goods);
	Cost(RawMaterialsCLass raw);
	Cost(ManufacturedGoodsClass goods);
	Cost(int coins);
	Cost(RawMaterialsCLass raw, ManufacturedGoodsClass goods, int coins);
	~Cost();

public:
	const RawMaterialsCLass& GetRawMaterial()const;
	const ManufacturedGoodsClass& GetManufacturedGood()const;
	const bool& GetIsRaw()const;
	const bool& GetIsGoods()const;
	const int& GetCoins()const;
	void setRawMaterials(RawMaterialsCLass  raw);
	void setManufacturedGoods(ManufacturedGoodsClass  goods);
	friend std::ostream& operator<<(std::ostream& os, Cost& cost);

private:
	RawMaterialsCLass m_raw;
	ManufacturedGoodsClass m_goods;
	int m_coins = 0;
	bool m_isRaw = false;
	bool m_isGoods = false;
	bool m_isCoins = false;
};