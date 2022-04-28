//#include "Company.h"
#include <iostream>
#include "Company.h"
#include <ostream>
using namespace std;

int main() {
	DaynHour Currenthour;
	Company* thecompany = new Company();
	cout << "please enter the file name without extentions";
	string filename;
	cin >> filename;
	filename += ".txt";
	thecompany->loadall(filename);
	{
		
		thecompany->Simulation(Currenthour);
		
	}

	cout << "end of the simulation";
	delete thecompany;
	return 0;
}