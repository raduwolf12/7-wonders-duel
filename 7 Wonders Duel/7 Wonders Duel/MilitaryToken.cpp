#include "MilitaryToken.h"
const MilitaryToken::MilitarySymbols &MilitaryToken::GetMilitarySymbol()const
{
	return m_militarySymbol;
}

const MilitaryToken::MilitaryEffects &MilitaryToken::GetEffect()const
{
	return m_effect;
}

std::ostream& operator <<(std::ostream& output, const MilitaryToken& piece)
{
	output <<
		static_cast<int>(piece.m_militarySymbol) <<
		static_cast<int>(piece.m_effect);
	return output;
}