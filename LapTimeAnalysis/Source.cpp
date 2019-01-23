#include <iostream>
#include <chrono>
#include "Time.h"
#include "Statistics.h"

using namespace std;

int main()
{
	cout << "Lap Time Program: \n";
	cout << "Need Time class, LapTime class, and Statistics class\n";

	auto start = chrono::system_clock::now();

	Time t{ 2.00f, 420.00f, 500.00f };
	Time t2{ 1.00f, 10.00f, 30.00f };
	cout << "Time 1: " << t.toString() << "\n"; // should output 9.00:8.00:20.00
	cout << "Time 2: " << t2.toString() << "\n"; // should output 1.00:10.00:30.00
	//cout << "Sum of Time 1 and 2: " << (t += t2).toString() << "\n";
	cout << "Sum of Time 1 and 2: " << (t + t2).toString() << "\n"; // should output 10:00:18.00:50.00
	cout << "Time 1: " << t.toString() << "\n"; // should output 9.00:8.00:20.00

	auto end = chrono::system_clock::now();
	chrono::duration<double> timeElapsed = end - start;
	cout << "Time elapsed: " << timeElapsed.count() << "s" << "\n\n";
	
	start = chrono::system_clock::now();
	Time t3{ 2.00f, 0.00f, 0.00f };
	Time t4{ 0.00f, -30.00f, 0.00f };
	cout << "Time 3: " << t3.toString() << "\n";
	cout << "Time 4: " << t4.toString() << "\n";
	cout << "Sum of T3 and T4: " << (t3 + t4).toString() << "\n";
	cout << "Time 3: " << t3.toString() << "\n";
	end = chrono::system_clock::now();
	timeElapsed = end - start;
	cout << "Time elapsed: " << timeElapsed.count() << "s" << "\n\n";
	
	std::vector<double> data{ 16,11,9,8,1 };
	cout << Statistics::mean(data) << "\n"; // should output 9
	cout << Statistics::variancePopulation(data) << "\n"; // should output 23.6

	cin.get();
}