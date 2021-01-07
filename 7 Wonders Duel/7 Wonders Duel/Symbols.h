#pragma once
#include<cstdint>
#include<iostream>
class Symbols
{
public:
	enum class Symbol
	{
		Gyroscope,
		Wheel,
		SolarClock,
		Bol,
		Pendulum,
		Feather,
		Null
	};
	Symbols() {}
	Symbols(Symbol symbol)
	{
		m_symbol = symbol;
	}
public:
	friend std::ostream& operator<<(std::ostream& output, const Symbols& s)
	{
		switch (s.m_symbol)
		{
		case Symbols::Symbol::Bol:
		{output << "Bol";
		break;
		}


		case Symbols::Symbol::Feather:
		{output << "Feather";
		break;
		}


		case Symbols::Symbol::Gyroscope:
		{output << "Gyroscope";
		break;
		}
		case Symbols::Symbol::Pendulum:
		{output << "Pendulum";
		break;
		}case Symbols::Symbol::SolarClock:
		{output << "SolarClock";
		break;
		}case Symbols::Symbol::Wheel:
		{output << "Wheel";
		break;
		}
		
		case Symbols::Symbol::Null:
		{output << "Null";
		break;
		}
		}
		return output;
	}

private:
	Symbols::Symbol m_symbol;
};

