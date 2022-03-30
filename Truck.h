#pragma once
#include "time.h"

class Truck
{
	
	int truckcapacity;
	timeh maintenancetime;
	int speed;
	float deliveryinterval;
	//truck can have a pointer to the cargo type it load
public:
	int getTcapacity();
	timeh Mtime();
	int Tspeed();
	float TdelivaryIn();
	
};

