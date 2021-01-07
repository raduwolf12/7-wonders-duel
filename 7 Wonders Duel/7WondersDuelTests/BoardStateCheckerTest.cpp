#include "CppUnitTest.h"
#include"..\7 Wonders Duel\Board.h"
#include"..\7 Wonders Duel\BoardStateChecker.h"


#include<cstdint>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BoardStateCheckerTest
{
	TEST_CLASS(BoardStateCheckerTest)
	{
	public:
		TEST_METHOD(None)
		{
			Board board;
			board.SetBoard();
			board.SetConflictPawn(8,board);
			uint8_t position = board.GetPownPosition();
			Assert::IsTrue(BoardStateChecker::StateOfGame::None == BoardStateChecker::Check(board, position));

		}
		TEST_METHOD(LeftWin)
		{
			Board board;
			board.SetBoard();
			board.SetConflictPawn(0,board);
			uint8_t position = board.GetPownPosition();
			Assert::IsTrue(BoardStateChecker::StateOfGame::Win == BoardStateChecker::Check(board, position));
		}
		TEST_METHOD(RightWin)
		{
			Board board;
			board.SetBoard();
			board.SetConflictPawn(18,board);
			uint8_t position = board.GetPownPosition();
			Assert::IsTrue(BoardStateChecker::StateOfGame::Win == BoardStateChecker::Check(board, position));
		}

	};
}
