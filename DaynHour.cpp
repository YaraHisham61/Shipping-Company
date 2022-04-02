#include "DaynHour.h"

DaynHour::DaynHour()
{
	day = hours = 0;
}

void DaynHour::setday(int d)
{
	if (d > 0)
		d += d;
}

void DaynHour::sethours(int h)
{
	if (h > 0)
		hours += h;
	if (hours >= 23)
	{
		hours -= 24;
		day += 1;
	}
}

int DaynHour::getday()
{
	return day;
}

int DaynHour::gethours()
{
	return hours;
}
string DaynHour::stringdisplay()
	{
		string currenttime = to_string(day);
		currenttime = currenttime + ":"+to_string(hour);
		return currenttime;
	}
