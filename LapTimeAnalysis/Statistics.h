#pragma once
#include <vector>

class Statistics
{
public:
	static double mean(const std::vector<double>& data);

	static double variancePopulation(const std::vector<double>& data);
};