#include "CppUnitTest.h"
#include"..\7 Wonders Duel\Cost.h"
#include"..\7 Wonders Duel\WonderCardDeck.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace My7WondersDuelTests
{
	TEST_CLASS(WonderCardDeckTest)
	{
	public:

		TEST_METHOD(Populate)
		{
			WonderCardDeck w;
			w.PopulateDeck();
			Assert::IsTrue(w.GetDeck().at(7).GetCardName() == "THE HANGING GARDENS");
			Assert::IsTrue(w.GetDeck().at(7).GetEffect() == "6 coins,it s your turn again,3 vicotry points ");
		/*	std::stringstream str;
			str << w.GetDeck().at("THE SPINX").getCost().at(0);
			Assert::AreEqual(std::string("Glass"), str.str(), L"If you can see this the First element of the Cost vector is not the same!");
		*/}
		TEST_METHOD(Constructor)
		{
			WonderCardDeck w;
			w.PopulateDeck();
			WonderCardDeck firstCopy(w);
			firstCopy.PopulateDeck();
			Assert::IsTrue(w.GetDeck().at(1).GetEffect() == firstCopy.GetDeck().at(1).GetEffect());
			WonderCardDeck secondCopy = firstCopy;
			secondCopy.PopulateDeck();
			Assert::IsTrue(secondCopy.GetDeck().at(1).GetEffect() == firstCopy.GetDeck().at(1).GetEffect());
		}
		TEST_METHOD(PickACard)
		{
			WonderCardDeck w;
			w.PopulateDeck();
			WonderCardModel wc = w.PickWonderCard("THE HANGING GARDENS");
		}
		TEST_METHOD(Print)
		{
			WonderCardDeck w;
			w.PopulateDeck();
			std::stringstream str1;
			str1 << w.GetDeck().at(7).GetCardName();
			Assert::AreEqual(std::string("THE HANGING GARDENS"), str1.str(), L"If you can see this the name of the WonderCardModel is not the same!");
			std::stringstream str2;
			str2 << w.GetDeck().at(7).GetEffect();
			Assert::AreEqual(std::string("6 coins,it s your turn again,3 vicotry points "), str2.str(), L"If you can see this the effect of the WonderCardModel is not the same!");
			
		}
	};
}
