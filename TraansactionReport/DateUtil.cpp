#include "stdafx.h"
#include "DateUtil.h"
#include <sstream>
#include <boost\date_time\posix_time\posix_time.hpp>

using namespace std;
using namespace TransactionReport;
using namespace boost::posix_time;

using namespace std;

time_t DateUtil::RemoveHourMinSec(time_t d)
{
	string sdate;
	stringstream ssdate;
	ptime t = from_time_t(d);
	tm pt_tm = to_tm(t);

	pt_tm.tm_hour = 0;
	pt_tm.tm_min = 0;
	pt_tm.tm_sec = 0;
	return mktime(&pt_tm);
}