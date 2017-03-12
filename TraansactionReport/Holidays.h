#ifndef HOLIDAYS_H
#define HOLIDAYS_H

#include "stdafx.h"
#include <vector>
#include <ctime>
#include <map>
#include <chrono>
#include <algorithm>
#include <sstream>
#include <boost\date_time\posix_time\posix_time.hpp>
#include "DateUtil.h"

using namespace std;
using namespace boost::posix_time;


namespace TransactionReport
{
	class Holidays
	{
	public:
		static map<string, vector<string> > currencyToHolidayMap;
		static void Initialise();
		static bool isTransactionDateHoliday(string currency, time_t date);
	private:
		Holidays();
		
	};
}

#endif  // HOLIDAYS_H