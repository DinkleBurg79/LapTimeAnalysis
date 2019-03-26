#pragma once
#include <iostream>
#include <string>

class Time
{
public:
	Time(int hours, int minutes, int seconds);

	Time& operator+=(const Time& t);

	Time& operator -=(const Time& t);
	
	// Returns a string representation of Time for easy printing
	std::string toString();

private:
	int _hours, _minutes, _seconds;

	// Simplifies seconds by converting excess seconds into minutes and keeping the remaining seconds
	void simplifySeconds();

	// Simplifies minutes by converting excess minutes into hours and keeping the remaining minutes
	void simplifyMinutes();

	// Simplifies Time by converting excess seconds into minutes, and converting excess minutes into hours
	void simplifyTime();

	// Checks if hours, minutes, or seconds have a conflicting signs such as positive hours and negative minutes
	bool hasMismatchedSigns();

	// converts hours and minutes into seconds
	void timeToSeconds();

};

// define operator+ outside of class because it doesn't require the objects representation

Time operator+(Time t1, Time t2);

Time operator-(Time t1, Time t2);