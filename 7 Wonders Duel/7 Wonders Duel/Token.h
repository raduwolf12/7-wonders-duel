#pragma once
#include<cstdint>
class Token
{
public:
	enum class TokenType : uint8_t
	{
		Military,
		Progress
	};
	enum class Shape : uint8_t
	{
		Square,
		Circle
	};

public:
	Token() {}
	Token(Token::TokenType type, Token::Shape shape) :m_type(type), m_shape(shape) {}
	Token(const Token& t);

public:
	const Token::TokenType& GetTokenType()const;
	const Token::Shape& GetTokenShape()const;
	void SetTokenType(Token::TokenType tokenType);
	void SetTokenShape(Token::Shape tokenShape);

private:
	TokenType m_type : 1;
	Shape m_shape : 1;
};

