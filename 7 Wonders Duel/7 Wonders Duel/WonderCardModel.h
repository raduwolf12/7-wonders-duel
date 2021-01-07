#pragma once
#include <cstdint>
#include<vector>
#include<iostream>
#include "Cost.h"

class WonderCardModel {
public:
	WonderCardModel(std::string name);
	WonderCardModel();
	~WonderCardModel();
	friend std::ostream& operator<<(std::ostream& os, WonderCardModel& card);
public:
	const std::string &GetCardName()const ;
	const std::string &GetEffect()const;
	const std::vector<Cost> &GetCost()const;
private:
	std::string m_name;
	std::vector<Cost> m_cost;
	std::string m_effect;
};