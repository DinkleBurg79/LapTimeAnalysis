#include "Time.h"
#include <iomanip>
#include <sstream>

Time::Time(float hours, float minutes, float seconds)
	: _hours(hours), _minutes(minutes), _seconds(seconds)
{
	// call just in case user inputs minutes or seconds that can be simplified
	simplifyTime();
}

void Time::simplifySeconds()
{
	if (_seconds >= 60)
	{
		float secondsToMinutes = _seconds / 60.0f;
		float excessSeconds = std::floor(secondsToMinutes); // seconds that are to be added to minutes
		float remainingSeconds = secondsToMinutes - excessSeconds; // remaining seconds that can't be converted and added to a whole minute
		_minutes += excessSeconds;
		_seconds = remainingSeconds * 60.0f; // convert remainingSeconds back to seconds to be set to _seconds
	}
}

void Time::simplifyMinutes()
{
	if (_minutes >= 60)
	{
		float minutesToHours = _minutes / 60.0f;
		float excessMinutes = std::floor(minutesToHours); // minutes that are to be added to hours
		float remainingMinutes = minutesToHours - excessMinutes; // remaining minutes that can't be converted and added to a whole hour
		_hours += excessMinutes;
		_minutes = remainingMinutes * 60.0f; // convert remainingMinutes back to minutes to be set to _minutes
	}
}

void Time::simplifyTime()
{
	// simplify seconds first so that all available minutes are accounted for
	simplifySeconds();
	// finally simplify all available minutes into hours
	simplifyMinutes();
}

std::string Time::toString()
{	
	std::stringstream stream{};
	std::stringstream stream2{};
	std::stringstream stream3{};
	stream << std::fixed << std::setprecision(2) << _hours;
	stream2 << std::fixed << std::setprecision(2) << _minutes;
	stream3 << std::fixed << std::setprecision(2) << _seconds;

	std::string result{ stream.str() };
	result.append(":");
	result += stream2.str();
	result.append(":");
	result += stream3.str();
	return result; 
	
	// unformatted result
	/* std::string result{ std::to_string(_hours) };
	result.append(":");
	result += std::to_string(_minutes); 
	result.append(":");
	result += std::to_string(_seconds);
	return result; */
}