// SOLUTION: DateUtility.h
#ifndef __DATE_UTILITY__
#define __DATE_UTILITY__

#pragma warning(disable : 4996)
#include <time.h>
#include <iostream>
using namespace std;

static tm* getLocalDateTime() {
	time_t curr_time;
	tm* curr_tm;

	time(&curr_time);
	curr_tm = localtime(&curr_time);

	return curr_tm;
}

static string getDateString() {
	char date_string[10];

	strftime(date_string, 10, "%x", getLocalDateTime());

	return date_string;
}

static string getTimeString() {
	char time_string[100];

	strftime(time_string, 50, "Current time is %r", getLocalDateTime());

	return time_string;
}
#endif
