#ifndef TRANSACTIONSTORETEST_H
#define TRANSACTIONSTORETEST_H

#include <cppunit/extensions/HelperMacros.h>


class TransactionStoreTest : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(TransactionStoreTest);
	CPPUNIT_TEST(testConstructor);
	CPPUNIT_TEST(testAddTransaction);
	CPPUNIT_TEST(testtotalIncoming);
	CPPUNIT_TEST(testtotalOutGoing);
	CPPUNIT_TEST(testProcess);
	CPPUNIT_TEST(testProcessTransactions);
	CPPUNIT_TEST_SUITE_END();

public:
	void setUp();
	void tearDown();
	void testConstructor();
	void testProcess();
	void testtotalIncoming();
	void testtotalOutGoing();
	void testAddTransaction();
	void testProcessTransactions();
};

#endif  // TRANSACTIONSTORETEST_H