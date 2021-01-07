#pragma once
#include<iostream>
class Signs
{
public:
	enum class Sign
	{
		Horseshoe,
		Sword,
		Tower,
		Target,
		Helmet,
		Book,
		Wheel,
		Harp,
		Lamp,
		Mask,
		Column,
		HalfMoon,
		Sun,
		WaterDrop,
		Temple,
		Vessel,
		Barrel,
		Null
	};

	Signs() {}
	Signs(Signs::Sign sign)
	{
		m_sign = sign;
	}
public:
	friend std::ostream& operator<<(std::ostream& output, const Signs& s)
	{
		switch (s.m_sign)
		{
		case Signs::Sign::Horseshoe:
		{
			output << "Horseshoe";
			break;
		}

		case Signs::Sign::Sword:
		{
			output << "Sword";
			break;
		}
		case Signs::Sign::Tower:
		{
			output << "Tower";
			break;
		}
		case Signs::Sign::Target:
		{
			output << "Target";
			break;
		}
		case Signs::Sign::Helmet:
		{
			output << "Helmet";
			break;
		}
		case Signs::Sign::Wheel:
		{
			output << "Wheel";
			break;
		}
		case Signs::Sign::Book:
		{
			output << "Book";
			break;
		}
		case Signs::Sign::Harp:
		{
			output << "Harp";
			break;
		}
		case Signs::Sign::Lamp:
		{
			output << "Lamp";
			break;
		}
		case Signs::Sign::Mask:
		{
			output << "Mask";
			break;
		}
		case Signs::Sign::Column:
		{
			output << "Column";
			break;
		}
		case Signs::Sign::HalfMoon:
		{
			output << "HalfMoon";
			break;
		}
		case Signs::Sign::Sun:
		{
			output << "Sun";
			break;
		}
		case Signs::Sign::WaterDrop
			:
		{
			output << "WaterDrop";
			break;
		}
		case Signs::Sign::Temple
			:
		{output << "Temple";
		break;
		}

		case Signs::Sign::Vessel
			:
		{output << "Vessel";
		break;
		}
		case Signs::Sign::Barrel
			:
		{output << "Barrel";
		break;
		}
		case Signs::Sign::Null
			:
		{output << "Null";
		break;
		}
	}

		return output;
	}
private:
	Signs::Sign m_sign;
};

