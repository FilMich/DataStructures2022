#pragma once

#include "../test.h"
#include "../../structures/matrix/matrix.h"
#include "../../structures/_logger/logger.h"
#include "../../structures/_logger/file_log_consumer.h"

namespace tests
{
	class MatrixTestInterface
		: public SimpleTest
	{
	public:
		MatrixTestInterface();
		void test() override;

	protected:
		virtual structures::Matrix<int>* makeMatrix(size_t rows, size_t cols) const = 0;
	};

	class CoherentMatrixTestGetters :
		public SimpleTest
	{
	public:
		CoherentMatrixTestGetters();
		void test() override;
	};

	class IncoherentMatrixTestGetters :
		public SimpleTest
	{
	public:
		IncoherentMatrixTestGetters();
		void test() override;
	};

	class CoherentMatrixTestAt
		: public SimpleTest
	{
	public:
		CoherentMatrixTestAt();
		void test() override;
	};

	class CoherentMatrixTestCopyConstructor
		: public SimpleTest
	{
	public:
		CoherentMatrixTestCopyConstructor();
		void test() override;
	};

	class IncoherentMatrixTestCopyConstructor
		: public SimpleTest
	{
	public:
		IncoherentMatrixTestCopyConstructor();
		void test() override;
	};

	class CoherentMatrixTestAssign
		: public SimpleTest
	{
	public:
		CoherentMatrixTestAssign();
		void test() override;
	};

	class CoherentMatrixTestEquals
		: public SimpleTest
	{
	public:
		CoherentMatrixTestEquals();
		void test() override;
	};

	class CoherentMatrixTestScenarioA
		: public SimpleTest
	{
	public:
		CoherentMatrixTestScenarioA();
		void test() override;
	};

	class CoherentMatrixTestScenarioB
		: public SimpleTest
	{
	public:
		CoherentMatrixTestScenarioB();
		void test() override;
	};

	class CoherentMatrixTestScenarioC
		: public SimpleTest
	{
	public:
		CoherentMatrixTestScenarioC();
		void test() override;
	};

	class CoherentMatrixTestScenarioD
		: public SimpleTest
	{
	public:
		CoherentMatrixTestScenarioD();
		void test() override;
	};

	class IncoherentMatrixTestScenarioA
		: public SimpleTest
	{
	public:
		IncoherentMatrixTestScenarioA();
		void test() override;
	};

	class IncoherentMatrixTestScenarioB
		: public SimpleTest
	{
	public:
		IncoherentMatrixTestScenarioB();
		void test() override;
	};

	class IncoherentMatrixTestScenarioC
		: public SimpleTest
	{
	public:
		IncoherentMatrixTestScenarioC();
		void test() override;
	};

	class IncoherentMatrixTestScenarioD
		: public SimpleTest
	{
	public:
		IncoherentMatrixTestScenarioD();
		void test() override;
	};

	class IncoherentMatrixTestSpeedAt
		: public SimpleTest
	{
	public:
		IncoherentMatrixTestSpeedAt();
		void test() override;
	};

	class IncoherentMatrixTestSpeedAssign
		: public SimpleTest
	{
	public:
		IncoherentMatrixTestSpeedAssign();
		void test() override;
	};

	class CoherentMatrixTestSpeedAt
		: public SimpleTest
	{
	public:
		CoherentMatrixTestSpeedAt();
		void test() override;
	};

	class CoherentMatrixTestSpeedAssign
		: public SimpleTest
	{
	public:
		CoherentMatrixTestSpeedAssign();
		void test() override;
	};

	class IncoherentMatrixTestAt
		: public SimpleTest
	{
	public:
		IncoherentMatrixTestAt();
		void test() override;
	};

	class IncoherentMatrixTestAssign
		: public SimpleTest
	{
	public:
		IncoherentMatrixTestAssign();
		void test() override;
	};

	class IncoherentMatrixTestEquals
		: public SimpleTest
	{
	public:
		IncoherentMatrixTestEquals();
		void test() override;
	};

	class CoherentMatrixTestInterface
		: public MatrixTestInterface
	{
	protected:
		structures::Matrix<int>* makeMatrix(size_t rows, size_t cols) const override;
	};

	class IncoherentMatrixTestInterface
		: public MatrixTestInterface
	{
	protected:
		structures::Matrix<int>* makeMatrix(size_t rows, size_t cols) const override;
	};

	class CoherentMatrixTestOverall
		: public ComplexTest
	{
	public:
		CoherentMatrixTestOverall();
	};

	class IncoherentMatrixTestOverall
		: public ComplexTest
	{
	public:
		IncoherentMatrixTestOverall();
	};

	class MatrixTestOverall
		: public ComplexTest
	{
	public:
		MatrixTestOverall();
	};
}