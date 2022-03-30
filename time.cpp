#include "time.h"

timeh::timeh() { day = 0; hour = 0; }


int  timeh::getday() { return day; }
	int  timeh::gethour() { return hour; }
	void  timeh::setday(int d)
	{
		if (d > 0)
			day = d;
	}
	void  timeh::sethour(int h)
	{
		if (h > 0)
			hour = h;
		if (h > 23)
		{
			hour -= 24;
			day++;
		}
	}
	string timeh::stringdisplay()
	{
		string currenttime = to_string(day);
		currenttime = currenttime + ":"+to_string(hour);
		return currenttime;
	}
