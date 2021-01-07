#pragma once
#include <iostream>

class Points
{
public:
	enum class PointsType
	{
		VictoryPoints,
		MilitaryVictoryPoints
	};
public:
	Points();
	Points(PointsType pointsType);
	const PointsType& GetPointsType() const;
	friend std::ostream& operator << (std::ostream& os, const Points& points);

private:
	PointsType m_pointsType;
};