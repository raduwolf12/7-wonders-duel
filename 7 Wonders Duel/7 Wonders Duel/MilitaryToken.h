#pragma once
#include<iostream>
#include"Token.h"
class MilitaryToken :public Token
{
public:
	enum class MilitarySymbols
	{
		Two,
		Five
	};
	enum class MilitaryEffects
	{
		TwoEffect,
		Fiveeffect
	};

public:
	MilitaryToken() {}
	MilitaryToken(Token::TokenType type, Token::Shape shape, MilitaryToken::MilitarySymbols militarySymbol, MilitaryToken::MilitaryEffects effect) :Token(type, shape), m_militarySymbol(militarySymbol), m_effect(effect) {}
	MilitaryToken(Token& t, MilitarySymbols militarySymbol, MilitaryEffects militaryEffect) : Token(t), m_militarySymbol(militarySymbol), m_effect(militaryEffect) {}

public:
	const MilitarySymbols &GetMilitarySymbol()const;
	const MilitaryEffects &GetEffect()const;
	friend std::ostream& operator <<(std::ostream& output, const MilitaryToken& piece);

private:
	MilitaryToken::MilitarySymbols m_militarySymbol : 1;
	MilitaryToken::MilitaryEffects m_effect : 1;

};

