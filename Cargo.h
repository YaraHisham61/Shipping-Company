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
	DaynHour MovingTime;
	int EndMovingTime;

public:
	Cargo(DaynHour Cprepare, int Cload, int distance, double cost, int id, type c);
	Cargo();
	int getVipprioity();
	void SetCost(int ncost);
	type getctype();
	void SetType(type t);
	double GetCost();
	int getID();
	DaynHour GetPrepareTime();
	bool operator==(int id);
	void setID(int i);
	int GetLtime();
	int GetDistance();
	void SetMovingTime();
	DaynHour GetMovingTime();
	DaynHour GetWaitingtime(DaynHour CurrTime);
	DaynHour GetCargodeliverytime();
	int GetEndMovingTime();
	int GetMpriority(DaynHour CurrTime);
	Truck* GetTruck();
};

