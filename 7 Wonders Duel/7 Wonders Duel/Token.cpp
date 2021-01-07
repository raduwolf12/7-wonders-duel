#include "Token.h"

Token::Token(const Token& t)
{
	this->m_shape = t.m_shape;
	this->m_type = t.m_type;

}

const Token::TokenType& Token::GetTokenType() const
{
	return m_type;
}

const Token::Shape& Token::GetTokenShape() const
{
	return m_shape;
}

void Token::SetTokenType(Token::TokenType tokenType)
{
	m_type = tokenType;
}

void Token::SetTokenShape(Token::Shape tokenShape)
{
	m_shape = tokenShape;
}
