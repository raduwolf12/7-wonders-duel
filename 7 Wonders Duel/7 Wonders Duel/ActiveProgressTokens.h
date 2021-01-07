#pragma once
#include <iostream>
#include <array>
#include <string>
#include"ProgressToken.h"
#include<vector>
#include <algorithm>    
#include <random>       
#include <chrono> 
#include <ctime>  
class ActiveProgressTokens
{
public:
	ActiveProgressTokens() {}
	void PopulateProgressTokens();
	void ShuffleActiveTokens();
	void SetUpProgressTokensForGame();
	void DiscardProgressToken(ProgressToken progressToken);
	std::vector<ProgressToken> GetActiveProgressTokens() const;

public:
	friend std::ostream& operator<<(std::ostream& output, const ActiveProgressTokens& apt);

public:
	static const size_t kActiveTokens = 5;
private:
	std::vector<ProgressToken> m_activeProgressTokens;

};

