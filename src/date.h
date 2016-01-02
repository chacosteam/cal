#ifndef H_DATE
#define	H_DATE

#include <iostream>
#include <string>
#include <ctime>
#include <cstdint>
#include "common.h"

NAMESPACE_ICAL_BEGIN

enum class datetype: uint8_t
{
	LOCAL,
	UTC,
	TZ
};

class date
{

	private:
	datetype dtype;
	time_t ts;
	string tz;

	int year;
	int month;
	int day;
	int hour;
	int minute;
	int second;

	public:
	date (datetype _dt = datetype::LOCAL, string _tz = ""): dtype (_dt), tz (_tz)
	{
		ts = time (NULL);
		init (ts);
	}
	date (time_t _t, datetype _dt = datetype::LOCAL, string _tz = ""): dtype (_dt), ts (_t), tz (_tz)
	{
		init (ts);
	}
	date (int _y, int _m, int _d, int _h, int _M, int _s, datetype _dt = datetype::LOCAL, string _tz = ""): year (_y), month (_m), day (_d), hour (_h), minute (_M), second (_s), dtype (_dt), tz (_tz) {}
	date (int _y, int _m, int _d, datetype _dt = datetype::LOCAL, string _tz = ""): date (_y, _m, _d, 0, 0, 0, _dt, _tz) {}
	date (string _d) {}
	~date () {}

	private:
	void init (time_t);

	friend ostream& operator<< (ostream &os, const date& d);

};

NAMESPACE_ICAL_END

#endif // H_DATE
