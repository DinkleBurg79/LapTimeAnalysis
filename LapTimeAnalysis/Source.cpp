#include <iostream>
#include "Time.h"
#include "Statistics.h"

using namespace std;

int main()
{
	cout << "Lap Time Program: \n";
	cout << "Need Time class, LapTime class, and Statistics class\n";

	Time t{ 2.00f, 420.00f, 500.00f };
	Time t2{ 1.00f, 10.00f, 30.00f };
	cout << "Time 1: " << t.toString() << "\n";
	cout << "Time 2: " << t2.toString() << "\n";
	//cout << "Sum of Time 1 and 2: " << (t += t2).toString() << "\n";
	cout << "Sum of Time 1 and 2: " << (t + t2).toString() << "\n";
	cout << "Time 1: " << t.toString() << "\n";
	
	std::vector<double> data{ 16,11,9,8,1 };
	cout << Statistics::mean(data) << "\n";
	cout << Statistics::variancePopulation(data) << "\n";

	cin.get();
}