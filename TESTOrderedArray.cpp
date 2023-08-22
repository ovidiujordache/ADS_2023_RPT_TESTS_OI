#include "pch.h"
#include"../ADS_2023_RPT_OI/Box.h"
#include "CppUnitTest.h"
#include "../ADS_2023_RPT_OI/OrderedArray.h";
#include "../ADS_2023_RPT_OI/OrderedArrayAlloc.h";

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
			//Assert::AreEqual(0, oA->length());
			oA->push(2);
			Assert::AreEqual(1, oA->length());
			oA->push(1);
			//will fail.
			//Assert::AreEqual(4, oA->length());
		}

		TEST_METHOD(TestSize)
		{
			OrderedArray<int>* oA =new  OrderedArray<int>();
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
			oA->push(723434);
			oA->push(7);
			oA->push(723434);
			int b = oA->getElement(0);
			Assert::AreEqual(7, b);
			//should fail
			//Assert::AreEqual(1, b);
		}
		TEST_METHOD(TestGetElementFAil) {
			OrderedArray<int>* oA = new OrderedArray<int>();

			oA->push(7);
			oA->push(723434);
			oA->push(7);
			oA->push(723434);
			int b = oA->getElement(4);
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
			int  s=120;
			Assert::AreEqual(s, oA->search(120));
		}
		TEST_METHOD(TestSearchFail) {
			OrderedArray<int>* oA = new OrderedArray<int>();
			oA->push(112);
			oA->push(120);
			int  s = 23;//not pushed.
			Assert::AreEqual(s, oA->search(23));
		}
		TEST_METHOD(TestObjectType) {
			OrderedArray<Box>* oB= new OrderedArray<Box>(5);
		/*
			Box* b1 = new Box(3, 5, 3);
			Box* b2 = new Bdox(36, 5, 5);
			Box* b3 = new Box(36, 5, 5);
			Box* b4 = new Box(36, 5, 5);
			Box* b5 = new Box(36, 5, 5);
			oB->push(*b1);
			oB->push(*b2);
			oB->push(*b3);
			oB->push(*b4);
			oB->push(*b5);
			//Box getBox = oB->getElement(5);
			//overidint to_string in Box
			//overiding equality [==, <,<] in Box
		   //  Assert::AreEqual(*b1, getBox);
			//code is good a bit of tweaking dfor Objects return TYPE in getELement if Array is NULL.
			*/


		}
		TEST_METHOD(TestFloat) {
			OrderedArray<float>* oF = new OrderedArray<float>(5);
			float* b1 = new float (34.);
			float* b2 = new float(34.);
			float* b3 = new float(34.);
			oF->push(*b1);
			oF->push(*b2);
			oF->push(*b3);
			float t = oF->getElement(0);

			Assert::AreEqual(t,*b1);




		}
		TEST_METHOD(TestOrderedArrayAllocPushPassInt) {
			OrderedArrayAlloc<int>* oAAlocInt = new OrderedArrayAlloc<int>();
			int* a =new int (34);
			int* b = new int(35);
			int* c = new int(36);
			oAAlocInt->push(*a);
			oAAlocInt->push(*b);
			oAAlocInt->push(*c);
			Assert::AreEqual(3, oAAlocInt->getSize());
		


		}
		TEST_METHOD(TestOrderedArrayAllocPushPassFloat) {
			OrderedArrayAlloc<float>* oAAlocInt = new OrderedArrayAlloc<float>();
			float* a = new float(34);
			float* b = new float(35);
			float* c = new  float(36);
			oAAlocInt->push(*a);
			oAAlocInt->push(*b);
			oAAlocInt->push(*c);
			Assert::AreEqual(3, oAAlocInt->getSize());

		}
		TEST_METHOD(TestOrderedArrayAllocPushPassDouble) {
			OrderedArrayAlloc<double>* oAAlocInt = new OrderedArrayAlloc<double>();
		
			double* a = new double(342323);
			double* b = new double(353);
			double* c = new  double(361);
			oAAlocInt->push(*a);
			oAAlocInt->push(*b);
			oAAlocInt->push(*c);
			Assert::AreEqual(3, oAAlocInt->getSize());

		}
	
		TEST_METHOD(TestOrderedArrayAllocSortPass) {
			OrderedArrayAlloc<int>* oAAlocInt = new OrderedArrayAlloc<int>();
			int* a = new int(134);
			int* b = new int(35);
			int* c = new int(36);
			int* d = new int(31);
			oAAlocInt->push(*a);
			oAAlocInt->push(*b);
			oAAlocInt->push(*c);
			oAAlocInt->sort();
			Assert::AreEqual(*b, oAAlocInt->getElement(1));
		
			
		
		}
		
	

		//cler 
		//get elem	//remove
		TEST_METHOD(TestOrderedArrayAllocClearPass) {

		}
		TEST_METHOD(TestOrderedArrayAllocGetElementPass) {
			
			OrderedArrayAlloc<double>* oAAlocInt = new OrderedArrayAlloc<double>();

			double* a = new double(342323);
			double* b = new double(353);
			double* c = new  double(0);
			oAAlocInt->push(*a);
			oAAlocInt->push(*b);
			oAAlocInt->push(*c);
		
			oAAlocInt->sort();//sorted
			Assert::AreEqual(*c,oAAlocInt->getElement(0));
			Assert::AreEqual(*b, oAAlocInt->getElement(1));
			Assert::AreEqual(*a, oAAlocInt->getElement(2));
		

		}
		TEST_METHOD(TestOrderedArrayAllocSortFailFail) {

		}

		TEST_METHOD(TestOrderedArrayAllocRemovePass) {

		}
		TEST_METHOD(TestOrderedArrayAllocRemoveFail) {

		}

	};
}
