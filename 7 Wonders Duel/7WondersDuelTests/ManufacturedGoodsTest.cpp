#include "CppUnitTest.h"
#include"..\7 Wonders Duel\ManufacturedGoods.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace My7WondersDuelTests
{
	TEST_CLASS(ManufacturedGoodsTest)
	{
	public:

		TEST_METHOD(Constructor)
		{
			ManufacturedGoodsClass manufacturedGood1(ManufacturedGoodsClass::ManufacturedGoods::Papirus);
			Assert::IsTrue(manufacturedGood1.GetManufacturedGood() == ManufacturedGoodsClass::ManufacturedGoods::Papirus);
			ManufacturedGoodsClass manufacturedGood2(manufacturedGood1);
			Assert::IsTrue(manufacturedGood2.GetManufacturedGood()==manufacturedGood1.GetManufacturedGood());
		}
		TEST_METHOD(Print)
		{
			ManufacturedGoodsClass manufacturedGood1(ManufacturedGoodsClass::ManufacturedGoods::Papirus);
			std::stringstream stream1;
			stream1 << manufacturedGood1;
			Assert::AreEqual(std::string("Papirus"), stream1.str(), L"If you see this message, manufactured good is not the same.");
			ManufacturedGoodsClass manufacturedGood2(ManufacturedGoodsClass::ManufacturedGoods::Glass);
			std::stringstream stream2;
			stream2 << manufacturedGood2;
			Assert::AreEqual(std::string("Glass"), stream2.str(), L"If you see this message, manufactured good is not the same.");
		}
	};
}
