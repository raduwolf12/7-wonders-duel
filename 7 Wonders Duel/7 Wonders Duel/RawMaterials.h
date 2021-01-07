#pragma once
#include<iostream>
class RawMaterialsCLass
{
public:
	enum class  RawMaterials
	{
		None,
		Wood,
		Stone,
		Clay
	};
public:
	RawMaterialsCLass(RawMaterials RawMaterials);
	RawMaterialsCLass();
	const RawMaterials& GetRawMaterial() const;
	void SetRawMaterial(RawMaterialsCLass::RawMaterials rawMaterial);
	friend std::ostream& operator<<(std::ostream& os, const RawMaterialsCLass& raw);
private:
	RawMaterials m_rawMaterial;
};




