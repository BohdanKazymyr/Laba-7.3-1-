#include "pch.h"
#include "CppUnitTest.h"
#include "../Laba 7.3/Laba 7.3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int Low = -23;
			int High = 26;
			int rowCount = 8;
			int colCount = 8;
			int** a = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				a[i] = new int[colCount];
			Create(a, rowCount, colCount, Low, High);
			Print(a, rowCount, colCount);
			int k = 0;
			Calc(a, rowCount, colCount, k);
			Sum(a, rowCount, colCount);
		}
	};
}
