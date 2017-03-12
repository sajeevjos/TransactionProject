#include "stdafx.h"
#include "Holidays.h"

using namespace std;
using namespace TransactionReport;

void Holidays::Initialise()
{
	currencyToHolidayMap["SGP"].push_back("2017-01-01 00:00:00.000");
	currencyToHolidayMap["SGP"].push_back("2017-01-06 00:00:00.000");
	currencyToHolidayMap["SGP"].push_back("2017-02-27 00:00:00.000");
	currencyToHolidayMap["SGP"].push_back("2017-03-25 00:00:00.000");
	currencyToHolidayMap["SGP"].push_back("2017-04-01 00:00:00.000");
	currencyToHolidayMap["SGP"].push_back("2017-04-14 00:00:00.000");
	currencyToHolidayMap["SGP"].push_back("2017-04-17 00:00:00.000");
	currencyToHolidayMap["SGP"].push_back("2017-05-01 00:00:00.000");
	currencyToHolidayMap["SGP"].push_back("2017-04-01 00:00:00.000");
	currencyToHolidayMap["SGP"].push_back("2017-04-14 00:00:00.000");
	currencyToHolidayMap["SGP"].push_back("2017-04-17 00:00:00.000");
	currencyToHolidayMap["SGP"].push_back("2017-05-01 00:00:00.000");
	currencyToHolidayMap["SGP"].push_back("2017-06-05 00:00:00.000");
	currencyToHolidayMap["SGP"].push_back("2017-08-15 00:00:00.000");
	currencyToHolidayMap["SGP"].push_back("2017-11-01 00:00:00.000");
	currencyToHolidayMap["SGP"].push_back("2017-11-28 00:00:00.000");
	currencyToHolidayMap["SGP"].push_back("2017-12-25 00:00:00.000");
	currencyToHolidayMap["SGP"].push_back("2017-12-26 00:00:00.000");
	//AED
	currencyToHolidayMap["AED"].push_back("2017-01-01 00:00:00.000");
	currencyToHolidayMap["AED"].push_back("2017-03-20 00:00:00.000");
	currencyToHolidayMap["AED"].push_back("2017-04-24 00:00:00.000");
	currencyToHolidayMap["AED"].push_back("2017-05-25 00:00:00.000");
	currencyToHolidayMap["AED"].push_back("2017-06-21 00:00:00.000");
	currencyToHolidayMap["AED"].push_back("2017-06-25 00:00:00.000");
	currencyToHolidayMap["AED"].push_back("2017-06-27 00:00:00.000");
	currencyToHolidayMap["AED"].push_back("2017-06-28 00:00:00.000");
	currencyToHolidayMap["AED"].push_back("2017-08-31 00:00:00.000");
	currencyToHolidayMap["AED"].push_back("2017-09-01 00:00:00.000");
	currencyToHolidayMap["AED"].push_back("2017-09-02 00:00:00.000");
	currencyToHolidayMap["AED"].push_back("2017-09-03 00:00:00.000");
	currencyToHolidayMap["AED"].push_back("2017-09-21 00:00:00.000");
	currencyToHolidayMap["AED"].push_back("2017-09-22 00:00:00.000");
	currencyToHolidayMap["AED"].push_back("2017-11-30 00:00:00.000");
	currencyToHolidayMap["AED"].push_back("2017-12-02 00:00:00.000");
	currencyToHolidayMap["AED"].push_back("2017-12-21 00:00:00.000");
	currencyToHolidayMap["AED"].push_back("2017-12-31 00:00:00.000");
}

bool Holidays::isTransactionDateHoliday(string currency, time_t date)
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
	ssdate << "000";
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