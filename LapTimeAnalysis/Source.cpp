#include <iostream>
#include "Time.h"

using namespace std;

int main()
{
	cout << "Lap Time Program: \n";
	cout << "Need Time class, LapTime class, and Statistics class\n";

	Time t{ 2.00f, 420.00f, 500.00f };
	cout << "Time: " << t.toString() << "\n";

	cin.get();
}