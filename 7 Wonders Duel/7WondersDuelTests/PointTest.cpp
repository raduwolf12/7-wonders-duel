#include "CppUnitTest.h"
#include"..\7 Wonders Duel\Points.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace My7WondersDuelTests
{
	TEST_CLASS(PointTest)
	{
	public:

		TEST_METHOD(Constructor)
		{
			Points p1(Points::PointsType::MilitaryVictoryPoints);
			Points p2(Points::PointsType::VictoryPoints);
			Assert::IsTrue(p1.GetPointsType() == Points::PointsType::MilitaryVictoryPoints);
			Assert::IsTrue(p2.GetPointsType() == Points::PointsType::VictoryPoints);
		}
		TEST_METHOD(Print)
		{
			Points p1(Points::PointsType::MilitaryVictoryPoints);
			std::stringstream stream;
			stream << p1;
			Assert::AreEqual(std::string("MilitaryVictoryPoints"), stream.str(), L"If you can see this is a problem with the << operator!");
		}
	};
}
