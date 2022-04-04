#pragma once
#include "DaynHour.h"
#include "Header.h"
class Cargo
{
	DaynHour Cprepare;
	DaynHour Cload;
	int distance;
	double cost;
	type ctype;
	int ID;

public:
	Cargo(DaynHour Cprepare, DaynHour Cload, int distance, double cost, int id, type c);
	Cargo();
	void SetCost(int ncost);
	int GetCost();
	int getID();

};

