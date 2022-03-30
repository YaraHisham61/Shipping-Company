#pragma once
#include <iostream>
using namespace std;
#include <string>
class timeh
{

		int day, hour;
	public:
		timeh();
		int getday(); 
		int gethour(); 
		void setday(int d);
	
		void sethour(int h);
	
		string stringdisplay();
	
};

