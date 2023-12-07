#include "pch.h"
#include "CppUnitTest.h"
#include "../93/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest93
{
	TEST_CLASS(UnitTest93)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Price testArray[4];
			testArray[0] = { "ProductC", "ShopC", 100.0 };
			testArray[1] = { "ProductA", "ShopA", 200.0 };
			testArray[2] = { "ProductD", "ShopD", 300.0 };
			testArray[3] = { "ProductB", "ShopB", 400.0 };

			SortByProductName(testArray, 4);

			Assert::AreEqual("ProductA", testArray[0].productName.c_str());
			Assert::AreEqual("ProductB", testArray[1].productName.c_str());
			Assert::AreEqual("ProductC", testArray[2].productName.c_str());
			Assert::AreEqual("ProductD", testArray[3].productName.c_str());
		}
	};
}
