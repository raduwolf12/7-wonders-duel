#pragma once
#include<iostream>
class ManufacturedGoodsClass
{
public:
	enum class ManufacturedGoods
	{	None,
		Papirus,
		Glass
	};
public:
	ManufacturedGoodsClass(ManufacturedGoods manufacturedGoods);
	ManufacturedGoodsClass();
	const ManufacturedGoods &GetManufacturedGood()const;
	friend std::ostream& operator<<(std::ostream& os, const ManufacturedGoodsClass &goods);

private:
	ManufacturedGoods m_manufacturedGoods;

};

