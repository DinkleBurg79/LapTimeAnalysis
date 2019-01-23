#include "Statistics.h"

double Statistics::mean(const std::vector<double>& data)
{
	double sum = 0;
	for (auto x : data)
		sum += x;
	return sum / data.size();
}

double Statistics::variancePopulation(const std::vector<double>& data)
{
	double mean = Statistics::mean(data);
	double sumOfSquaredDeviations = 0;
	for (auto x : data)
	{
		sumOfSquaredDeviations += std::pow(x - mean, 2);
	}

	// since this is population variance, the sum of squared deviations are
	// divided by the number of samples in the data
	return sumOfSquaredDeviations / data.size();
}