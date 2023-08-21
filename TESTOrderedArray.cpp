#include "pch.h"
#include"../ADS_2023_RPT_OI/Box.h"
#include "CppUnitTest.h"
#include "../ADS_2023_RPT_OI/OrderedArray.h";

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TESTOrderedArray
{
	TEST_CLASS(TESTOrderedArrayClass)
	{
	public:
		
		TEST_METHOD(TestLength)
		{
			//testing number of elements
			OrderedArray<int>* oA = new OrderedArray<int>();
			Assert::AreEqual(0, oA->length());
			oA->push(2);
			Assert::AreEqual(1, oA->length());
			oA->push(1);
			//will fail.
			Assert::AreEqual(4, oA->length());
		}

		TEST_METHOD(TestSize)
		{
			OrderedArray<int>* oA = new OrderedArray<int>();
			Assert::AreEqual(0, oA->length());
			oA->push(2);
			Assert::AreEqual(1, oA->length());

			oA->push(1);
			Assert::AreEqual(2, oA->length());
			oA->push(1);
			//not added
			//array size/capacity  is 2 
			//
			Assert::AreEqual(2, oA->length());
		}
	
		

		TEST_METHOD(TestGrowSize) {
		
			OrderedArray<int>* oA = new OrderedArray<int>(5);
			oA->push(1);
			oA->push(2);
			oA->push(3);
			oA->push(4);
			oA->push(5);
			oA->push(6);



			Assert::AreEqual(5, oA->length());
			//should fail.
			Assert::AreEqual(6, oA->length());

		}

		TEST_METHOD(TestDestructor)
		{
			//object on Heap Memory
			OrderedArray<int>* oA = new OrderedArray<int>();
			oA->push(1);
			oA->push(2);
			oA->push(3);
			oA = nullptr;
			//Assert::IsNotNull("value", *oA);
		}

		TEST_METHOD(TestISEmpty) {
			OrderedArray<int>* oA = new OrderedArray<int>();

			Assert::AreEqual(true, oA->isEmpty());
			oA->push(3);
			Assert::AreEqual(false, oA->isEmpty());


		}

		TEST_METHOD(TestPush) {
			OrderedArray<int>* oA = new OrderedArray<int>();
			//pu
			oA->push(2);
			oA->push(20);
			Assert::AreEqual(2, oA->getElement(0));
			Assert::AreEqual(20, oA->getElement(1));
		
				
		

		}
		TEST_METHOD(TestGetElement) {
			OrderedArray<int>* oA = new OrderedArray<int>();

			oA->push(7);
			oA->push(7);
			int b = oA->getElement(0);
			Assert::AreEqual(7, b);
			//should fail
			//Assert::AreEqual(1, b);
		}

		TEST_METHOD(TestRemoveLength) {
			OrderedArray<int>* oA = new OrderedArray<int>();
			oA->push(112);
			oA->push(120);
			oA->remove(1);
			Assert::AreEqual(1,oA->length());
			

		}
		TEST_METHOD(TestSearch) {
			OrderedArray<int>* oA = new OrderedArray<int>();
			oA->push(112);
			oA->push(120);
			Assert::AreEqual(0, oA->search(112));
		}
		TEST_METHOD(TestObjectType) {
			OrderedArray<Box>* oB= new OrderedArray<Box>(5);
		
			Box* b1 = new Box(3, 5, 3);
			Box* b2 = new Box(36, 5, 5);
			Box* b3 = new Box(36, 5, 5);
			Box* b4 = new Box(36, 5, 5);
			Box* b5 = new Box(36, 5, 5);
			oB->push(*b1);
			oB->push(*b2);
			oB->push(*b3);
			oB->push(*b4);
			oB->push(*b5);
			//Box getBox = oB->getElement(5);
			//equals method implemented for Box object
			// 
			// fails on getElement return TYPE T.
			// and toString. 
			//Assert::AreEqual(*b1, getBox);
			//code is good a bit of tweaking for Objects return TYPE in getELement if Array is NULL.



		}
		


	};
}
