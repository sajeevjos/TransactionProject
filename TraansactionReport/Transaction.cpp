#include "stdafx.h"
#include "Transaction.h"
#include <chrono>
#include <ctime>
#include <map>
#include <algorithm>
#include <sstream>
#include <boost\date_time\posix_time\posix_time.hpp>
#include "DateUtil.h"

using namespace std;
using namespace TransactionReport;
using namespace boost::posix_time;

Transaction::Transaction()
{
	//There should a different way to read from a xml file for this data.
	currencyToHolidayMap["SGP"].push_back("2017-1-1 00:00:00.000");
	currencyToHolidayMap["SGP"].push_back("2017-1-6 00:00:00.000");
	currencyToHolidayMap["SGP"].push_back("2017-2-27 00:00:00.000");
	currencyToHolidayMap["SGP"].push_back("2017-3-25 00:00:00.000");
	currencyToHolidayMap["SGP"].push_back("2017-4-1 00:00:00.000");
	currencyToHolidayMap["SGP"].push_back("2017-4-14 00:00:00.000");
	currencyToHolidayMap["SGP"].push_back("2017-4-17 00:00:00.000");
	currencyToHolidayMap["SGP"].push_back("2017-5-1 00:00:00.000");
	currencyToHolidayMap["SGP"].push_back("2017-4-1 00:00:00.000");
	currencyToHolidayMap["SGP"].push_back("2017-4-14 00:00:00.000");
	currencyToHolidayMap["SGP"].push_back("2017-4-17 00:00:00.000");
	currencyToHolidayMap["SGP"].push_back("2017-5-1 00:00:00.000");
	currencyToHolidayMap["SGP"].push_back("2017-6-5 00:00:00.000");
	currencyToHolidayMap["SGP"].push_back("2017-8-15 00:00:00.000");
	currencyToHolidayMap["SGP"].push_back("2017-11-1 00:00:00.000");
	currencyToHolidayMap["SGP"].push_back("2017-11-28 00:00:00.000");
	currencyToHolidayMap["SGP"].push_back("2017-12-25 00:00:00.000");
	currencyToHolidayMap["SGP"].push_back("2017-12-26 00:00:00.000");
	//AED
	currencyToHolidayMap["AED"].push_back("2017-1-1 00:00:00.000");
	currencyToHolidayMap["AED"].push_back("2017-3-20 00:00:00.000");
	currencyToHolidayMap["AED"].push_back("2017-4-24 00:00:00.000");
	currencyToHolidayMap["AED"].push_back("2017-5-25 00:00:00.000");
	currencyToHolidayMap["AED"].push_back("2017-6-21 00:00:00.000");
	currencyToHolidayMap["AED"].push_back("2017-6-25 00:00:00.000");
	currencyToHolidayMap["AED"].push_back("2017-6-27 00:00:00.000");
	currencyToHolidayMap["AED"].push_back("2017-6-28 00:00:00.000");
	currencyToHolidayMap["AED"].push_back("2017-8-31 00:00:00.000");
	currencyToHolidayMap["AED"].push_back("2017-9-01 00:00:00.000");
	currencyToHolidayMap["AED"].push_back("2017-9-02 00:00:00.000");
	currencyToHolidayMap["AED"].push_back("2017-9-03 00:00:00.000");
	currencyToHolidayMap["AED"].push_back("2017-9-21 00:00:00.000");
	currencyToHolidayMap["AED"].push_back("2017-9-22 00:00:00.000");
	currencyToHolidayMap["AED"].push_back("2017-11-30 00:00:00.000");
	currencyToHolidayMap["AED"].push_back("2017-12-2 00:00:00.000");
	currencyToHolidayMap["AED"].push_back("2017-12-21 00:00:00.000");
	currencyToHolidayMap["AED"].push_back("2017-12-31 00:00:00.000");
}

Transaction::~Transaction()
{

}

//constructor
Transaction::Transaction(string e, string t, double fx, string c, time_t instrdate, double pu, int num) : entity(e), transaction(t), agreedFx(fx),
currency(c), instructionDate(instrdate), pricePerUnit(pu), numOfUnits(num), tradeAmount(0), instructionSettlementDate(0)
{
	//There should a different way to read from a xml file for this data.
	currencyToHolidayMap["SGP"].push_back("2017-1-1 00:00:00.000");
	currencyToHolidayMap["SGP"].push_back("2017-1-6 00:00:00.000");
	currencyToHolidayMap["SGP"].push_back("2017-2-27 00:00:00.000");
	currencyToHolidayMap["SGP"].push_back("2017-3-25 00:00:00.000");
	currencyToHolidayMap["SGP"].push_back("2017-4-1 00:00:00.000");
	currencyToHolidayMap["SGP"].push_back("2017-4-14 00:00:00.000");
	currencyToHolidayMap["SGP"].push_back("2017-4-17 00:00:00.000");
	currencyToHolidayMap["SGP"].push_back("2017-5-1 00:00:00.000");
	currencyToHolidayMap["SGP"].push_back("2017-4-1 00:00:00.000");
	currencyToHolidayMap["SGP"].push_back("2017-4-14 00:00:00.000");
	currencyToHolidayMap["SGP"].push_back("2017-4-17 00:00:00.000");
	currencyToHolidayMap["SGP"].push_back("2017-5-1 00:00:00.000");
	currencyToHolidayMap["SGP"].push_back("2017-6-5 00:00:00.000");
	currencyToHolidayMap["SGP"].push_back("2017-8-15 00:00:00.000");
	currencyToHolidayMap["SGP"].push_back("2017-11-1 00:00:00.000");
	currencyToHolidayMap["SGP"].push_back("2017-11-28 00:00:00.000");
	currencyToHolidayMap["SGP"].push_back("2017-12-25 00:00:00.000");
	currencyToHolidayMap["SGP"].push_back("2017-12-26 00:00:00.000");
	//AED
	currencyToHolidayMap["AED"].push_back("2017-1-1 00:00:00.000");
	currencyToHolidayMap["AED"].push_back("2017-3-20 00:00:00.000");
	currencyToHolidayMap["AED"].push_back("2017-4-24 00:00:00.000");
	currencyToHolidayMap["AED"].push_back("2017-5-25 00:00:00.000");
	currencyToHolidayMap["AED"].push_back("2017-6-21 00:00:00.000");
	currencyToHolidayMap["AED"].push_back("2017-6-25 00:00:00.000");
	currencyToHolidayMap["AED"].push_back("2017-6-27 00:00:00.000");
	currencyToHolidayMap["AED"].push_back("2017-6-28 00:00:00.000");
	currencyToHolidayMap["AED"].push_back("2017-8-31 00:00:00.000");
	currencyToHolidayMap["AED"].push_back("2017-9-01 00:00:00.000");
	currencyToHolidayMap["AED"].push_back("2017-9-02 00:00:00.000");
	currencyToHolidayMap["AED"].push_back("2017-9-03 00:00:00.000");
	currencyToHolidayMap["AED"].push_back("2017-9-21 00:00:00.000");
	currencyToHolidayMap["AED"].push_back("2017-9-22 00:00:00.000");
	currencyToHolidayMap["AED"].push_back("2017-11-30 00:00:00.000");
	currencyToHolidayMap["AED"].push_back("2017-12-2 00:00:00.000");
	currencyToHolidayMap["AED"].push_back("2017-12-21 00:00:00.000");
	currencyToHolidayMap["AED"].push_back("2017-12-31 00:00:00.000");
}

//Process the transaction , the holidays map is passed in as argument.
void Transaction::Process()
{
	if (isTransactionDateHoliday(instructionDate))
	{
		//find the next day is holiday or not
		time_t nextDay = instructionDate + 24 * 60 * 60;
		if (!isTransactionDateHoliday(nextDay))
		{
			instructionSettlementDate = nextDay;
			tradeAmount = agreedFx * numOfUnits * pricePerUnit;
		}
		// the next day is also a holiday
		// scenaion of two consecutive holidays
		else
		{
			//Need to find a way to deal with consecutive holidays more than 1
			nextDay = instructionDate + 24 * 60 * 60;

		}

	}
	else
	{
		//Set the settlement date as the instruction date
		instructionSettlementDate = instructionDate;
		//calculate the  trading amount
		tradeAmount = agreedFx * numOfUnits * pricePerUnit;
	}

}

//This function determines if the instruction date is a hoilday or a weekend.
bool Transaction::isTransactionDateHoliday( time_t date)
{		
	string sdate;
	stringstream ssdate;
	ptime t = from_time_t(date);
	tm pt_tm = to_tm(t);

	// This part of the code changes the Date "2002-01-20 23:59:59.000" to "2002-01-20 00:00:00.000"
	
	ssdate << pt_tm.tm_year + 1900 << '-';
	ssdate << pt_tm.tm_mon + 1 << '-';
	ssdate << pt_tm.tm_mday << ' ';
	ssdate << "00" << ':';
	ssdate << "00" << ':';
	ssdate << "00" << '.';
	ssdate << "000" ;
	sdate = ssdate.str();

	//get the vector of holidays for the given currency
	if (currencyToHolidayMap.find(currency) != currencyToHolidayMap.end())
	{
		//Find the given date is in the vector of holidays
		const vector<string> holidays = currencyToHolidayMap.find(currency)->second;
		auto holiday = find(holidays.begin(), holidays.end(), sdate);


		//The given day is a holiday
		if (holiday != holidays.end())
		{
			return true;
		}
		//Given day is not a holiday
		else
		{
			//check if the day is a weekend 
			if (pt_tm.tm_mday == 0 || pt_tm.tm_mday == 6)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}

