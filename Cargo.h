#pragma once
#include "DaynHour.h"
#include "Header.h"
#include <ostream>


class Truck;
class Cargo
{
	DaynHour Cprepare;
	int Cload;
	int distance;
	double cost;
	type ctype;
	int ID;
	Truck* Movingtruck;


public:
	Cargo(DaynHour Cprepare, int Cload, int distance, double cost, int id, type c);
	Cargo();
	int getVipprioity();
	void SetCost(int ncost);
	type getctype();
	double GetCost();
	int getID();
	bool operator==(int id);
	void setID(int i);
	int GetLtime();
	int GetDistance();
	DaynHour GetWaitingtime();
	DaynHour GetCargodeliverytime();
	int GetMpriority(DaynHour CurrTime);
};

