// Used with PR1520
// Specification file for the DateTime class
#ifndef DATETIME_H
#define DATETIME_H
#include <iostream>
#include <string>
#include "Date.h"
#include "Time.h"
using namespace std;

class DateTime : public Date, public Time
{
public:
	//************************************************
	// Default constructor                           *
	// Note that this constructor does nothing other *
	// than call default base class constructors.    *
	//************************************************
	DateTime() : Date(), Time()
	{ }

	//************************************************
	// Constructor                                   *
	// Note that this constructor does nothing other *
	// than call base class constructors.            *
	//************************************************
	DateTime(int dy, int mon, int yr, int hr, int mt, int sc) :
		Date(dy, mon, yr), Time(hr, mt, sc)
	{ }

	//************************************************
	// The showDateTime member function displays the *
	// date and the time.                            *
	//************************************************
	void showDateTime() const
	{
		// Display the date in the form MM/DD/YYYY.
		cout << getMonth() << "/" << getDay() << "/" << getYear() << " ";

		// Display the time in the form HH:MM:SS.
		cout << getHour() << ":" << getMin() << ":" << getSec() << endl;
	}
};
#endif
