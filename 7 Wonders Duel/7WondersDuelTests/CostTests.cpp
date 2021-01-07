#include "CppUnitTest.h"
#include "..\7 Wonders Duel\Cost.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace My7WondersDuelTests
{
	TEST_CLASS(CostTests)
	{
	public:

		TEST_METHOD(Constructor)
		{
			Cost cost1(RawMaterialsCLass::RawMaterials::Wood);
			Assert::IsTrue(cost1.GetRawMaterial().GetRawMaterial() == RawMaterialsCLass::RawMaterials::Wood);
			Cost cost2(ManufacturedGoodsClass::ManufacturedGoods::Glass);
			Assert::IsTrue(cost2.GetManufacturedGood().GetManufacturedGood() == ManufacturedGoodsClass::ManufacturedGoods::Glass);
			/*Cost cost3(int coin);
			Assert::IsTrue(cost3.getCoins() == 6);*/
		}
		TEST_METHOD(Print)
		{
			Cost cost(RawMaterialsCLass::RawMaterials::Wood);
			std::stringstream stream;
			stream << cost;
			Assert::AreEqual(std::string("Wood"), stream.str(), L"If you can see this is a problem with the << operator!");
			
			Cost cost1(ManufacturedGoodsClass::ManufacturedGoods::Glass);
			std::stringstream stream1;
			stream1 << cost1;
			Assert::AreEqual(std::string("Glass"), stream1.str(), L"If you can see this is a problem with the << operator!");
		}

	};
}