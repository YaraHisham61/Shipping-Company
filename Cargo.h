#pragma once
#include "DaynHour.h"
#include "Cargolist.h"
#include "Header.h"
#include <iostream>
using namespace std;

class Cargo
{
	DaynHour Cprepare;
	DaynHour Cload;
	int distance;
	double cost;
	type ctype;
	int ID;

public:
	Cargo();
	Cargo(DaynHour Cprepare, DaynHour Cload, int distance, double cost, int id, type c);
	int getdistance();
	Cargo* GetCargo();


};