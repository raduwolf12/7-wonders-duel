#include "ActiveProgressTokens.h"

void ActiveProgressTokens::PopulateProgressTokens()
{
	m_activeProgressTokens.insert(m_activeProgressTokens.begin(), { ProgressToken(Token::TokenType::Progress, Token::Shape::Circle, ProgressToken::ScientificSymbols::Agriculture),ProgressToken(Token::TokenType::Progress, Token::Shape::Circle, ProgressToken::ScientificSymbols::Architecture),ProgressToken(Token::TokenType::Progress, Token::Shape::Circle, ProgressToken::ScientificSymbols::Economy),	ProgressToken(Token::TokenType::Progress, Token::Shape::Circle, ProgressToken::ScientificSymbols::Law),ProgressToken(Token::TokenType::Progress, Token::Shape::Circle, ProgressToken::ScientificSymbols::Masonry),ProgressToken(Token::TokenType::Progress, Token::Shape::Circle, ProgressToken::ScientificSymbols::Mathematics),ProgressToken(Token::TokenType::Progress, Token::Shape::Circle, ProgressToken::ScientificSymbols::Philosophy),ProgressToken(Token::TokenType::Progress, Token::Shape::Circle, ProgressToken::ScientificSymbols::Strategy),ProgressToken(Token::TokenType::Progress, Token::Shape::Circle, ProgressToken::ScientificSymbols::Theology),ProgressToken(Token::TokenType::Progress, Token::Shape::Circle, ProgressToken::ScientificSymbols::Urbanism) });
}

void ActiveProgressTokens::ShuffleActiveTokens()
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	shuffle(m_activeProgressTokens.begin(), m_activeProgressTokens.end(), std::default_random_engine(seed));
}

void ActiveProgressTokens::SetUpProgressTokensForGame()
{
	ShuffleActiveTokens();
	m_activeProgressTokens.erase(m_activeProgressTokens.begin() + kActiveTokens, m_activeProgressTokens.end());
}

void ActiveProgressTokens::DiscardProgressToken(ProgressToken progressToken)
{
	m_activeProgressTokens.erase(std::remove_if(m_activeProgressTokens.begin(), m_activeProgressTokens.end(), [&progressToken](ProgressToken& x) {return progressToken.GetScientificSymbol() == x.GetScientificSymbol(); }), m_activeProgressTokens.end());
}

std::vector<ProgressToken> ActiveProgressTokens::GetActiveProgressTokens()const
{
	return m_activeProgressTokens;
}

std::ostream& operator<<(std::ostream& output, const ActiveProgressTokens& apt)
{
	for (auto progressToken : apt.m_activeProgressTokens)
		output << progressToken << "\n";
	return output;
}
