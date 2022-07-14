#include "list_test.h"
#include <stdlib.h>

namespace tests
{
// ListTestInterface:

	ListTestInterface::ListTestInterface(std::string name) :
		SimpleTest(std::move(name))
	{
	}

	void ListTestInterface::test()
	{
		int x = 0;
		structures::List<int>* list = this->makeList();
		list->add(x);
		list->assign(*list);
		list->clear();
		delete list->getBeginIterator();
		delete list->getEndIterator();
		list->getIndexOf(x);
		list->insert(x, x);
		list->isEmpty();
		list->operator[](0);
		list->removeAt(0);
		list->size();
		list->tryRemove(x);
		delete list;
		this->logPass("Compiled.");
	}

// ArrayListTestInterface:

	ArrayListTestInterface::ArrayListTestInterface() :
		ListTestInterface("Interface")
	{
	}

	structures::List<int>* ArrayListTestInterface::makeList() const
	{
		return new structures::ArrayList<int>();
	}

// LinkedListTestInterface:

	LinkedListTestInterface::LinkedListTestInterface() :
		ListTestInterface("Interface")
	{
	}

	structures::List<int>* LinkedListTestInterface::makeList() const
	{
		return new structures::LinkedList<int>();
	}

// ArrayListTestOverall:

	ArrayListTestOverall::ArrayListTestOverall() :
		ComplexTest("ArrayList")
	{
		addTest(new ArrayListTestInterface());
		addTest(new ArrayListTestAssign("TestAssign"));
		addTest(new ArrayListTestAt("TestAt"));
		addTest(new ArrayListTestAdd("TestAdd"));
		addTest(new ArrayListTestEquals("TestEquals"));
		addTest(new ArrayListTestGetIndexOf("TestGetIndexOf"));
		addTest(new ArrayListTestInsert("TestInsert"));
		addTest(new ArrayListTestTryRemove("TestTryRemove"));
		addTest(new ArrayListTestScenario("TestScenarioA", 100000, 20000, 20000, 50000, 10000));
		addTest(new ArrayListTestScenario("TestScenarioB", 100000, 35000, 35000, 20000, 10000));
		addTest(new ArrayListTestScenario("TestScenarioC", 100000, 45000, 45000, 5000, 5000));
		addTest(new ArrayListTestSpeedAt("TestSpeedAt"));
		addTest(new ArrayListTestSpeedInsert("TestSpeedInsert"));
		addTest(new ArrayListTestSpeedRemoveAt("TestSpeedRemoveAt"));
	}

// LinkedListTestOverall:

	LinkedListTestOverall::LinkedListTestOverall() :
		ComplexTest("LinkedList")
	{
		addTest(new LinkedListTestInterface());
		
	}

// DoubleLinkedListTestOverall:

	DoubleLinkedListTestOverall::DoubleLinkedListTestOverall() :
		ComplexTest("DoubleLinkedList")
	{
		addTest(new DoubleLinkedListTestAssign("TestAssign"));
		addTest(new DoubleLinkedListTestAt("TestAt"));
		addTest(new DoubleLinkedListTestAdd("TestAdd"));
		addTest(new DoubleLinkedListTestEquals("TestEquals"));
		addTest(new DoubleLinkedListTestGetIndexOf("TestGetIndexOf"));
		addTest(new DoubleLinkedListTestInsert("TestInsert"));
		addTest(new DoubleLinkedListTestTryRemove("TestTryRemove"));
		addTest(new DoubleLinkedListTestScenario("TestScenarioA", 100000, 20000, 20000, 50000, 10000));
		addTest(new DoubleLinkedListTestScenario("TestScenarioB", 100000, 35000, 35000, 20000, 10000));
		addTest(new DoubleLinkedListTestScenario("TestScenarioC", 100000, 45000, 45000, 5000, 5000));
		addTest(new DoubleLinkedListTestSpeedAt("TestSpeedAt"));
		addTest(new DoubleLinkedListTestSpeedInsert("TestSpeedInsert"));
		addTest(new DoubleLinkedListTestSpeedRemoveAt("TestSpeedRemoveAt"));

	}

// ListTestOverall:

	ListTestOverall::ListTestOverall() :
		ComplexTest("List")
	{
		addTest(new ArrayListTestOverall());
		//addTest(new LinkedListTestOverall());
		addTest(new DoubleLinkedListTestOverall());
	}
	
	ArrayListTest::ArrayListTest(std::string name) :
		ListTest(name)
	{
	}

	structures::List<int>* ArrayListTest::makeTestList() const
	{
		return new structures::ArrayList<int>();
	}

	DoubleLinkedListTest::DoubleLinkedListTest(std::string name) :
		ListTest(name)
	{
	}

	structures::List<int>* DoubleLinkedListTest::makeTestList() const
	{
		return new structures::DoubleLinkedList<int>();
	}

	ListTest::ListTest(std::string name) :
		SimpleTest(name)
	{
	}

	void ListTest::testAdd(int data)
	{
		structures::List<int>* list = this->makeTestList();
		int size = 15;
		for (int i = 0; i < size; i++) {
			list->add(i + i);
		}

		for (int i = 0; i < size; i++) {
			SimpleTest::assertTrue(list->at(i) == i + i, "list->at(" + std::to_string(i) + ") =  " + std::to_string(list->at(i)) + " ==  i + i =" + std::to_string(i + i));
			SimpleTest::assertTrue(list->size() == size);
		}

		delete list;
	}

	void ListTest::testAssign()
	{
		structures::List<int>* list = this->makeTestList();
		structures::List<int>* otherList = this->makeTestList();
		int size = 15;
		for (int i = 0; i < size; i++) {
			otherList->add(i + i);
		}
		SimpleTest::assertFalse(list->equals(*otherList));
		list->assign(*otherList);

		for (int i = 0; i < size; i++) {
			SimpleTest::assertTrue(list->equals(*otherList), "list->assign(*otherList)   list->at(" + std::to_string(i) + ") =  " + std::to_string(list->at(i)) + " ==  otherList->at(" + std::to_string(i) + ") = " + std::to_string(otherList->at(i)));

		}

		delete list;
		delete otherList;
	}

	void ListTest::testAt(int index)
	{
		structures::List<int>* list = this->makeTestList();
		int size = 15;
		for (int i = 0; i < size; i++) {
			list->add(i);
		}

		for (int i = 0; i < size; i++) {
			SimpleTest::assertTrue(list->at(i) == i, "list->at(" + std::to_string(i) + ") =  " + std::to_string(list->at(i)) + " == " + std::to_string(i));

		}

		delete list;
	}

	void ListTest::testEquals()
	{
		structures::List<int>* list = this->makeTestList();
		structures::List<int>* otherList = this->makeTestList();
		structures::List<int>* badOtherList = this->makeTestList();
		int size = 15;
		for (int i = 0; i < size; i++) {
			list->add(i + i);
			otherList->add(i + i);
			badOtherList->add(i);
		}
		SimpleTest::assertFalse(list->equals(*badOtherList));
		SimpleTest::assertTrue(list->equals(*otherList), "list->equals(*otherList)");

		delete list;
		delete otherList;
		delete badOtherList;
	}

	void ListTest::testGetIndexOf(int data)
	{
		structures::List<int>* list = this->makeTestList();
		int size = 15;
		for (int i = 0; i < size; i++) {
			list->add(i + i);
		}
		SimpleTest::assertTrue(list->getIndexOf(10) == 5, "list->getIndexOf(10) == 6");
		delete list;
	}

	void ListTest::testInsert(int data, int index)
	{
		structures::List<int>* list = this->makeTestList();
		int size = 15;
		for (int i = 0; i < size; i++) {
			list->add(i + i);
		}
		list->insert(429, 9);
		SimpleTest::assertTrue(list->getIndexOf(429) == 9, "list->getIndexOf(429) == 9");
		SimpleTest::assertTrue(list->size() == 16, "list->size() == 16");

		delete list;
	}

	void ListTest::testTryRemove(int data)
	{
		structures::List<int>* list = this->makeTestList();
		int size = 15;
		for (int i = 0; i < size; i++) {
			list->add(i + i);
		}
		SimpleTest::assertTrue(list->tryRemove(2), "list->tryRemove(2)");
		delete list;
	}

	void ListTest::testScenario(std::string name, int countOfOperations, int countOfInsert, int countOfRemoveAt, int countOfAt, int countOfGetIndexOf)
	{
		srand(time(NULL));
		structures::List<int>* list = this->makeTestList();
		for (int i = 0; i < 1000; i++)
		{
			list->add(rand() % 10 + 1);
		}
		int ratioCount1 = 0;
		int ratioCount2 = 0;
		int ratioCount3 = 0;
		int ratioCount4 = 0;
		int randIndex = 0;
		int ratio = 0;
		int fffff = 0;

		auto cas = DurationType(0);

		for (int i = 0; i < (countOfOperations); i++)
		{
			ratio = rand() % 4 + 1;
			if (list->isEmpty())
			{
				list->add(1);
			}
			if (ratio == 1 && ratioCount1 < countOfInsert)
			{
				int data = rand() % 10 + 1;
				int index = rand() % list->size();
				this->startStopwatch();
				list->insert(data, index); 
				this->stopStopwatch();
				cas += this->getElapsedTime();
				ratioCount1++;
			}
			else if (ratio == 2 && ratioCount2 < countOfRemoveAt)
			{
				int index = rand() % list->size();
				this->startStopwatch();
				list->removeAt(index); 
				this->stopStopwatch();
				cas += this->getElapsedTime();
				ratioCount2++;
			}
			else if (ratio == 3 && ratioCount3 < countOfAt)
			{
				int index = rand() % (list->size());
				this->startStopwatch();
				list->at(index); 
				this->stopStopwatch();
				cas += this->getElapsedTime();
				ratioCount3++;
			}
			else if (ratio == 4 && ratioCount4 < countOfGetIndexOf)
			{
				int data = rand() % 10 + 1;
				this->startStopwatch();
				list->getIndexOf(data); 
				this->stopStopwatch();
				cas += this->getElapsedTime();
				ratioCount4++;
			}
			else
			{
				i--;
			}
			fffff++;
		}
		this->logInfo("countOfInsert " + std::to_string(ratioCount1));
		this->logInfo("countOfRemoveAt " + std::to_string(ratioCount2));
		this->logInfo("countOfAt " + std::to_string(ratioCount3));
		this->logInfo("countOfGetIndexOf " + std::to_string(ratioCount4));
		this->logInfo("count " + std::to_string(fffff));
		this->logInfo(name + " " + std::to_string(cas.count()) + " ns");
		structures::Logger::getInstance().logDuration(list->size(), cas," " + name);
		delete list;
	}

	void ListTest::testSpeedAt()
	{
		std::ofstream fileStreamAt("SpeedTestAt.csv");
		if (!fileStreamAt.is_open()) {
			throw std::invalid_argument("FileLogConsumer::FileLogConsumer: Failed to open the file");
		}
		auto cas = DurationType(0);
		for (int i = 1; i < 10000; i+= 100)
		{
			structures::List<int>* list = this->makeTestList();
			for (int j = 0; j < i; j++)
			{
				list->add(j);
			}
			for (int k = 0; k < 100; k++)
			{
				int index = rand() % list->size();
				this->startStopwatch();
				list->at(index);
				this->stopStopwatch();
				cas += this->getElapsedTime();
			}
			fileStreamAt << cas.count() / 100 << ";";
			delete list;
			cas = DurationType(0);
		}
		fileStreamAt.close();
	}

	void ListTest::testSpeedInsert()
	{
		std::ofstream fileStreamAt("SpeedInsert.csv");
		if (!fileStreamAt.is_open()) {
			throw std::invalid_argument("FileLogConsumer::FileLogConsumer: Failed to open the file");
		}
		auto cas = DurationType(0);
		for (int i = 1; i < 10000; i += 10)
		{
			structures::List<int>* list = this->makeTestList();
			for (int j = 0; j < i; j++)
			{
				list->add(j);
			}
			for (int k = 0; k < 100; k++)
			{
				int index = rand() % list->size();
				int data = rand() % 10;
				this->startStopwatch();
				list->insert(data, index);
				this->stopStopwatch();
				cas += this->getElapsedTime();
			}
			fileStreamAt << cas.count() / 100 << ";";
			delete list;
			cas = DurationType(0);
		}
		fileStreamAt.close();
	}

	void ListTest::testSpeedRemoveAt()
	{
		std::ofstream fileStreamAt("RemoveAt.csv");
		if (!fileStreamAt.is_open()) {
			throw std::invalid_argument("FileLogConsumer::FileLogConsumer: Failed to open the file");
		}
		auto cas = DurationType(0);
		for (int i = 102; i < 10000; i += 100)
		{
			structures::List<int>* list = this->makeTestList();
			for (int j = 0; j < i; j++)
			{
				list->add(j);
			}
			for (int k = 0; k < 100; k++)
			{
				int index = rand() % (list->size());
				this->startStopwatch();
				list->removeAt(index);
				this->stopStopwatch();
				cas += this->getElapsedTime();
			}
			fileStreamAt << cas.count() / 100 << ";";
			delete list;
			cas = DurationType(0);
		}
		fileStreamAt.close();
	}

	DoubleLinkedListTestAssign::DoubleLinkedListTestAssign(std::string name) :
		DoubleLinkedListTest(name)
	{
	}

	ArrayListTestAdd::ArrayListTestAdd(std::string name) :
		ArrayListTest(name)
	{
	}

	ArrayListTestAssign::ArrayListTestAssign(std::string name) :
		ArrayListTest(name)
	{
	}

	ArrayListTestAt::ArrayListTestAt(std::string name) :
		ArrayListTest(name)
	{
	}

	ArrayListTestEquals::ArrayListTestEquals(std::string name) :
		ArrayListTest(name)
	{
	}

	ArrayListTestGetIndexOf::ArrayListTestGetIndexOf(std::string name) :
		ArrayListTest(name)
	{
	}

	ArrayListTestInsert::ArrayListTestInsert(std::string name) :
		ArrayListTest(name)
	{
	}

	ArrayListTestTryRemove::ArrayListTestTryRemove(std::string name) :
		ArrayListTest(name)
	{
	}

	DoubleLinkedListTestAdd::DoubleLinkedListTestAdd(std::string name) :
		DoubleLinkedListTest(name)
	{
	}

	DoubleLinkedListTestAt::DoubleLinkedListTestAt(std::string name) :
		DoubleLinkedListTest(name)
	{
	}

	DoubleLinkedListTestEquals::DoubleLinkedListTestEquals(std::string name) :
		DoubleLinkedListTest(name)
	{
	}

	DoubleLinkedListTestGetIndexOf::DoubleLinkedListTestGetIndexOf(std::string name) :
		DoubleLinkedListTest(name)
	{
	}

	DoubleLinkedListTestInsert::DoubleLinkedListTestInsert(std::string name) :
		DoubleLinkedListTest(name)
	{
	}

	DoubleLinkedListTestTryRemove::DoubleLinkedListTestTryRemove(std::string name) :
		DoubleLinkedListTest(name)
	{
	}

	DoubleLinkedListTestScenario::DoubleLinkedListTestScenario(std::string name, int countOfOperations, int countOfInsert, int countOfRemoveAt, int countOfAt, int countOfGetIndexOf) :
		DoubleLinkedListTest(name)
	{
		this->name = name;
		this->countOfOperations = countOfOperations;
		this->countOfInsert = countOfInsert;
		this->countOfRemoveAt = countOfRemoveAt;
		this->countOfAt = countOfAt;
		this->countOfGetIndexOf = countOfGetIndexOf;
	}

	ArrayListTestScenario::ArrayListTestScenario(std::string name, int countOfOperations, int countOfInsert, int countOfRemoveAt, int countOfAt, int countOfGetIndexOf) :
		ArrayListTest(name)
	{
		this->name = name;
		this->countOfOperations = countOfOperations;
		this->countOfInsert = countOfInsert;
		this->countOfRemoveAt = countOfRemoveAt;
		this->countOfAt = countOfAt;
		this->countOfGetIndexOf = countOfGetIndexOf;
	}

	ArrayListTestSpeedAt::ArrayListTestSpeedAt(std::string name) :
		ArrayListTest(name)
	{
	}

	DoubleLinkedListTestSpeedAt::DoubleLinkedListTestSpeedAt(std::string name) :
		DoubleLinkedListTest(name)
	{
	}

	ArrayListTestSpeedInsert::ArrayListTestSpeedInsert(std::string name) :
		ArrayListTest(name)
	{
	}

	DoubleLinkedListTestSpeedInsert::DoubleLinkedListTestSpeedInsert(std::string name) :
		DoubleLinkedListTest(name)
	{
	}

	ArrayListTestSpeedRemoveAt::ArrayListTestSpeedRemoveAt(std::string name) :
		ArrayListTest(name)
	{
	}

	DoubleLinkedListTestSpeedRemoveAt::DoubleLinkedListTestSpeedRemoveAt(std::string name) :
		DoubleLinkedListTest(name)
	{
	}

}