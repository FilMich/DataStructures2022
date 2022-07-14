#pragma once

#include "../test.h"
#include "../../structures/priority_queue/priority_queue.h"
#include "../../structures/priority_queue/priority_queue_list.h"
#include "../../structures/_logger/logger.h"
#include "../../structures/_logger/file_log_consumer.h"

namespace tests
{
    /// <summary>
    /// Zavola vsetky metody z rozhrania prioritneho frontu avsak nekontroluje ich spravnost.
    /// Zabezpeci, ze vsetky metody budu prelozene kompilatorom.
    /// </summary>
    class PriorityQueueTestInterface
        : public SimpleTest
    {
    public:
        PriorityQueueTestInterface();
        void test() override;

    protected:
        virtual structures::PriorityQueue<int>* makePriorityQueue() = 0;
    };

    class PriorityQueueTest
        : public SimpleTest
    {
    public:
        PriorityQueueTest(std::string name);

    protected:
        virtual structures::PriorityQueue<int>* makeTestPriorityQueue() const = 0;
        void testPush(int priority, int data);
        void testAssign();
        void testPeek();
        void testPeekPriority();
        void testPop();
        void testSize();
        void testScenario(std::string name, int countOfOperations, int countOfPush, int countOfPop, int countOfPeek);
        void testSpeedPush(std::string name);
        void testSpeedPop(std::string name);
        void testSpeedPeek(std::string name);
    };



    class PriorityQueueTwoListTest
        : public PriorityQueueTest
    {
    public:
        PriorityQueueTwoListTest(std::string name);

    protected:
        structures::PriorityQueue<int>* makeTestPriorityQueue() const override;
    };

    class PriorityQueueTwoListTestPush
        : public PriorityQueueTwoListTest
    {
    public:
        PriorityQueueTwoListTestPush(std::string name);
        void test() override { testPush(5, 5); };
    };

    class PriorityQueueTwoListTestAssign
        : public PriorityQueueTwoListTest
    {
    public:
        PriorityQueueTwoListTestAssign(std::string name);
        void test() override { testAssign(); };
    };

    class PriorityQueueTwoListTestPeek
        : public PriorityQueueTwoListTest
    {
    public:
        PriorityQueueTwoListTestPeek(std::string name);
        void test() override { testPeek(); };
    };

    class PriorityQueueTwoListTestPeekPriority
        : public PriorityQueueTwoListTest
    {
    public:
        PriorityQueueTwoListTestPeekPriority(std::string name);
        void test() override { testPeekPriority(); };
    };

    class PriorityQueueTwoListTestPop
        : public PriorityQueueTwoListTest
    {
    public:
        PriorityQueueTwoListTestPop(std::string name);
        void test() override { testPop(); };
    };

    class PriorityQueueTwoListTestSize
        : public PriorityQueueTwoListTest
    {
    public:
        PriorityQueueTwoListTestSize(std::string name);
        void test() override { testSize(); };
    };

    class PriorityQueueTwoListTestScenario
        : public PriorityQueueTwoListTest
    {
    public:
        PriorityQueueTwoListTestScenario(std::string name, int countOfOperations, int countOfPush, int countOfPop, int countOfPeek);
    private:
        std::string name;
        int countOfOperations;
        int countOfPush;
        int countOfPop;
        int countOfPeek;
        void test() override { testScenario(name, countOfOperations, countOfPush, countOfPop, countOfPeek); };
    };

    class PriorityQueueTwoListTestSpeedPush
        : public PriorityQueueTwoListTest
    {
    public:
        PriorityQueueTwoListTestSpeedPush(std::string name);
    private:
        std::string name;
        void test() override { testSpeedPush(name); };
    };

    class PriorityQueueTwoListTestSpeedPop
        : public PriorityQueueTwoListTest
    {
    public:
        PriorityQueueTwoListTestSpeedPop(std::string name);
       private:
        std::string name;
        void test() override { testSpeedPop(name); };
    };

    class PriorityQueueTwoListTestSpeedPeek
        : public PriorityQueueTwoListTest
    {
    public:
        PriorityQueueTwoListTestSpeedPeek(std::string name);
    private:
        std::string name;
        void test() override { testSpeedPeek(name); };
    };






    class HeapTest
        : public PriorityQueueTest
    {
    public:
        HeapTest(std::string name);

    protected:
        structures::PriorityQueue<int>* makeTestPriorityQueue() const override;
    };

    class HeapTestPush
        : public HeapTest
    {
    public:
        HeapTestPush(std::string name);
        void test() override { testPush(5, 5); };
    };

    class HeapTestAssign
        : public HeapTest
    {
    public:
        HeapTestAssign(std::string name);
        void test() override { testAssign(); };
    };

    class HeapTestPeek
        : public HeapTest
    {
    public:
        HeapTestPeek(std::string name);
        void test() override { testPeek(); };
    };

    class HeapTestPeekPriority
        : public HeapTest
    {
    public:
        HeapTestPeekPriority(std::string name);
        void test() override { testPeekPriority(); };
    };

    class HeapTestPop
        : public HeapTest
    {
    public:
        HeapTestPop(std::string name);
        void test() override { testPop(); };
    };

    class HeapTestSize
        : public HeapTest
    {
    public:
        HeapTestSize(std::string name);
        void test() override { testSize(); };
    };

    class HeapTestScenario
        : public HeapTest
    {
    public:
        HeapTestScenario(std::string name, int countOfOperations, int countOfPush, int countOfPop, int countOfPeek);
    private:
        std::string name;
        int countOfOperations;
        int countOfPush;
        int countOfPop;
        int countOfPeek;
        void test() override { testScenario(name, countOfOperations, countOfPush, countOfPop, countOfPeek); };
    };

    class HeapTestSpeedPush
        : public HeapTest
    {
    public:
        HeapTestSpeedPush(std::string name);
    private:
        std::string name;
        void test() override { testSpeedPush(name); };
    };

    class HeapTestSpeedPop
        : public HeapTest
    {
    public:
        HeapTestSpeedPop(std::string name);
    private:
        std::string name;
        void test() override { testSpeedPop(name); };
    };

    class HeapTestSpeedPeek
        : public HeapTest
    {
    public:
        HeapTestSpeedPeek(std::string name);
    private:
        std::string name;
        void test() override { testSpeedPeek(name); };
    };







    /// <summary>
    /// Zavola vsetky metody prioritneho frontu.
    /// </summary>
    class PriorityQueueUnsortedArrayListTestInterface
        : public PriorityQueueTestInterface
    {
    protected:
        structures::PriorityQueue<int>* makePriorityQueue() override;
    };

    /// <summary>
    /// Zavola vsetky metody prioritneho frontu.
    /// </summary>
    class PriorityQueueSortedArrayListTestInterface
        : public PriorityQueueTestInterface
    {
    protected:
        structures::PriorityQueue<int>* makePriorityQueue() override;
    };

    /// <summary>
    /// Zavola vsetky metody prioritneho frontu.
    /// </summary>
    class PriorityQueueLimitedSortedArrayListTestInterface
        : public PriorityQueueTestInterface
    {
    protected:
        structures::PriorityQueue<int>* makePriorityQueue() override;
    };

    /// <summary>
    /// Zavola vsetky metody prioritneho frontu.
    /// </summary>
    class PriorityQueueLinkedListTestInterface
        : public PriorityQueueTestInterface
    {
    protected:
        structures::PriorityQueue<int>* makePriorityQueue() override;
    };

    /// <summary>
    /// Zavola vsetky metody prioritneho frontu.
    /// </summary>
    class PriorityQueueTwoListsTestInterface
        : public PriorityQueueTestInterface
    {
    protected:
        structures::PriorityQueue<int>* makePriorityQueue() override;
    };

    /// <summary>
    /// Zavola vsetky metody prioritneho frontu.
    /// </summary>
    class HeapTestInterface
        : public PriorityQueueTestInterface
    {
    protected:
        structures::PriorityQueue<int>* makePriorityQueue() override;
    };

    /// <summary>
    /// Zahrna v sebe vsetky testy, ktore testuju dany prioritny front.
    /// </summary>
    class PriorityQueueUnsortedArrayListTestOverall
        : public ComplexTest
    {
    public:
        PriorityQueueUnsortedArrayListTestOverall();
    };

    /// <summary>
    /// Zahrna v sebe vsetky testy, ktore testuju dany prioritny front.
    /// </summary>
    class PriorityQueueSortedArrayListTestOverall
        : public ComplexTest
    {
    public:
        PriorityQueueSortedArrayListTestOverall();
    };

    /// <summary>
    /// Zahrna v sebe vsetky testy, ktore testuju dany prioritny front.
    /// </summary>
    class PriorityQueueLimitedSortedArrayListTestOverall
        : public ComplexTest
    {
    public:
        PriorityQueueLimitedSortedArrayListTestOverall();
    };

    /// <summary>
    /// Zahrna v sebe vsetky testy, ktore testuju dany prioritny front.
    /// </summary>
    class PriorityQueueLinkedListTestOverall
        : public ComplexTest
    {
    public:
        PriorityQueueLinkedListTestOverall();
    };

    /// <summary>
    /// Zahrna v sebe vsetky testy, ktore testuju dany prioritny front.
    /// </summary>
    class PriorityQueueTwoListsTestOverall
        : public ComplexTest
    {
    public:
        PriorityQueueTwoListsTestOverall();
    };

    /// <summary>
    /// Zahrna v sebe vsetky testy, ktore testuju dany prioritny front.
    /// </summary>
    class HeapTestOverall
        : public ComplexTest
    {
    public:
        HeapTestOverall();
    };

    /// <summary>
    /// Zahrna v sebe vsetky testy, ktore testuju prioritny front.
    /// </summary>
    class PriorityQueueTestOverall
        : public ComplexTest
    {
    public:
        PriorityQueueTestOverall();
    };
}