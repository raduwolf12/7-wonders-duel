#pragma once

#include<iostream>
#include"Token.h"

class ProgressToken :public Token
{
public:
	enum class ScientificSymbols
	{
		Agriculture,
		Architecture,
		Economy,
		Law,
		Masonry,
		Mathematics,
		Philosophy,
		Strategy,
		Theology,
		Urbanism
	};

public:
	ProgressToken()
	{}
	ProgressToken(Token::TokenType type, Token::Shape shape, ProgressToken::ScientificSymbols scientificSymbol) :Token(type, shape), m_scientificSymbol(scientificSymbol) {}
	ProgressToken(Token t, ProgressToken::ScientificSymbols scientificSymbol) :Token(t), m_scientificSymbol(scientificSymbol) {}

public:
	std::string GetScientificSymbol()const;
	void SetScientificSymbol(ProgressToken::ScientificSymbols scientificSymbol);
	friend std::ostream& operator <<(std::ostream& output, const ProgressToken& piece);

private:
	ProgressToken::ScientificSymbols m_scientificSymbol : 9;

};

