#pragma once
#include "DaynHour.h"
#include "Header.h"
class Cargo
{
	DaynHour Cprepare;
	int Cload;
	int distance;
	double cost;
	type ctype;
	int ID;

public:
	Cargo(DaynHour Cprepare, int Cload, int distance, double cost, int id, type c);
	Cargo();
	void SetCost(int ncost);
	double GetCost();
	int getID();

};

