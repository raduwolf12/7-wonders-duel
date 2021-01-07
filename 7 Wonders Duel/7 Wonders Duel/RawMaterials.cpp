#include "RawMaterials.h"

RawMaterialsCLass::RawMaterialsCLass(RawMaterials rawMaterials) :m_rawMaterial(rawMaterials) {}

RawMaterialsCLass::RawMaterialsCLass() {}

const RawMaterialsCLass::RawMaterials& RawMaterialsCLass::GetRawMaterial() const
{
	return m_rawMaterial;
}

void RawMaterialsCLass::SetRawMaterial(RawMaterialsCLass::RawMaterials rawMaterial)
{
	m_rawMaterial = rawMaterial;
}

std::ostream& operator<<(std::ostream& os, const RawMaterialsCLass& raw)
{

	switch (raw.m_rawMaterial)
	{
	case RawMaterialsCLass::RawMaterials::Clay:
		os << "Clay";
		break;
	case RawMaterialsCLass::RawMaterials::Stone:
		os << "Stone";
		break;
	case RawMaterialsCLass::RawMaterials::Wood:
		os << "Wood";
		break;
	default:
		throw "Not a valid value";
		break;
	}
	return os;
}


