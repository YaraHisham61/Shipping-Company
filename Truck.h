#pragma once
#include "DaynHour.h"
#include"Header.h"
class Truck
{

	int truckcapacity;
	DaynHour maintenancetime;
	int speed;
	float deliveryinterval;
	int id;
	type ttype;
	//truck can have a pointer to the cargo type it load
public:
	int getTcapacity();
	DaynHour Mtime();
	int Tspeed();
	float TdelivaryIn();

};
