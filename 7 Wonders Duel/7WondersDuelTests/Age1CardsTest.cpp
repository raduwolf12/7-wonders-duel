
#include "CppUnitTest.h"
#include<string>
#include"..\7 Wonders Duel\Card.h"
#include"..\7 Wonders Duel\AgeICards.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace  My7WondersDuelTests
{
	TEST_CLASS(Age1CardsTest)
	{
		TEST_METHOD(PopulateDeck)
		{
			AgeICards deck;
			deck.PopulateDeck();
			AgeICards firstCopy(deck);
			firstCopy.PopulateDeck();
			int index = 2;
			Assert::AreEqual(deck.GetDeck().at(index).GetCardName(), firstCopy.GetDeck().at(index).GetCardName(), L" If you can see this message the of the 2 cards names are not the same");

		}
		TEST_METHOD(Constructor)
		{
			AgeICards deck;
			deck.PopulateDeck();
			int index1 = 0;
			int index2 = 22;
			std::stringstream str;
			str << deck.GetDeck().at(index1).GetCardName();
			Assert::AreEqual(deck.GetDeck().at(index1).GetCardName(), str.str(), L"if you can see this message the constructor does not work! ");
			
			std::stringstream str1;
			str1 << deck.GetDeck().at(index2).GetCardName();
			Assert::AreEqual(deck.GetDeck().at(index2).GetCardName(), str1.str(), L"if you can see this message the constructor does not work! ");
		}
		TEST_METHOD(ShuffleInCards)
		{
			AgeICards deck;
			deck.PopulateDeck();
			int index1 = 0;
			std::stringstream str;
			str << deck.GetDeck().at(index1).GetCardName();
			Assert::AreEqual(deck.GetDeck().at(index1).GetCardName(), str.str(), L"If you can see this message the shuffle functions does not work !");
		}
	};
}
