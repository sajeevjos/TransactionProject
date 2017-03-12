#ifndef TRANSACTIONTEST_H
#define TRANSACTIONTEST_H

#include <cppunit/extensions/HelperMacros.h>

class TransactionTest : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(TransactionTest);
	CPPUNIT_TEST(testConstructor);
	CPPUNIT_TEST(testProcess);
	CPPUNIT_TEST(testIsHoliday);
	CPPUNIT_TEST(testProcessWithInstructionDateAsHoliday);
	CPPUNIT_TEST(testIsHolidayWithHoliday);
	CPPUNIT_TEST_SUITE_END();

public:
	void setUp();
	void tearDown();
	void testProcess();
	void testIsHoliday();
	void testConstructor();
	void testProcessWithInstructionDateAsHoliday();
	void testIsHolidayWithHoliday();
};

#endif  // TRANSACTIONTEST_H