#include "Cargo.h"
#include "Truck.h"


Cargo::Cargo(DaynHour Cprepare, int Cload, int distance, double cost, int id, type c)
{
	this-> Cprepare= Cprepare;
	this-> Cload= Cload;
	this-> distance= distance;
	this-> cost=cost;
	this->ctype=c;
	this-> ID=id;
}
int Cargo::getVipprioity()
{

	float eq = (Cprepare.DaytoHours() * distance)/cost;
	int priority = eq * 100;
	return priority;
}
Cargo::Cargo()
{
	cost= 0;
}
void Cargo::SetCost(int ncost)
{
	cost = ncost;
}
type Cargo::getctype()
{
	return ctype;
}
double Cargo::GetCost()
{
	return cost;
}
int Cargo::getID()
{
	return ID;
}

bool Cargo::operator==(int id)
{
	return ID==id;
}

void Cargo::setID(int i)
{
	ID = i;
}


DaynHour Cargo::GetWaitingtime()
{
	DaynHour WT ;
	WT = Movingtruck->getmovingtime() - Cprepare;
	return WT;
}

int Cargo::GetLtime()
{
	return Cload;
}

DaynHour Cargo::GetCargodeliverytime()
{
	DaynHour CDT;
	CDT = Movingtruck->getmovingtime() + (distance / Movingtruck->getspeed()) + Cload;
	return CDT;
}

int Cargo::GetDistance()
{
	return distance;
}

int Cargo::GetMpriority(DaynHour CurrTime)
{
	return CurrTime.DaytoHours()+ distance/ Movingtruck->getspeed();
}
