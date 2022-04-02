#pragma once
#include "string.h"
#include <iostream>
using namespace std;
class DaynHour
{
	int day, hours;
public:

	DaynHour();
	void setday(int d);
	void sethours(int h);
	int getday();
	int gethours();
	string stringdisplay();
};

