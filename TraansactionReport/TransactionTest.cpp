#include "stdafx.h"
#include "TransactionTest.h"
#include "Transaction.h"
#include <chrono>
#include <ctime>
#include <iostream>
#include <boost\date_time\posix_time\posix_time.hpp>
#include <map>

using namespace std;
using namespace TransactionReport;
using namespace boost::posix_time;
// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(TransactionTest);



void
TransactionTest::setUp()
{
	//Holidays::Initialise();
	//map<string, vector<string> > currencyToHolidayMapTemp;
	//currencyToHolidayMapTemp["SGP"].push_back("2017-1-1 00:00:00.000");
	//currencyToHolidayMapTemp["SGP"].push_back("2017-1-6 00:00:00.000");
	//currencyToHolidayMapTemp["SGP"].push_back("2017-2-27 00:00:00.000");
	//currencyToHolidayMapTemp["SGP"].push_back("2017-3-25 00:00:00.000");
	//currencyToHolidayMapTemp["SGP"].push_back("2017-4-1 00:00:00.000");
	//currencyToHolidayMapTemp["SGP"].push_back("2017-4-14 00:00:00.000");
	//currencyToHolidayMapTemp["SGP"].push_back("2017-4-17 00:00:00.000");
	//currencyToHolidayMapTemp["SGP"].push_back("2017-5-1 00:00:00.000");
	//currencyToHolidayMapTemp["SGP"].push_back("2017-4-01 00:00:00.000");
	//currencyToHolidayMapTemp["SGP"].push_back("2017-4-14 00:00:00.000");
	//currencyToHolidayMapTemp["SGP"].push_back("2017-4-17 00:00:00.000");
	//currencyToHolidayMapTemp["SGP"].push_back("2017-5-1 00:00:00.000");
	//currencyToHolidayMapTemp["SGP"].push_back("2017-6-5 00:00:00.000");
	//currencyToHolidayMapTemp["SGP"].push_back("2017-8-15 00:00:00.000");
	//currencyToHolidayMapTemp["SGP"].push_back("2017-11-1 00:00:00.000");
	//currencyToHolidayMapTemp["SGP"].push_back("2017-11-28 00:00:00.000");
	//currencyToHolidayMapTemp["SGP"].push_back("2017-12-25 00:00:00.000");
	//currencyToHolidayMapTemp["SGP"].push_back("2017-12-26 00:00:00.000");
	////AED
	//currencyToHolidayMapTemp["AED"].push_back("2017-1-1 00:00:00.000");
	//currencyToHolidayMapTemp["AED"].push_back("2017-3-20 00:00:00.000");
	//currencyToHolidayMapTemp["AED"].push_back("2017-4-24 00:00:00.000");
	//currencyToHolidayMapTemp["AED"].push_back("2017-5-25 00:00:00.000");
	//currencyToHolidayMapTemp["AED"].push_back("2017-6-21 00:00:00.000");
	//currencyToHolidayMapTemp["AED"].push_back("2017-6-25 00:00:00.000");
	//currencyToHolidayMapTemp["AED"].push_back("2017-6-27 00:00:00.000");
	//currencyToHolidayMapTemp["AED"].push_back("2017-6-28 00:00:00.000");
	//currencyToHolidayMapTemp["AED"].push_back("2017-8-31 00:00:00.000");
	//currencyToHolidayMapTemp["AED"].push_back("2017-9-1 00:00:00.000");
	//currencyToHolidayMapTemp["AED"].push_back("2017-9-2 00:00:00.000");
	//currencyToHolidayMapTemp["AED"].push_back("2017-9-3 00:00:00.000");
	//currencyToHolidayMapTemp["AED"].push_back("2017-9-21 00:00:00.000");
	//currencyToHolidayMapTemp["AED"].push_back("2017-9-22 00:00:00.000");
	//currencyToHolidayMapTemp["AED"].push_back("2017-11-30 00:00:00.000");
	//currencyToHolidayMapTemp["AED"].push_back("2017-12-2 00:00:00.000");
	//currencyToHolidayMapTemp["AED"].push_back("2017-12-21 00:00:00.000");
	//currencyToHolidayMapTemp["AED"].push_back("2017-12-31 00:00:00.000");
	//Holidays::currencyToHolidayMap = currencyToHolidayMapTemp;
}


void
TransactionTest::tearDown()
{
}


void
TransactionTest::testConstructor()
{
	std::string ts("2002-01-20 23:59:59");
	ptime t(time_from_string(ts));
	tm pt_tm = to_tm(t);
	int s = pt_tm.tm_wday;
	auto tp = std::chrono::system_clock::from_time_t(std::mktime(&pt_tm));
	
	Transaction tr = Transaction("foo", "B", 0.5, "SGP", std::mktime(&pt_tm), 100.25, 200);
	CPPUNIT_ASSERT(tr.GetCurrency() == "SGP");
	CPPUNIT_ASSERT(tr.GetEntity() == "foo");
	CPPUNIT_ASSERT(tr.GetSettlementDate() == 0);
	CPPUNIT_ASSERT(tr.GetTradeAmount() == 0);
	CPPUNIT_ASSERT(tr.GetTransactionType() == "B");
	CPPUNIT_ASSERT(tr.GetNumOfUnits() == 200);
	CPPUNIT_ASSERT(tr.GetPricePerUnit() == 100.25);
	CPPUNIT_ASSERT(tr.GetInstructionDate() == std::mktime(&pt_tm));
}

void
TransactionTest::testProcess()
{
	std::string ts("2017-01-20 23:59:59.000");
	ptime t(time_from_string(ts));
	tm pt_tm = to_tm(t);	
	auto tp = std::mktime(&pt_tm);

	Transaction tr = Transaction("foo", "B", 0.5, "SGP", tp, 200, 100.25);
	tr.Process();
	CPPUNIT_ASSERT(tr.GetTradeAmount() == 10000.000);
	CPPUNIT_ASSERT(tr.GetSettlementDate() == tp);

}

void
TransactionTest::testProcessWithInstructionDateAsHoliday()
{
	std::string ts("2017-01-01 23:00:00.000");
	ptime t(time_from_string(ts));
	tm pt_tm = to_tm(t);
	auto tp = std::mktime(&pt_tm);

	Transaction tr = Transaction("foo", "B", 0.5, "SGP", tp, 200, 100.25);
	tr.Process();
	CPPUNIT_ASSERT(tr.GetTradeAmount() == 10000.000);
	CPPUNIT_ASSERT(tr.GetSettlementDate() == tp + 24 * 60 * 60);

}

//Test if the given date is a holiday 
void
TransactionTest::testIsHoliday()
{
	//Holidays::Initialise();
	std::string ts("2017-01-03 00:00:00.000");
	ptime t(time_from_string(ts));
	tm pt_tm = to_tm(t);
	int s = pt_tm.tm_wday;
	auto tp = std::chrono::system_clock::from_time_t(std::mktime(&pt_tm));

	Transaction tr = Transaction("foo", "B", 0.5, "SGP", std::mktime(&pt_tm), 200, 100.25);
	bool res = tr.isTransactionDateHoliday(std::mktime(&pt_tm));
	CPPUNIT_ASSERT(res==false);
}

//Test if the given date is a holiday 
void
TransactionTest::testIsHolidayWithHoliday()
{
	//Holidays::Initialise();
	std::string ts("2017-01-01 00:00:00.000");
	ptime t(time_from_string(ts));
	tm pt_tm = to_tm(t);
	int s = pt_tm.tm_wday;
	auto tp = std::chrono::system_clock::from_time_t(std::mktime(&pt_tm));

	Transaction tr = Transaction("foo", "B", 0.5, "SGP", std::mktime(&pt_tm), 200, 100.25);
	bool res = tr.isTransactionDateHoliday(std::mktime(&pt_tm));
	CPPUNIT_ASSERT(res == true);
}