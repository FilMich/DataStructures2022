#include "priority_queue_test.h"
#include "../../structures/priority_queue/heap.h"
#include "../../structures/priority_queue/priority_queue_limited_sorted_array_list.h"
#include "../../structures/priority_queue/priority_queue_linked_list.h"
#include "../../structures/priority_queue/priority_queue_sorted_array_list.h"
#include "../../structures/priority_queue/priority_queue_two_lists.h"
#include "../../structures/priority_queue/priority_queue_unsorted_array_list.h"

namespace tests
{
    PriorityQueueTestInterface::PriorityQueueTestInterface() :
        SimpleTest("Interface")
    {
    }

    void PriorityQueueTestInterface::test()
    {
        int x = 0;
        structures::PriorityQueue<int>* queue = this->makePriorityQueue();
        queue->push(0, x);
        queue->peek();
        queue->peekPriority();
        queue->pop();
        queue->assign(*queue);
        delete queue;
        this->logPass("Compiled.");
    }

    structures::PriorityQueue<int>* PriorityQueueUnsortedArrayListTestInterface::makePriorityQueue()
    {
        return new structures::PriorityQueueUnsortedArrayList<int>();
    }

    structures::PriorityQueue<int>* PriorityQueueSortedArrayListTestInterface::makePriorityQueue()
    {
        return new structures::PriorityQueueSortedArrayList<int>();
    }

    structures::PriorityQueue<int>* PriorityQueueLimitedSortedArrayListTestInterface::makePriorityQueue()
    {
        return new structures::PriorityQueueLimitedSortedArrayList<int>();
    }

    structures::PriorityQueue<int>* PriorityQueueLinkedListTestInterface::makePriorityQueue()
    {
        return new structures::PriorityQueueLinkedList<int>();
    }

    structures::PriorityQueue<int>* PriorityQueueTwoListsTestInterface::makePriorityQueue()
    {
        return new structures::PriorityQueueTwoLists<int>();
    }

    structures::PriorityQueue<int>* HeapTestInterface::makePriorityQueue()
    {
        return new structures::Heap<int>();
    }

    PriorityQueueUnsortedArrayListTestOverall::PriorityQueueUnsortedArrayListTestOverall() :
        ComplexTest("PriorityQueueUnsortedArray")
    {
        addTest(new PriorityQueueUnsortedArrayListTestInterface());
    }

    PriorityQueueSortedArrayListTestOverall::PriorityQueueSortedArrayListTestOverall() :
        ComplexTest("PriorityQueueSortedArrayList")
    {
        addTest(new PriorityQueueSortedArrayListTestInterface());
    }

    PriorityQueueLimitedSortedArrayListTestOverall::PriorityQueueLimitedSortedArrayListTestOverall() :
        ComplexTest("PriorityQueueLimitedSortedArrayList")
    {
        addTest(new PriorityQueueLimitedSortedArrayListTestInterface());
    }

    PriorityQueueLinkedListTestOverall::PriorityQueueLinkedListTestOverall() :
        ComplexTest("PriorityQueueLinkedList")
    {
        addTest(new PriorityQueueLinkedListTestInterface());
    }

    PriorityQueueTwoListsTestOverall::PriorityQueueTwoListsTestOverall() :
        ComplexTest("PriorityQueueTwoLists")
    {
        addTest(new PriorityQueueTwoListsTestInterface());
        addTest(new PriorityQueueTwoListTestScenario("TwoListTestScenarioA", 100000, 35000, 35000, 30000));
        addTest(new PriorityQueueTwoListTestScenario("TwoListTestScenarioB", 100000, 50000, 30000, 20000));
        addTest(new PriorityQueueTwoListTestScenario("TwoListTestScenarioC", 100000, 70000, 25000, 5000));
        addTest(new PriorityQueueTwoListTestSpeedPush("TwoListTestSpeedPush"));
        addTest(new PriorityQueueTwoListTestSpeedPeek("TwoListTestSpeedPeek"));
        addTest(new PriorityQueueTwoListTestSpeedPop("TwoListTestSpeedPop"));
    }

    HeapTestOverall::HeapTestOverall() :
        ComplexTest("Heap")
    {
        addTest(new HeapTestInterface());
        addTest(new HeapTestScenario("HeapTestScenarioA", 100000, 35000, 35000, 30000));
        addTest(new HeapTestScenario("HeapTestScenarioB", 100000, 50000, 30000, 20000));
        addTest(new HeapTestScenario("HeapTestScenarioC", 100000, 70000, 25000, 5000));
        addTest(new HeapTestSpeedPush("HeapTestSpeedPush"));
        addTest(new HeapTestSpeedPeek("HeapTestSpeedPeek"));
        addTest(new HeapTestSpeedPop("HeapTestSpeedPop"));
    }

    PriorityQueueTestOverall::PriorityQueueTestOverall() :
        ComplexTest("PriorityQueue")
    {
        //addTest(new PriorityQueueUnsortedArrayListTestOverall());
        //addTest(new PriorityQueueSortedArrayListTestOverall());
        //addTest(new PriorityQueueLimitedSortedArrayListTestOverall());
        //addTest(new PriorityQueueLinkedListTestOverall());
        addTest(new PriorityQueueTwoListsTestOverall());
        addTest(new HeapTestOverall());
    }
    PriorityQueueTest::PriorityQueueTest(std::string name) :
        SimpleTest(name)
    {
    }
    void PriorityQueueTest::testPush(int priority, int data)
    {
    }
    void PriorityQueueTest::testAssign()
    {
    }
    void PriorityQueueTest::testPeek()
    {
    }
    void PriorityQueueTest::testPeekPriority()
    {
    }
    void PriorityQueueTest::testPop()
    {
    }
    void PriorityQueueTest::testSize()
    {
    }
    void PriorityQueueTest::testScenario(std::string name, int countOfOperations, int countOfPush, int countOfPop, int countOfPeek)
    {
        std::ofstream fileStreamScenario(name + ".csv");
        if (!fileStreamScenario.is_open()) {
            throw std::invalid_argument("FileLogConsumer::FileLogConsumer: Failed to open the file");
        }
        srand(time(NULL));

        structures::PriorityQueue<int>* queue = this->makeTestPriorityQueue();

        int ratioCount1 = 0;
        int ratioCount2 = 0;
        int ratioCount3 = 0;
        int ratio = 0;
        auto cas = DurationType(0);
        auto casSum = DurationType(0);

        for (int i = 0; i < (countOfOperations); i++)
        {
            ratio = rand() % 3 + 1;
            if (queue->isEmpty())
            {
                queue->push(rand() % countOfOperations, i);
            }
            if (ratio == 1 && ratioCount1 < countOfPush)
            {
                int priority = rand() % countOfOperations;
                this->startStopwatch();
                queue->push(priority, i);
                this->stopStopwatch();
                cas = this->getElapsedTime();
                casSum += cas;
                ratioCount1++;
                fileStreamScenario << "queue->push(" << priority << ", " << i << ");" << cas.count() << "; ns" << std::endl;
            }
            else if (ratio == 2 && ratioCount2 < countOfPop)
            {
                this->startStopwatch();
                queue->pop();
                this->stopStopwatch();
                cas = this->getElapsedTime();
                casSum += cas;
                ratioCount2++;
                fileStreamScenario << "queue->pop();" << cas.count() << "; ns" << std::endl;
            }
            else
            {
                this->startStopwatch();
                queue->peek();
                this->stopStopwatch();
                cas = this->getElapsedTime();
                casSum += cas;
                ratioCount3++;
                fileStreamScenario << "queue->peek();" << cas.count() << "; ns" << std::endl;
            }
        }
        this->logInfo(name + " " + std::to_string(casSum.count()) + " ns");
        delete queue;
    }
    void PriorityQueueTest::testSpeedPush(std::string name)
    {
        std::ofstream fileStreamAt(name + ".csv");
        if (!fileStreamAt.is_open()) {
            throw std::invalid_argument("FileLogConsumer::FileLogConsumer: Failed to open the file");
        }
        auto cas = DurationType(0);
        for (int i = 1; i < 10000; i += 100)
        {
            structures::PriorityQueue<int>* queue = this->makeTestPriorityQueue();
            for (int j = 0; j < i; j++)
            {
                queue->push(j, i);
            }
            for (int k = 0; k < 100; k++)
            {
                int index = rand() % queue->size();
                this->startStopwatch();
                queue->push(k, i);
                this->stopStopwatch();
                cas += this->getElapsedTime();
            }
            fileStreamAt << cas.count() / 100 << ";";
            delete queue;
            cas = DurationType(0);
        }
        fileStreamAt.close();
    }
    void PriorityQueueTest::testSpeedPop(std::string name)
    {
        std::ofstream fileStreamAt(name + ".csv");
        if (!fileStreamAt.is_open()) {
            throw std::invalid_argument("FileLogConsumer::FileLogConsumer: Failed to open the file");
        }
        auto cas = DurationType(0);
        for (int i = 101; i < 10000; i += 100)
        {
            structures::PriorityQueue<int>* queue = this->makeTestPriorityQueue();
            for (int j = 0; j < i; j++)
            {
                queue->push(j, i);
            }
            for (int k = 0; k < 100; k++)
            {
                int index = rand() % queue->size();
                this->startStopwatch();
                queue->pop();
                this->stopStopwatch();
                cas += this->getElapsedTime();
            }
            fileStreamAt << cas.count() / 100 << ";";
            delete queue;
            cas = DurationType(0);
        }
        fileStreamAt.close();
    }
    void PriorityQueueTest::testSpeedPeek(std::string name)
    {
        std::ofstream fileStreamAt(name + ".csv");
        if (!fileStreamAt.is_open()) {
            throw std::invalid_argument("FileLogConsumer::FileLogConsumer: Failed to open the file");
        }
        auto cas = DurationType(0);
        for (int i = 1; i < 10000; i += 100)
        {
            structures::PriorityQueue<int>* queue = this->makeTestPriorityQueue();
            for (int j = 0; j < i; j++)
            {
                queue->push(j, i);
            }
            for (int k = 0; k < 100; k++)
            {
                int index = rand() % queue->size();
                this->startStopwatch();
                queue->peek();
                this->stopStopwatch();
                cas += this->getElapsedTime();
            }
            fileStreamAt << cas.count() / 100 << ";";
            delete queue;
            cas = DurationType(0);
        }
        fileStreamAt.close();
    }
    PriorityQueueTwoListTest::PriorityQueueTwoListTest(std::string name) :
        PriorityQueueTest(name)
    {
    }
    structures::PriorityQueue<int>* PriorityQueueTwoListTest::makeTestPriorityQueue() const
    {
        return new structures::PriorityQueueTwoLists<int>();
    }
    PriorityQueueTwoListTestPush::PriorityQueueTwoListTestPush(std::string name) :
        PriorityQueueTwoListTest(name)
    {
    }
    PriorityQueueTwoListTestAssign::PriorityQueueTwoListTestAssign(std::string name) :
        PriorityQueueTwoListTest(name)
    {
    }
    PriorityQueueTwoListTestPeek::PriorityQueueTwoListTestPeek(std::string name) :
        PriorityQueueTwoListTest(name)
    {
    }
    PriorityQueueTwoListTestPeekPriority::PriorityQueueTwoListTestPeekPriority(std::string name) :
        PriorityQueueTwoListTest(name)
    {
    }
    PriorityQueueTwoListTestPop::PriorityQueueTwoListTestPop(std::string name) :
        PriorityQueueTwoListTest(name)
    {
    }
    PriorityQueueTwoListTestSize::PriorityQueueTwoListTestSize(std::string name) :
        PriorityQueueTwoListTest(name)
    {
    }
    PriorityQueueTwoListTestScenario::PriorityQueueTwoListTestScenario(std::string name, int countOfOperations, int countOfPush, int countOfPop, int countOfPeek) :
        PriorityQueueTwoListTest(name)
    {
        this->name = name;
        this->countOfOperations = countOfOperations;
        this->countOfPush = countOfPush;
        this->countOfPop = countOfPop;
        this->countOfPeek = countOfPeek;
    }
    PriorityQueueTwoListTestSpeedPush::PriorityQueueTwoListTestSpeedPush(std::string name) :
        PriorityQueueTwoListTest(name)
    {
        this->name = name;
    }
    PriorityQueueTwoListTestSpeedPop::PriorityQueueTwoListTestSpeedPop(std::string name) :
        PriorityQueueTwoListTest(name)
    {
        this->name = name;
    }
    PriorityQueueTwoListTestSpeedPeek::PriorityQueueTwoListTestSpeedPeek(std::string name) :
        PriorityQueueTwoListTest(name)
    {
        this->name = name;
    }
    HeapTest::HeapTest(std::string name) :
        PriorityQueueTest(name)
    {
    }
    structures::PriorityQueue<int>* HeapTest::makeTestPriorityQueue() const
    {
        return new structures::Heap<int>();
    }
    HeapTestPush::HeapTestPush(std::string name) :
        HeapTest(name)
    {
    }
    HeapTestAssign::HeapTestAssign(std::string name) :
        HeapTest(name)
    {
    }
    HeapTestPeek::HeapTestPeek(std::string name) :
        HeapTest(name)
    {
    }
    HeapTestPeekPriority::HeapTestPeekPriority(std::string name) :
        HeapTest(name)
    {
    }
    HeapTestPop::HeapTestPop(std::string name) :
        HeapTest(name)
    {
    }
    HeapTestSize::HeapTestSize(std::string name) :
        HeapTest(name)
    {
    }
    HeapTestScenario::HeapTestScenario(std::string name, int countOfOperations, int countOfPush, int countOfPop, int countOfPeek) :
        HeapTest(name)
    {
        this->name = name;
        this->countOfOperations = countOfOperations;
        this->countOfPush = countOfPush;
        this->countOfPop = countOfPop;
        this->countOfPeek = countOfPeek;
    }
    HeapTestSpeedPush::HeapTestSpeedPush(std::string name) :
        HeapTest(name)
    {
        this->name = name;
    }
    HeapTestSpeedPop::HeapTestSpeedPop(std::string name) :
        HeapTest(name)
    {
        this->name = name;
    }
    HeapTestSpeedPeek::HeapTestSpeedPeek(std::string name) :
        HeapTest(name)
    {
        this->name = name;
    }
}