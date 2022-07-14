#include "matrix_test.h"
#include "../../structures/matrix/coherent_matrix.h"
#include "../../structures/matrix/incoherent_matrix.h"
#include <stdlib.h>

namespace tests
{
	tests::MatrixTestInterface::MatrixTestInterface() :
		SimpleTest("Interface")
	{
	}

	void tests::MatrixTestInterface::test()
	{
		structures::Matrix<int>* matrix = this->makeMatrix(20, 20);
		matrix->assign(*matrix);
		matrix->equals(*matrix);
		matrix->size();
		matrix->isEmpty();
		matrix->getRowCount();
		matrix->getColumnCount();
		matrix->at(10, 10);
		delete matrix;
		this->logPass("Compiled");
	}

	structures::Matrix<int>* CoherentMatrixTestInterface::makeMatrix(size_t rows, size_t cols) const
	{
		return new structures::CoherentMatrix<int>(rows, cols);
	}

	structures::Matrix<int>* IncoherentMatrixTestInterface::makeMatrix(size_t rows, size_t cols) const
	{
		return new structures::IncoherentMatrix<int>(rows, cols);
	}

	CoherentMatrixTestOverall::CoherentMatrixTestOverall() :
		ComplexTest("CoherentMatrix")
	{
		addTest(new CoherentMatrixTestInterface());
		addTest(new CoherentMatrixTestGetters);
		addTest(new CoherentMatrixTestCopyConstructor);
		addTest(new CoherentMatrixTestAt());
		addTest(new CoherentMatrixTestAssign());
		addTest(new CoherentMatrixTestEquals());
		addTest(new CoherentMatrixTestScenarioA());
		addTest(new CoherentMatrixTestScenarioB());
		addTest(new CoherentMatrixTestScenarioC());
		addTest(new CoherentMatrixTestScenarioD());
		addTest(new CoherentMatrixTestSpeedAt());
		addTest(new CoherentMatrixTestSpeedAssign);
	}

	IncoherentMatrixTestOverall::IncoherentMatrixTestOverall() :
		ComplexTest("IncoherentMatrix")
	{
		addTest(new IncoherentMatrixTestInterface());
		addTest(new IncoherentMatrixTestGetters);
		addTest(new IncoherentMatrixTestCopyConstructor);
		addTest(new IncoherentMatrixTestAt());
		addTest(new IncoherentMatrixTestAssign());
		addTest(new IncoherentMatrixTestEquals());
		addTest(new IncoherentMatrixTestScenarioA());
		addTest(new IncoherentMatrixTestScenarioB());
		addTest(new IncoherentMatrixTestScenarioC());
		addTest(new IncoherentMatrixTestScenarioD());
		addTest(new IncoherentMatrixTestSpeedAt());
		addTest(new IncoherentMatrixTestSpeedAssign);
	}

	MatrixTestOverall::MatrixTestOverall() :
		ComplexTest("Matrix")
	{
		addTest(new CoherentMatrixTestOverall());
		addTest(new IncoherentMatrixTestOverall());
	}

	CoherentMatrixTestCopyConstructor::CoherentMatrixTestCopyConstructor() :
		SimpleTest("TestCopyConstructor")
	{
	}
	void CoherentMatrixTestCopyConstructor::test()
	{
		structures::CoherentMatrix<int>* otherCohMatrix = new structures::CoherentMatrix<int>(2, 2);

		for (int i = 0; i < otherCohMatrix->getRowCount(); i++)
		{
			for (int j = 0; j < otherCohMatrix->getColumnCount(); j++)
			{
				otherCohMatrix->at(i, j) = i + j;
			}
		}
		structures::CoherentMatrix<int>* cohMatrix = new structures::CoherentMatrix<int>(*otherCohMatrix);
		SimpleTest::assertTrue(cohMatrix->equals(*otherCohMatrix), " incohMatrix->equals(*otherCohMatrix) ");

		delete cohMatrix;
		delete otherCohMatrix;
	}

	IncoherentMatrixTestCopyConstructor::IncoherentMatrixTestCopyConstructor() :
		SimpleTest("TestCopyConstructor")
	{
	}
	void IncoherentMatrixTestCopyConstructor::test()
	{
		
		structures::IncoherentMatrix<int>* otherIncohMatrix = new structures::IncoherentMatrix<int>(2, 2);

		for (int i = 0; i < otherIncohMatrix->getRowCount(); i++)
		{
			for (int j = 0; j < otherIncohMatrix->getColumnCount(); j++)
			{
				otherIncohMatrix->at(i, j) = i + j;
			}
		}
		structures::IncoherentMatrix<int>* incohMatrix = new structures::IncoherentMatrix<int>(*otherIncohMatrix);
		SimpleTest::assertTrue(incohMatrix->equals(*otherIncohMatrix), " incohMatrix->equals(*otherIncohMatrix) ");

		delete incohMatrix;
		delete otherIncohMatrix;
	}

	CoherentMatrixTestAt::CoherentMatrixTestAt() :
		SimpleTest("TestAt")
	{
	}
	void CoherentMatrixTestAt::test()
	{
		structures::CoherentMatrix<int>* cohMatrix = new structures::CoherentMatrix<int>(2, 2);
		for (int i = 0; i < cohMatrix->getRowCount(); i++)
		{
			for (int j = 0; j < cohMatrix->getColumnCount(); j++)
			{
				cohMatrix->at(i, j) = i + j;
				SimpleTest::assertTrue(cohMatrix->at(i, j) == i + j, " cohMatrix->at(i, j) = " + std::to_string(cohMatrix->at(i, j)) + " == i + j " + std::to_string(i + j));
			}
		}

		delete cohMatrix;
	}

	CoherentMatrixTestAssign::CoherentMatrixTestAssign() :
		SimpleTest("TestAssign")
	{
	}
	void CoherentMatrixTestAssign::test()
	{
		structures::CoherentMatrix<int>* cohMatrix = new structures::CoherentMatrix<int>(2, 2);
		structures::CoherentMatrix<int>* otherCohMatrix = new structures::CoherentMatrix<int>(2, 2);
		for (int i = 0; i < cohMatrix->getRowCount(); i++)
		{
			for (int j = 0; j < cohMatrix->getColumnCount(); j++)
			{
				cohMatrix->at(i, j) = 0;
				otherCohMatrix->at(i, j) = i + j;
				
			}
		}

		SimpleTest::assertFalse(cohMatrix->equals(*otherCohMatrix));
		cohMatrix->assign(*otherCohMatrix);
		SimpleTest::assertTrue(cohMatrix->equals(*otherCohMatrix), " incohMatrix->equals(*otherCohMatrix) ");

		delete cohMatrix;
		delete otherCohMatrix;
	}
	CoherentMatrixTestEquals::CoherentMatrixTestEquals() :
		SimpleTest("TestEquals")
	{

	}
	void CoherentMatrixTestEquals::test()
	{
		structures::CoherentMatrix<int>* cohMatrix = new structures::CoherentMatrix<int>(2, 2);
		structures::CoherentMatrix<int>* otherCohMatrix = new structures::CoherentMatrix<int>(2, 2);
		structures::CoherentMatrix<int>* badOtherCohMatrix = new structures::CoherentMatrix<int>(2, 2);
		structures::Array<int>* nullptrCohMatrix = new structures::Array<int>(2);
		structures::CoherentMatrix<int>* sizeOtherCohMatrix = new structures::CoherentMatrix<int>(1, 3);

		for (int i = 0; i < cohMatrix->getRowCount(); i++)
		{
			for (int j = 0; j < otherCohMatrix->getColumnCount(); j++)
			{
				cohMatrix->at(i, j) = i + j;
				otherCohMatrix->at(i, j) = i + j;
				badOtherCohMatrix->at(i, j) = i;
			}
		}

		for (int i = 0; i < sizeOtherCohMatrix->getRowCount(); i++)
		{
			for (int j = 0; j < sizeOtherCohMatrix->getColumnCount(); j++)
			{
				sizeOtherCohMatrix->at(i, j) = i + j;
			}
		}

		SimpleTest::assertTrue(cohMatrix->equals(*otherCohMatrix), " incohMatrix->equals(*otherIncohMatrix)");
		SimpleTest::assertFalse(cohMatrix->equals(*badOtherCohMatrix), " cohMatrix->equals(*otherCohMatrix) ");
		SimpleTest::assertFalse(cohMatrix->equals(*sizeOtherCohMatrix), " cohMatrix->equals(*sizeOtherCohMatrix)");
		SimpleTest::assertFalse(cohMatrix->equals(*nullptrCohMatrix), " cohMatrix->equals(*nullptrCohMatrix)");

		delete cohMatrix;
		delete otherCohMatrix;
		delete badOtherCohMatrix;
		delete nullptrCohMatrix;
		delete sizeOtherCohMatrix;
	}

	IncoherentMatrixTestAt::IncoherentMatrixTestAt() :
		SimpleTest("TestAt")
	{
	}
	void IncoherentMatrixTestAt::test()
	{
		structures::IncoherentMatrix<int>* incohMatrix = new structures::IncoherentMatrix<int>(2, 2);
		for (int i = 0; i < incohMatrix->getRowCount(); i++)
		{
			for (int j = 0; j < incohMatrix->getColumnCount(); j++)
			{
				incohMatrix->at(i, j) = i + j;
				SimpleTest::assertTrue(incohMatrix->at(i, j) == i + j, " cohMatrix->at(i, j) = " + std::to_string(incohMatrix->at(i, j)) + " == i + j " + std::to_string(i + j));
			}
		}

		delete incohMatrix;
	}

	IncoherentMatrixTestAssign::IncoherentMatrixTestAssign() :
		SimpleTest("TestAssign")
	{
	}
	void IncoherentMatrixTestAssign::test()
	{
		structures::IncoherentMatrix<int>* incohMatrix = new structures::IncoherentMatrix<int>(2, 2);
		structures::IncoherentMatrix<int>* otherIncohMatrix = new structures::IncoherentMatrix<int>(2, 2);
		for (int i = 0; i < incohMatrix->getRowCount(); i++)
		{
			for (int j = 0; j < incohMatrix->getColumnCount(); j++)
			{
				incohMatrix->at(i, j) = 0;
				otherIncohMatrix->at(i, j) = i + j;
				
			}
		}

		SimpleTest::assertFalse(incohMatrix->equals(*otherIncohMatrix));
		incohMatrix->assign(*otherIncohMatrix);
		SimpleTest::assertTrue(incohMatrix->equals(*otherIncohMatrix), " incohMatrix->equals(*otherIncohMatrix) " );

		delete incohMatrix;
		delete otherIncohMatrix;
	}
	IncoherentMatrixTestEquals::IncoherentMatrixTestEquals() :
		SimpleTest("TestEquals")
	{

	}
	void IncoherentMatrixTestEquals::test()
	{
		structures::IncoherentMatrix<int>* incohMatrix = new structures::IncoherentMatrix<int>(2, 2);
		structures::IncoherentMatrix<int>* otherIncohMatrix = new structures::IncoherentMatrix<int>(2, 2);
		structures::IncoherentMatrix<int>* badOtherIncohMatrix = new structures::IncoherentMatrix<int>(2, 2);
		structures::Array<int>* nullptrIncohMatrix = new structures::Array<int>(2);
		structures::IncoherentMatrix<int>* sizeOtherIncohMatrix = new structures::IncoherentMatrix<int>(1, 3);
		for (int i = 0; i < incohMatrix->getRowCount(); i++)
		{
			for (int j = 0; j < incohMatrix->getColumnCount(); j++)
			{
				incohMatrix->at(i, j) = i + j;
				otherIncohMatrix->at(i, j) = i + j;
				badOtherIncohMatrix->at(i, j) = i;
			}
		}

		for (int i = 0; i < sizeOtherIncohMatrix->getRowCount(); i++)
		{
			for (int j = 0; j < sizeOtherIncohMatrix->getColumnCount(); j++)
			{
				sizeOtherIncohMatrix->at(i, j) = i + j;
			}
		}

		SimpleTest::assertTrue(incohMatrix->equals(*otherIncohMatrix), " incohMatrix->equals(*otherIncohMatrix)");
		SimpleTest::assertFalse(incohMatrix->equals(*badOtherIncohMatrix), " incohMatrix->equals(*badOtherIncohMatrix)");
		SimpleTest::assertFalse(incohMatrix->equals(*sizeOtherIncohMatrix), " incohMatrix->equals(*sizeOtherIncohMatrix)");
		SimpleTest::assertFalse(incohMatrix->equals(*nullptrIncohMatrix), " incohMatrix->equals(*nullOtherIncohMatrix)");

		delete incohMatrix;
		delete otherIncohMatrix;
		delete badOtherIncohMatrix;
		delete nullptrIncohMatrix;
		delete sizeOtherIncohMatrix;
	}

	CoherentMatrixTestScenarioA::CoherentMatrixTestScenarioA() :
		SimpleTest("TestScenarioA")
	{
	}
	void CoherentMatrixTestScenarioA::test()
	{
		srand(time(NULL));
		structures::CoherentMatrix<int>* cohMatrix = new structures::CoherentMatrix<int>(10, 50);
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 50; j++)
			{
				cohMatrix->at(i, j) = i + j;
			}
		}
		int ratioCount1 = 0;
		int ratioCount2 = 0;
		int ratioCount3 = 0;
		int randColumnIndex = 0;
		int randRowIndex = 0;
		int ratio = 0;

		auto cas = DurationType(0);
		
		for (int i = 0; i < (1000000); i++)
		{
			ratio = rand() % 3 + 1;
			if (ratio == 1 && ratioCount1 < 50000)
			{
				this->startStopwatch();
				cohMatrix->getRowCount();
				this->stopStopwatch();
				cas += this->getElapsedTime();
				ratioCount1++;
			}
			else if (ratio == 2 && ratioCount2 < 50000)
			{
				this->startStopwatch();
				cohMatrix->getColumnCount();
				this->stopStopwatch();
				cas += this->getElapsedTime();
				ratioCount2++;
			}
			else
			{
				this->startStopwatch();
				cohMatrix->at(randRowIndex, randColumnIndex);
				this->stopStopwatch();
				cas += this->getElapsedTime();
				ratioCount3++;
			}
		}
		this->logInfo("TestScenarioA " + std::to_string(cas.count()) + " ns");
		structures::Logger::getInstance().logDuration(cohMatrix->size() , cas, " CohTestScenarioA");
		delete cohMatrix;
	}

	CoherentMatrixTestScenarioB::CoherentMatrixTestScenarioB() :
		SimpleTest("TestScenarioB")
	{
	}
	void CoherentMatrixTestScenarioB::test()
	{
		srand(time(NULL));
		structures::CoherentMatrix<int>* cohMatrix = new structures::CoherentMatrix<int>(2000, 500);
		for (int i = 0; i < 2000; i++)
		{
			for (int j = 0; j < 500; j++)
			{
				cohMatrix->at(i, j) = i + j;
			}
		}
		auto cas = tests::DurationType(0);
		int ratioCount1 = 0;
		int ratioCount2 = 0;
		int ratioCount3 = 0;
		int randColumnIndex = 0;
		int randRowIndex = 0;
		int ratio = 0;
		for (int i = 0; i < (1000000); i++)
		{
			randColumnIndex = rand() % cohMatrix->getColumnCount();
			randRowIndex = rand() % cohMatrix->getRowCount();
			ratio = rand() % 3 + 1;
			if (ratio == 1 && ratioCount1 < 50000)
			{
				this->startStopwatch();
				cohMatrix->getRowCount();
				this->stopStopwatch();
				cas += this->getElapsedTime();
				ratioCount1++;
			}
			else if (ratio == 2 && ratioCount2 < 50000)
			{
				this->startStopwatch();
				cohMatrix->getColumnCount();
				this->stopStopwatch();
				cas += this->getElapsedTime();
				ratioCount2++;
			}
			else
			{
				this->startStopwatch();
				cohMatrix->at(randRowIndex, randColumnIndex);
				this->stopStopwatch();
				cas += this->getElapsedTime();
				ratioCount3++;
			}
		}

		this->logInfo("TestScenarioB " + std::to_string(cas.count()) + " ns");
		structures::Logger::getInstance().logDuration(cohMatrix->size(), cas, " CohTestScenarioB");
		delete cohMatrix;
	}

	CoherentMatrixTestScenarioC::CoherentMatrixTestScenarioC() :
		SimpleTest("TestScenarioC")
	{
	}
	void CoherentMatrixTestScenarioC::test()
	{
		srand(time(NULL));
		structures::CoherentMatrix<int>* cohMatrix = new structures::CoherentMatrix<int>(50, 10);
		for (int i = 0; i < 50; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				cohMatrix->at(i, j) = i + j;
			}
		}
		int ratioCount1 = 0;
		int ratioCount2 = 0;
		int ratioCount3 = 0;
		int randColumnIndex = 0;
		int randRowIndex = 0;
		int ratio = 0;
		auto cas = tests::DurationType(0);
		for (int i = 0; i < (1000000); i++)
		{
			randColumnIndex = rand() % cohMatrix->getColumnCount();
			randRowIndex = rand() % cohMatrix->getRowCount();
			ratio = rand() % 3 + 1;
			if (ratio == 1 && ratioCount1 < 10000)
			{
				this->startStopwatch();
				cohMatrix->getRowCount();
				this->stopStopwatch();
				cas += this->getElapsedTime();
				ratioCount1++;
			}
			else if (ratio == 2 && ratioCount2 < 30000)
			{
				this->startStopwatch();
				cohMatrix->getColumnCount();
				this->stopStopwatch();
				cas += this->getElapsedTime();
				ratioCount2++;
			}
			else
			{
				this->startStopwatch();
				cohMatrix->at(randRowIndex, randColumnIndex);
				this->stopStopwatch();
				cas += this->getElapsedTime();
				ratioCount3++;
			}
		}

		this->logInfo("TestScenarioC " + std::to_string(cas.count()) + " ns");
		structures::Logger::getInstance().logDuration(cohMatrix->size(), cas, " CohTestScenarioC");
		delete cohMatrix;
	}

	CoherentMatrixTestScenarioD::CoherentMatrixTestScenarioD() :
		SimpleTest("TestScenarioD")
	{
	}
	void CoherentMatrixTestScenarioD::test()
	{
		srand(time(NULL));
		structures::CoherentMatrix<int>* cohMatrix = new structures::CoherentMatrix<int>(500, 2000);
		for (int i = 0; i < 500; i++)
		{
			for (int j = 0; j < 2000; j++)
			{
				cohMatrix->at(i, j) = i + j;
			}
		}
		int ratioCount1 = 0;
		int ratioCount2 = 0;
		int ratioCount3 = 0;
		int randColumnIndex = 0;
		int randRowIndex = 0;
		int ratio = 0;
		auto cas = tests::DurationType(0);
		for (int i = 0; i < (1000000); i++)
		{
			randColumnIndex = rand() % cohMatrix->getColumnCount();
			randRowIndex = rand() % cohMatrix->getRowCount();
			ratio = rand() % 3 + 1;
			if (ratio == 1 && ratioCount1 < 1000)
			{
				this->startStopwatch();
				cohMatrix->getRowCount();
				this->stopStopwatch();
				cas += this->getElapsedTime();
				ratioCount1++;
			}
			else if (ratio == 2 && ratioCount2 < 30000)
			{
				this->startStopwatch();
				cohMatrix->getColumnCount();
				this->stopStopwatch();
				cas += this->getElapsedTime();
				ratioCount2++;
			}
			else
			{
				this->startStopwatch();
				cohMatrix->at(randRowIndex, randColumnIndex);
				this->stopStopwatch();
				cas += this->getElapsedTime();
				ratioCount3++;
			}
		}

		this->logInfo("TestScenarioD " + std::to_string(cas.count()) + " ns");
		structures::Logger::getInstance().logDuration(cohMatrix->size(), cas, " CohTestScenarioD");
		delete cohMatrix;
	}

	IncoherentMatrixTestScenarioA::IncoherentMatrixTestScenarioA() :
		SimpleTest("TestScenarioA")
	{
	}
	void IncoherentMatrixTestScenarioA::test()
	{
		srand(time(NULL));
		structures::IncoherentMatrix<int>* incohMatrix = new structures::IncoherentMatrix<int>(10, 50);
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 50; j++)
			{
				incohMatrix->at(i, j) = i + j;
			}
		}
		int ratioCount1 = 0;
		int ratioCount2 = 0;
		int ratioCount3 = 0;
		int randColumnIndex = 0;
		int randRowIndex = 0;
		int ratio = 0;

		auto cas = tests::DurationType(0);

		for (int i = 0; i < (1000000); i++)
		{
			ratio = rand() % 3 + 1;
			if (ratio == 1 && ratioCount1 < 50000)
			{
				this->startStopwatch();
				incohMatrix->getRowCount();
				this->stopStopwatch();
				cas += this->getElapsedTime();
				ratioCount1++;
			}
			else if (ratio == 2 && ratioCount2 < 50000)
			{
				this->startStopwatch();
				incohMatrix->getColumnCount();
				this->stopStopwatch();
				cas += this->getElapsedTime();
				ratioCount2++;
			}
			else
			{
				this->startStopwatch();
				incohMatrix->at(randRowIndex, randColumnIndex);
				this->stopStopwatch();
				cas += this->getElapsedTime();
				ratioCount3++;
			}
		}
		this->logInfo("TestScenarioA " + std::to_string(cas.count()) + " ns");
		structures::Logger::getInstance().logDuration(incohMatrix->size(), cas, " IncohTestScenarioA");
		delete incohMatrix;
	}

	IncoherentMatrixTestScenarioB::IncoherentMatrixTestScenarioB() :
		SimpleTest("TestScenarioB")
	{
	}
	void IncoherentMatrixTestScenarioB::test()
	{
		srand(time(NULL));
		structures::IncoherentMatrix<int>* incohMatrix = new structures::IncoherentMatrix<int>(2000, 500);
		for (int i = 0; i < 2000; i++)
		{
			for (int j = 0; j < 500; j++)
			{
				incohMatrix->at(i, j) = i + j;
			}
		}
		auto cas = tests::DurationType(0);
		int ratioCount1 = 0;
		int ratioCount2 = 0;
		int ratioCount3 = 0;
		int randColumnIndex = 0;
		int randRowIndex = 0;
		int ratio = 0;
		for (int i = 0; i < (1000000); i++)
		{
			randColumnIndex = rand() % incohMatrix->getColumnCount();
			randRowIndex = rand() % incohMatrix->getRowCount();
			ratio = rand() % 3 + 1;
			if (ratio == 1 && ratioCount1 < 50000)
			{
				this->startStopwatch();
				incohMatrix->getRowCount();
				this->stopStopwatch();
				cas += this->getElapsedTime();
				ratioCount1++;
			}
			else if (ratio == 2 && ratioCount2 < 50000)
			{
				this->startStopwatch();
				incohMatrix->getColumnCount();
				this->stopStopwatch();
				cas += this->getElapsedTime();
				ratioCount2++;
			}
			else
			{
				this->startStopwatch();
				incohMatrix->at(randRowIndex, randColumnIndex);
				this->stopStopwatch();
				cas += this->getElapsedTime();
				ratioCount3++;
			}
		}

		this->logInfo("TestScenarioB " + std::to_string(cas.count()) + " ns");
		structures::Logger::getInstance().logDuration(incohMatrix->size(), cas, " IncohTestScenarioB");
		delete incohMatrix;
	}

	IncoherentMatrixTestScenarioC::IncoherentMatrixTestScenarioC() :
		SimpleTest("TestScenarioC")
	{
	}
	void IncoherentMatrixTestScenarioC::test()
	{
		srand(time(NULL));
		structures::IncoherentMatrix<int>* incohMatrix = new structures::IncoherentMatrix<int>(50, 10);
		for (int i = 0; i < 50; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				incohMatrix->at(i, j) = i + j;
			}
		}
		int ratioCount1 = 0;
		int ratioCount2 = 0;
		int ratioCount3 = 0;
		int randColumnIndex = 0;
		int randRowIndex = 0;
		int ratio = 0;
		auto cas = tests::DurationType(0);
		for (int i = 0; i < (1000000); i++)
		{
			randColumnIndex = rand() % incohMatrix->getColumnCount();
			randRowIndex = rand() % incohMatrix->getRowCount();
			ratio = rand() % 3 + 1;
			if (ratio == 1 && ratioCount1 < 10000)
			{
				this->startStopwatch();
				incohMatrix->getRowCount();
				this->stopStopwatch();
				cas += this->getElapsedTime();
				ratioCount1++;
			}
			else if (ratio == 2 && ratioCount2 < 30000)
			{
				this->startStopwatch();
				incohMatrix->getColumnCount();
				this->stopStopwatch();
				cas += this->getElapsedTime();
				ratioCount2++;
			}
			else
			{
				this->startStopwatch();
				incohMatrix->at(randRowIndex, randColumnIndex);
				this->stopStopwatch();
				cas += this->getElapsedTime();
				ratioCount3++;
			}
		}

		this->logInfo("TestScenarioC " + std::to_string(cas.count()) + " ns");
		structures::Logger::getInstance().logDuration(incohMatrix->size(), cas, " IncohTestScenarioC");
		delete incohMatrix;
	}

	IncoherentMatrixTestScenarioD::IncoherentMatrixTestScenarioD() :
		SimpleTest("TestScenarioD")
	{
	}
	void IncoherentMatrixTestScenarioD::test()
	{
		srand(time(NULL));
		structures::IncoherentMatrix<int>* incohMatrix = new structures::IncoherentMatrix<int>(500, 2000);
		for (int i = 0; i < 500; i++)
		{
			for (int j = 0; j < 2000; j++)
			{
				incohMatrix->at(i, j) = i + j;
			}
		}
		int ratioCount1 = 0;
		int ratioCount2 = 0;
		int ratioCount3 = 0;
		int randColumnIndex = 0;
		int randRowIndex = 0;
		int ratio = 0;
		auto cas = tests::DurationType(0);
		for (int i = 0; i < (1000000); i++)
		{
			randColumnIndex = rand() % incohMatrix->getColumnCount();
			randRowIndex = rand() % incohMatrix->getRowCount();
			ratio = rand() % 3 + 1;
			if (ratio == 1 && ratioCount1 < 1000)
			{
				this->startStopwatch();
				incohMatrix->getRowCount();
				this->stopStopwatch();
				cas += this->getElapsedTime();
				ratioCount1++;
			}
			else if (ratio == 2 && ratioCount2 < 30000)
			{
				this->startStopwatch();
				incohMatrix->getColumnCount();
				this->stopStopwatch();
				cas += this->getElapsedTime();
				ratioCount2++;
			}
			else
			{
				this->startStopwatch();
				incohMatrix->at(randRowIndex, randColumnIndex);
				this->stopStopwatch();
				cas += this->getElapsedTime();
				ratioCount3++;
			}
		}

		this->logInfo("TestScenarioD " + std::to_string(cas.count()) + " ns");
		structures::Logger::getInstance().logDuration(incohMatrix->size(), cas, " IncohTestScenarioD");
		delete incohMatrix;
	}

	IncoherentMatrixTestSpeedAt::IncoherentMatrixTestSpeedAt() :
		SimpleTest("TestIncoherentMatrixTestSpeedAt")
	{
	}

	void IncoherentMatrixTestSpeedAt::test()
	{
		std::ofstream fileStreamIncoh_("IncohSpeedTestAt.csv");
		if (!fileStreamIncoh_.is_open()) {
			throw std::invalid_argument("FileLogConsumer::FileLogConsumer: Failed to open the file");
		}

		srand(time(NULL));
		int randColumnIndex = 0;
		int randRowIndex = 0;
		auto cas = DurationType(0);
		for (int i = 1; i < 1001; i += 100)
		{
			for (int j = 1; j < 1001; j += 100)
			{
				structures::IncoherentMatrix<int>* incohMatrix = new structures::IncoherentMatrix<int>(i, j);

				for (int k = 0; k < 100; k++)
				{
					randColumnIndex = rand() % incohMatrix->getColumnCount();
					randRowIndex = rand() % incohMatrix->getRowCount();
					this->startStopwatch();
					incohMatrix->at(randRowIndex, randColumnIndex);
					this->stopStopwatch();
					cas += this->getElapsedTime();
				}
				fileStreamIncoh_ << cas.count() / 100 << ";";
				//this->logInfo("IncohSpeedTestAt " + std::to_string(cas.count()) + " ns");
				delete incohMatrix;
				cas = DurationType(0);

			}
			fileStreamIncoh_ << std::endl;
		}
		fileStreamIncoh_.close();
	}

	IncoherentMatrixTestSpeedAssign::IncoherentMatrixTestSpeedAssign() :
		SimpleTest("TestIncoherentMatrixTestSpeedAssign")
	{
	}

	void IncoherentMatrixTestSpeedAssign::test()
	{
		std::ofstream fileStreamIncoh_("IncohSpeedTestAssign.csv");
		if (!fileStreamIncoh_.is_open()) {
			throw std::invalid_argument("FileLogConsumer::FileLogConsumer: Failed to open the file");
		}

		srand(time(NULL));
		int randColumnIndex = 0;
		int randRowIndex = 0;
		auto cas = DurationType(0);
		for (int i = 1; i < 1001; i += 100)
		{
			for (int j = 1; j < 1001; j += 100)
			{
				structures::IncoherentMatrix<int>* incohMatrix = new structures::IncoherentMatrix<int>(i, j);
				structures::IncoherentMatrix<int>* OtherIncohMatrix = new structures::IncoherentMatrix<int>(i, j);

				for (int k = 0; k < 100; k++)
				{
					randColumnIndex = rand() % incohMatrix->getColumnCount();
					randRowIndex = rand() % incohMatrix->getRowCount();
					this->startStopwatch();
					incohMatrix->assign(*OtherIncohMatrix);
					this->stopStopwatch();
					cas += this->getElapsedTime();
				}
				fileStreamIncoh_ << cas.count() / 100 << ";";
				//this->logInfo("IncohSpeedTestAssign " + std::to_string(cas.count()) + " ns");
				delete incohMatrix;
				delete OtherIncohMatrix;
				cas = DurationType(0);

			}
			fileStreamIncoh_ << std::endl;
		}
		fileStreamIncoh_.close();
	}

	CoherentMatrixTestSpeedAt::CoherentMatrixTestSpeedAt() :
		SimpleTest("TestCoherentMatrixTestSpeedAt")
	{
	}

	void CoherentMatrixTestSpeedAt::test()
	{
		std::ofstream fileStreamCoh_("CohSpeedTestAt.csv");
		if (!fileStreamCoh_.is_open()) {
			throw std::invalid_argument("FileLogConsumer::FileLogConsumer: Failed to open the file");
		}
		srand(time(NULL));
		int randColumnIndex = 0;
		int randRowIndex = 0;
		auto cas = DurationType(0);
		for (int i = 1; i < 1001; i += 100)
		{
			for (int j = 1; j < 1001; j += 100)
			{
				structures::CoherentMatrix<int>* cohMatrix = new structures::CoherentMatrix<int>(i, j);

				for (int k = 0; k < 100; k++)
				{
					randColumnIndex = rand() % cohMatrix->getColumnCount();
					randRowIndex = rand() % cohMatrix->getRowCount();
					this->startStopwatch();
					cohMatrix->at(randRowIndex, randColumnIndex);
					this->stopStopwatch();
					cas += this->getElapsedTime();
				}
				fileStreamCoh_ << cas.count() / 100 << ";";
				//this->logInfo("CohSpeedTestAt " + std::to_string(cas.count()) + " ns");
				delete cohMatrix;
				cas = DurationType(0);

			}
			fileStreamCoh_ << std::endl;
		}
		fileStreamCoh_.close();
	}

	CoherentMatrixTestSpeedAssign::CoherentMatrixTestSpeedAssign() :
		SimpleTest("TestCoherentMatrixTestSpeedAssign")
	{
	}

	void CoherentMatrixTestSpeedAssign::test()
	{
		std::ofstream fileStreamCoh_("CohSpeedTestAssign.csv");
		if (!fileStreamCoh_.is_open()) {
			throw std::invalid_argument("FileLogConsumer::FileLogConsumer: Failed to open the file");
		}
		srand(time(NULL));
		int randColumnIndex = 0;
		int randRowIndex = 0;
		auto cas = DurationType(0);
		for (int i = 1; i < 1001; i += 100)
		{
			for (int j = 1; j < 1001; j += 100)
			{
				structures::CoherentMatrix<int>* cohMatrix = new structures::CoherentMatrix<int>(i, j);
				structures::CoherentMatrix<int>* OtherCohMatrix = new structures::CoherentMatrix<int>(i, j);

				for (int k = 0; k < 100; k++)
				{
					randColumnIndex = rand() % cohMatrix->getColumnCount();
					randRowIndex = rand() % cohMatrix->getRowCount();
					this->startStopwatch();
					cohMatrix->assign(*OtherCohMatrix);
					this->stopStopwatch();
					cas += this->getElapsedTime();
				}
				fileStreamCoh_ << cas.count() / 100 << ";";
				//this->logInfo("CohSpeedTestAssign " + std::to_string(cas.count()) + " ns");
				delete cohMatrix;
				delete OtherCohMatrix;
				cas = DurationType(0);

			}
			fileStreamCoh_ << std::endl;
		}
		fileStreamCoh_.close();
	}

	CoherentMatrixTestGetters::CoherentMatrixTestGetters() :
		SimpleTest(" CoherentMatrixTestGetters ")
	{
	}

	void CoherentMatrixTestGetters::test()
	{
		int row = 2;
		int column = 2;

		structures::CoherentMatrix<int>* cohMatrix = new structures::CoherentMatrix<int>(row, column);

		SimpleTest::assertTrue(cohMatrix->getRowCount() == row, " cohMatrix->getRowCount() == row");
		SimpleTest::assertTrue(cohMatrix->getColumnCount() == column, " cohMatrix->getColumnCount() == column");
		delete cohMatrix;
	}

	IncoherentMatrixTestGetters::IncoherentMatrixTestGetters() :
		SimpleTest(" IncoherentMatrixTestGetters ")
	{
	}

	void IncoherentMatrixTestGetters::test()
	{
		int row = 2;
		int column = 2;

		structures::IncoherentMatrix<int>* incohMatrix = new structures::IncoherentMatrix<int>(row, column);

		SimpleTest::assertTrue(incohMatrix->getRowCount() == row, " incohMatrix->getRowCount() == row");
		SimpleTest::assertTrue(incohMatrix->getColumnCount() == column, " incohMatrix->getColumnCount() == column");
		delete incohMatrix;
	}

}