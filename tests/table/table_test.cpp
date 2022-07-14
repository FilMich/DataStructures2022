#include "table_test.h"
#include "../../structures/table/binary_search_tree.h"
#include "../../structures/table/hash_table.h"
#include "../../structures/table/linked_table.h"
#include "../../structures/table/sorted_sequence_table.h"
#include "../../structures/table/table.h"
#include "../../structures/table/treap.h"
#include "../../structures/table/unsorted_sequence_table.h"

namespace tests
{
	TableTestInterface::TableTestInterface() :
		SimpleTest("Interface")
	{
	}

	void TableTestInterface::test()
	{
		int x = 0;
		structures::Table<int, int>* table = this->makeTable();
		table->equals(*table);
		table->assign(*table);
		table->insert(0, 0);
		table->find(0);
		table->remove(0);
		table->tryFind(0, x);
		table->containsKey(0);
		delete table;
		this->logPass("Compiled.");
	}

	structures::Table<int, int>* BinarySearchTreeTestInterface::makeTable()
	{
		return new structures::BinarySearchTree<int, int>();
	}

	structures::Table<int, int>* HashTableTestInterface::makeTable()
	{
		return new structures::HashTable<int, int>();
	}

	structures::Table<int, int>* LinkedTableTestInterface::makeTable()
	{
		return new structures::LinkedTable<int, int>();
	}

	structures::Table<int, int>* SortedSequenceTableTestInterface::makeTable()
	{
		return new structures::SortedSequenceTable<int, int>();
	}

	structures::Table<int, int>* TreapTestInterface::makeTable()
	{
		return new structures::Treap<int, int>();
	}

	structures::Table<int, int>* UnsortedSequenceTableTestInterface::makeTable()
	{
		return new structures::UnsortedSequenceTable<int, int>();
	}

	BinarySearchTreeTestOverall::BinarySearchTreeTestOverall() :
		ComplexTest("BinarySearchTree")
	{
		addTest(new BinarySearchTreeTestInterface());
		addTest(new BinarySearchTreeTestContainsKey("ContainsKey"));
		addTest(new BinarySearchTreeTestEquals("Equals"));
		addTest(new BinarySearchTreeTestAssign("Assign"));
		addTest(new BinarySearchTreeTestInsert("Insert"));
		addTest(new BinarySearchTreeTestRemove("Remove"));
		addTest(new BinarySearchTreeTestFind("Find"));
		addTest(new BinarySearchTreeTestTryFind("TryFind"));
		addTest(new BinarySearchTreeTestScenario("BSTScenarioA", 100000, 20000, 20000, 60000));
		addTest(new BinarySearchTreeTestScenario("BSTScenarioB", 100000, 40000, 40000, 20000));
		addTest(new BinarySearchTreeTestSpeedInsert("BSTSpeedInsert"));
		addTest(new BinarySearchTreeTestSpeedRemove("BSTSpeedRemove"));
		addTest(new BinarySearchTreeTestSpeedTryFind("BSTSpeedTryFind"));
	}

	HashTableTestOverall::HashTableTestOverall() :
		ComplexTest("HashTable")
	{
		addTest(new HashTableTestInterface());
	}

	LinkedTableTestOverall::LinkedTableTestOverall() :
		ComplexTest("LinkedTable")
	{
		addTest(new LinkedTableTestInterface());
	}

	SortedSequenceTableTestOverall::SortedSequenceTableTestOverall() :
		ComplexTest("SortedSequenceTable")
	{
		addTest(new SortedSequenceTableTestInterface());
		addTest(new SortedSequenceTableTestContainsKey("ContainsKey"));
		addTest(new SortedSequenceTableTestEquals("Equals"));
		addTest(new SortedSequenceTableTestAssign("Assign"));
		addTest(new SortedSequenceTableTestInsert("Insert"));
		addTest(new SortedSequenceTableTestRemove("Remove"));
		addTest(new SortedSequenceTableTestFind("Find"));
		addTest(new SortedSequenceTableTestTryFind("TryFind"));
		addTest(new SortedSequenceTableTestScenario("SSTScenarioA", 100000, 20000, 20000, 60000));
		addTest(new SortedSequenceTableTestScenario("SSTScenarioB", 100000, 40000, 40000, 20000));
		addTest(new SortedSequenceTableTestSpeedInsert("SSTSpeedInsert"));
		addTest(new SortedSequenceTableTestSpeedRemove("SSTSpeedRemove"));
		addTest(new SortedSequenceTableTestSpeedTryFind("SSTSpeedTryFind"));
	}

	TreapTestOverall::TreapTestOverall() :
		ComplexTest("Treap")
	{
		addTest(new TreapTestInterface());
	}

	UnsortedSequenceTableTestOverall::UnsortedSequenceTableTestOverall() :
		ComplexTest("UnsortedSequenceTable")
	{
		addTest(new UnsortedSequenceTableTestInterface());
	}

	TableTestOverall::TableTestOverall() :
		ComplexTest("Table")
	{
		addTest(new BinarySearchTreeTestOverall());
		//addTest(new HashTableTestOverall());
		//addTest(new LinkedTableTestOverall());
		addTest(new SortedSequenceTableTestOverall());
		//addTest(new TreapTestOverall());
		//addTest(new UnsortedSequenceTableTestOverall());
	}
	TableTest::TableTest(std::string name) :
		SimpleTest(name)
	{
	}
	void TableTest::testContainsKey()
	{
		structures::Table<int, int>* table = this->makeTestTable();
		table->insert(5, 5);
		SimpleTest::assertTrue(table->containsKey(5), "contain 5");
		SimpleTest::assertFalse(table->containsKey(6), "does not contain 6");
		delete table;
	}
	void TableTest::testEquals()
	{
		structures::Table<int, int>* table = this->makeTestTable();
		structures::Table<int, int>* otherTable = this->makeTestTable();
		structures::Table<int, int>* otherDifTable = this->makeTestTable();
		
		table->insert(1, 1);
		table->insert(5, 5);
		table->insert(3, 3);
		table->insert(9, 9);
		otherTable->insert(1, 1);
		otherTable->insert(5, 5);
		otherTable->insert(3, 3);
		otherTable->insert(9, 9);
		otherDifTable->insert(2, 2);
		otherDifTable->insert(6, 6);
		otherDifTable->insert(4, 4);
		otherDifTable->insert(10, 10);

		SimpleTest::assertTrue(table->equals(*otherTable), "equals");
		SimpleTest::assertFalse(table->equals(*otherDifTable), "not equals");
		delete table;
		delete otherTable;
		delete otherDifTable;
	}
	void TableTest::testAssign()
	{
		structures::Table<int, int>* table = this->makeTestTable();
		structures::Table<int, int>* otherTable = this->makeTestTable();

		otherTable->insert(1, 1);
		otherTable->insert(5, 5);
		otherTable->insert(3, 3);
		otherTable->insert(9, 9);

		SimpleTest::assertFalse(table->equals(*otherTable));
		table->assign(*otherTable);
		SimpleTest::assertTrue(table->equals(*otherTable), " size " + std::to_string(table->size()));
		delete table;
		delete otherTable;
	}
	void TableTest::testInsert()
	{
		structures::Table<int, int>* table = this->makeTestTable();
		SimpleTest::assertTrue(table->isEmpty(), " size " + std::to_string(table->size()));
		table->insert(1, 1);
		SimpleTest::assertFalse(table->isEmpty(), " size " + std::to_string(table->size()));
		delete table;
	}
	void TableTest::testRemove()
	{
		structures::Table<int, int>* table = this->makeTestTable();
		table->insert(5, 10);
		SimpleTest::assertTrue(table->remove(5) == 10, "remove 10");
		delete table;
	}
	void TableTest::testFind()
	{
		structures::Table<int, int>* table = this->makeTestTable();
		table->insert(5, 5);
		SimpleTest::assertTrue(table->find(5) == 5);
		delete table;
	}
	void TableTest::testTryFind()
	{
		int x = 5;
		structures::Table<int, int>* table = this->makeTestTable();
		table->insert(5, x);
		SimpleTest::assertTrue(table->tryFind(5, x));
		SimpleTest::assertFalse(table->tryFind(6, x));

		delete table;
	}
	void TableTest::testScenario(std::string name, int countOfOperations, int countOfInsert, int countOfRemove, int countOfTryFind)
	{
		std::ofstream fileStreamScenario(name + ".csv");
		if (!fileStreamScenario.is_open()) {
			throw std::invalid_argument("FileLogConsumer::FileLogConsumer: Failed to open the file");
		}
		srand(time(NULL));

		structures::Table<int, int>* table = this->makeTestTable();
		std::vector<int>* arrayOfKeys = new std::vector<int>();
		int key = 0;
		int ratioCount1 = 0;
		int ratioCount2 = 0;
		int ratioCount3 = 0;
		int ratio = 0;
		int indexInsert = 0;
		int indexRemove = 0;
		auto cas = DurationType(0);
		auto casSum = DurationType(0);
		for (int i = 0; i < countOfOperations + 5000; i++)
		{
			arrayOfKeys->push_back(i);
		}

		std::default_random_engine rngData;
		std::shuffle(arrayOfKeys->begin(), arrayOfKeys->end(), rngData);

		for (int i = 0; i < (countOfOperations); i++)
		{
			ratio = rand() % 3 + 1;
			if (table->isEmpty())
			{
				key = arrayOfKeys->at(indexInsert);
				indexInsert++;
				table->insert(key, key);
			}
			if (ratio == 1 && ratioCount1 < countOfInsert)
			{
				key = arrayOfKeys->at(indexInsert);
				indexInsert++;
				this->startStopwatch();
				table->insert(key, key);
				this->stopStopwatch();
				cas = this->getElapsedTime();
				casSum += cas;
				ratioCount1++;
				fileStreamScenario << "table->insert(" << key << ", " << key << ");" << cas.count() << "; ns" << std::endl;
			}
			else if (ratio == 2 && ratioCount2 < countOfRemove)
			{
				key = arrayOfKeys->at(indexRemove);
				indexRemove++;
				this->startStopwatch();
				table->remove(key);
				this->stopStopwatch();
				cas = this->getElapsedTime();
				casSum += cas;
				ratioCount2++;
				fileStreamScenario << "table->remove(" << key << ");" << cas.count() << "; ns" << std::endl;
			}
			else
			{
				int k = rand() % countOfOperations;
				this->startStopwatch();
				table->tryFind(k, k);
				this->stopStopwatch();
				cas = this->getElapsedTime();
				casSum += cas;
				ratioCount3++;
				fileStreamScenario << "table->tryFind(" << k << ", " << k << ");" << cas.count() << "; ns" << std::endl;
			}
		}
		this->logInfo(name + " " + std::to_string(casSum.count()) + " ns");
		delete table;
		delete arrayOfKeys;
	}
	void TableTest::testSpeedInsert(std::string name)
	{
		std::ofstream fileStreamInsert(name + ".csv");
		if (!fileStreamInsert.is_open()) {
			throw std::invalid_argument("FileLogConsumer::FileLogConsumer: Failed to open the file");
		}
		auto cas = DurationType(0);

		for (int ii = 1; ii < 10000; ii += 100)
		{
			std::vector<int>* arrayOfKeys = new std::vector<int>();
			int index = 0;
			int key = 0;
			for (int i = 0; i < ii + 100; i++)
			{
				arrayOfKeys->push_back(i);
			}

			std::default_random_engine rngData;
			std::shuffle(arrayOfKeys->begin(), arrayOfKeys->end(), rngData);

			structures::Table<int, int>* table = this->makeTestTable();
			for (int j = 0; j < ii; j++)
			{
				key = arrayOfKeys->at(index);
				index++;
				table->insert(key, key);
			}
			for (int k = 0; k < 100; k++)
			{
				key = arrayOfKeys->at(index);
				index++;
				this->startStopwatch();
				table->insert(key, key);
				this->stopStopwatch();
				cas += this->getElapsedTime();
			}
			fileStreamInsert << cas.count() / 100 << ";";
			delete table;
			delete arrayOfKeys;
			cas = DurationType(0);
		}
		fileStreamInsert.close();
	}
	void TableTest::testSpeedRemove(std::string name)
	{
		std::ofstream fileStreamRemove(name + ".csv");
		if (!fileStreamRemove.is_open()) {
			throw std::invalid_argument("FileLogConsumer::FileLogConsumer: Failed to open the file");
		}
		auto cas = DurationType(0);

		for (int ii = 101; ii < 10000; ii += 100)
		{
			std::vector<int>* arrayOfKeys = new std::vector<int>();
			int indexInsert = 0;
			int indexRemove = 0;
			int key = 0;
			for (int i = 0; i < ii + 100; i++)
			{
				arrayOfKeys->push_back(i);
			}

			std::default_random_engine rngData;
			std::shuffle(arrayOfKeys->begin(), arrayOfKeys->end(), rngData);

			structures::Table<int, int>* table = this->makeTestTable();
			for (int j = 0; j < ii; j++)
			{
				key = arrayOfKeys->at(indexInsert);
				indexInsert++;
				table->insert(key, key);
			}
			for (int k = 0; k < 100; k++)
			{
				key = arrayOfKeys->at(indexRemove);
				indexRemove++;
				this->startStopwatch();
				table->remove(key);
				this->stopStopwatch();
				cas += this->getElapsedTime();
			}
			fileStreamRemove << cas.count() / 100 << ";";
			delete table;
			delete arrayOfKeys;
			cas = DurationType(0);
		}
		fileStreamRemove.close();
	}
	void TableTest::testSpeedTryFind(std::string name)
	{
		std::ofstream fileStreamTryFind(name + ".csv");
		if (!fileStreamTryFind.is_open()) {
			throw std::invalid_argument("FileLogConsumer::FileLogConsumer: Failed to open the file");
		}
		auto cas = DurationType(0);

		for (int ii = 1; ii < 10000; ii += 100)
		{
			std::vector<int>* arrayOfKeys = new std::vector<int>();
			int index = 0;
			int key = 0;
			for (int i = 0; i < ii + 100; i++)
			{
				arrayOfKeys->push_back(i);
			}

			std::default_random_engine rngData;
			std::shuffle(arrayOfKeys->begin(), arrayOfKeys->end(), rngData);

			structures::Table<int, int>* table = this->makeTestTable();
			for (int j = 0; j < ii; j++)
			{
				key = arrayOfKeys->at(index);
				index++;
				table->insert(key, key);
			}
			for (int k = 0; k < 100; k++)
			{
				key = arrayOfKeys->at(rand() % index);
				this->startStopwatch();
				table->tryFind(key, key);
				this->stopStopwatch();
				cas += this->getElapsedTime();
			}
			fileStreamTryFind << cas.count() / 100 << ";";
			delete table;
			delete arrayOfKeys;
			cas = DurationType(0);
		}
		fileStreamTryFind.close();
	}
	BinarySearchTreeTest::BinarySearchTreeTest(std::string name) :
		TableTest(name)
	{
	}
	structures::Table<int, int>* BinarySearchTreeTest::makeTestTable() const
	{
		return new structures::BinarySearchTree<int, int>();
	}
	structures::Table<int, int>* SortedSequenceTableTest::makeTestTable() const
	{
		return new structures::SortedSequenceTable<int, int>();
	}
	BinarySearchTreeTestContainsKey::BinarySearchTreeTestContainsKey(std::string name) :
		BinarySearchTreeTest(name)
	{
	}
	BinarySearchTreeTestEquals::BinarySearchTreeTestEquals(std::string name) :
		BinarySearchTreeTest(name)
	{
	}
	BinarySearchTreeTestAssign::BinarySearchTreeTestAssign(std::string name) :
		BinarySearchTreeTest(name)
	{
	}
	BinarySearchTreeTestInsert::BinarySearchTreeTestInsert(std::string name) :
		BinarySearchTreeTest(name)
	{
	}
	BinarySearchTreeTestRemove::BinarySearchTreeTestRemove(std::string name) :
		BinarySearchTreeTest(name)
	{
	}
	BinarySearchTreeTestFind::BinarySearchTreeTestFind(std::string name) :
		BinarySearchTreeTest(name)
	{
	}
	BinarySearchTreeTestTryFind::BinarySearchTreeTestTryFind(std::string name) :
		BinarySearchTreeTest(name)
	{
	}
	BinarySearchTreeTestScenario::BinarySearchTreeTestScenario(std::string name, int countOfOperations, int countOfInsert, int countOfRemove, int countOfTryFind) :
		BinarySearchTreeTest(name)
	{
		this->name = name;
		this->countOfOperations = countOfOperations;
		this->countOfInsert = countOfInsert;
		this->countOfRemove = countOfRemove;
		this->countOfTryFind = countOfTryFind;
	}
	BinarySearchTreeTestSpeedInsert::BinarySearchTreeTestSpeedInsert(std::string name) :
		BinarySearchTreeTest(name)
	{
		this->name = name;
	}
	BinarySearchTreeTestSpeedRemove::BinarySearchTreeTestSpeedRemove(std::string name) :
		BinarySearchTreeTest(name)
	{
		this->name = name;
	}
	BinarySearchTreeTestSpeedTryFind::BinarySearchTreeTestSpeedTryFind(std::string name) :
		BinarySearchTreeTest(name)
	{
		this->name = name;
	}
	SortedSequenceTableTest::SortedSequenceTableTest(std::string name) :
		TableTest(name)
	{
	}
	SortedSequenceTableTestContainsKey::SortedSequenceTableTestContainsKey(std::string name) :
		SortedSequenceTableTest(name)
	{
	}
	SortedSequenceTableTestEquals::SortedSequenceTableTestEquals(std::string name) :
		SortedSequenceTableTest(name)
	{
	}
	SortedSequenceTableTestAssign::SortedSequenceTableTestAssign(std::string name) :
		SortedSequenceTableTest(name)
	{
	}
	SortedSequenceTableTestInsert::SortedSequenceTableTestInsert(std::string name) :
		SortedSequenceTableTest(name)
	{
	}
	SortedSequenceTableTestRemove::SortedSequenceTableTestRemove(std::string name) :
		SortedSequenceTableTest(name)
	{
	}
	SortedSequenceTableTestFind::SortedSequenceTableTestFind(std::string name) :
		SortedSequenceTableTest(name)
	{
	}
	SortedSequenceTableTestTryFind::SortedSequenceTableTestTryFind(std::string name) :
		SortedSequenceTableTest(name)
	{
	}
	SortedSequenceTableTestScenario::SortedSequenceTableTestScenario(std::string name, int countOfOperations, int countOfInsert, int countOfRemove, int countOfTryFind) :
		SortedSequenceTableTest(name)
	{
		this->name = name;
		this->countOfOperations = countOfOperations;
		this->countOfInsert = countOfInsert;
		this->countOfRemove = countOfRemove;
		this->countOfTryFind = countOfTryFind;
	}
	SortedSequenceTableTestSpeedInsert::SortedSequenceTableTestSpeedInsert(std::string name) :
		SortedSequenceTableTest(name)
	{
		this->name = name;
	}
	SortedSequenceTableTestSpeedRemove::SortedSequenceTableTestSpeedRemove(std::string name) :
		SortedSequenceTableTest(name)
	{
		this->name = name;
	}
	SortedSequenceTableTestSpeedTryFind::SortedSequenceTableTestSpeedTryFind(std::string name) :
		SortedSequenceTableTest(name)
	{
		this->name = name;
	}
}