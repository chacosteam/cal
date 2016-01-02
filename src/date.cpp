#include <iostream>
#include <iomanip>
#include "date.h"

NAMESPACE_ICAL_BEGIN

ostream&
operator<< (ostream& os, const date& d)
{
	if (d.dtype == datetype::TZ)
		os << "TZID=" << d.tz << ';';
	os << setfill('0');
	os << setw(4) << d.year << setw(2) << d.month << setw(2) << d.day;
	os << 'T';
	os << setw(2) << d.hour << setw(2) << d.minute << setw(2) << d.second;
	if (d.dtype == datetype::UTC)
		os << 'Z';
	os << endl;
	return os;
}

void
date::init (time_t _t)
{
	struct tm* datedetail = localtime (&_t);
	year = datedetail->tm_year + 1900;
	month = datedetail->tm_mon + 1;
	day = datedetail->tm_mday;
	hour = datedetail->tm_hour;
	minute = datedetail->tm_min;
	second = datedetail->tm_sec;
}

NAMESPACE_ICAL_END

