#include "DaynHour.h"

DaynHour::DaynHour()
{
	day = hours = 0;
}

DaynHour::DaynHour(string a)
{
	string b;
	string c;
	int i = 0;
	for (i = 0; i < a.length(); i++)
	{

		if (a[i] == ':')
			break;
			b += a[i];
	}
	int j;
	for (j = i+1; j < a.length(); j++)
	{
			c += a[j];
	}
	day = stoi(b);
	hours = stoi(c);
}

void DaynHour::setday(int d)
{
	if (d > 0)
		d += d;
}

void DaynHour::sethours(int h)
{
	if (h > 0)
		hours = h;
	if (hours >= 24)
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
	currenttime = currenttime + ":" + to_string(hours);
	return currenttime;
}

bool DaynHour::operator==(DaynHour t2)
{

	return (this->day==t2.getday()&&this->hours==t2.gethours());
}

DaynHour DaynHour::operator-(DaynHour t2)
{
	DaynHour difference;
	difference.day = day - t2.day;
	difference.hours = hours - t2.hours;
	return difference;
}

DaynHour DaynHour::operator+(int t2)
{

	DaynHour sum;
	sum.sethours(hours + t2);
	sum.setday(sum.getday() + day);
	return sum;
}

bool DaynHour::operator>=(DaynHour t2)
{
	if (day >= t2.day)
		return true;
	if (hours >= t2.hours)
		return true;
	return false;
}
bool DaynHour::operator<=(DaynHour t2)
{
	if (day <= t2.day)
		return true;
	if (hours <= t2.hours)
		return true;
	return false;
}

void DaynHour::operator++()
{
	sethours(hours + 1);
}

int DaynHour::DaytoHours()
{
	int num = day * 24 + hours;
	return num;
}
