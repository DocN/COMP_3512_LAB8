#include "CppUnitTest.h"
#include "../lab8/lab8.hpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(testAdd)
		{
			FixedList<int, 10> l;
			int res = l.add(1);
			Assert::AreEqual(res, 1);
		}

		TEST_METHOD(testGet) {
			FixedList<int, 10> l;
			l.add(3);
			l.add(566);
			l.add(3);
			int res = l.get(2);
			Assert::AreEqual(res, 3);
		}

		TEST_METHOD(testCapacity)
		{
			FixedList<int, 50> l;
			int res = l.capacity();
			Assert::AreEqual(res, 50);
		}

		TEST_METHOD(testSize)
		{
			FixedList<int, 50> l;
			l.add(2);
			int res = l.size();
			Assert::AreEqual(res, 1);
		}

		TEST_METHOD(testRemove)
		{
			FixedList<int, 5> l;
			l.add(3);
			l.add(1230);
			int res = l.remove(3);
			Assert::AreEqual(res, 3);
		}



	};
}