#pragma once

#include "../test.h"
#include "../../structures/table/table.h"
#include "../../structures/_logger/logger.h"
#include "../../structures/_logger/file_log_consumer.h"

namespace tests
{
	/// <summary>
	/// Zavola vsetky metody z rozhrania tabulky avsak nekontroluje ich spravnost.
	/// Zabezpeci, ze vsetky metody budu prelozene kompilatorom.
	/// </summary>
	class TableTestInterface
		: public SimpleTest
	{
	public:
		TableTestInterface();
		void test() override;

	protected:
		virtual structures::Table<int, int>* makeTable() = 0;
	};

	class TableTest
		: public SimpleTest
	{
	public:
		TableTest(std::string name);

	protected:
		virtual structures::Table<int, int>* makeTestTable() const = 0;
		void testContainsKey();
		void testEquals();
		void testAssign();
		void testInsert();
		void testRemove();
		void testFind();
		void testTryFind();
		void testScenario(std::string name, int countOfOperations, int countOfInsert, int countOfRemove, int countOfTryFind);
		void testSpeedInsert(std::string name);
		void testSpeedRemove(std::string name);
		void testSpeedTryFind(std::string name);
	};

	class BinarySearchTreeTest
		: public TableTest
	{
	public:
		BinarySearchTreeTest(std::string name);

	protected:
		structures::Table<int, int>* makeTestTable() const override;
	};

	class BinarySearchTreeTestContainsKey
		: public BinarySearchTreeTest
	{
	public:
		BinarySearchTreeTestContainsKey(std::string name);
		void test() override { testContainsKey(); }; 
	};

	class BinarySearchTreeTestEquals
		: public BinarySearchTreeTest
	{
	public:
		BinarySearchTreeTestEquals(std::string name);
		void test() override { testEquals(); };
	};

	class BinarySearchTreeTestAssign
		: public BinarySearchTreeTest
	{
	public:
		BinarySearchTreeTestAssign(std::string name);
		void test() override { testAssign(); };
	};

	class BinarySearchTreeTestInsert
		: public BinarySearchTreeTest
	{
	public:
		BinarySearchTreeTestInsert(std::string name);
		void test() override { testInsert(); };
	};

	class BinarySearchTreeTestRemove
		: public BinarySearchTreeTest
	{
	public:
		BinarySearchTreeTestRemove(std::string name);
		void test() override { testRemove(); };
	};

	class BinarySearchTreeTestFind
		: public BinarySearchTreeTest
	{
	public:
		BinarySearchTreeTestFind(std::string name);
		void test() override { testFind(); };
	};

	class BinarySearchTreeTestTryFind 
		: public BinarySearchTreeTest
	{
	public:
		BinarySearchTreeTestTryFind(std::string name);
		void test() override { testTryFind(); };
	};



	class BinarySearchTreeTestScenario
		: public BinarySearchTreeTest
	{
	public:
		BinarySearchTreeTestScenario(std::string name, int countOfOperations, int countOfInsert, int countOfRemove, int countOfTryFind);
	private:
		std::string name;
		int countOfOperations;
		int countOfInsert;
		int countOfRemove;
		int countOfTryFind;
		void test() override { testScenario(name, countOfOperations, countOfInsert, countOfRemove, countOfTryFind); };
	};

	class BinarySearchTreeTestSpeedInsert
		: public BinarySearchTreeTest
	{
	public:
		BinarySearchTreeTestSpeedInsert(std::string name);
	private:
		std::string name;
		void test() override { testSpeedInsert(name); };
	};

	class BinarySearchTreeTestSpeedRemove
		: public BinarySearchTreeTest
	{
	public:
		BinarySearchTreeTestSpeedRemove(std::string name);
	private:
		std::string name;
		void test() override { testSpeedRemove(name); };
	};

	class BinarySearchTreeTestSpeedTryFind
		: public BinarySearchTreeTest
	{
	public:
		BinarySearchTreeTestSpeedTryFind(std::string name);
	private:
		std::string name;
		void test() override { testSpeedTryFind(name); };
	};



	class SortedSequenceTableTest
		: public TableTest
	{
	public:
		SortedSequenceTableTest(std::string name);

	protected:
		structures::Table<int, int>* makeTestTable() const override;
	};

	class SortedSequenceTableTestContainsKey
		: public SortedSequenceTableTest
	{
	public:
		SortedSequenceTableTestContainsKey(std::string name); 
		void test() override { testContainsKey(); };
	};

	class SortedSequenceTableTestEquals
		: public SortedSequenceTableTest
	{
	public:
		SortedSequenceTableTestEquals(std::string name);
		void test() override { testEquals(); };
	};

	class SortedSequenceTableTestAssign
		: public SortedSequenceTableTest
	{
	public:
		SortedSequenceTableTestAssign(std::string name);
		void test() override { testAssign(); };
	};

	class SortedSequenceTableTestInsert
		: public SortedSequenceTableTest
	{
	public:
		SortedSequenceTableTestInsert(std::string name);
		void test() override { testInsert(); };
	};

	class SortedSequenceTableTestRemove
		: public SortedSequenceTableTest
	{
	public:
		SortedSequenceTableTestRemove(std::string name);
		void test() override { testRemove(); };
	};

	class SortedSequenceTableTestFind
		: public SortedSequenceTableTest
	{
	public:
		SortedSequenceTableTestFind(std::string name);
		void test() override { testFind(); };
	};
	
	class SortedSequenceTableTestTryFind
		: public SortedSequenceTableTest
	{
	public:
		SortedSequenceTableTestTryFind(std::string name);
		void test() override { testTryFind(); };
	};



	class SortedSequenceTableTestScenario
		: public SortedSequenceTableTest
	{
	public:
		SortedSequenceTableTestScenario(std::string name, int countOfOperations, int countOfInsert, int countOfRemove, int countOfTryFind);
	private:
		std::string name;
		int countOfOperations;
		int countOfInsert;
		int countOfRemove;
		int countOfTryFind;
		void test() override { testScenario(name, countOfOperations, countOfInsert, countOfRemove, countOfTryFind); };
	};

	class SortedSequenceTableTestSpeedInsert
		: public SortedSequenceTableTest
	{
	public:
		SortedSequenceTableTestSpeedInsert(std::string name);
	private:
		std::string name;
		void test() override { testSpeedInsert(name); };
	};

	class SortedSequenceTableTestSpeedRemove
		: public SortedSequenceTableTest
	{
	public:
		SortedSequenceTableTestSpeedRemove(std::string name);
	private:
		std::string name;
		void test() override { testSpeedRemove(name); };
	};

	class SortedSequenceTableTestSpeedTryFind
		: public SortedSequenceTableTest
	{
	public:
		SortedSequenceTableTestSpeedTryFind(std::string name);
	private:
		std::string name;
		void test() override { testSpeedTryFind(name); };
	};

	/// <summary>
	/// Zavola vsetky metody danej tabulky.
	/// </summary>
	class BinarySearchTreeTestInterface
		: public TableTestInterface
	{
	protected:
		structures::Table<int, int>* makeTable() override;
	};

	/// <summary>
	/// Zavola vsetky metody danej tabulky.
	/// </summary>
	class HashTableTestInterface
		: public TableTestInterface
	{
	protected:
		structures::Table<int, int>* makeTable() override;
	};

	/// <summary>
	/// Zavola vsetky metody danej tabulky.
	/// </summary>
	class LinkedTableTestInterface
		: public TableTestInterface
	{
	protected:
		structures::Table<int, int>* makeTable() override;
	};

	/// <summary>
	/// Zavola vsetky metody danej tabulky.
	/// </summary>
	class SortedSequenceTableTestInterface
		: public TableTestInterface
	{
	protected:
		structures::Table<int, int>* makeTable() override;
	};

	/// <summary>
	/// Zavola vsetky metody danej tabulky.
	/// </summary>
	class TreapTestInterface
		: public TableTestInterface
	{
	protected:
		structures::Table<int, int>* makeTable() override;
	};

	/// <summary>
	/// Zavola vsetky metody danej tabulky.
	/// </summary>
	class UnsortedSequenceTableTestInterface
		: public TableTestInterface
	{
	protected:
		structures::Table<int, int>* makeTable() override;
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju danu tabulku.
	/// </summary>
	class BinarySearchTreeTestOverall
		: public ComplexTest
	{
	public:
		BinarySearchTreeTestOverall();
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju danu tabulku.
	/// </summary>
	class HashTableTestOverall
		: public ComplexTest
	{
	public:
		HashTableTestOverall();
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju danu tabulku.
	/// </summary>
	class LinkedTableTestOverall
		: public ComplexTest
	{
	public:
		LinkedTableTestOverall();
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju danu tabulku.
	/// </summary>
	class SortedSequenceTableTestOverall
		: public ComplexTest
	{
	public:
		SortedSequenceTableTestOverall();
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju danu tabulku.
	/// </summary>
	class TreapTestOverall
		: public ComplexTest
	{
	public:
		TreapTestOverall();
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju danu tabulku.
	/// </summary>
	class UnsortedSequenceTableTestOverall
		: public ComplexTest
	{
	public:
		UnsortedSequenceTableTestOverall();
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju tabulku.
	/// </summary>
	class TableTestOverall
		: public ComplexTest
	{
	public:
		TableTestOverall();
	};
}