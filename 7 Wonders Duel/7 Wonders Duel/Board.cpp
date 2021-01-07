#include "Board.h"

void Board::SetBoard()
{
	for (int index = 0; index < kBoardSize; ++index)
		m_board[index] = false;
	m_conflictPawn = 9;
	m_board.at(m_conflictPawn) = true;

}

void Board::SetPawnPosition(bool aux, int index, Board& b)
{
	if (b.m_board[index] == false)
		b.m_board[index] = aux;
}

void Board::SetConflictPawn(int conflictPawn, Board& b)
{
	b.m_conflictPawn = conflictPawn;
	b.m_board.at(m_conflictPawn) = true;
}

std::string Board::PawnPosition(Board& b)
{
	if (b.m_conflictPawn == 0 || b.m_conflictPawn == 18)
	{
		return "Game Over!";
	}
	if (b.m_conflictPawn == 9)
	{
		SetPawnPosition(true, 9, b);

		return "Start!";
	}
	if (b.m_conflictPawn == 1)
	{
		if (b.m_board[1] == false && b.m_board[2] == false && b.m_board[3] == false)
		{
			SetPawnPosition(true, 1, b);
			return "Your power increases with 5 Military Tokens.";
		}
		else
		{
			if (b.m_board[2] == true || b.m_board[3] == true
				|| b.m_board[1] == true)
			{
				return "This Military Token has already been used.";
			}
		}
	}
	if (b.m_conflictPawn == 2)
	{
		if (b.m_board[1] == false && b.m_board[2] == false && b.m_board[3] == false)
		{
			SetPawnPosition(true, 2, b);
			return "Your power increases with 5 Military Tokens.";
		}
		else
		{
			if (b.m_board[1] == true || b.m_board[3] == true || b.m_board[2] == true)
			{
				return "This Military Token has already been used.";
			}
		}
	}
	if (b.m_conflictPawn == 3)
	{
		if (b.m_board[1] == false && b.m_board[2] == false && b.m_board[3] == false)
		{
			SetPawnPosition(true, 3, b);
			return "Your power increases with 5 Military Tokens.";
		}
		else
			if (b.m_board[1] == true || b.m_board[2] == true || b.m_board[3] == true)
			{
				return "This Military Token has already been used.";
			}
	}
	if (b.m_conflictPawn == 4)
	{
		if (b.m_board[4] == false && b.m_board[5] == false && b.m_board[6] == false)
		{
			SetPawnPosition(true, 4, b);
			return "Your power increases with 2 Military Tokens.";
		}
		else
			if (b.m_board[5] == true || b.m_board[6] == true || b.m_board[4] == true)
			{
				return "This Military Token has already been used.";
			}
	}
	if (b.m_conflictPawn == 5)
	{
		if (b.m_board[4] == false && b.m_board[5] == false && b.m_board[6] == false)
		{
			SetPawnPosition(true, 5, b);
			return "Your power increases with 2 Military Tokens.";
		}
		else
			if (b.m_board[4] == true || b.m_board[5] == true || b.m_board[6] == true)
			{
				return "This Military Token has already been used.";
			}
	}
	if (b.m_conflictPawn == 6)
	{
		if (b.m_board[6] == false && b.m_board[5] == false && b.m_board[6] == false)
		{
			SetPawnPosition(true, 6, b);
			return "Your power increases with 2 Military Tokens.";
		}
		else
			if (b.m_board[4] == true || b.m_board[5] == true || b.m_board[6] == true)
			{
				return "This Military Token has already been used.";
			}
	}
	if (b.m_conflictPawn == 7)
	{
		if (b.m_board[7] == false && b.m_board[8] == false)
		{
			SetPawnPosition(true, 7, b);
			return "You got 2 victory points.";
		}
		else
		{
			if (b.m_board[8] == true || b.m_board[7] == true)
			{
				return "These points have already been received.";
			}

		}
	}
	if (b.m_conflictPawn == 8)
	{
		if (b.m_board[7] == false && m_board[8] == false)
		{
			SetPawnPosition(true, 8, b);
			return "You got 2 victory points.";
		}
		else
			if (b.m_board[7] == true || b.m_board[8] == true)
			{
				return "These points have already been received.";
			}
	}
	if (b.m_conflictPawn == 10)
	{
		if (b.m_board[10] == false && b.m_board[11] == false)
		{
			SetPawnPosition(true, 10, b);
			return "You got 2 victory points.";
		}
		else
			if (b.m_board[11] == true || b.m_board[10] == true)
			{
				return "These points have already been received.";
			}
	}
	if (b.m_conflictPawn == 11)
	{
		if (b.m_board[10] == false && b.m_board[11] == false)
		{
			SetPawnPosition(true, 11, b);
			return "You got 2 victory points.";
		}
		else
			if (b.m_board[10] == true || b.m_board[11] == true)
			{
				return "These points have already been received.";
			}
	}
	if (b.m_conflictPawn == 12)
	{
		if (b.m_board[12] == false && b.m_board[13] == false && b.m_board[14] == false)
		{
			SetPawnPosition(true, 12, b);
			return "Your power increases with 2 Military Tokens.";
		}
		else
			if (b.m_board[13] == true || b.m_board[14] == true || b.m_board[12] == true)
			{
				return "This Military Token has already been used.";
			}
	}
	if (b.m_conflictPawn == 13)
	{
		if (b.m_board[12] == false && b.m_board[13] == false && b.m_board[14] == false)
		{
			SetPawnPosition(true, 13, b);
			return "Your power increases with 2 Military Tokens.";
		}
		else
			if (b.m_board[14] == true || b.m_board[12] == true || b.m_board[13] == true)
			{
				return "This Military Token has already been used.";
			}
	}
	if (b.m_conflictPawn == 14)
	{
		if (b.m_board[12] == false && b.m_board[13] == false && b.m_board[14] == false)
		{
			SetPawnPosition(true, 14, b);
			return "Your power increases with 2 Military Tokens.";
		}
		else
			if (b.m_board[12] == true || b.m_board[13] == true || b.m_board[14] == true)
			{
				return "This Military Token has already been used.";
			}
	}
	if (b.m_conflictPawn == 15)
	{
		if (b.m_board[15] == false && b.m_board[16] == false && b.m_board[17] == false)
		{
			SetPawnPosition(true, 15, b);
			return "Your power increases with 5 Military Tokens.";
		}
		else
			if (b.m_board[16] == true || b.m_board[17] == true || b.m_board[15] == true)
			{
				return "This Military Token has already been used.";
			}
	}
	if (b.m_conflictPawn == 16)
	{
		if (b.m_board[15] == false && b.m_board[16] == false && b.m_board[17] == false)
		{
			SetPawnPosition(true, 16, b);
			return "Your power increases with 5 Military Tokens.";
		}
		else
			if (b.m_board[15] == true || b.m_board[17] == true || b.m_board[16] == true)
			{
				return "This Military Token has already been used.";
			}
	}
	if (b.m_conflictPawn == 17)
	{
		if (b.m_board[15] == false && b.m_board[16] == false && b.m_board[17] == false)
		{
			SetPawnPosition(true, 17, b);
			return "Your power increases with 5 Military Tokens.";
		}
		else
		{
			if (b.m_board[15] == true || b.m_board[16] == true || b.m_board[17] == true)
			{
				return "This Military Token has already been used.";
			}
			if (b.m_board[15] == false || b.m_board[16] == true)
			{
				return "This Military Token has already been used.";
			}
			if (b.m_board[15] == true || b.m_board[16] == false)
			{
				return "This Military Token has already been used.";
			}
		}
	}
}

const int& Board::GetPownPosition()const
{
	return m_conflictPawn;
}

std::ostream& operator<<(std::ostream& output, const Board& b)
{
	for (int i = 0; i < b.m_board.size(); i++)
	{
		if (b.m_board[i] == false && i != b.m_conflictPawn)
			output << " 0 ";
		else if (b.m_board[i] == true && i != b.m_conflictPawn)
			output << " | ";
		else if (i == b.m_conflictPawn)
			output << " X ";
	}
	return output;
}
