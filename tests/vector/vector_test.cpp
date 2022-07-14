#include "vector_test.h"
#include "../../structures/vector/vector.h"

namespace tests
{
// VectorTestInterface:

    VectorTestInterface::VectorTestInterface() :
        SimpleTest("Interface")
    {
    }

    void VectorTestInterface::test()
    {
        structures::Vector* vector = new structures::Vector(10);
        vector->size();
        vector->assign(*vector);
        vector->equals(*vector);
        vector->at(0);
        vector->getBytePointer(0);
        structures::Vector::copy(*vector, 0, *vector, 0, 1);
        delete vector;
        SimpleTest::logPass("Compiled.");
    }



// VectorTestOverall:

    VectorTestOverall::VectorTestOverall() :
        ComplexTest("Vector")
    {
        this->addTest(new VectorTestInterface());
        this->addTest(new VectorTestAt());
    }

    VectorTestAt::VectorTestAt() :
        SimpleTest("At")
    {

    }
        
    void VectorTestAt::test()
    {
        structures::Vector* vector = new structures::Vector(10);
        this->assertTrue(vector->size() == 10, "vector->size() == 10");
        for (int i = 0; i < vector->size(); i++)
        {
            vector->at(i) = i;
        }
        for (int i = 0; i < vector->size(); i++)
        {
            this->assertTrue(vector->at(i) == i, "vector->at(" + std::to_string(i) + ") == " + std::to_string(i));
        }
        for (int i = 0; i < vector->size(); i++)
        {
            this->assertTrue(*vector->getBytePointer(i) == i, "*vector->getBytePointer(" + std::to_string(i) + ") == " + std::to_string(i));
        }
    }
}