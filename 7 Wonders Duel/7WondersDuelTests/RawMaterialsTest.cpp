#include "CppUnitTest.h"
#include"..\7 Wonders Duel\RawMaterials.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace My7WondersDuelTests
{
	TEST_CLASS(RawMaterialsTest)
	{
	public:
		
		TEST_METHOD(Constructor)
		{
			RawMaterialsCLass rawMat1(RawMaterialsCLass::RawMaterials::Clay);
			Assert::IsTrue(rawMat1.GetRawMaterial() == RawMaterialsCLass::RawMaterials::Clay);
			RawMaterialsCLass rawMat2(RawMaterialsCLass::RawMaterials::Stone);
			Assert::IsTrue(rawMat2.GetRawMaterial() == RawMaterialsCLass::RawMaterials::Stone);
			RawMaterialsCLass rawMat3(RawMaterialsCLass::RawMaterials::Wood);
			Assert::IsTrue(rawMat3.GetRawMaterial() == RawMaterialsCLass::RawMaterials::Wood);
		}
		TEST_METHOD(Print)
		{
			RawMaterialsCLass rawMat1(RawMaterialsCLass::RawMaterials::Clay);
			std::stringstream stream1;
			stream1<< rawMat1;
			Assert::AreEqual(std::string("Clay"), stream1.str(), L"If you see this message the Raw Material Clay is not the same.");
			RawMaterialsCLass rawMat2(RawMaterialsCLass::RawMaterials::Stone);
			std::stringstream stream2;
			stream2 << rawMat2;
			Assert::AreEqual(std::string("Stone"), stream2.str(), L"If you see this message the Raw Material Stone is not the same.");
			RawMaterialsCLass rawMat(RawMaterialsCLass::RawMaterials::Wood);
			std::stringstream stream;
			stream << rawMat;
			Assert::AreEqual(std::string("Wood"), stream.str(), L"If you see this message the Raw Material Stone is not the same.");

		}
	};
}
