#pragma once

#include "../test.h"
#include "../../structures/list/array_list.h"
#include "../../structures/list/double_linked_list.h"
#include "../../structures/list/linked_list.h"
#include "../../structures/_logger/logger.h"
#include "../../structures/_logger/file_log_consumer.h"

namespace tests
{
	 //<summary>
	 //Zavola vsetky metody z rozhrania listu avsak nekontroluje ich spravnost.
	 //Zabezpeci, ze vsetky metody budu prelozene kompilatorom.
	 //</summary>
	class ListTestInterface
		: public SimpleTest
	{
	public:
		ListTestInterface(std::string name);
		void test() override;

	protected:
		virtual structures::List<int>* makeList() const = 0;
	};

	/// <summary>
	/// Zavola vsetky metody ArrayListu.
	/// </summary>
	class ArrayListTestInterface
		: public ListTestInterface
	{
	public:
		ArrayListTestInterface();

	protected:
		structures::List<int>* makeList() const override;
	};
	





	class ListTest
		: public SimpleTest
	{
	public:
		ListTest(std::string name);

	protected:
		virtual structures::List<int>* makeTestList() const = 0;
		void testAdd(int data);
		void testAssign();
		void testAt(int index);
		void testEquals();
		void testGetIndexOf(int data);
		void testInsert(int data, int index);
		void testTryRemove(int data);
		void testScenario(std::string name, int countOfOperations, int countOfInsert, int countOfRemoveAt, int countOfAt, int countOfGetIndexOf);
		void testSpeedAt();
		void testSpeedInsert();
		void testSpeedRemoveAt();
	};

	class DoubleLinkedListTest
		: public ListTest
	{
	public:
		DoubleLinkedListTest(std::string name);

	protected:
		structures::List<int>* makeTestList() const override;  /////////////////////////////////////////////////////////////////////
	};

	class ArrayListTest
		: public ListTest
	{
	public:
		ArrayListTest(std::string name);

	protected:
		structures::List<int>* makeTestList() const override;
	};

	class ArrayListTestAdd
		: public ArrayListTest
	{
	public:
		ArrayListTestAdd(std::string name);
		void test() override { testAdd(5); };
	};

	class ArrayListTestAssign
		: public ArrayListTest
	{
	public:
		ArrayListTestAssign(std::string name);
		void test() override { testAssign(); };
	};

	class ArrayListTestAt
		: public ArrayListTest
	{
	public:
		ArrayListTestAt(std::string name);
		void test() override { testAt(5); };
	};

	class ArrayListTestEquals
		: public ArrayListTest
	{
	public:
		ArrayListTestEquals(std::string name);
		void test() override { testEquals(); };
	};

	class ArrayListTestGetIndexOf
		: public ArrayListTest
	{
	public:
		ArrayListTestGetIndexOf(std::string name);
		void test() override { testGetIndexOf(5); };
	};

	class ArrayListTestInsert
		: public ArrayListTest
	{
	public:
		ArrayListTestInsert(std::string name);
		void test() override { testInsert(5, 5); };
	};

	class ArrayListTestTryRemove
		: public ArrayListTest
	{
	public:
		ArrayListTestTryRemove(std::string name);
		void test() override { testTryRemove(5); };
	};

	class ArrayListTestScenario
		: public ArrayListTest
	{
	public:
		ArrayListTestScenario(std::string name, int countOfOperations, int countOfInsert, int countOfRemoveAt, int countOfAt, int countOfGetIndexOf);
	private:
		std::string name;
		int countOfOperations;
		int countOfInsert;
		int countOfRemoveAt;
		int countOfAt;
		int countOfGetIndexOf;
		void test() override { testScenario(name, countOfOperations, countOfInsert, countOfRemoveAt, countOfAt, countOfGetIndexOf); };
	};
	
	class ArrayListTestSpeedAt
		: public ArrayListTest
	{
	public:
		ArrayListTestSpeedAt(std::string name);
		void test() override { testSpeedAt(); };
	};

	class ArrayListTestSpeedInsert
		: public ArrayListTest
	{
	public:
		ArrayListTestSpeedInsert(std::string name);
		void test() override { testSpeedInsert(); };
	};

	class ArrayListTestSpeedRemoveAt
		: public ArrayListTest
	{
	public:
		ArrayListTestSpeedRemoveAt(std::string name);
		void test() override { testSpeedRemoveAt(); };
	};



	class DoubleLinkedListTestAdd
		: public DoubleLinkedListTest
	{
	public:
		DoubleLinkedListTestAdd(std::string name);
		void test() override { testAdd(5); };
	};

	class DoubleLinkedListTestAssign
		: public DoubleLinkedListTest
	{
	public:
		DoubleLinkedListTestAssign(std::string name);
		void test() override { testAssign(); };
	};

	class DoubleLinkedListTestAt
		: public DoubleLinkedListTest
	{
	public:
		DoubleLinkedListTestAt(std::string name);
		void test() override { testAt(5); };
	};

	class DoubleLinkedListTestEquals
		: public DoubleLinkedListTest
	{
	public:
		DoubleLinkedListTestEquals(std::string name);
		void test() override { testEquals(); };
	};

	class DoubleLinkedListTestGetIndexOf
		: public DoubleLinkedListTest
	{
	public:
		DoubleLinkedListTestGetIndexOf(std::string name);
		void test() override { testGetIndexOf(5); };
	};

	class DoubleLinkedListTestInsert
		: public DoubleLinkedListTest
	{
	public:
		DoubleLinkedListTestInsert(std::string name);
		void test() override { testInsert(5, 10); };
	};

	class DoubleLinkedListTestTryRemove
		: public DoubleLinkedListTest
	{
	public:
		DoubleLinkedListTestTryRemove(std::string name);
		void test() override { testTryRemove(5); };
	};

	class DoubleLinkedListTestScenario
		: public DoubleLinkedListTest
	{
	public:
		DoubleLinkedListTestScenario(std::string name, int countOfOperations, int countOfInsert, int countOfRemoveAt, int countOfAt, int countOfGetIndexOf);
	private:
			std::string name;
			int countOfOperations;
			int countOfInsert;
			int countOfRemoveAt;
			int countOfAt;
			int countOfGetIndexOf;
			void test() override { testScenario(name, countOfOperations, countOfInsert, countOfRemoveAt, countOfAt, countOfGetIndexOf); };
	};

	class DoubleLinkedListTestSpeedAt
		: public DoubleLinkedListTest
	{
	public:
		DoubleLinkedListTestSpeedAt(std::string name);
		void test() override { testSpeedAt(); };
	};

	class DoubleLinkedListTestSpeedInsert
		: public DoubleLinkedListTest
	{
	public:
		DoubleLinkedListTestSpeedInsert(std::string name);
		void test() override { testSpeedInsert(); };
	};

	class DoubleLinkedListTestSpeedRemoveAt
		: public DoubleLinkedListTest
	{
	public:
		DoubleLinkedListTestSpeedRemoveAt(std::string name);
		void test() override { testSpeedRemoveAt(); };
	};







	/// <summary>
	/// Zavola vsetky metody LinkedListu.
	/// </summary>
	class LinkedListTestInterface
		: public ListTestInterface
	{
	public:
		LinkedListTestInterface();

	protected:
		structures::List<int>* makeList() const override;
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju ArrayList.
	/// </summary>
	class ArrayListTestOverall
		: public ComplexTest
	{
	public:
		ArrayListTestOverall();
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju LinkedList.
	/// </summary>
	class LinkedListTestOverall
		: public ComplexTest
	{
	public:
		LinkedListTestOverall();
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju LinkedList.
	/// </summary>
	class DoubleLinkedListTestOverall
		: public ComplexTest
	{
	public:
		DoubleLinkedListTestOverall();
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju ArrayList a LinkedList.
	/// </summary>
	class ListTestOverall :
		public ComplexTest
	{
	public:
		ListTestOverall();
	};
}