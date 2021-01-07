#pragma once
#include <iostream>
#include <array>
#include <string>

class Board
{
public:
	static const size_t kBoardSize = 19;
public:
	void SetBoard();
	void SetPawnPosition(bool aux, int index, Board& b);
	void SetConflictPawn(int conflictPawn, Board& b);
	std::string PawnPosition(Board& b);
	const int& GetPownPosition()const;
	friend std::ostream& operator<<(std::ostream& output, const Board& b
		);
private:
	std::array < bool, 19> m_board;
	int m_conflictPawn;

};