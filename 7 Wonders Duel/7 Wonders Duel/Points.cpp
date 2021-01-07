#include "Points.h"

Points::Points() = default;

Points::Points(PointsType pointsType) :m_pointsType(pointsType) {}

const Points::PointsType& Points::GetPointsType() const
{
	return m_pointsType;
}

std::ostream& operator<<(std::ostream & output, const Points & points)
{
	switch (points.m_pointsType)
	{
	case Points::PointsType::MilitaryVictoryPoints:
		output << "MilitaryVictoryPoints";
		break;
	case Points::PointsType::VictoryPoints:
		output << "VictoryPoints";
		break;
	default:
		throw  "Not a valid value.";
		break;
	}

	return output;
}
