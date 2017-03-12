#ifndef DATEUTIL_H
#define DATEUTIL_H

#include <ctime>

namespace TransactionReport
{
	static class DateUtil
	{
	public:
		static time_t RemoveHourMinSec(time_t);
	};
}

#endif  // DATEUTIL_H