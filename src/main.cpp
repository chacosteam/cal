#include <iostream>
#include <fstream>
#include <typeinfo>
#include "date.h"

using namespace ical;

int main ()
{

	date d1 (datetype::TZ, "CET");
	cout << d1;

	date d2(2015, 01, 15, datetype::LOCAL);
	cout << d2;

	date d3(1234567890, datetype::LOCAL);
	cout << d3;

	cout << typeid(&d1).name() << endl;

	ofstream ofs;
	ofs.open ("data", ofstream::out);
	ofs << d1;
	ofs.close ();

	return 0;
}
