#include "ProgressToken.h"
std::string  ProgressToken::GetScientificSymbol()const
{
	if (m_scientificSymbol == ProgressToken::ScientificSymbols::Agriculture)
		return "Agriculture";
	if (m_scientificSymbol == ProgressToken::ScientificSymbols::Architecture)
		return "Architecture";
	if (m_scientificSymbol == ProgressToken::ScientificSymbols::Economy)
		return "Economy";
	if (m_scientificSymbol == ProgressToken::ScientificSymbols::Law)
		return "Law";
	if (m_scientificSymbol == ProgressToken::ScientificSymbols::Masonry)
		return "Masonry";
	if (m_scientificSymbol == ProgressToken::ScientificSymbols::Mathematics)
		return "Mathematics";
	if (m_scientificSymbol == ProgressToken::ScientificSymbols::Philosophy)
		return "Philosophy";
	if (m_scientificSymbol == ProgressToken::ScientificSymbols::Strategy)
		return "Strategy";
	if (m_scientificSymbol == ProgressToken::ScientificSymbols::Theology)
		return "Theology";
	if (m_scientificSymbol == ProgressToken::ScientificSymbols::Urbanism)
		return "Urbanism";
}

void ProgressToken::SetScientificSymbol(ProgressToken::ScientificSymbols scientificSymbol)
{
	m_scientificSymbol = scientificSymbol;
}
std::ostream& operator <<(std::ostream& output, const ProgressToken& piece)
{
	switch (piece.m_scientificSymbol)
	{
	case ProgressToken::ScientificSymbols::Agriculture:
	{
		output << "Agriculture";
		break;
	}
	case ProgressToken::ScientificSymbols::Architecture:
	{
		output << "Architecture";
		break;
	}
	case ProgressToken::ScientificSymbols::Economy:
	{
		output << "Economy";
		break;
	}
	case ProgressToken::ScientificSymbols::Law:
	{
		output << "Law";
		break;
	}
	case ProgressToken::ScientificSymbols::Masonry:
	{
		output << "Masonry";
		break;
	}
	case ProgressToken::ScientificSymbols::Mathematics:
	{
		output << "Mathematics";
		break;
	}
	case ProgressToken::ScientificSymbols::Philosophy:
	{
		output << "Philosophy";
		break;
	}
	case ProgressToken::ScientificSymbols::Strategy:
	{
		output << "Strategy";
		break;
	}
	case ProgressToken::ScientificSymbols::Theology:
	{
		output << "Theology";
		break;
	}
	case ProgressToken::ScientificSymbols::Urbanism:
	{
		output << "Urbanism";
		break;
	}
	}
	return output;
}