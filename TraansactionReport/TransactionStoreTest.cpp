#include "stdafx.h"
#include "TransactionStoreTest.h"
#include "TransactionStore.h"
#include <boost\date_time\posix_time\posix_time.hpp>
#include <ctime>


// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(TransactionStoreTest);

//map<string, vector<string> > currencyToHolidayMap;


using namespace std;
using namespace TransactionReport;
using namespace boost::posix_time;

void
TransactionStoreTest::setUp()
{
	//Holidays::Initialise();
	//map<string, vector<string> > currencyToHolidayMapTemp;
	//currencyToHolidayMapTemp["SGP"].push_back("2017-1-1 00:00:00.000");
	//currencyToHolidayMapTemp["SGP"].push_back("2017-1-6 00:00:00.000");
	//currencyToHolidayMapTemp["SGP"].push_back("2017-2-27 00:00:00.000");
	//currencyToHolidayMapTemp["SGP"].push_back("2017-3-25 00:00:00.000");
	//currencyToHolidayMapTemp["SGP"].push_back("2017-4-01 00:00:00.000");
	//currencyToHolidayMapTemp["SGP"].push_back("2017-4-14 00:00:00.000");
	//currencyToHolidayMapTemp["SGP"].push_back("2017-4-17 00:00:00.000");
	//currencyToHolidayMapTemp["SGP"].push_back("2017-5-1 00:00:00.000");
	//currencyToHolidayMapTemp["SGP"].push_back("2017-04-01 00:00:00.000");
	//currencyToHolidayMapTemp["SGP"].push_back("2017-04-14 00:00:00.000");
	//currencyToHolidayMapTemp["SGP"].push_back("2017-04-17 00:00:00.000");
	//currencyToHolidayMapTemp["SGP"].push_back("2017-05-01 00:00:00.000");
	//currencyToHolidayMapTemp["SGP"].push_back("2017-06-05 00:00:00.000");
	//currencyToHolidayMapTemp["SGP"].push_back("2017-08-15 00:00:00.000");
	//currencyToHolidayMapTemp["SGP"].push_back("2017-11-01 00:00:00.000");
	//currencyToHolidayMapTemp["SGP"].push_back("2017-11-28 00:00:00.000");
	//currencyToHolidayMapTemp["SGP"].push_back("2017-12-25 00:00:00.000");
	//currencyToHolidayMapTemp["SGP"].push_back("2017-12-26 00:00:00.000");
	////AED
	//currencyToHolidayMapTemp["AED"].push_back("2017-01-01 00:00:00.000");
	//currencyToHolidayMapTemp["AED"].push_back("2017-03-20 00:00:00.000");
	//currencyToHolidayMapTemp["AED"].push_back("2017-04-24 00:00:00.000");
	//currencyToHolidayMapTemp["AED"].push_back("2017-05-25 00:00:00.000");
	//currencyToHolidayMapTemp["AED"].push_back("2017-06-21 00:00:00.000");
	//currencyToHolidayMapTemp["AED"].push_back("2017-06-25 00:00:00.000");
	//currencyToHolidayMapTemp["AED"].push_back("2017-06-27 00:00:00.000");
	//currencyToHolidayMapTemp["AED"].push_back("2017-06-28 00:00:00.000");
	//currencyToHolidayMapTemp["AED"].push_back("2017-08-31 00:00:00.000");
	//currencyToHolidayMapTemp["AED"].push_back("2017-09-01 00:00:00.000");
	//currencyToHolidayMapTemp["AED"].push_back("2017-09-02 00:00:00.000");
	//currencyToHolidayMapTemp["AED"].push_back("2017-09-03 00:00:00.000");
	//currencyToHolidayMapTemp["AED"].push_back("2017-09-21 00:00:00.000");
	//currencyToHolidayMapTemp["AED"].push_back("2017-09-22 00:00:00.000");
	//currencyToHolidayMapTemp["AED"].push_back("2017-11-30 00:00:00.000");
	//currencyToHolidayMapTemp["AED"].push_back("2017-12-02 00:00:00.000");
	//currencyToHolidayMapTemp["AED"].push_back("2017-12-21 00:00:00.000");
	//currencyToHolidayMapTemp["AED"].push_back("2017-12-31 00:00:00.000");
	//Holidays::currencyToHolidayMap = currencyToHolidayMapTemp;
}


void
TransactionStoreTest::tearDown()
{
}


//Test the constructor
void
TransactionStoreTest::testConstructor()
{
	TransactionStore trStore;
	//CPPUNIT_FAIL("not implemented");
}

// Test for AddTransaction method
void TransactionStoreTest::testAddTransaction()
{
	TransactionStore trStore;
	//The date string used to create the transaction.
	//The offset of minutes MM * 60 is added to the converted time_t to create different times in day.
	//The offset of hours is added with HH * 60 * 60 to get different hours of the day
	std::string ts("2017-01-03 00:00:00.000");

	// calling the posix function to create posix time from the string.
	ptime t(time_from_string(ts));
	// converting posix time to tm structure
	// later uses the mktime to create the time_t
	tm pt_tm = to_tm(t);

	//Creating new transactions with diffrent entities, with different times of transaction.
	Transaction tr1 = Transaction("foo", "B", 0.5, "SGP", std::mktime(&pt_tm) + 2 * 60 * 60, 111, 100.25);
	Transaction tr2 = Transaction("foo", "B", 0.5, "SGP", std::mktime(&pt_tm) + 4 * 60 * 60, 333, 100.25);
	Transaction tr3 = Transaction("foo", "B", 0.5, "SGP", std::mktime(&pt_tm) + 5 * 60 * 60, 555, 100.25);
	Transaction tr4 = Transaction("foo", "B", 0.5, "SGP", std::mktime(&pt_tm) + 7 * 60 * 60, 555, 100.25);
	Transaction tr5 = Transaction("foo", "B", 0.5, "SGP", std::mktime(&pt_tm) + 9 * 60 * 60, 444, 100.25);
	Transaction tr6 = Transaction("foo", "B", 0.5, "SGP", std::mktime(&pt_tm) + 10 * 60 * 60, 222, 100.25);
	Transaction tr7 = Transaction("SAJ", "B", 0.5, "SGP", std::mktime(&pt_tm) + 5 * 60, 999, 100.25);
	Transaction tr8 = Transaction("SAJ", "B", 0.5, "SGP", std::mktime(&pt_tm) + 30 * 60, 444, 100.25);
	Transaction tr9 = Transaction("SAJ", "B", 0.5, "SGP", std::mktime(&pt_tm) + 50 * 60, 333, 100.25);
	Transaction tr10 = Transaction("SAJ", "B", 0.5, "SGP", std::mktime(&pt_tm) + 55 * 60, 666, 100.25);

	//Adding transactions to the Transaction Store
	trStore.addTransaction(tr1);
	trStore.addTransaction(tr2);
	trStore.addTransaction(tr3);
	trStore.addTransaction(tr4);
	trStore.addTransaction(tr5);
	trStore.addTransaction(tr6);
	trStore.addTransaction(tr7);
	trStore.addTransaction(tr8);
	trStore.addTransaction(tr9);
	trStore.addTransaction(tr10);

	// Test the TransactionStore to see if the counts are correct.

	CPPUNIT_ASSERT(trStore.GetSizeOfMap() == 2);
	CPPUNIT_ASSERT(trStore.GetNumOfTransactions("foo") == 6);
	CPPUNIT_ASSERT(trStore.GetNumOfTransactions("SAJ") == 4);
	CPPUNIT_ASSERT(trStore.GetSizeOfMap() == 2);
	
}


void
TransactionStoreTest::testProcess()
{
	TransactionStore trStore;
	std::string ts("2017-01-03 00:00:00.000");
	ptime t(time_from_string(ts));
	tm pt_tm = to_tm(t);

	Transaction tr1 = Transaction("foo", "B", 0.5, "SGP", std::mktime(&pt_tm) + 2 * 60 * 60, 100.25, 111);

	tr1.Process();
	time_t res = tr1.GetSettlementDate();
	CPPUNIT_ASSERT(res == 1483408800);
	double resAmount = tr1.GetTradeAmount();
	CPPUNIT_ASSERT(resAmount == 5563.8750000000000);
	
}

void 
TransactionStoreTest::testtotalIncoming()
{
	TransactionStore trStore;
	std::string ts("2017-01-03 00:00:00.000");
	ptime t(time_from_string(ts));
	tm pt_tm = to_tm(t);

	Transaction tr1 = Transaction("foo", "B", 0.5, "SGP", std::mktime(&pt_tm) + 2 * 60 * 60, 100.25, 111);
	Transaction tr2 = Transaction("foo", "B", 0.5, "SGP", std::mktime(&pt_tm) + 4 * 60 * 60, 100.25, 333);
	Transaction tr3 = Transaction("foo", "S", 0.5, "SGP", std::mktime(&pt_tm) + 5 * 60 * 60, 100.25, 555);
	Transaction tr4 = Transaction("foo", "S", 0.5, "SGP", std::mktime(&pt_tm) + 7 * 60 * 60, 100.25, 555);
	Transaction tr5 = Transaction("foo", "S", 0.5, "SGP", std::mktime(&pt_tm) + 9 * 60 * 60, 100.25, 444);
	Transaction tr6 = Transaction("foo", "S", 0.5, "SGP", std::mktime(&pt_tm) + 10 * 60 * 60, 100.25, 222);
	Transaction tr7 = Transaction("SAJ", "B", 0.5, "SGP", std::mktime(&pt_tm) + 5 * 60, 100.25, 999);
	Transaction tr8 = Transaction("SAJ", "B", 0.5, "SGP", std::mktime(&pt_tm) + 30 * 60, 100.25, 444);
	Transaction tr9 = Transaction("SAJ", "B", 0.5, "SGP", std::mktime(&pt_tm) + 50 * 60, 100.25, 333);
	Transaction tr10 = Transaction("SAJ", "B", 0.5, "SGP", std::mktime(&pt_tm) + 55 * 60, 100.25, 666);

	tr1.Process();
	tr2.Process();
	tr3.Process();
	tr4.Process();
	tr5.Process();
	tr6.Process();
	tr7.Process();
	tr8.Process();
	tr9.Process();
	tr10.Process();	

	trStore.addTransaction(tr1);
	trStore.addTransaction(tr2);
	trStore.addTransaction(tr3);
	trStore.addTransaction(tr4);
	trStore.addTransaction(tr5);
	trStore.addTransaction(tr6);
	trStore.addTransaction(tr7);
	trStore.addTransaction(tr8);
	trStore.addTransaction(tr9);
	trStore.addTransaction(tr10);

	auto sum = trStore.totalIncoming("foo", std::mktime(&pt_tm));
}

void TransactionStoreTest::testtotalOutGoing()
{
	TransactionStore trStore;
	std::string ts("2017-01-03 00:00:00.000");
	ptime t(time_from_string(ts));
	tm pt_tm = to_tm(t);

	Transaction tr1 = Transaction("foo", "B", 0.5, "SGP", std::mktime(&pt_tm) + 2 * 60 * 60, 100.25, 111);
	Transaction tr2 = Transaction("foo", "B", 0.5, "SGP", std::mktime(&pt_tm) + 4 * 60 * 60, 100.25, 333);
	Transaction tr3 = Transaction("foo", "S", 0.5, "SGP", std::mktime(&pt_tm) + 5 * 60 * 60, 100.25, 555);
	Transaction tr4 = Transaction("foo", "S", 0.5, "SGP", std::mktime(&pt_tm) + 7 * 60 * 60, 100.25, 555);
	Transaction tr5 = Transaction("foo", "S", 0.5, "SGP", std::mktime(&pt_tm) + 9 * 60 * 60, 100.25, 444);
	Transaction tr6 = Transaction("foo", "S", 0.5, "SGP", std::mktime(&pt_tm) + 10 * 60 * 60, 100.25, 222);
	Transaction tr7 = Transaction("SAJ", "B", 0.5, "SGP", std::mktime(&pt_tm) + 5 * 60, 100.25, 999);
	Transaction tr8 = Transaction("SAJ", "B", 0.5, "SGP", std::mktime(&pt_tm) + 30 * 60, 100.25, 444);
	Transaction tr9 = Transaction("SAJ", "B", 0.5, "SGP", std::mktime(&pt_tm) + 50 * 60, 100.25, 333);
	Transaction tr10 = Transaction("SAJ", "B", 0.5, "SGP", std::mktime(&pt_tm) + 55 * 60, 100.25, 666);

	tr1.Process();
	tr2.Process();
	tr3.Process();
	tr4.Process();
	tr5.Process();
	tr6.Process();
	tr7.Process();
	tr8.Process();
	tr9.Process();
	tr10.Process();

	trStore.addTransaction(tr1);
	trStore.addTransaction(tr2);
	trStore.addTransaction(tr3);
	trStore.addTransaction(tr4);
	trStore.addTransaction(tr5);
	trStore.addTransaction(tr6);
	trStore.addTransaction(tr7);
	trStore.addTransaction(tr8);
	trStore.addTransaction(tr9);
	trStore.addTransaction(tr10);

	auto sum = trStore.totalOutGoing("foo", std::mktime(&pt_tm));
	CPPUNIT_ASSERT(sum == 22255.5);

	sum = trStore.totalOutGoing("SAJ", std::mktime(&pt_tm));
	CPPUNIT_ASSERT(sum == 122405.25000000000);
}

void TransactionStoreTest::testProcessTransactions()
{
	TransactionStore trStore;
	std::string ts("2017-01-03 00:00:00.000");
	ptime t(time_from_string(ts));
	tm pt_tm = to_tm(t);

	Transaction tr1 = Transaction("foo", "B", 0.5, "SGP", std::mktime(&pt_tm) + 2 * 60 * 60, 100.25, 111);
	Transaction tr2 = Transaction("foo", "B", 0.5, "SGP", std::mktime(&pt_tm) + 4 * 60 * 60, 100.25, 333);
	Transaction tr3 = Transaction("foo", "S", 0.5, "SGP", std::mktime(&pt_tm) + 5 * 60 * 60, 100.25, 555);
	Transaction tr4 = Transaction("foo", "S", 0.5, "SGP", std::mktime(&pt_tm) + 7 * 60 * 60, 100.25, 555);
	Transaction tr5 = Transaction("foo", "S", 0.5, "SGP", std::mktime(&pt_tm) + 9 * 60 * 60, 100.25, 444);
	Transaction tr6 = Transaction("foo", "S", 0.5, "SGP", std::mktime(&pt_tm) + 10 * 60 * 60, 100.25, 222);
	Transaction tr7 = Transaction("SAJ", "B", 0.5, "SGP", std::mktime(&pt_tm) + 5 * 60, 100.25, 999);
	Transaction tr8 = Transaction("SAJ", "B", 0.5, "SGP", std::mktime(&pt_tm) + 30 * 60, 100.25, 444);
	Transaction tr9 = Transaction("SAJ", "B", 0.5, "SGP", std::mktime(&pt_tm) + 50 * 60, 100.25, 333);
	Transaction tr10 = Transaction("SAJ", "B", 0.5, "SGP", std::mktime(&pt_tm) + 55 * 60, 100.25, 666);

	trStore.addTransaction(tr1);
	trStore.addTransaction(tr2);
	trStore.addTransaction(tr3);
	trStore.addTransaction(tr4);
	trStore.addTransaction(tr5);
	trStore.addTransaction(tr6);
	trStore.addTransaction(tr7);
	trStore.addTransaction(tr8);
	trStore.addTransaction(tr9);
	trStore.addTransaction(tr10);

	trStore.ProcessTransactions();
	trStore.RankEntitiesOnTrasactions();
	
}