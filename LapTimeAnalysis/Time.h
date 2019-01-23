#pragma once
#include <iostream>
#include <string>

class Time
{
public:
	Time(float hours, float minutes, float seconds);

	Time& operator+=(const Time& t);
	
	// Returns a string representation of Time for easy printing
	std::string toString();

private:
	float _hours, _minutes, _seconds, _thousandthSeconds;

	// Simplifies seconds by converting excess seconds into minutes and keeping the remaining seconds
	void simplifySeconds();

	// Simplifies minutes by converting excess minutes into hours and keeping the remaining minutes
	void simplifyMinutes();

	// Simplifies Time by converting excess seconds into minutes, and converting excess minutes into hours
	void simplifyTime();
};

//define operator+ outside of class because it doesn't require the objects representation

Time operator+(Time t1, Time t2);