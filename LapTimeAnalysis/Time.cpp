#include "Time.h"
#include <iomanip>
#include <sstream>

Time::Time(int hours, int minutes, int seconds)
	: _hours(hours), _minutes(minutes), _seconds(seconds)
{
	// call just in case user inputs minutes or seconds that can be simplified
	simplifyTime();
}

Time& Time::operator+=(const Time& t)
{
	_hours += t._hours;
	_minutes += t._minutes;
	_seconds += t._seconds;
	simplifyTime();
	return *this;
}

Time operator+(Time t1, Time t2)
{
	return t1 += t2;
}

void Time::simplifySeconds()
{
	if (abs(_seconds) >= 60 )
	{
		_minutes += _seconds / 60; // _minutes adds the amount of excess seconds
		_seconds %= 60; // _seconds gets the remainder from _seconds / 60
	}
}

void Time::simplifyMinutes()
{
	if (abs(_minutes) >= 60)
	{
		_hours += _minutes / 60; // _hours adds the amount of excess minutes
		_minutes %= 60; // _minutes gets the remainder from _minutes / 60
	}
}

void Time::simplifyTime()
{
	// Check for mismatched signs
	if (hasMismatchedSigns())
	{
		// converts hours and minutes to seconds so that all positive and negatives 
		//  are added up to get the net total time in seconds
		timeToSeconds();
	}

	// simplify seconds first so that all available minutes are accounted for
	simplifySeconds();
	// finally simplify all available minutes into hours
	simplifyMinutes();
}

bool Time::hasMismatchedSigns()
{
	if (_hours <= 0 && _minutes <= 0 && _seconds <= 0)
		return false;
	else if (_hours >= 0 && _minutes >= 0 && _seconds >= 0)
		return false;

	return true;
}

void Time::timeToSeconds()
{
		// convert all hours and minutes into seconds, then add them with seconds for total time in seconds
		int totalTimeInSeconds = (_hours * pow(60, 2)) + (_minutes * 60) + _seconds;
		// converts all time into seconds
		_hours = 0;
		_minutes = 0;
		_seconds = totalTimeInSeconds;
}

std::string Time::toString()
{	
	//std::stringstream stream{};
	//std::stringstream stream2{};
	//std::stringstream stream3{};
	//stream << std::setw(2) << std::setfill('0') << _hours;
	//stream2 << std::setw(2) << std::setfill('0') << _minutes;
	//stream3 << std::setw(2) << std::setfill('0') << _seconds;
	
	//std::string result{ stream.str() };
	//result.append(":");
	//result += stream2.str();
	//result.append(":");
	//result += stream3.str();
	//return result; 

	std::stringstream result{};
	result << std::setw(2) << std::setfill('0') << _hours;
	result << ":" << std::setw(2) << std::setfill('0') << _minutes;
	result << ":" << std::setw(2) << std::setfill('0') << _seconds;
	return result.str();
}